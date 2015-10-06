#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

class Triangle
{
public:
    // 프로그램 포인터, 버텍스,컬러 attr값 + 추가부분 : 텍스쳐
    Triangle( QOpenGLShaderProgram *program,
              int vertexAttr, int textureAttr, //,int colorAttr,
              int textureUniform );
    ~Triangle();

    void draw();

    // 키보드 추가부분
    void setX0( float x );
    void setY0( float y );
    float x0() const;
    float y0() const;

private:
    void initVertices();
        //void initColors();
    void initTextureCoord();    // 텍스쳐 코드 이닛

    std::vector<float> m_vertices;  // vertices 값 벡터
    std::vector<float> m_textureCoodrs;
    //std::vector<float> m_colors;


    QOpenGLShaderProgram *m_program;    // 쉐이더 프로그램 객체
    QOpenGLTexture *m_texture;          // 추가부분 : 텍스쳐 객체

    // 쉐이더 애트리뷰트들
    int m_vertexAttr;
    int m_colorAttr;
    int m_textureAttr;
    int m_textureUniform; // 추가부분 : 텍스쳐

    // 추가부분 : 키보드
    float m_x0;
    float m_y0;
    float m_size;

};

#endif // TRIANGLE_H
