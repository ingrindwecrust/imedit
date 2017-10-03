#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindow window;
	window.resize(666, 666);
	window.setWindowTitle("imedit");
	window.show();

	return app.exec();
}
