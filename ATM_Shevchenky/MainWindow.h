#pragma once
#include <QtWidgets/QMainWindow>
#include "LoginWidget.h"
#include "MainWidget.h"
#include "TransferWidget.h"
#include "CreateTransferWidget.h"
#include "CreateTransferDaemonWidget.h"
#include "TransferDaemonsListWidget.h"
#include "OverflowWidget.h"
#include "OverflowServiceWidget.h"
#include "CreateOverflowCreditServiceWidget.h"
#include "OverflowCreditServicesListWidget.h"
#include "TransferHistoryWidget.h"
#include "WithdrawalWidget.h"
#include "CreditLimitWidget.h"
#include "CreateCardDialog.h"

class ATM;

class MainWindow : public QMainWindow
{

	Q_OBJECT

public:
	MainWindow(ATM& atm, QWidget* parent = nullptr);
	~MainWindow();
	void logout();
	void setLoginWidget();
	void setMainWidget();
	void setTransferWidget();
	void setCreateTransferWidget();
	void setCreateTransferDaemonWidget();
	void setTransferDaemonsListWidget();
	void setOverflowWidget();
	void setOverflowServiceWidget();
	void setCreateOverflowCreditServiceWidget();
	void setOverflowCreditServicesListWidget();
	void setTransferHistoryWidget();
	void setWithdrawalWidget();
	void setCreditLimitWidget();
private:
	ATM& _atm;
	LoginWidget* _loginWidget;
	MainWidget* _mainWidget;
	TransferWidget* _transferWidget;
	CreateTransferWidget* _createTransferWidget;
	CreateTransferDaemonWidget* _createTransferDaemonWidget;
	TransferDaemonsListWidget* _transferDaemonsListWidget;
	OverflowWidget* _overflowWidget;
	OverflowServiceWidget* _overflowServiceWidget;
	CreateOverflowCreditServiceWidget* _createOverflowCreditServiceWidget;
	OverflowCreditServicesListWidget* _overflowCreditServicesListWidget;
	TransferHistoryWidget* _transferHistoryWidget;
	WithdrawalWidget* _withdrawalWidget;
	CreditLimitWidget* _creditLimitWidget;
	CreateCardDialog* _createCardDialog;

	void initConnections();
	void initMenuBar();
	void tryNextDay();
	void tryCreateCard();
	void doIncasators();
};