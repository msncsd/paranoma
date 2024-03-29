#-------------------------------------------------
#
# Project created by QtCreator 2015-07-26T13:31:31
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = paranoma
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    frame.cpp \
    framelist.cpp \
    glviewwidget.cpp \
    framelabel.cpp \
    object.cpp

HEADERS  += mainwindow.h \
    frame.h \
    framelist.h \
    glviewwidget.h \
    framelabel.h \
    object.h

FORMS    += mainwindow.ui

RESOURCES += \
    pics.qrc
