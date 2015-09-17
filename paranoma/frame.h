#ifndef FRAME_H
#define FRAME_H

#include <QString>
#include <QVector>
#include "object.h"

class Frame
{
public:
    Frame();
    void setFilePath(QString filenpath);
    void setFileName(QString filename);
    QString getFileName();
    QString getFilePath();


private:
    QString filename;
    QString filepath;
    int width;
    int height;
    QVector<object> *obj;

};

#endif // FRAME_H
