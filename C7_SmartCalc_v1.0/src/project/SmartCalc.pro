QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calc_grapfform.cpp \
    credit.cpp \
    deposit.cpp \
    helpers.cpp \
    s21_calculation.c \
    calc_defaultform.cpp \
    calc_mainform.cpp \
    smartcalc.cpp \
    main.cpp \
    s21_stack.c \
    qcustomplot.cpp

HEADERS += \
    credit.h \
    deposit.h \
    helpers.h \
    s21_calculation.h \
    smartcalc.h \
    stylesheet.h \
    qcustomplot.h

FORMS += \
    credit.ui \
    deposit.ui \
    smartcalc.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = ../$${TARGET}/
!isEmpty(target.path): INSTALLS += target
