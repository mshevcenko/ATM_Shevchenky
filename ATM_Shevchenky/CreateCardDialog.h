#pragma once
#include "ui_create_card.h"

class ATM;

class CreateCardDialog : public QDialog
{
	Q_OBJECT

public:
	CreateCardDialog(ATM&, QWidget* parent = nullptr);
	~CreateCardDialog();

	void updateData();

private:
	ATM& _atm;
	Ui_CreateCard ui;

	void tryCreateCard();
};