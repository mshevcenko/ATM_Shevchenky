#include <QRegularExpressionValidator>
#include "IntegerLineEdit.h"

IntegerLineEdit::IntegerLineEdit(QWidget* parent) :
    QLineEdit(parent)
{
    setValidator((new QRegularExpressionValidator(QRegularExpression("[0-9]*"), this)));
}

IntegerLineEdit::~IntegerLineEdit()
{}