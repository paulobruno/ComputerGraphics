#-------------------------------------------------
#
# Project created by QtCreator 2013-11-16T03:25:02
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG(debug, debug|release) {
    DESTDIR     =   bin/debug
    OBJECTS_DIR =   obj/debug
} else {
    DESTDIR     =   bin/release
    OBJECTS_DIR =   obj/release
}

LIBS	+=  -lm -lGL -lGLU

UI_DIR  =   temp
RCC_DIR =   temp
MOC_DIR =   temp

TARGET  =   pbChess6
TEMPLATE=   app

INCLUDEPATH +=	.assets assets/models \
    .res res/display \
    .res res/layout \
    .src src/objects \
    .src src/primitives \
    .src src/scene

SOURCES	+=  res/display/PbGLWidget.cpp \
    res/layout/main.cpp \
    res/layout/mainwindow.cpp \
    src/objects/PbChessboard.cpp \
    src/objects/PbPawn.cpp \
    src/primitives/PbPoint.cpp \
    src/primitives/PbVector.cpp \
    src/scene/PbCamera.cpp \
    src/scene/PbQuaternion.cpp

HEADERS	+=  res/display/PbGLWidget.h \
    res/layout/mainwindow.h \
    src/objects/PbChessboard.h \
    src/objects/PbChessObject.h \
    src/objects/PbPawn.h \
    src/primitives/PbPoint.h \
    src/primitives/PbVector.h \
    src/scene/PbCamera.h \
    src/scene/PbQuaternion.h

FORMS   +=  res/layout/mainwindow.ui
