#ifndef OBJECT_H
#define OBJECT_H
#include <QPoint>
#include <QVector>
//#include "frame.h"

class object
{
public:
    object();
    void delAction();
    void setAction();

private:
    int id; // object id
    QPoint center;

    // isAction == true 일때 값이 저장되는 변수들
    bool isAction; // default: false 클릭 시 동작하는 액션 존재 여부
    QVector<QPoint> obj_corners;
    int nextFrameNum;


};

#endif // OBJECT_H
