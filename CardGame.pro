QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        JHFramework.cpp \
        JHModule.cpp \
        JHObject.cpp \
        Utility.cpp \
        main.cpp

RESOURCES += \
    JHLandlord.qrc \
    Resource.qrc
include($$PWD/CardManager/CardManager.pri)
include($$PWD/CardRule/CardRule.pri)
include($$PWD/GameContorl/GameContorl.pri)
include($$PWD/Interface/Interface.pri)
include($$PWD/AppData/AppData.pri)
include($$PWD/Player/Player.pri)
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    JHFramework.h \
    JHModule.h \
    JHObject.h \
    Utility.h



msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}
