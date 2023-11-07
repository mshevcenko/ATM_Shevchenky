#pragma once
#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include "customshadoweffect.h"

class ServiceOptionWidget : public QFrame
{
	Q_OBJECT

public:
	explicit ServiceOptionWidget(QWidget* parent = nullptr);

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