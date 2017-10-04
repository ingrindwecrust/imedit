#include "mainwindow.h"

#include <iostream>

int usage()
{
	std::cout << "usage:\timedit [picture]" << std::endl;
	return 1;
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	const auto args = app.arguments();
	QString infile;
	if (args.count() == 2)
		infile = args.at(1);
	else if (args.count() > 2)
		return usage();

	MainWindow window(infile);
	window.resize(666, 666);
	window.setWindowTitle("imedit");
	window.show();

	return app.exec();
}
