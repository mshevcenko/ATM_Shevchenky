#include "OverflowWidget.h"

OverflowWidget::OverflowWidget(QWidget* parent) :
    QWidget(parent)
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