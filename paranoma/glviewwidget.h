#ifndef GLVIEWWIDGET_H
#define GLVIEWWIDGET_H

#include <QGLWidget>

class GLViewWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLViewWidget(QWidget *parent = 0);

signals:

public slots:


protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void draw();

    int xRot,yRot,zRot; //회전을 위한 변수

    QPoint lastPos;
};

#endif // GLVIEWWIDGET_H
