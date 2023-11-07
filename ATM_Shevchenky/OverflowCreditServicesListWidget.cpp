#include "OverflowCreditServicesListWidget.h"
#include "ATM.h"
#include "gutil.h"

OverflowCreditServicesListWidget::OverflowCreditServicesListWidget(ATM& atm, QWidget* parent) :
    QWidget(parent),
    _atm(atm)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &OverflowCreditServicesListWidget::closed);
}

OverflowCreditServicesListWidget::~OverflowCreditServicesListWidget()
{}

void OverflowCreditServicesListWidget::updateData()
{
    ui.balanceLineEdit->setText(QString::number(_atm.getBalance(), 'f', 2));
    ui.creditLimitLineEdit->setText(QString::number(_atm.getCreditLimit(), 'f', 2));
    //std::cout << ui.transferDaemonsListLayout->count() << std::endl;
    clearLayout(ui.overflowCreditServicesListLayout);
    vector<OverflowCreditService> overflowCreditServices = _atm.getOverflowCreditServices();
    //std::cout << transferDaemons.size() << std::endl;
    if (overflowCreditServices.size() == 0)
    {
        ui.emptyLabel->setVisible(true);
    }
    else
    {
        ui.emptyLabel->setVisible(false);
        for (int i = 0; i < overflowCreditServices.size(); i++)
        {
            OverflowCreditServiceCardWidget* s = new OverflowCreditServiceCardWidget(_atm, overflowCreditServices[i], this);
            ui.overflowCreditServicesListLayout->addWidget(s);
            connect(
                s,
                &OverflowCreditServiceCardWidget::deleted,
                this,
                &OverflowCreditServicesListWidget::deleteOverflowCreditServiceCard
            );
        }
    }
}

void OverflowCreditServicesListWidget::deleteOverflowCreditServiceCard(OverflowCreditServiceCardWidget* s)
{
    ui.overflowCreditServicesListLayout->removeWidget(s);
    delete s;
    if (ui.overflowCreditServicesListLayout->count() == 0)
    {
        ui.emptyLabel->setVisible(true);
    }
}