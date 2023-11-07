#include <QRegularExpressionValidator>
#include "WithdrawalWidget.h"
#include "ATM.h"

WithdrawalWidget::WithdrawalWidget(ATM& atm, QWidget* parent) :
    QWidget(parent),
    _atm(atm)
{
    ui.setupUi(this);
    ui.ammountLineEdit->setValidator((new QRegularExpressionValidator(QRegularExpression("[1-9][0-9]*"), ui.ammountLineEdit)));
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &WithdrawalWidget::closed);
    connect(
        ui.withdrawButton,
        &QPushButton::clicked,
        this,
        &WithdrawalWidget::tryWithdraw);
}

WithdrawalWidget::~WithdrawalWidget()
{}

void WithdrawalWidget::updateData() 
{
    ui.balanceLineEdit->setText(QString::number(_atm.getBalance(), 'f', 2));
    ui.creditLimitLineEdit->setText(QString::number(_atm.getCreditLimit(), 'f', 2));
    ui.ammountLineEdit->setText("");
}

void WithdrawalWidget::tryWithdraw()
{
    _atm.withdraw(ui.ammountLineEdit->text().toInt());
    updateData();
}