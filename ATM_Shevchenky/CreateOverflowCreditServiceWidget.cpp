#include <QMessageBox>
#include "CreateOverflowCreditServiceWidget.h"
#include "ATM.h"

CreateOverflowCreditServiceWidget::CreateOverflowCreditServiceWidget(ATM& atm, QWidget* parent) :
    QWidget(parent),
    _atm(atm)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &CreateOverflowCreditServiceWidget::closed);
    connect(
        ui.createButton,
        &QPushButton::clicked,
        this,
        &CreateOverflowCreditServiceWidget::tryCreateOverflowCreditService);
}

CreateOverflowCreditServiceWidget::~CreateOverflowCreditServiceWidget()
{}

void CreateOverflowCreditServiceWidget::updateData()
{
    ui.balanceLineEdit->setText(QString::number(_atm.getBalance(), 'f', 2));
    ui.creditLimitLineEdit->setText(QString::number(_atm.getCreditLimit(), 'f', 2));
    ui.targetLineEdit->setText("");
    ui.ammountToBeTriggeredLineEdit->setText("");
}

void CreateOverflowCreditServiceWidget::tryCreateOverflowCreditService()
{
    OverflowCreditService service(
        _atm.currentCardNumber(),
        ui.targetLineEdit->text().toStdString(),
        ui.ammountToBeTriggeredLineEdit->text().replace(",", ".").toDouble()
    );
    QMessageBox msgBox;
    msgBox.setWindowTitle("Overflow credit service");
    //_atm.createOverflowCreditService(service)
    if (_atm.createOverflowCreditService(service))
    {
        msgBox.setText("Overflow credit service was created successfully!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        updateData();
    }
    else
    {
        msgBox.setText("Overflow credit service wasn't created!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}