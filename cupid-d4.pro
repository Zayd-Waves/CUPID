#-------------------------------------------------
#
# Project created by QtCreator 2015-11-26T13:22:33
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cupid-d4
TEMPLATE = app

SOURCES += main.cpp

HEADERS  +=

FORMS    +=

include(AdministratorInterface/AdministratorInterface.pri)
include(AdministratorLogic/AdministratorLogic.pri)
include(AuthenticationInterface/AuthenticationInterface.pri)
include(StudentInterface/StudentInterface.pri)
include(StudentLogic/StudentLogic.pri)
include(ProjectLogic/ProjectLogic.pri)
include(Storage/Storage.pri)
include(Database/Database.pri)
include(libs/libs.pri)


