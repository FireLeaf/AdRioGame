#include "mapeditor.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MapEditor w;
	w.show();
	return a.exec();
}
