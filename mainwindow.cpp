#include "mainwindow.h"

#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
	QAction *niib = new QAction("&New", this);
//	niib->setShortcut(tr("CTRL+N"));
	QAction *open = new QAction("&Open", this);
//	open->setShortcut(tr("CTRL+O"));
	QAction *save = new QAction("&Save", this);
//	save->setShortcut(tr("CTRL+S"));
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

//	connect(open, &QAction::triggered, , );
//	connect(open, &QAction::triggered, , );
//	connect(save, &QAction::triggered, , );
	connect(quit, &QAction::triggered, qApp, QApplication::quit);
}
