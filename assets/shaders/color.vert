precision mediump float;

attribute vec3 vPosition;
attribute vec4 vColor;
attribute vec2 vTextureCoord;

varying vec4 varyColor;
varying vec2 varyTextureCoord;

uniform mat4 uMVP;

void main()
{
	varyColor = vColor;
	varyTextureCoord = vTextureCoord;
	gl_Position = uMVP * vec4(vPosition, 1.0);
};
