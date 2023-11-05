#pragma once
#include <QLineEdit>

class IntegerLineEdit : public QLineEdit
{

    Q_OBJECT

public:
    IntegerLineEdit(QWidget* parent = nullptr);
    ~IntegerLineEdit();

};