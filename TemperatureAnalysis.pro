#-------------------------------------------------
#
# Project created by QtCreator 2017-07-12T20:33:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

TARGET = TemperatureAnalysis
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    iofile.cpp \
    stringtokenizer.cpp \
    stringtotime.cpp \
    temperatureanalysis.cpp \
    dataparser.cpp \
    validatetemperature.cpp

HEADERS  += mainwindow.h \
    iofile.h \
    temperaturedata.h \
    stringtokenizer.h \
    stringtotime.h \
    temperatureanalysis.h \
    dataparser.h \
    validatetemperature.h

FORMS    += mainwindow.ui
