#include <QMatrix4x4>
#include <QVector>
#include <cmath>
#include <Qvector4D>
#include <QDebug>
#include "Scene.h"
#include "Cylinder.h"
#include "SceneObject.h"
#include "gl.h"
#include "glu.h"

Scene::Scene( QWidget *parent ) :
    QOpenGLWidget( parent ),
    x(1.0),
    y(1.0),
    z(0.0),
    w(1.0)
    //1.0,0.5,0.1,1.0
{
    this->setFocusPolicy(Qt::StrongFocus);
}

Scene::~Scene()
{
    makeCurrent();
    delete m_triangle;
    doneCurrent();

}

void Scene::initializeGL()
{
    // 배경 컬러 초기화
    glClearColor( 0.1f, 0.1f, 0.2f, 1.0f );

    // 쉐이더 생성 및 컴파일
    QOpenGLShader vShader( QOpenGLShader::Vertex );
    vShader.compileSourceFile( ":/Shaders/vShader.glsl" );
    QOpenGLShader fShader( QOpenGLShader::Fragment );
    fShader.compileSourceFile( ":/Shaders/fShader.glsl" );

    // 각 쉐이더를 프로그램에 추가한다
    // QOpenGLShaderProgram m_program : 멤버 변수
    m_program.addShader( &vShader );
    m_program.addShader( &fShader );
    if ( !m_program.link() )
    {   // ! 쉐이더 프로그램에 링크되지 않는 경우 경고
        qWarning( "Error: unable to link a shader program." );
        return;
    }    

    // 쉐이더 프로그램의 인자 리스트에서 attribute 이름const char*의 위치를 반환
    // int m_vertexAttr, m_colorAttr, matrixUniform
    m_vertexAttr = m_program.attributeLocation( "vertexAttr" );
    //m_textureAttr = m_program.attributeLocation( "textureAttr" );
    m_colorAttr = m_program.attributeLocation( "colorAttr" );
    m_matrixUniform = m_program.uniformLocation( "matrix" );
    m_cameraUniform = m_program.uniformLocation("camera");

    // 텍스쳐
    //m_textureUniform = m_program.uniformLocation( "textureUniform" );

    // 새 트라이앵글을 생성하고 프로그램,버텍스,컬러 인트값 보냄 + 텍스쳐유니폼 값 보냄
    //m_triangle = new Triangle( &m_program, m_vertexAttr, m_textureAttr, m_textureUniform ); //텍스쳐용
    m_triangle = new Triangle( &m_program, m_vertexAttr ,m_colorAttr );
}

void Scene::paintGL()
{
    // 컬러버퍼초기화
    glClear( GL_COLOR_BUFFER_BIT );

    // 프로그램 바인드
    m_program.bind();

    // Matrix 설정
    QMatrix4x4 matrix;
    matrix.ortho( -2.0f, 2.0f, -3.0f, 2.0f, 2.0f, -3.0f ); // left, right,bottom, top, nearPlane, farPlane
    matrix.translate( 0.0f, 0.0f, -2.0f );

    QVector4D cameraVec;
    cameraVec = QVector4D(x,y,z,w);

    // 주어진 사이즈의(parm2 : Qsize) 현재 컨텍스트에 이 유니폼 값을 설정함
    m_program.setUniformValue( m_matrixUniform, matrix );
    m_program.setUniformValue(m_cameraUniform, cameraVec);

    // 그리기
    m_triangle->draw();


   // static double deg=0.0;
//    glClearColor (0.0, 0.0, 0.0, 0.0);
//       glMatrixMode(GL_PROJECTION);
//       glLoadIdentity();
//       glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
//       glMatrixMode(GL_MODELVIEW);
//       glLoadIdentity();

//    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //뒤의 것 싹 지워버림
//    glPushMatrix();

//    glRotatef(deg, 0.0, 0.0, 1.0); //angle
   // glColor3f (0.0, 0.5, 0.0);

    //QVector3D *xxx = new QVector3D(1.0,0.0,0.0);
    //std::vector<float> m_vertices;



//    glBegin(GL_POLYGON); //GL_POLYGON //GL_LINE_STRIP
//    glVertex3f (0, 0, 0.0);
//        glVertex3f (1, 0, 0.0);
//        glVertex3f (1, 0.75, 0.0);
//        glVertex3f (0.8, 0.82, 0.0);
//        glVertex3f (0.6, 0.85, 0.0);
//        glVertex3f (0.4, 0.85, 0.0);
//        glVertex3f (0.2, 0.82, 0.0);
//          glVertex3f (0.0, 0.75, 0.0);
//        glEnd();

//    glClear(GL_COLOR_BUFFER_BIT);
//    glLoadIdentity();
     //gluLookAt (2.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
    glLoadIdentity();
    glTranslatef(-1.5f,0.0f,-6.0f);
    glBegin(GL_TRIANGLES); //GL_TRIANGLES //GL_TRIANGLES

    glColor3f(1.0f,0.0f,0.0f);          // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Front)
    glColor3f(0.0f,1.0f,0.0f);          // Green
    glVertex3f(-1.0f,-1.0f, 1.0f);          // Left Of Triangle (Front)
    glColor3f(0.0f,0.0f,1.0f);          // Blue
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glEnd();
    glBegin(GL_LINE_STRIP);
    GLUquadric *obj = gluNewQuadric();
    //gluQuadricDrawStyle( obj, GLU_LINE );
    //glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(obj, 1, 1, 2, 30, 1); //(GLUquadric*, base, top, height, slices, stacks);
    glEnd();

    //프로그램 객체 릴리즈
    m_program.release();
}

void Scene::resizeGL( int w, int h )
{
    //화면 사이즈에 맞게 뷰포트 조정
    glViewport( 0, 0, w, h );
}

void Scene::keyPressEvent(QKeyEvent *event){
    const float step = 0.1f;

    switch( event->key() )
    {
        case Qt::Key_Up:
            y = y+0.2;
            qDebug()<<"x y z w : "<<x<<" "<<y<<" "<<z<<" "<<w;
            m_triangle->setY0( m_triangle->y0() + step );
            break;
        case Qt::Key_Left:
            x= x+0.2;
            qDebug()<<"x y z w : "<<x<<" "<<y<<" "<<z<<" "<<w;
            m_triangle->setX0( m_triangle->x0() - step );
            break;
        case Qt::Key_Down:
            y = y-0.2;
            qDebug()<<"x y z w : "<<x<<" "<<y<<" "<<z<<" "<<w;
            m_triangle->setY0( m_triangle->y0() - step );
            break;
        case Qt::Key_Right:
            x = x-0.2;
            qDebug()<<"x y z w : "<<x<<" "<<y<<" "<<z<<" "<<w;
            m_triangle->setX0( m_triangle->x0() + step );
            break;
    }
    update();

}
