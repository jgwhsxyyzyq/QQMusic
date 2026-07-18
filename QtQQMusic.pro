QT += widgets
QT += core gui widgets
QT += core gui multimedia
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    RecBoxItem.cpp \
    btform.cpp \
    commonpage.cpp \
    listitembox.cpp \
    main.cpp \
    music.cpp \
    musiclist.cpp \
    musicslide.cpp \
    recbox.cpp \
    volumetool.cpp \
    widget.cpp

HEADERS += \
    RecBoxItem.h \
    btform.h \
    commonpage.h \
    listitembox.h \
    music.h \
    musiclist.h \
    musicslide.h \
    recbox.h \
    volumetool.h \
    widget.h

FORMS += \
    RecBoxItem.ui \
    btform.ui \
    commonpage.ui \
    listitembox.ui \
    musicslide.ui \
    recbox.ui \
    volumetool.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
