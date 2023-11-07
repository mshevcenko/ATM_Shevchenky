#include <QMessageBox>
#include "OverflowServiceWidget.h"
#include "ATM.h"

OverflowServiceWidget::OverflowServiceWidget(ATM& atm, QWidget* parent) :
    QWidget(parent),
    _atm(atm)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &OverflowServiceWidget::closed);
    connect(
        ui.createButton,
        &QPushButton::clicked,
        this,
        &OverflowServiceWidget::tryCreateOverflowService);
    connect(
        ui.deleteButton,
        &QPushButton::clicked,
        this,
        &OverflowServiceWidget::tryDeleteOverflowService);
}

OverflowServiceWidget::~OverflowServiceWidget()
{}

void OverflowServiceWidget::updateData()
{
    ui.balanceLineEdit->setText(QString::number(_atm.getBalance(), 'f', 2));
    ui.creditLimitLineEdit->setText(QString::number(_atm.getCreditLimit(), 'f', 2));
    if (_atm.hasOverflowService())
    {
        ui.createOverflowServiceWidget->setVisible(false);
        ui.deleteOverflowServiceWidget->setVisible(true);
        OverflowService s = _atm.getOverflowService();
        ui.targetLineEdit2->setText(QString::fromStdString(s.to()));
        ui.thresholdLineEdit2->setText(QString::number(s.threshold(), 'f', 2));
    }
    else
    {
        ui.createOverflowServiceWidget->setVisible(true);
        ui.deleteOverflowServiceWidget->setVisible(false);
        ui.targetLineEdit1->setText("");
        ui.thresholdLineEdit1->setText("");
    }
}

void OverflowServiceWidget::tryDeleteOverflowService()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Overflow service");
    if (_atm.deleteOverflowService(_atm.getOverflowService()))
    {
        msgBox.setText("Overflow service was deleted successfully!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        updateData();
    }
    else
    {
        msgBox.setText("Overflow service wasn't deleted!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}

void OverflowServiceWidget::tryCreateOverflowService()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Overflow service");
    OverflowService service(
        _atm.currentCardNumber(),
        ui.targetLineEdit1->text().toStdString(),
        ui.thresholdLineEdit1->text().replace(",", ".").toDouble()
    );
    if (_atm.createOverflowService(service))
    {
        msgBox.setText("Overflow service was created successfully!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        updateData();
    }
    else
    {
        msgBox.setText("Overflow service wasn't created!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}