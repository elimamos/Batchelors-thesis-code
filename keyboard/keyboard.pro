#-------------------------------------------------
#
# Project created by QtCreator 2017-10-25T17:08:24
#
#-------------------------------------------------

QT       += core gui
QT      += network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = keyboard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    buttonoperator.cpp \
    hovermanager.cpp \
    TimeManager.cpp \
    dictionary.cpp \
    personalizeview.cpp \
    googlesearcher.cpp \
    layoutlook.cpp

HEADERS  += mainwindow.h \
    buttonoperator.h \
    const.h \
    hovermanager.h \
    TimeManager.h \
    dictionary.h \
    personalizeview.h \
    googlesearcher.h \
    layoutlook.h

FORMS    += mainwindow.ui \
    personalizeview.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
