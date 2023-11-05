#include <QRegularExpressionValidator>
#include "CreditLimitWidget.h"

CreditLimitWidget::CreditLimitWidget(QWidget* parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &CreditLimitWidget::closed);
}

CreditLimitWidget::~CreditLimitWidget()
{}