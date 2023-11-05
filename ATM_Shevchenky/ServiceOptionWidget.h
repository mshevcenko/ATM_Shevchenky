#pragma once
#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include "customshadoweffect.h"
#include "Window.h"

class ServiceOptionWidget : public QFrame
{
	Q_OBJECT

public:
	explicit ServiceOptionWidget(QWidget* parent = nullptr);
	//void setTargetWindow(Window window);

signals:
	void clicked();

protected:
	void enterEvent(QEnterEvent*);
	void leaveEvent(QEvent*);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

private:
	CustomShadowEffect* _shadowEffect;
	//Window _targetWindow;
};