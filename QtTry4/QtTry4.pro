QT       += core gui sql printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clickablecalendar.cpp \
    clickablewidget.cpp \
    main.cpp \
    mainwindow.cpp \
    printorder.cpp \
    qtoolcalendar.cpp \
    secondwindow.cpp

HEADERS += \
    Libraries.h \
    clickablecalendar.h \
    clickablewidget.h \
    mainwindow.h \
    printorder.h \
    qtabwidget_v.h \
    qtoolcalendar.h \
    secondwindow.h

FORMS += \
    mainwindow.ui \
    printorder.ui \
    secondwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



RESOURCES += \
    resourses.qrc

win32:CONFIG(release, debug|release): LIBS += -LD:/Programs/QT_3/5.15.2/mingw81_32/lib/ -lwwwidgets4
else:win32:CONFIG(debug, debug|release): LIBS += -LD:/Programs/QT_3/5.15.2/mingw81_32/lib/ -lwwwidgets4d

INCLUDEPATH += D:/Programs/QT_3/5.15.2/mingw81_32/include
DEPENDPATH += D:/Programs/QT_3/5.15.2/mingw81_32/include
