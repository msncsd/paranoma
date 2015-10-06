#include "Triangle.h"

Triangle::Triangle( QOpenGLShaderProgram *program,
                    int vertexAttr, int textureAttr, int textureUniform) : //int colorAttr) :
    // 멤버 변수로 생성시 인자값 저장
    m_program( program ),       // QOpenGLShaderProgram m_program
    m_vertexAttr( vertexAttr ), // std::vector<float> m_vertice;
    //m_colorAttr( colorAttr ),    // std::vector<float> m_colors;
    m_textureAttr( textureAttr ),
    m_textureUniform( textureUniform ),
    m_x0( -0.5f ),
    m_y0( -0.5f ),
    m_size( 1.0f )
{
    // 초기화
    initVertices();
    initTextureCoord();
    //initColors();
    QString filepath = "/Users/koeunjeong/Documents/06.jpeg";
    QImage image(filepath);
     m_texture = new QOpenGLTexture( image);//QImage( ":/Textures/Blocks.jpg" ) );
}

Triangle::~Triangle()
{
    delete m_texture;
}

// Scene에서 Trianlge 객체 생헝 후 draw를 호출함
void Triangle::draw()
{
    // 0. 텍스쳐 bind 추가
    m_texture->bind();

    // 1. 쉐이더프로그램의 attribute location에 vertex의 값을 넣는다
    // tupleSize는 버텍스 별 컴포넌트 갯수
    // ( int location, float vertices ,int tupleSize)
    m_program->setAttributeArray( m_vertexAttr, m_vertices.data(), 3 );
    m_program->setAttributeArray( m_textureAttr, m_textureCoodrs.data(), 2 );
        // m_program->setAttributeArray( m_colorAttr, m_colors.data(), 3 );
    //추가된 텍스쳐 value
    m_program->setUniformValue(m_textureUniform,0);


    // 2.쉐이더 프로그램의 '이름'을 불러서 해당 값을 사용할 수 있는 상태로 바꾼다
    // setAttributeArray로 인해 '이름'이 사용될 것이다
    m_program->enableAttributeArray( m_vertexAttr );
     //m_program->enableAttributeArray( m_colorAttr );
    m_program->enableAttributeArray( m_textureAttr );


    // 3.어레이를 그리는 gl함수 ex (GL_TRIANGLE,0,3)
    glDrawArrays( GL_TRIANGLES, 0, m_vertices.size() / 3 );

    // 4. 1과 반대로 사용불가능하게 설정함
    m_program->disableAttributeArray( m_vertexAttr );
        //m_program->disableAttributeArray( m_colorAttr );
    m_program->disableAttributeArray( m_textureAttr );

}

void Triangle::initVertices()
{
    // 벡터의 새 크기 지정
    m_vertices.resize( 9 );

    // 0
    m_vertices[0] = m_x0; //-0.5f;
    m_vertices[1] = m_y0; //-0.5f;
    m_vertices[2] = 0.0f;

    // 1
    m_vertices[3] = m_x0 + m_size;  //0.5f;
    m_vertices[4] = m_y0;           // -0.5f;
    m_vertices[5] = 0.0f;

    // 2
    m_vertices[6] = m_x0 + m_size / 2.0f ; //0.0f;
    m_vertices[7] = m_y0 + m_size; //0.5f;
    m_vertices[8] = 0.0f;
}

//void Triangle::initColors()
//{
//    m_colors.resize( 9 );

//    // 0
//    m_colors[0] = 1.0f;
//    m_colors[1] = 0.0f;
//    m_colors[2] = 0.0f;

//    // 1
//    m_colors[3] = 0.0f;
//    m_colors[4] = 1.0f;
//    m_colors[5] = 0.0f;

//    // 2
//    m_colors[6] = 0.0f;
//    m_colors[7] = 0.0f;
//    m_colors[8] = 1.0f;
//}

void Triangle::initTextureCoord()
{
    m_textureCoodrs.resize( 6 );

    // 0 (0,0)
    m_textureCoodrs[0] = 0.0f;
    m_textureCoodrs[1] = 0.0f;

    // 1 (1,0)
    m_textureCoodrs[2] = 1.0f;
    m_textureCoodrs[3] = 0.0f;

    // 2 (0.5,1)
    m_textureCoodrs[4] = 0.5f;
    m_textureCoodrs[5] = 1.0f;
}


void Triangle::setX0( float x )
{
    m_x0 = x;
    initVertices(); // vertice 초기화
}

void Triangle::setY0( float y )
{
    m_y0 = y;
    initVertices(); // vertice 초기화
}

float Triangle::x0() const
{
    return m_x0;
}
float Triangle::y0() const
{
    return m_y0;
}

