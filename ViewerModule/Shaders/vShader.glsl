attribute vec4 vertexAttr;
//attribute vec4 colorAttr;
attribute vec2 textureAttr;
uniform mat4 matrix;
//varying vec4 color;
varying vec2 textureCoord;

void main()
{                // mat4    vec4
    gl_Position = matrix * vertexAttr;
    textureCoord = textureAttr;
    //color = colorAttr;
}
