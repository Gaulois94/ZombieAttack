attribute vec3 vPosition;
attribute vec4 vColor;
attribute vec2 vTextureCoord;

uniform mat4 uMVP;

varying vec4 varyColor;
varying vec2 varyTextureCoord;

void main()
{
	varyColor = vColor;
	varyTextureCoord = vTextureCoord;
	gl_Position = uMVP * vec4(vPosition, 1.0);
};
