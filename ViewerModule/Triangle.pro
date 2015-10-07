#-------------------------------------------------
#
# Project created by QtCreator 2014-12-24T07:10:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#QMAKE_MAC_SDK = macosx10.11
TARGET = Triangle
TEMPLATE = app


SOURCES += main.cpp\
        Dialog.cpp \
    Scene.cpp \
    Triangle.cpp \
    Cylinder.cpp

HEADERS  += Dialog.h \
    Scene.h \
    Triangle.h \
    Cylinder.h \
    SceneObject.h

FORMS    += Dialog.ui

RESOURCES += \
    Shaders.qrc \
    texture.qrc

DISTFILES += \
    Textures/Blocks.jpg
