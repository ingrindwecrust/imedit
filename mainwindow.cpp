#include "mainwindow.h"

#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
	QAction *niib = new QAction("&New", this);
	niib->setShortcut(tr("CTRL+N"));
	QAction *open = new QAction("&Open", this);
	open->setShortcut(tr("CTRL+O"));
	QAction *save = new QAction("&Save", this);
	save->setShortcut(tr("CTRL+S"));
	QAction *quit = new QAction("&Quit", this);
	quit->setShortcut(tr("CTRL+Q"));

	{
		QMenu *file = menuBar()->addMenu("&File");

		file->addAction(niib);
		file->addAction(open);
		file->addAction(save);
		file->addSeparator();
		file->addAction(quit);
	}

	statusBar()->showMessage("Ready");

	connect(niib, &QAction::triggered, this, &MainWindow::onNew);
	connect(open, &QAction::triggered, this, &MainWindow::onOpen);
	connect(save, &QAction::triggered, this, &MainWindow::onSave);
	connect(quit, &QAction::triggered, this, &MainWindow::onQuit);
}

void MainWindow::onNew()
{
}

void MainWindow::onOpen()
{
}

void MainWindow::onSave()
{
}

void MainWindow::onQuit()
{
	qApp->quit();
}
