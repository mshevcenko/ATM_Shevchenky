#include <iostream>
#include "TransferDaemonsListWidget.h"
#include "ATM.h"
#include "gutil.h"

TransferDaemonsListWidget::TransferDaemonsListWidget(ATM& atm, QWidget* parent):
    QWidget(parent),
    _atm(atm)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &TransferDaemonsListWidget::closed);
}

TransferDaemonsListWidget::~TransferDaemonsListWidget()
{}

void TransferDaemonsListWidget::updateData()
{
    ui.balanceLineEdit->setText(QString::number(_atm.getBalance(), 'f', 2));
    ui.creditLimitLineEdit->setText(QString::number(_atm.getCreditLimit(), 'f', 2));
    //std::cout << ui.transferDaemonsListLayout->count() << std::endl;
    clearLayout(ui.transferDaemonsListLayout);
    vector<TransferDaemon> transferDaemons = _atm.getTransferDaemons();
    //std::cout << transferDaemons.size() << std::endl;
    if (transferDaemons.size() == 0)
    {
        ui.emptyLabel->setVisible(true);
    }
    else
    {
        ui.emptyLabel->setVisible(false);
        for (int i = 0; i < transferDaemons.size(); i++)
        {
            TransferDaemonCardWidget* t = new TransferDaemonCardWidget(_atm, transferDaemons[i], this);
            ui.transferDaemonsListLayout->addWidget(t);
            connect(
                t,
                &TransferDaemonCardWidget::deleted,
                this,
                &TransferDaemonsListWidget::deleteTransferDaemonCard
            );
        }
    }
}

void TransferDaemonsListWidget::deleteTransferDaemonCard(TransferDaemonCardWidget* t)
{
    ui.transferDaemonsListLayout->removeWidget(t);
    delete t;
    if (ui.transferDaemonsListLayout->count() == 0)
    {
        ui.emptyLabel->setVisible(true);
    }
}