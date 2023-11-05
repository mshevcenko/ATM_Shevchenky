#pragma once
#include <QLineEdit>

class MoneyLineEdit : public QLineEdit
{

    Q_OBJECT

public:
    MoneyLineEdit(QWidget* parent = nullptr);
    ~MoneyLineEdit();

};