#include <QRegularExpressionValidator>
#include "MoneyLineEdit.h"

MoneyLineEdit::MoneyLineEdit(QWidget* parent) :
    QLineEdit(parent)
{
    setValidator((new QRegularExpressionValidator(QRegularExpression("^(0|([1-9][0-9]*))((\\.|,)[0-9]{1,2})?"), this)));
}

MoneyLineEdit::~MoneyLineEdit()
{}