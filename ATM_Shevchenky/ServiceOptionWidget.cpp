#include "serviceoptionwidget.h"
#include "MainWindow.h"

ServiceOptionWidget::ServiceOptionWidget(QWidget* parent) :
	QFrame(parent),
	_shadowEffect(new CustomShadowEffect(this))
	//_targetWindow(UNDEFINED)
{
	_shadowEffect->setBlurRadius(10.0);
	_shadowEffect->setColor(QColor(200, 200, 200));
	_shadowEffect->setDistance(4.0);
	_shadowEffect->setEnabled(false);
	setGraphicsEffect(_shadowEffect);
}

//void ServiceOptionWidget::setTargetWindow(Window window)
//{
//	_targetWindow = window;
//}

void ServiceOptionWidget::mousePressEvent(QMouseEvent* event)
{
	_shadowEffect->setColor(QColor(100, 100, 100));
	update();
}

void ServiceOptionWidget::mouseReleaseEvent(QMouseEvent* event)
{
	_shadowEffect->setColor(QColor(200, 200, 200));
	update();
	emit clicked();
}

void ServiceOptionWidget::enterEvent(QEnterEvent* e)
{
	QFrame::enterEvent(e);
	_shadowEffect->setEnabled(true);
}

void ServiceOptionWidget::leaveEvent(QEvent* e)
{
	QFrame::leaveEvent(e);
	_shadowEffect->setEnabled(false);
}