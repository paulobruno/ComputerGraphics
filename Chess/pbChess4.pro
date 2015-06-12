#-------------------------------------------------
#
# Project created by QtCreator 2013-10-18T21:49:55
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pbChess4
TEMPLATE = app

LIBS    += -lGLU

SOURCES += main.cpp\
    mainwindow.cpp \
    gldisplay.cpp \
    chessboard.cpp \
    pawn.cpp \
    camera.cpp

HEADERS  += mainwindow.h \
    gldisplay.h \
    chessboard.h \
    pawn.h \
    camera.h

FORMS    += mainwindow.ui
