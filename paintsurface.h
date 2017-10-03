#pragma once

#include <QPixmap>
#include <QWidget>

class PaintSurface: public QWidget
{
public:
	PaintSurface(QWidget *parent = nullptr);

private:
	QPixmap m_pixmap;
};
