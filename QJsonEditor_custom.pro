#-------------------------------------------------
#
# Project created by QtCreator 2017-05-05T13:28:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QJsonEditor_custom
TEMPLATE = app


SOURCES += main.cpp \
        MainWindow.cpp \
        qjsonmodel.cpp

HEADERS  += MainWindow.h \
            qjsonmodel.h

FORMS    += MainWindow.ui
