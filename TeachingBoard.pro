QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    drawableComponent.cpp \
    ellipseComponent.cpp \
    eraseComponent.cpp \
    freehandComponent.cpp \
    imageComponent.cpp \
    lineComponent.cpp \
    main.cpp \
    pageInformation.cpp \
    rectangleComponent.cpp \
    redo.cpp \
    tbModel.cpp \
    teachingboard.cpp \
    undo.cpp

HEADERS += \
    drawableComponent.h \
    ellipseComponent.h \
    eraseComponent.h \
    freehandComponent.h \
    imageComponent.h \
    lineComponent.h \
    pageInformation.h \
    rectangleComponent.h \
    redo.h \
    tbmodel.h \
    teachingboard.h \
    undo.h

FORMS += \
    teachingboard.ui

TRANSLATIONS += \
    TeachingBoard_en_IN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
