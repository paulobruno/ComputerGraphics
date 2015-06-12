#-------------------------------------------------
#
# Project created by QtCreator 2013-10-14T15:26:29
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pbChess
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    gldisplay.cpp \
    pawn.cpp \
    chessboard.cpp

HEADERS  += mainwindow.h \
    gldisplay.h \
    pawn.h \
    chessboard.h

FORMS    += mainwindow.ui
