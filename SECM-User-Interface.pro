#-------------------------------------------------
#
# Project created by QtCreator 2018-11-03T08:04:12
#
#-------------------------------------------------

QT       += core gui widgets charts

TARGET = SECM-User-Interface
TEMPLATE = app
INCLUDEPATH += "C:\Program Files\JAI\SDK\library\CPP\include"

LIBS += -LC:\Users\Administrator\Documents\PI -lPI_GCS2_DLL -L"C:\Program Files\JAI\SDK\library\CPP\lib\Win64_x64" -lJai_Factory
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    leftstatus.cpp \
    qt-material-widgets/components/layouts/qtmaterialsnackbarlayout.cpp \
    qt-material-widgets/components/lib/qtmaterialcheckable.cpp \
    qt-material-widgets/components/lib/qtmaterialcheckable_internal.cpp \
    qt-material-widgets/components/lib/qtmaterialoverlaywidget.cpp \
    qt-material-widgets/components/lib/qtmaterialripple.cpp \
    qt-material-widgets/components/lib/qtmaterialrippleoverlay.cpp \
    qt-material-widgets/components/lib/qtmaterialstatetransition.cpp \
    qt-material-widgets/components/lib/qtmaterialstyle.cpp \
    qt-material-widgets/components/lib/qtmaterialtheme.cpp \
    qt-material-widgets/components/qtmaterialappbar.cpp \
    qt-material-widgets/components/qtmaterialautocomplete.cpp \
    qt-material-widgets/components/qtmaterialautocomplete_internal.cpp \
    qt-material-widgets/components/qtmaterialavatar.cpp \
    qt-material-widgets/components/qtmaterialbadge.cpp \
    qt-material-widgets/components/qtmaterialcheckbox.cpp \
    qt-material-widgets/components/qtmaterialcircularprogress.cpp \
    qt-material-widgets/components/qtmaterialcircularprogress_internal.cpp \
    qt-material-widgets/components/qtmaterialdialog.cpp \
    qt-material-widgets/components/qtmaterialdialog_internal.cpp \
    qt-material-widgets/components/qtmaterialdrawer.cpp \
    qt-material-widgets/components/qtmaterialdrawer_internal.cpp \
    qt-material-widgets/components/qtmaterialfab.cpp \
    qt-material-widgets/components/qtmaterialflatbutton.cpp \
    qt-material-widgets/components/qtmaterialflatbutton_internal.cpp \
    qt-material-widgets/components/qtmaterialiconbutton.cpp \
    qt-material-widgets/components/qtmateriallist.cpp \
    qt-material-widgets/components/qtmateriallistitem.cpp \
    qt-material-widgets/components/qtmaterialmenu.cpp \
    qt-material-widgets/components/qtmaterialmenu_internal.cpp \
    qt-material-widgets/components/qtmaterialpaper.cpp \
    qt-material-widgets/components/qtmaterialprogress.cpp \
    qt-material-widgets/components/qtmaterialprogress_internal.cpp \
    qt-material-widgets/components/qtmaterialradiobutton.cpp \
    qt-material-widgets/components/qtmaterialraisedbutton.cpp \
    qt-material-widgets/components/qtmaterialscrollbar.cpp \
    qt-material-widgets/components/qtmaterialscrollbar_internal.cpp \
    qt-material-widgets/components/qtmaterialslider.cpp \
    qt-material-widgets/components/qtmaterialslider_internal.cpp \
    qt-material-widgets/components/qtmaterialsnackbar.cpp \
    qt-material-widgets/components/qtmaterialsnackbar_internal.cpp \
    qt-material-widgets/components/qtmaterialtable.cpp \
    qt-material-widgets/components/qtmaterialtabs.cpp \
    qt-material-widgets/components/qtmaterialtabs_internal.cpp \
    qt-material-widgets/components/qtmaterialtextfield.cpp \
    qt-material-widgets/components/qtmaterialtextfield_internal.cpp \
    qt-material-widgets/components/qtmaterialtoggle.cpp \
    qt-material-widgets/components/qtmaterialtoggle_internal.cpp \
    topstatus.cpp \
    tabb.cpp \
    uxlp.cpp \
    uxccdw.cpp \
    include/uxccddownb.cpp \
    include/uxccdleftb.cpp \
    include/uxccdrightb.cpp \
    include/uxccdupb.cpp \
    include/UXMSGR.cpp \
    uxpainthread.cpp \
    fileopr.cpp \
    selecter.cpp \
    scanarea.cpp \
    mylabel.cpp \
    uxdlc.cpp \
    Qt-project/uxdl.cpp \
    sigma/sigmacontrol.cpp \
    sigma/rs232-win.c \
    picontorl.cpp \
    jaicontrol.cpp \
    controlpad.cpp \
    settingwindow.cpp \
    threadpool.cpp \
    comoper.cpp \
    axiscontrols.cpp \
    uxinputline.cpp \
    axgroupbase.cpp \
    sigmagroup.cpp \
    pigroup.cpp \
    debugwin.cpp \
    labelwithinputline.cpp \
    addandsub.cpp \
    comportsetting.cpp

HEADERS += \
        mainwindow.h \
    leftstatus.h \
    qt-material-widgets/components/layouts/qtmaterialsnackbarlayout.h \
    qt-material-widgets/components/layouts/qtmaterialsnackbarlayout_p.h \
    qt-material-widgets/components/lib/qtmaterialcheckable.h \
    qt-material-widgets/components/lib/qtmaterialcheckable_internal.h \
    qt-material-widgets/components/lib/qtmaterialcheckable_p.h \
    qt-material-widgets/components/lib/qtmaterialoverlaywidget.h \
    qt-material-widgets/components/lib/qtmaterialripple.h \
    qt-material-widgets/components/lib/qtmaterialrippleoverlay.h \
    qt-material-widgets/components/lib/qtmaterialstatetransition.h \
    qt-material-widgets/components/lib/qtmaterialstatetransitionevent.h \
    qt-material-widgets/components/lib/qtmaterialstyle.h \
    qt-material-widgets/components/lib/qtmaterialstyle_p.h \
    qt-material-widgets/components/lib/qtmaterialtheme.h \
    qt-material-widgets/components/lib/qtmaterialtheme_p.h \
    qt-material-widgets/components/qtmaterialappbar.h \
    qt-material-widgets/components/qtmaterialappbar_p.h \
    qt-material-widgets/components/qtmaterialautocomplete.h \
    qt-material-widgets/components/qtmaterialautocomplete_internal.h \
    qt-material-widgets/components/qtmaterialautocomplete_p.h \
    qt-material-widgets/components/qtmaterialavatar.h \
    qt-material-widgets/components/qtmaterialavatar_p.h \
    qt-material-widgets/components/qtmaterialbadge.h \
    qt-material-widgets/components/qtmaterialbadge_p.h \
    qt-material-widgets/components/qtmaterialcheckbox.h \
    qt-material-widgets/components/qtmaterialcheckbox_p.h \
    qt-material-widgets/components/qtmaterialcircularprogress.h \
    qt-material-widgets/components/qtmaterialcircularprogress_internal.h \
    qt-material-widgets/components/qtmaterialcircularprogress_p.h \
    qt-material-widgets/components/qtmaterialdialog.h \
    qt-material-widgets/components/qtmaterialdialog_internal.h \
    qt-material-widgets/components/qtmaterialdialog_p.h \
    qt-material-widgets/components/qtmaterialdrawer.h \
    qt-material-widgets/components/qtmaterialdrawer_internal.h \
    qt-material-widgets/components/qtmaterialdrawer_p.h \
    qt-material-widgets/components/qtmaterialfab.h \
    qt-material-widgets/components/qtmaterialfab_p.h \
    qt-material-widgets/components/qtmaterialflatbutton.h \
    qt-material-widgets/components/qtmaterialflatbutton_internal.h \
    qt-material-widgets/components/qtmaterialflatbutton_p.h \
    qt-material-widgets/components/qtmaterialiconbutton.h \
    qt-material-widgets/components/qtmaterialiconbutton_p.h \
    qt-material-widgets/components/qtmateriallist.h \
    qt-material-widgets/components/qtmateriallist_p.h \
    qt-material-widgets/components/qtmateriallistitem.h \
    qt-material-widgets/components/qtmateriallistitem_p.h \
    qt-material-widgets/components/qtmaterialmenu.h \
    qt-material-widgets/components/qtmaterialmenu_internal.h \
    qt-material-widgets/components/qtmaterialmenu_p.h \
    qt-material-widgets/components/qtmaterialpaper.h \
    qt-material-widgets/components/qtmaterialpaper_p.h \
    qt-material-widgets/components/qtmaterialprogress.h \
    qt-material-widgets/components/qtmaterialprogress_internal.h \
    qt-material-widgets/components/qtmaterialprogress_p.h \
    qt-material-widgets/components/qtmaterialradiobutton.h \
    qt-material-widgets/components/qtmaterialradiobutton_p.h \
    qt-material-widgets/components/qtmaterialraisedbutton.h \
    qt-material-widgets/components/qtmaterialraisedbutton_p.h \
    qt-material-widgets/components/qtmaterialscrollbar.h \
    qt-material-widgets/components/qtmaterialscrollbar_internal.h \
    qt-material-widgets/components/qtmaterialscrollbar_p.h \
    qt-material-widgets/components/qtmaterialslider.h \
    qt-material-widgets/components/qtmaterialslider_internal.h \
    qt-material-widgets/components/qtmaterialslider_p.h \
    qt-material-widgets/components/qtmaterialsnackbar.h \
    qt-material-widgets/components/qtmaterialsnackbar_internal.h \
    qt-material-widgets/components/qtmaterialsnackbar_p.h \
    qt-material-widgets/components/qtmaterialtable.h \
    qt-material-widgets/components/qtmaterialtable_p.h \
    qt-material-widgets/components/qtmaterialtabs.h \
    qt-material-widgets/components/qtmaterialtabs_internal.h \
    qt-material-widgets/components/qtmaterialtabs_p.h \
    qt-material-widgets/components/qtmaterialtextfield.h \
    qt-material-widgets/components/qtmaterialtextfield_internal.h \
    qt-material-widgets/components/qtmaterialtextfield_p.h \
    qt-material-widgets/components/qtmaterialtoggle.h \
    qt-material-widgets/components/qtmaterialtoggle_internal.h \
    qt-material-widgets/components/qtmaterialtoggle_p.h \
    topstatus.h \
    tabb.h \
    uxlp.h \
    uxccdw.h \
    include/AfmMessage.h \
    include/uxccddownb.h \
    include/uxccdleftb.h \
    include/uxccdrightb.h \
    include/uxccdupb.h \
    include/UXMSGR.h \
    uxpainthread.h \
    fileopr.h \
    selecter.h \
    scanarea.h \
    mylabel.h \
    uxdlc.h \
    Qt-project/uxdl.h \
    sigma/rs232.h \
    sigma/sigmacontrol.h \
    PI/PI_GCS2_DLL.h \
    PI/PI_GCS2_DLL_PF.h \
    picontorl.h \
    jaicontrol.h \
    controlpad.h \
    commandtype.h \
    settingwindow.h \
    threadpool.h \
    controls.h \
    comoper.h \
    axiscontrols.h \
    uxinputline.h \
    axgroupbase.h \
    sigmagroup.h \
    pigroup.h \
    debugwin.h \
    labelwithinputline.h \
    addandsub.h \
    comportsetting.h
FORMS += \
        mainwindow.ui \
    settingwindow.ui \
    debugwin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    qt-material-widgets/components/components.pro \
    PI/PI.pro

RESOURCES += \
    qt-material-widgets/components/resources.qrc
