#pragma once

#include <QMainWindow>
#include <QApplication>

#include "paintsurface.h"

class MainWindow: public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(const QString &filename, QWidget *parent = nullptr);

public slots:
	void onNew();
	void onOpen();
	void onSave();
	void onSaveAs();
	void onQuit();

signals:
	void created(unsigned int w, unsigned int h);
	void opened(const QString &filename);
	void saved(const QString &filename);

private:
	QString m_filename;

	PaintSurface *m_paintsurface;
};
