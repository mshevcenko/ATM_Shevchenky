#include <QRegularExpressionValidator>
#include <QDoubleValidator>
#include "MoneyLineEdit.h"

MoneyLineEdit::MoneyLineEdit(QWidget* parent) :
    QLineEdit(parent)
{
    /*QDoubleValidator* validator = new QDoubleValidator(this);
    validator->setBottom(0.00);
    validator->setDecimals(2);
    validator->setTop(999999999.99);
    validator->setLocale(QLocale("en_US"));
    validator->setNotation(QDoubleValidator::StandardNotation);
    setValidator(validator);*/
    setValidator((new QRegularExpressionValidator(QRegularExpression("(0|([1-9][0-9]{0,8}))((\\.|,)[0-9]{1,2})?"), this)));
}

MoneyLineEdit::~MoneyLineEdit()
{}