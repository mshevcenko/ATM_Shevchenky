#pragma once
#include "ui_check_pin_code.h"

class ATM;

class CheckPinCodeDialog : public QDialog
{
	Q_OBJECT

public:
	CheckPinCodeDialog(ATM&, QWidget* parent = nullptr);
	~CheckPinCodeDialog();

	void updateData();

private:
	ATM& _atm;
	Ui_CheckPinCode ui;
	int _counter;

	void checkPinCode();
};
