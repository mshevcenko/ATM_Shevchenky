#include "OverflowWidget.h"
#include "ATM.h"

OverflowWidget::OverflowWidget(ATM& atm, QWidget* parent) :
    QWidget(parent),
    _atm(atm)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &OverflowWidget::closed);
    connect(
        ui.overflowServiceButton,
        &QPushButton::clicked,
        this,
        &OverflowWidget::overflowService);
    connect(
        ui.createOverflowCreditServiceButton,
        &QPushButton::clicked,
        this,
        &OverflowWidget::createOverflowCreditService);
    connect(
        ui.overflowCreditServicesListButton,
        &QPushButton::clicked,
        this,
        &OverflowWidget::overflowCreditServicesList);
}

OverflowWidget::~OverflowWidget()
{}

void OverflowWidget::updateData()
{
    ui.balanceLineEdit->setText(QString::number(_atm.getBalance(), 'f', 2));
    ui.creditLimitLineEdit->setText(QString::number(_atm.getCreditLimit(), 'f', 2));
}