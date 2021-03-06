#-------------------------------------------------
#
# Project created by QtCreator 2018-11-08T18:50:09
#
#-------------------------------------------------

QT       += core gui network
QT       += sql
RC_ICONS = forum.ico
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = My_forum
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    comment.cpp \
    post.cpp \
    loginwindow.cpp \
    signup.cpp \
    personal_infomation.cpp \
    writepostwindow.cpp \
    details_of_posts.cpp \
    ordinary_user.cpp \
    user.cpp \
    administrators.cpp \
    moderatorwindow.cpp \
    moderator_user.cpp \
    anonymous.cpp

HEADERS += \
        mainwindow.h \
    comment.h \
    post.h \
    loginwindow.h \
    signup.h \
    personal_infomation.h \
    writepostwindow.h \
    details_of_posts.h \
    ordinary_user.h \
    user.h \
    administrators.h \
    moderatorwindow.h \
    moderator_user.h \
    headers.h \
    anonymous.h

FORMS += \
    mainwindow.ui \
    loginwindow.ui \
    signup.ui \
    personal_infomation.ui \
    writepostwindow.ui \
    details_of_posts.ui \
    moderatorwindow.ui

RESOURCES += \
    qss.qrc

DISTFILES +=
