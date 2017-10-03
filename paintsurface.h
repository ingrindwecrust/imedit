#pragma once

#include <QPixmap>

class PaintSurface: public QWidget
{
public:
	PaintSurface(QWidget *parent = nullptr);

private:
	QPixmap m_pixmap;
};
