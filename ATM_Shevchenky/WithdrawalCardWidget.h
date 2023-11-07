#pragma once
#include "ui_withdrawal_card.h"
#include "WithdrawalService.h"

class WithdrawalCardWidget : public QWidget
{
	Q_OBJECT

public:
	WithdrawalCardWidget(const WithdrawalService&, QWidget* parent = nullptr);
	~WithdrawalCardWidget();

private:
	WithdrawalService _withdrawal;
	Ui_WithdrawalCard ui;
};