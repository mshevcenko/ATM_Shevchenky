#include "TransferHistoryWidget.h"
#include "ATM.h"
#include "gutil.h"
#include "TransferToCardWidget.h"
#include "TransferFromCardWidget.h"
#include "WithdrawalCardWidget.h"

TransferHistoryWidget::TransferHistoryWidget(ATM& atm, QWidget* parent) :
    QWidget(parent),
    _atm(atm)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &TransferHistoryWidget::closed);
}

TransferHistoryWidget::~TransferHistoryWidget()
{}

void TransferHistoryWidget::updateData()
{
    ui.balanceLineEdit->setText(QString::number(_atm.getBalance(), 'f', 2));
    ui.creditLimitLineEdit->setText(QString::number(_atm.getCreditLimit(), 'f', 2));
    clearLayout(ui.transferHistoryLayout);
    vector<Transfer> transfers = _atm.getTransfers();
    vector<WithdrawalService> withdrawals = _atm.getWithdrawalServices();
    if (transfers.size() + withdrawals.size() == 0)
    {
        ui.emptyLabel->setVisible(true);
    }
    else
    {
        ui.emptyLabel->setVisible(false);
        for (int i = 0, j = 0; i + j < transfers.size() + withdrawals.size();)
        {
            if (i == transfers.size())
            {
                ui.transferHistoryLayout->addWidget(
                    new WithdrawalCardWidget(withdrawals[j++], this)
                );
                continue;
            }
            if (j == withdrawals.size())
            {
                if (transfers[i].from() == _atm.currentCardNumber())
                {
                    ui.transferHistoryLayout->addWidget(
                        new TransferToCardWidget(transfers[i++], this)
                    );
                }
                else
                {
                    ui.transferHistoryLayout->addWidget(
                        new TransferFromCardWidget(transfers[i++], this)
                    );
                }
                continue;
            }
            if (transfers[i].transferDate() > withdrawals[j].withdrawalDate())
            {
                if (transfers[i].from() == _atm.currentCardNumber())
                {
                    ui.transferHistoryLayout->addWidget(
                        new TransferToCardWidget(transfers[i++], this)
                    );
                }
                else
                {
                    ui.transferHistoryLayout->addWidget(
                        new TransferFromCardWidget(transfers[i++], this)
                    );
                }
            }
            else
            {
                ui.transferHistoryLayout->addWidget(
                    new WithdrawalCardWidget(withdrawals[j++], this)
                );
            }
        }
    }
}