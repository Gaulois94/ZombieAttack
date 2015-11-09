#include "Player.h"

Player::Player(Updatable* parent) : PatternAnimation(parent, NULL, textureResources.get("players"),
				Vector2ui(32*6, 32*4), Vector2ui(0, 0), Vector2ui(32, 32), Vector2ui(3, 1), 3, 10), m_shots(NULL), m_nbShots(0), m_orientation(AHEAD), m_currentWeapon(NULL)
{
	m_weapons.add("MachineGun", new MachineGun(this, NULL));
	m_currentWeapon = m_weapons.get("MachineGun");
	m_textureMaterial = new TextureMaterial();
	setMaterial(m_textureMaterial);
	scale(glm::vec3(0.15, 0.15, 1.0));
	setPositionOrigin(glm::vec3(0.5, 0.5, 0.0), true);
}

Player::~Player()
{
	deleteShots();
	delete m_textureMaterial;
}

void Player::onUpdate(Render& render)
{
	if(m_currentWeapon->addShots())
		m_currentWeapon->createShots(*this, m_shots, m_nbShots);
	PatternAnimation::onUpdate(render);
}

void Player::deleteShots()
{
	for(uint32_t i=0; i < m_nbShots; i++)
		if(m_shots[i])
			delete m_shots[i];
	delete m_shots;
	m_shots = NULL;
	m_nbShots = 0;
}

void Player::changeOrientation()
{
	if(m_orientation == BACK)
	{
		m_orientation = AHEAD;
		setRotate(0, glm::vec3(0.0, 0.0, 1.0));
	}
	else
	{
		m_orientation = BACK;
		setRotate(PI, glm::vec3(0.0, 0.0, 1.0));
	}
}

Shot** Player::getShots()
{
	return m_shots;
}

uint32_t Player::getNbShots() const
{
	return m_nbShots;
}

Orientation Player::getOrientation() const
{
	return m_orientation;
}

void Player::destroyShot(uint32_t i)
{
	if(i >= m_nbShots)
		return;
	delete m_shots[i];
	for(uint32_t j = i; j < m_nbShots-1; j++)
		m_shots[j] = m_shots[j+1];
	m_nbShots--;
}

void Player::move(const glm::vec3& m, int useScale)
{
	PatternAnimation::move(m,useScale);
	glm::vec3 p = getPosition(true);
	glm::vec3 o = getPositionOrigin(true);
	glm::vec3 s = getDefaultSize()*getScale();
	if(m.x < 0 && p.x - o.x < -1)
		setPosition(glm::vec3(-1.0+o.x, p.y, p.z), false);
	else if(p.x - o.x + s.x > 1)
		setPosition(glm::vec3(1.0+o.x-s.x, p.y, p.z), false);
}
