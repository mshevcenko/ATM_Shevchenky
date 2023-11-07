#include <QDateTime>
#include "WithdrawalCardWidget.h"

WithdrawalCardWidget::WithdrawalCardWidget(const WithdrawalService& withdrawal, QWidget* parent) :
	QWidget(parent),
	_withdrawal(withdrawal)
{
	ui.setupUi(this);
	ui.ammountLineEdit->setText(QString::number(_withdrawal.amount(), 'f', 2));
	ui.dateLineEdit->setText(QDateTime::fromSecsSinceEpoch(_withdrawal.withdrawalDate()).date().toString("dd.MM.yyyy"));
}

WithdrawalCardWidget::~WithdrawalCardWidget()
{}