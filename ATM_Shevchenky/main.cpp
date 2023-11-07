#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <iostream>
#include <stdio.h>
#include <string>
#include "ui_main.h"
#include "MainWindow.h"
#include "TransferDaemonCardWidget.h"
#include "Windows.h"
#include "Wincon.h"
#include "Database.h"
#include "sqlite/sqlite3.h"
#include "OverflowCreditServiceDao.h"
#include "WithdrawalServiceDao.h"
#include "OverflowServiceDao.h"
#include "TransferDaemonDao.h"
#include "MoneyStorageDao.h"
#include "TransferDao.h"
#include "AccountDao.h"
#include "CardDao.h"
#include "BankDao.h"
#include "AtmDao.h"
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
    Console();
    //cout << boolalpha << atm.insertCard("1234567890876543", "1234") << endl;
    //cout << atm.getBalance() << endl;
    QApplication a(argc, argv);
    /*Card* card = g_CardDao.getByNumber("0000000000000000");
    if (card == nullptr) { 
        cout << "nullptr" << endl;
    }
    else
    {
        cout << card->cardNumber() << endl;
    }*/
    ATM atm = copyAndDeletePointer(Toolbox::getAtmWithMoney(1));
    MainWindow mainWindow(atm);
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
