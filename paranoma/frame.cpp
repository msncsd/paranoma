#include "frame.h"

// 개별의 Frame 객체 클래스

Frame::Frame()
{

}

void Frame::setFilePath(QString filepath){

    this->filepath = filepath;
}

void Frame::setFileName(QString filename){

    this->filename = filename;

}


QString Frame::getFileName(){
    return this->filename;
}

QString Frame::getFilePath(){
    return this->filepath;
}
