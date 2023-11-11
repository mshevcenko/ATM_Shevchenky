#include "TransferHistoryWidget.h"
#include "ATM.h"
#include "gutil.h"
#include "TransferToCardWidget.h"
#include "TransferFromCardWidget.h"
#include "WithdrawalCardWidget.h"

TransferHistoryWidget::TransferHistoryWidget(ATM& atm, QWidget* parent) :
    QWidget(parent),
    _atm(atm),
    _transfers(),
    _withdrawals(),
    _lastTransfer(0),
    _lastWithdrawal(0)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &TransferHistoryWidget::closed);
    connect(
        ui.moreButton,
        &QPushButton::clicked,
        this,
        &TransferHistoryWidget::loadMore);
}

TransferHistoryWidget::~TransferHistoryWidget()
{}

void TransferHistoryWidget::updateData()
{
    _lastTransfer = 0;
    _lastWithdrawal = 0;
    ui.balanceLineEdit->setText(QString::number(_atm.getBalance(), 'f', 2));
    ui.creditLimitLineEdit->setText(QString::number(_atm.getCreditLimit(), 'f', 2));
    clearLayout(ui.transferHistoryLayout);
    _transfers = _atm.getTransfers();
    _withdrawals = _atm.getWithdrawalServices();
    if (_transfers.size() + _withdrawals.size() == 0)
    {
        ui.emptyLabel->setVisible(true);
        ui.moreButton->setVisible(false);
    }
    else
    {
        if (_transfers.size() + _withdrawals.size() < 50)
        {
            ui.moreButton->setVisible(false);
        }
        else
        {
            ui.moreButton->setVisible(true);
        }
        ui.emptyLabel->setVisible(false);
        for (int i = 0; i < 50 && _lastTransfer + _lastWithdrawal < _transfers.size() + _withdrawals.size(); i++)
        {
            if (_lastTransfer == _transfers.size())
            {
                ui.transferHistoryLayout->addWidget(
                    new WithdrawalCardWidget(_withdrawals[_lastWithdrawal++], this)
                );
                continue;
            }
            if (_lastWithdrawal == _withdrawals.size())
            {
                if (_transfers[_lastTransfer].from() == _atm.currentCardNumber())
                {
                    ui.transferHistoryLayout->addWidget(
                        new TransferToCardWidget(_transfers[_lastTransfer++], this)
                    );
                }
                else
                {
                    ui.transferHistoryLayout->addWidget(
                        new TransferFromCardWidget(_transfers[_lastTransfer++], this)
                    );
                }
                continue;
            }
            if (_transfers[_lastTransfer].transferDate() > _withdrawals[_lastWithdrawal].withdrawalDate())
            {
                if (_transfers[_lastTransfer].from() == _atm.currentCardNumber())
                {
                    ui.transferHistoryLayout->addWidget(
                        new TransferToCardWidget(_transfers[_lastTransfer++], this)
                    );
                }
                else
                {
                    ui.transferHistoryLayout->addWidget(
                        new TransferFromCardWidget(_transfers[_lastTransfer++], this)
                    );
                }
            }
            else
            {
                ui.transferHistoryLayout->addWidget(
                    new WithdrawalCardWidget(_withdrawals[_lastWithdrawal++], this)
                );
            }
        }
    }
}

void TransferHistoryWidget::loadMore()
{
    for (int i = 0; i < 10 && _lastTransfer + _lastWithdrawal < _transfers.size() + _withdrawals.size(); i++)
    {
        if (_lastTransfer == _transfers.size())
        {
            ui.transferHistoryLayout->addWidget(
                new WithdrawalCardWidget(_withdrawals[_lastWithdrawal++], this)
            );
            continue;
        }
        if (_lastWithdrawal == _withdrawals.size())
        {
            if (_transfers[_lastTransfer].from() == _atm.currentCardNumber())
            {
                ui.transferHistoryLayout->addWidget(
                    new TransferToCardWidget(_transfers[_lastTransfer++], this)
                );
            }
            else
            {
                ui.transferHistoryLayout->addWidget(
                    new TransferFromCardWidget(_transfers[_lastTransfer++], this)
                );
            }
            continue;
        }
        if (_transfers[_lastTransfer].transferDate() > _withdrawals[_lastWithdrawal].withdrawalDate())
        {
            if (_transfers[_lastTransfer].from() == _atm.currentCardNumber())
            {
                ui.transferHistoryLayout->addWidget(
                    new TransferToCardWidget(_transfers[_lastTransfer++], this)
                );
            }
            else
            {
                ui.transferHistoryLayout->addWidget(
                    new TransferFromCardWidget(_transfers[_lastTransfer++], this)
                );
            }
        }
        else
        {
            ui.transferHistoryLayout->addWidget(
                new WithdrawalCardWidget(_withdrawals[_lastWithdrawal++], this)
            );
        }
    }
    if (_lastTransfer + _lastWithdrawal == _transfers.size() + _withdrawals.size())
    {
        ui.moreButton->setVisible(false);
    }
}