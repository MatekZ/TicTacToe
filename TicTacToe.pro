QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Ai.cpp \
    GameBoard20x20.cpp \
    GameBoard3x3.cpp \
    Gameplay20x20.cpp \
    PVAI_3x3.cpp \
    PVE_3x3.cpp \
    PVP_3x3.cpp \
    main.cpp \
    mainwindow20x20.cpp \
    menu.cpp

HEADERS += \
    Ai.h \
    Board20x20.h \
    Gameplay20x20.h \
    Structures.h \
    TicAi_3x3.h \
    TicRand_3x3.h \
    TicTacToe_3x3.h \
    mainwindow20x20.h \
    menu.h

FORMS += \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recources.qrc
