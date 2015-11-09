#include "Ennemies/Kamikaze.h"

Kamikaze::Kamikaze(Updatable* parent, Material* material, Texture* texture, float x, float y, Orientation orientation) : Ennemy(parent, material, texture, KAMIKAZE_SCORE, KAMIKAZE_LIFE, 6, 2, x, y, orientation)
{}

void Kamikaze::onUpdate(Render& render)
{
	float speed = KAMIKAZE_SPEED;
	if(m_orientation == BACK)
		speed *= -1;
	move(glm::vec3(0.0, speed, 0.0), false);
	PatternAnimation::onUpdate(render);
}

bool Kamikaze::collisionPlayer(Player& player)
{

	if(rectCollision2(getRect(), player.getRect()))
		return true;
	glm::vec3 pKami = getPosition(true);
	glm::vec3 pPlay = player.getPosition(true) - player.getPositionOrigin(true);
	glm::vec3 sizeP = player.getDefaultSize() * player.getScale();

	if(m_orientation == BACK && pKami.y < 0 && (pKami.x - KAMIKAZE_EXPLOSION_X/2 < pPlay.x + sizeP.x) && 
			(pKami.x + KAMIKAZE_EXPLOSION_X/2 > pPlay.x))
		return true;
	else if(m_orientation == AHEAD && pKami.y > 0 && (pKami.x - KAMIKAZE_EXPLOSION_X/2 < pPlay.x + sizeP.x) && 
			(pKami.x + KAMIKAZE_EXPLOSION_X/2 > pPlay.x))
		return true;
	return false;
}

bool Kamikaze::destroy()
{
	glm::vec3 pKami = getPosition(true);
	if((m_orientation== BACK && pKami.y < 0) || (m_orientation == AHEAD && pKami.y > 0))
		return true;
	return Ennemy::destroy();
}
