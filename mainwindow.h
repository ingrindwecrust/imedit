#pragma once

#include <QMainWindow>
#include <QApplication>

class MainWindow: public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);

public slots:
	void onNew();
	void onOpen(const QString &filename);
	void onSave(const QString &filename);
	void onQuit();

signals:
	void created(unsigned int w, unsigned int h);
	void opened(const QString &filename);
	void saved(const QString &filename);
};
