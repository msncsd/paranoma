//attribute vec4 vertexAttr;
attribute vec3 vertexAttr;
//attribute vec4 cylinderAttr;
attribute vec2 textureAttr;
uniform mat4 matrix;
    vec4 cameraVec; //임 시
uniform vec4 camera; // 사용자가 시점 조작하는 카메라
varying vec2 textureCoord;
attribute vec4 colorAttr;
varying vec4 color;

void main()
{
    cameraVec = vec4(1.0,1.0,0.0,1.0);
    gl_Position = matrix * vec4(vertexAttr ,1.0) * camera; //vec4(1.0,0.5,0.1,1.0); //* vec4(1.0,0.5,0.1,1.0);//cylinderAttr; //
    //textureCoord = textureAttr;
    color = colorAttr;
}
