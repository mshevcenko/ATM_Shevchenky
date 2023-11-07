#include "TransferWidget.h"
#include "ATM.h"

TransferWidget::TransferWidget(ATM& atm, QWidget* parent) :
    QWidget(parent),
    _atm(atm)
{
    ui.setupUi(this);
    connect(
        ui.createTransferButton, 
        &QPushButton::clicked, 
        this,
        &TransferWidget::createTransfer);
    connect(
        ui.createTransferDaemonButton, 
        &QPushButton::clicked, 
        this,
        &TransferWidget::createTransferDaemon);
    connect(ui.transferDaemonsListButton, 
        &QPushButton::clicked, 
        this,
        &TransferWidget::transferDaemonsList);
    connect(
        ui.closeButton, 
        &ClickableLabel::clicked, 
        this,
        &TransferWidget::closed);
}

TransferWidget::~TransferWidget()
{}

void TransferWidget::updateData()
{
    ui.balanceLineEdit->setText(QString::number(_atm.getBalance(), 'f', 2));
    ui.creditLimitLineEdit->setText(QString::number(_atm.getCreditLimit(), 'f', 2));
}