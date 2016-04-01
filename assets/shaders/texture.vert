precision mediump float;

attribute vec3 vPosition;
attribute vec2 vTextureCoord;
uniform mat4 uMVP;

varying vec2 varyTextureCoord;

void main()
{
	gl_Position = uMVP * vec4(vPosition, 1.0);
	varyTextureCoord = vTextureCoord;
};
