#include <QMessageBox>
#include "MainWidget.h"
#include "ATM.h"

MainWidget::MainWidget(ATM& atm, QWidget* parent) :
    QWidget(parent),
    _atm(atm)
{
    ui.setupUi(this);
    connect(
        ui.transferFrame,
        &ServiceOptionWidget::clicked,
        this,
        &MainWidget::transfer
    );
    connect(
        ui.overflowFrame,
        &ServiceOptionWidget::clicked,
        this,
        &MainWidget::overflow
    );
    connect(
        ui.transferHistoryFrame,
        &ServiceOptionWidget::clicked,
        this,
        &MainWidget::transferHistory
    );
    connect(
        ui.withdrawalFrame,
        &ServiceOptionWidget::clicked,
        this,
        &MainWidget::withdrawal
    );
    connect(
        ui.creditLimitFrame,
        &ServiceOptionWidget::clicked,
        this,
        &MainWidget::creditLimit
    );
    connect(
        ui.pickupCardFrame,
        &ServiceOptionWidget::clicked,
        this,
        &MainWidget::tryPickupCard
    );
}

MainWidget::~MainWidget() {}

void MainWidget::updateData()
{
    ui.balanceLineEdit->setText(QString::number(_atm.getBalance(), 'f', 2));
    ui.creditLimitLineEdit->setText(QString::number(_atm.getCreditLimit(), 'f', 2));
}


void MainWidget::tryPickupCard()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Pickup card");
    msgBox.setText("Do you really want to pickup card?");
    //msgBox.setInformativeText("Do you really want to pickup card?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int res = msgBox.exec();
    if(res == QMessageBox::Yes)
    {
        _atm.exit();
        emit pickupCard();
    }
}