#include "stdafx.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QMessageBox>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    int result = 0;

    try
    {
        result = app.exec();
    }
    catch(const std::exception& ex)
    {
        QString message = ex.what();
        QMessageBox::critical(nullptr, qtTrId("Error"), message);
        result = -1;
    }

    return result;
}

