#include <QApplication>
#include <QDebug>
#include <QShortcut>
#include <QTranslator>
#include <QtSingleApplication>
#include "ukmedia_systemtray_widget.h"
#include <QObject>
int main(int argc, char *argv[])
{
//    QApplication a(argc,argv);
    QtSingleApplication app("ukui-volume-control-applet",argc,argv);
    if (app.isRunning()) {
       app.sendMessage("raise_window_noop");
       qDebug() << "";
       return EXIT_SUCCESS;
    }

    //加载qm翻译文件o
    QString locale = QLocale::system().name();
    QTranslator translator;

    if (locale == "zh_CN") {
        if (translator.load("/usr/share/ukui-media/translations/ukui-volume-control-applet-qt-zh_CN.qm")) {
            app.installTranslator(&translator);
        }
        else {
            qDebug() << "Load translations file" << locale << "failed!";
        }

    }
//    qDebug() << locale;
    //加载qss文件
    QFile qss(":/data/qss/ukuimedia.qss");
    bool ok = qss.open(QFile::ReadOnly);
    if (!ok)
        qDebug() << "加载失败";
    qApp->setStyleSheet(qss.readAll());
    qss.close();

    UkmediaSystemTrayWidget w;

//    QShortcut *shortCut = new QShortcut("F10",&w);
//    shortCut->setKey(tr("F10"));
//    shortCut->setAutoRepeat(false);

//    connect(shortCut,SIGNAL(activated()),w,SLOT(keyControlVolume()));
//    app.setActivationWindow(&w);
//       w.show();
//       w.raise();
//       w.activateWindow();

    return app.exec();
}

