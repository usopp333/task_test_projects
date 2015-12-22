#-------------------------------------------------
#
# Project created by QtCreator 2015-12-22T10:56:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = helloworld
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
QWAKE_CXXFLAGS += -std=c++0x
