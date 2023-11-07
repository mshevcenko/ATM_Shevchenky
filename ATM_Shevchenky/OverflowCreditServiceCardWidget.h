#pragma once
#include "ui_overflow_credit_service_card.h"
#include "OverflowCreditService.h"

class ATM;

class OverflowCreditServiceCardWidget : public QWidget
{
	Q_OBJECT

public:
	OverflowCreditServiceCardWidget(ATM&, const OverflowCreditService&, QWidget* parent = nullptr);
	~OverflowCreditServiceCardWidget();

signals:
	void deleted(OverflowCreditServiceCardWidget*);

private:
	ATM& _atm;
	OverflowCreditService _overflowCreditService;
	Ui_OverflowCreditServiceCard ui;

	void deleteOverflowCreditService();
};