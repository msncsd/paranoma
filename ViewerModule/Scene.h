#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include "Triangle.h"

class Scene : public QOpenGLWidget
{
public:
    Scene( QWidget *parent = 0 );
    ~Scene();

private:
    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );

    void keyPressEvent( QKeyEvent *event );

    Triangle *m_triangle;
    QOpenGLShaderProgram m_program;

    int m_vertexAttr;
    int m_cylinderAttr;
    int m_colorAttr;
    int m_textureAttr;
    int m_matrixUniform;
    int m_textureUniform;
};

#endif // SCENE_H
