#include <QRegularExpressionValidator>
#include "WithdrawalWidget.h"

WithdrawalWidget::WithdrawalWidget(QWidget* parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    ui.ammountLineEdit->setValidator((new QRegularExpressionValidator(QRegularExpression("[1-9][0-9]*"), ui.ammountLineEdit)));
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &WithdrawalWidget::closed);
}

WithdrawalWidget::~WithdrawalWidget()
{}