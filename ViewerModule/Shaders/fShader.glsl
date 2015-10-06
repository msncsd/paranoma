//varying vec4 color;

//void main()
//{
//    gl_FragColor = color;
//}

varying vec2 textureCoord;
uniform sampler2D textureUniform;

void main()
{
   gl_FragColor = texture2D( textureUniform, textureCoord );
}
