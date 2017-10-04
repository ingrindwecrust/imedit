#include "mainwindow.h"

#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(const QString &filename, QWidget *parent): QMainWindow(parent), m_filename(filename), m_paintsurface(new PaintSurface(this))
{
	QAction *niib = new QAction("&New", this);
	niib->setShortcut(tr("CTRL+N"));
	QAction *open = new QAction("&Open", this);
	open->setShortcut(tr("CTRL+O"));
	QAction *save = new QAction("&Save", this);
	save->setShortcut(tr("CTRL+S"));
	QAction *saveas = new QAction("&Save As", this);
	QAction *quit = new QAction("&Quit", this);
	quit->setShortcut(tr("CTRL+Q"));

	{
		QMenu *file = menuBar()->addMenu("&File");

		file->addAction(niib);
		file->addAction(open);
		file->addAction(save);
		file->addAction(saveas);
		file->addSeparator();
		file->addAction(quit);
	}

	statusBar()->showMessage("Idle");

	connect(niib, &QAction::triggered, this, &MainWindow::onNew);
	connect(open, &QAction::triggered, this, &MainWindow::onOpen);
	connect(save, &QAction::triggered, this, &MainWindow::onSave);
	connect(saveas, &QAction::triggered, this, &MainWindow::onSaveAs);
	connect(quit, &QAction::triggered, this, &MainWindow::onQuit);

	connect(this, &MainWindow::created, m_paintsurface, &PaintSurface::onNew);
	connect(this, &MainWindow::opened, m_paintsurface, &PaintSurface::onLoad);
	connect(this, &MainWindow::saved, m_paintsurface, &PaintSurface::onSave);

//	TODO: messages in status bar
	connect(m_paintsurface, &PaintSurface::done, statusBar(), &QStatusBar::showMessage);
	connect(m_paintsurface, &PaintSurface::clicked, statusBar(), &QStatusBar::clearMessage);
}

void MainWindow::onNew()
{
//	TODO: create dialog box to ask for dimensions
}

void MainWindow::onOpen()
{
	QString name = QFileDialog::getOpenFileName(this, tr("Which file shall be opened ?"));

	if (!name.isEmpty())
	{
		m_filename = name;
		emit MainWindow::opened(m_filename);
	}
}

void MainWindow::onSave()
{
	if (m_filename.isEmpty())
		m_filename = QFileDialog::getOpenFileName(this, tr("In what file shall we save ?"));
	if (!m_filename.isEmpty())
		emit MainWindow::saved(m_filename);
}

void MainWindow::onSaveAs()
{
	QString name = QFileDialog::getOpenFileName(this, tr("In what file shall we save ?"));

	if (!name.isEmpty())
	{
		m_filename = name;
		emit MainWindow::saved(m_filename);
	}
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
