#include<QLayout>
#include "gutil.h"

void clearLayout(QLayout* layout)
{
    QLayoutItem* child;
    while (layout->count() != 0) {
        child = layout->takeAt(0);
        /*if (child->layout() != 0) {
            clearLayout(child->layout());
        }
        else if (child->widget() != 0) {
            delete child->widget();
        }*/
        delete child;
    }
}