attribute vec4 vertexAttr;
//attribute vec4 cylinderAttr;
attribute vec2 textureAttr;
uniform mat4 matrix;
 vec4 camera; //uniform 으로 변경 가능
uniform vec4 cameraVec;
varying vec2 textureCoord;
attribute vec4 colorAttr;
varying vec4 color;

void main()
{
    camera = vec4(1.0,1.0,0.0,1.0);
    gl_Position = matrix * vertexAttr * camera; //vec4(1.0,0.5,0.1,1.0); //* vec4(1.0,0.5,0.1,1.0);//cylinderAttr; //
    //textureCoord = textureAttr;
    color = colorAttr;
}
