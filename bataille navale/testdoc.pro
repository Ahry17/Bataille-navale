TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        fonction.cpp \
        main.cpp

HEADERS += \
    fonction.h \
    structure.h
QMAKE_LFLAGS+=-static
