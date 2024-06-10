QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card.cpp \
    cardlist.cpp \
    cardwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    user.cpp \
    userwidget.cpp

HEADERS += \
    card.h \
    cardlist.h \
    cardwidget.h \
    mainwindow.h \
    user.h \
    userwidget.h

FORMS += \
    cardwidget.ui \
    mainwindow.ui \
    user.ui \
    userwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
