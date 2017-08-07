#include "todolist.h"
#include "addDialog.h"
#include <qapplication.h>

TodoList::TodoList(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButtonAdd, &QPushButton::clicked, this, &TodoList::Add);
}

TodoList::~TodoList()
{

}

void TodoList::Add()
{
	AddDialog deltaDialog(this);
	deltaDialog.exec();
}