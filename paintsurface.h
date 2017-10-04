#pragma once

#include <QPixmap>
#include <QWidget>

class PaintSurface: public QWidget
{
	Q_OBJECT

public:
	PaintSurface(QWidget *parent = nullptr);

//	not implementing a destructor ; use this method instead
	void reset();

public slots:
//	both call reset()
	void onNew(unsigned int w, unsigned int h);
	void onLoad(const QString &filename);

	void onSave(const QString &filename);

signals:
//	both for status bar
	void done(const QString &msg, int timeout = 0);
	void clicked();

private:
	QVector<QPixmap *> m_states;
	QPixmap *m_currentRectangle;
};
