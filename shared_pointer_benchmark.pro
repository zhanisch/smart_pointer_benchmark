QT += core
QT -= gui

TARGET = shared_pointer_benchmark
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Dummy.cpp

HEADERS += \
    Dummy.h

HEADERS += \
    timer.h

CONFIG += c++17

QMAKE_CXXFLAGS += -O3

