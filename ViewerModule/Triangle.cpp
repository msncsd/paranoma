#include "Triangle.h"

Triangle::Triangle( QOpenGLShaderProgram *program,
                    int vertexAttr,
                    //int cylinderAttr,
                   // int textureAttr,
                    //int colorAttr,
                    //int textureUniform) :
                    int colorAttr) :
    // 멤버 변수로 생성시 인자값 저장
    m_program( program ),       // QOpenGLShaderProgram m_program
    m_vertexAttr( vertexAttr ), // std::vector<float> m_vertice;
    m_colorAttr( colorAttr ),    // std::vector<float> m_colors;
    //m_textureAttr( textureAttr ),
   // m_cylinderAttr(cylinderAttr),
    //m_textureUniform( textureUniform ),
    m_x0( -0.5f ),
    m_y0( -0.5f ),
    m_size( 1.0f )
{
    // 초기화
    initVertices();
    initVertices2();
   // initTextureCoord();
    initColors();
    QString filepath = "/Users/koeunjeong/Documents/01.PNG";
    QImage image(filepath);
    m_texture = new QOpenGLTexture(image); //QImage( ":/Textures/Blocks.jpg" ) );
}

Triangle::~Triangle()
{
    delete m_texture;
}

// Scene에서 Trianlge 객체 생헝 후 draw를 호출함
void Triangle::draw()
{
    // 텍스쳐 bind 추가
   // m_texture->bind();

    // 쉐이더 프로그램의 '레이아웃을 사용할 수 있게 설정
    m_program->enableAttributeArray( m_vertexAttr );
    //m_program->enableAttributeArray( m_textureAttr );
    m_program->enableAttributeArray( m_colorAttr );

    // 쉐이더프로그램의 속성 별 레이아웃에 vertex의 값을 넣는다
    // ( int location, float vertices ,int tupleSize) (*) tupleSize는 버텍스 별 컴포넌트 갯수
    m_program->setAttributeArray( m_vertexAttr, m_cylinder.data(), 3 );
    //m_program->setAttributeArray( m_vertexAttr, m_vertices.data(), 3 );

    //m_program->setAttributeArray( m_textureAttr, m_textureCoodrs.data(), 2 );
    m_program->setAttributeArray( m_colorAttr, m_colors.data(), 3 );

    // 텍스쳐의 uniform 값 설정 (location, value) (*) value : 현재의 컨텍스트
   // m_program->setUniformValue(m_textureUniform,0);


    // 어레이를 그리는 gl함수 ex (GL_TRIANGLE,0,3)
    glDrawArrays( GL_TRIANGLES, 0, m_cylinder.size() / 3 );
    //glDrawArrays( GL_TRIANGLES, 0, m_vertices.size() / 3 );


    // 레이아웃을 다시 사용불가능하게 설정함
    m_program->disableAttributeArray( m_vertexAttr );
    //m_program->disableAttributeArray( m_textureAttr );
    m_program->disableAttributeArray( m_colorAttr );

}

void Triangle::initVertices2()
{
    // 벡터의 새 크기 지정
    m_cylinder.resize(18);

    // 0
    m_cylinder[0] = 0.0f;
    m_cylinder[1] = 0.0f;
    m_cylinder[2] = 0.0f;

    // 1
    m_cylinder[3] = 1.0f;
    m_cylinder[4] = 0.0f;
    m_cylinder[5] = 0.0f;

    // 2
    m_cylinder[6] = 0.0f;
    m_cylinder[7] = 1.0f;
    m_cylinder[8] = 0.0f;


    // 4
    m_cylinder[9] = 0.0f;
    m_cylinder[10] = 0.0f;
    m_cylinder[11] = 0.0f;
    // 5
    m_cylinder[12] = 1.0f;
    m_cylinder[13] = 0.0f;
    m_cylinder[14] = 0.0f;
    // 6
    m_cylinder[15] = -1.0f;
    m_cylinder[16] = -1.0f;
    m_cylinder[17] = 0.0f;

//    // 4
//    m_cylinder[9] = 1.0f;
//    m_cylinder[10] = 0.0f;
//    m_cylinder[11] = 0.0f;

//    // 5
//    m_cylinder[12] = 0.0f;
//    m_cylinder[13] = 1.0f;
//    m_cylinder[14] = 0.0f;
//    // 6
//    m_cylinder[15] = 1.0f;
//    m_cylinder[16] = 1.0f;
//    m_cylinder[17] = 0.0f;


//    // 7
//    m_cylinder[18] = 0.0f;
//    m_cylinder[19] = 0.0f;
//    m_cylinder[20] = 0.0f;

//    // 8
//    m_cylinder[21] = 0.0f;
//    m_cylinder[22] = 1.0f;
//    m_cylinder[23] = 0.0f;
//    // 9
//    m_cylinder[24] = 1.0f;
//    m_cylinder[25] = 1.0f;
//    m_cylinder[26] = 0.0f;
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

void Triangle::initColors()
{
    m_colors.resize( 30 );

    // 0
    m_colors[0] = 1.0f;
    m_colors[1] = 0.0f;
    m_colors[2] = 0.0f;

    // 1
    m_colors[3] = 0.0f;
    m_colors[4] = 1.0f; // green
    m_colors[5] = 0.0f;

    // 2
    m_colors[6] = 0.0f;
    m_colors[7] = 0.0f;
    m_colors[8] = 1.0f; // blue

}

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

