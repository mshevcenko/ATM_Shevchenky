#include <QMenuBar>
#include <QMessageBox>
#include "MainWindow.h"
#include "ATM.h"

MainWindow::MainWindow(ATM& atm, QWidget* parent) :
	QMainWindow(parent),
	_atm(atm),
	_loginWidget(new LoginWidget(_atm, this)),
	_mainWidget(new MainWidget(_atm, this)),
	_transferWidget(new TransferWidget(_atm, this)),
	_createTransferWidget(new CreateTransferWidget(_atm, this)),
	_createTransferDaemonWidget(new CreateTransferDaemonWidget(_atm, this)),
	_transferDaemonsListWidget(new TransferDaemonsListWidget(_atm, this)),
	_overflowWidget(new OverflowWidget(_atm, this)),
	_overflowServiceWidget(new OverflowServiceWidget(_atm, this)),
	_createOverflowCreditServiceWidget(new CreateOverflowCreditServiceWidget(_atm, this)),
	_overflowCreditServicesListWidget(new OverflowCreditServicesListWidget(_atm, this)),
	_transferHistoryWidget(new TransferHistoryWidget(_atm, this)),
	_withdrawalWidget(new WithdrawalWidget(_atm, this)),
	_creditLimitWidget(new CreditLimitWidget(_atm, this)),
	_createCardDialog(new CreateCardDialog(_atm, this))
{
	setWindowTitle("ATM");
	setMinimumSize(650, 650);
	_loginWidget->updateData();
	setCentralWidget(_loginWidget);
	_mainWidget->setVisible(false);
	_transferWidget->setVisible(false);
	_createTransferWidget->setVisible(false);
	_createTransferDaemonWidget->setVisible(false);
	_transferDaemonsListWidget->setVisible(false);
	_overflowWidget->setVisible(false);
	_overflowServiceWidget->setVisible(false);
	_createOverflowCreditServiceWidget->setVisible(false);
	_overflowCreditServicesListWidget->setVisible(false);
	_transferHistoryWidget->setVisible(false);
	_withdrawalWidget->setVisible(false);
	_creditLimitWidget->setVisible(false);
	initMenuBar();
	initConnections();
}

void MainWindow::initMenuBar()
{
	QAction* createCard = menuBar()->addAction("Create Card");
	QAction* nextDay = menuBar()->addAction("Next Day");
	QAction* incasators = menuBar()->addAction("Incasators");
	connect(
		createCard,
		&QAction::triggered,
		this,
		&MainWindow::tryCreateCard
	);
	connect(
		nextDay,
		&QAction::triggered,
		this,
		&MainWindow::tryNextDay
	);
	connect(
		incasators,
		&QAction::triggered,
		this,
		&MainWindow::doIncasators
	);
}

void MainWindow::tryNextDay()
{
	if (centralWidget() == _loginWidget)
	{
		_atm.nextDay();
		QMessageBox msgBox;
		msgBox.setWindowTitle("Next day");
		msgBox.setText("Next day has been called successfully!");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setWindowTitle("Next day");
		msgBox.setText("Next day can be called only on login window!");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
	}
}

void MainWindow::tryCreateCard()
{
	_createCardDialog->updateData();
	_createCardDialog->show();
}

void MainWindow::doIncasators()
{
	_atm.doIncasators();
	QMessageBox msgBox;
	msgBox.setWindowTitle("Incasators");
	msgBox.setText("Incasators came and refilled the ATM!");
	msgBox.setStandardButtons(QMessageBox::Ok);
	msgBox.setDefaultButton(QMessageBox::Ok);
	msgBox.exec();
}

void MainWindow::initConnections()
{
	connect(
		_loginWidget,
		&LoginWidget::login,
		this,
		&MainWindow::setMainWidget);
	connect(
		_mainWidget,
		&MainWidget::transfer,
		this,
		&MainWindow::setTransferWidget);
	connect(
		_mainWidget,
		&MainWidget::overflow,
		this,
		&MainWindow::setOverflowWidget);
	connect(
		_mainWidget,
		&MainWidget::transferHistory,
		this,
		&MainWindow::setTransferHistoryWidget);
	connect(
		_mainWidget,
		&MainWidget::withdrawal,
		this,
		&MainWindow::setWithdrawalWidget);
	connect(
		_mainWidget,
		&MainWidget::creditLimit,
		this,
		&MainWindow::setCreditLimitWidget);
	connect(
		_mainWidget,
		&MainWidget::pickupCard,
		this,
		&MainWindow::setLoginWidget);
	connect(
		_transferWidget,
		&TransferWidget::createTransfer,
		this,
		&MainWindow::setCreateTransferWidget);
	connect(
		_transferWidget,
		&TransferWidget::createTransferDaemon,
		this,
		&MainWindow::setCreateTransferDaemonWidget);
	connect(
		_transferWidget,
		&TransferWidget::transferDaemonsList,
		this,
		&MainWindow::setTransferDaemonsListWidget);
	connect(
		_transferWidget,
		&TransferWidget::closed,
		this,
		&MainWindow::setMainWidget);
	connect(
		_createTransferWidget,
		&CreateTransferWidget::closed,
		this,
		&MainWindow::setTransferWidget);
	connect(
		_createTransferWidget,
		&CreateTransferWidget::logout,
		this,
		&MainWindow::logout);
	connect(
		_createTransferDaemonWidget,
		&CreateTransferDaemonWidget::closed,
		this,
		&MainWindow::setTransferWidget);
	connect(
		_createTransferDaemonWidget,
		&CreateTransferDaemonWidget::logout,
		this,
		&MainWindow::logout);
	connect(
		_transferDaemonsListWidget,
		&TransferDaemonsListWidget::closed,
		this,
		&MainWindow::setTransferWidget);
	connect(
		_overflowWidget,
		&OverflowWidget::overflowService,
		this,
		&MainWindow::setOverflowServiceWidget);
	connect(
		_overflowWidget,
		&OverflowWidget::createOverflowCreditService,
		this,
		&MainWindow::setCreateOverflowCreditServiceWidget);
	connect(
		_overflowWidget,
		&OverflowWidget::overflowCreditServicesList,
		this,
		&MainWindow::setOverflowCreditServicesListWidget);
	connect(
		_overflowWidget,
		&OverflowWidget::closed,
		this,
		&MainWindow::setMainWidget);
	connect(
		_overflowServiceWidget,
		&OverflowServiceWidget::closed,
		this,
		&MainWindow::setOverflowWidget);
	connect(
		_overflowServiceWidget,
		&OverflowServiceWidget::logout,
		this,
		&MainWindow::logout);
	connect(
		_createOverflowCreditServiceWidget,
		&CreateOverflowCreditServiceWidget::closed,
		this,
		&MainWindow::setOverflowWidget);
	connect(
		_createOverflowCreditServiceWidget,
		&CreateOverflowCreditServiceWidget::logout,
		this,
		&MainWindow::logout);
	connect(
		_overflowCreditServicesListWidget,
		&OverflowCreditServicesListWidget::closed,
		this,
		&MainWindow::setOverflowWidget);
	connect(
		_transferHistoryWidget,
		&TransferHistoryWidget::closed,
		this,
		&MainWindow::setMainWidget);
	connect(
		_creditLimitWidget,
		&CreditLimitWidget::closed,
		this,
		&MainWindow::setMainWidget);
	connect(
		_creditLimitWidget,
		&CreditLimitWidget::closed,
		this,
		&MainWindow::setMainWidget);
	connect(
		_withdrawalWidget,
		&WithdrawalWidget::closed,
		this,
		&MainWindow::setMainWidget);
	connect(
		_withdrawalWidget,
		&WithdrawalWidget::logout,
		this,
		&MainWindow::logout);
}

MainWindow::~MainWindow() {}

void MainWindow::logout()
{
	_atm.exit();
	setLoginWidget();
}

void MainWindow::setLoginWidget()
{
	takeCentralWidget()->setVisible(false);
	setCentralWidget(_loginWidget);
	_loginWidget->updateData();
	_loginWidget->setVisible(true);
}

void MainWindow::setMainWidget()
{
	takeCentralWidget()->setVisible(false);
	setCentralWidget(_mainWidget);
	_mainWidget->updateData();
	_mainWidget->setVisible(true);
}

void MainWindow::setTransferWidget()
{
	takeCentralWidget()->setVisible(false);
	setCentralWidget(_transferWidget);
	_transferWidget->updateData();
	_transferWidget->setVisible(true);
}

void MainWindow::setCreateTransferWidget()
{
	takeCentralWidget()->setVisible(false);
	setCentralWidget(_createTransferWidget);
	_createTransferWidget->updateData();
	_createTransferWidget->setVisible(true);
}

void MainWindow::setCreateTransferDaemonWidget()
{
	takeCentralWidget()->setVisible(false);
	setCentralWidget(_createTransferDaemonWidget);
	_createTransferDaemonWidget->updateData();
	_createTransferDaemonWidget->setVisible(true);
}

void MainWindow::setTransferDaemonsListWidget()
{
	takeCentralWidget()->setVisible(false);
	setCentralWidget(_transferDaemonsListWidget);
	_transferDaemonsListWidget->updateData();
	_transferDaemonsListWidget->setVisible(true);
}

void MainWindow::setOverflowWidget()
{
	takeCentralWidget()->setVisible(false);
	setCentralWidget(_overflowWidget);
	_overflowWidget->updateData();
	_overflowWidget->setVisible(true);
}

void MainWindow::setOverflowServiceWidget()
{
	takeCentralWidget()->setVisible(false);
	setCentralWidget(_overflowServiceWidget);
	_overflowServiceWidget->updateData();
	_overflowServiceWidget->setVisible(true);
}

void MainWindow::setCreateOverflowCreditServiceWidget()
{
	takeCentralWidget()->setVisible(false);
	setCentralWidget(_createOverflowCreditServiceWidget);
	_createOverflowCreditServiceWidget->updateData();
	_createOverflowCreditServiceWidget->setVisible(true);
}

void MainWindow::setOverflowCreditServicesListWidget()
{
	takeCentralWidget()->setVisible(false);
	setCentralWidget(_overflowCreditServicesListWidget);
	_overflowCreditServicesListWidget->updateData();
	_overflowCreditServicesListWidget->setVisible(true);
}

void MainWindow::setTransferHistoryWidget()
{
	takeCentralWidget()->setVisible(false);
	setCentralWidget(_transferHistoryWidget);
	_transferHistoryWidget->updateData();
	_transferHistoryWidget->setVisible(true);
}

void MainWindow::setWithdrawalWidget()
{
	takeCentralWidget()->setVisible(false);
	setCentralWidget(_withdrawalWidget);
	_withdrawalWidget->updateData();
	_withdrawalWidget->setVisible(true);
}

void MainWindow::setCreditLimitWidget()
{
	takeCentralWidget()->setVisible(false);
	setCentralWidget(_creditLimitWidget);
	_creditLimitWidget->updateData();
	_creditLimitWidget->setVisible(true);
}