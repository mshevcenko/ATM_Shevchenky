#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <iostream>
#include <string>
#include "MainWindow.h"
#include "TransferDaemonCardWidget.h"
#include "Windows.h"
#include "Wincon.h"
#include "ATM.h"
#include "autil.h"

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
    //1234567890876543
    //1234
    QApplication a(argc, argv);
    ATM atm = copyAndDeletePointer(ATM::getAtmWithMoneyStorage(1));
    MainWindow mainWindow(atm);
    mainWindow.show();
    return a.exec();
}
