#-------------------------------------------------
#
# Project created by QtCreator 2017-08-29T10:58:59
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opencv_app
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

OPENCV_ROOT = $${PWD}
SOURCE_DIR = $${OPENCV_ROOT}/src/
TEMP_DIR = $${OPENCV_ROOT}tmp/

INCLUDEPATH += $${SOURCE_DIR}

SOURCES += \
        $${OPENCV_ROOT}/main.cpp \
        $${SOURCE_DIR}/opencv_main_window.cpp \
    src/camera_commander.cpp \
    src/camera_thread.cpp

HEADERS += \
        $${SOURCE_DIR}/opencv_main_window.h \
    src/camera_commander.h \
    src/camera_thread.h

FORMS += \
        $${SOURCE_DIR}/opencv_main_window_base.ui

DESTDIR = "$${OPENCV_ROOT}/bin"
OBJECTS_DIR = "$${TEMP_DIR}/tmp/obj"
MOC_DIR = "$${TEMP_DIR}/tmp/moc"
UI_DIR = "$${TEMP_DIR}/tmp/uic"
RCC_DIR = "$${TEMP_DIR}/rcc"

LIBS += -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_flann
