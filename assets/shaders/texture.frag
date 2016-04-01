precision mediump float;

uniform vec4 uMaskColor;
uniform bool uUseTexture;
varying vec2 varyTextureCoord;

uniform sampler2D uTexture;

void main()
{
	if(uUseTexture)
	{
		vec4 color = texture2D(uTexture, varyTextureCoord);
		if(uMaskColor == color)
			gl_FragColor = vec4(1.0, 1.0, 1.0, 0.0);
		else if(uMaskColor[3] == 0.0 && color[3] == 0.0)
			gl_FragColor = color;
		else gl_FragColor = color;
	}
	else
		gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
};
