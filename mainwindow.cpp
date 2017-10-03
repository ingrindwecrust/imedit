#include "mainwindow.h"

#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

#include <QMessageBox>
#include <QFileDialog>

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
/*	QString name = QFileDialog::getOpenFileName(this, tr("Which file shall be opened ?"));
	emit MainWindow::opened(name);*/
}

void MainWindow::onSave()
{
/*	QString name = QFileDialog::getOpenFileName(this, tr("In what file shall we save ?"));
	emit MainWindow::saved(name);*/
}

void MainWindow::onQuit()
{
	QMessageBox yesno;

	yesno.setText("So I herd u liek kuiting.");
	yesno.setInformativeText("Do you really want to quit ?");
	yesno.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	yesno.setDefaultButton(QMessageBox::Yes);

	if (yesno.exec() == QMessageBox::Yes)
		qApp->quit();
}
