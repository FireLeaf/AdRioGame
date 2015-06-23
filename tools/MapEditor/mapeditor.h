#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include <QtGui/QMainWindow>
#include "ui_mapeditor.h"

class MapEditor : public QMainWindow
{
	Q_OBJECT

public:
	MapEditor(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MapEditor();

private:
	Ui::MapEditorClass ui;
};

#endif // MAPEDITOR_H
