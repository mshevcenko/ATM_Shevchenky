#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <iostream>
#include "ui_main.h"
#include "MainWindow.h"
#include "MainWidget.h"
#include "TransferDaemonCardWidget.h"
#include "LoginWidget.h"
#include "Windows.h"
#include "Wincon.h"

using namespace std;

void Console()
{
    AllocConsole();
    FILE* pFileCon = NULL;
    pFileCon = freopen("CONOUT$", "w", stdout);

    COORD coordInfo;
    coordInfo.X = 130;
    coordInfo.Y = 9000;

    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coordInfo);
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_QUICK_EDIT_MODE | ENABLE_EXTENDED_FLAGS);
}

int main(int argc, char *argv[])
{
    //Console();
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    //MainWidget widget; widget.show();
    //LoginWidget widget; widget.show();
    /*QWidget* widget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->addWidget(new TransferDaemonCardWidget(widget));
    layout->addWidget(new TransferDaemonCardWidget(widget));
    widget->setLayout(layout);
    widget->show();*/
    //cout << "Hello world!\n";
    return a.exec();
}
