#include "todolist.h"
#include "addDialog.h"
#include <qapplication.h>
#include <QStringListModel.h>
#include <QListView>

TodoList::TodoList(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButtonAdd, &QPushButton::clicked, this, &TodoList::Add);
	QStringListModel *model = new QStringListModel(this);

	QStringList list;

	list << "First Task"<<"Second Task"<<"";

	model->setStringList(list);

	ui.listViewPlaned->setModel(model);
	ui.listViewPlaned->setEditTriggers(QAbstractItemView::AllEditTriggers);
	//ui.listViewPlaned->setFlags(ui.listViewPlaned->flags() | Qt::ItemIsEditable);
	connect(ui.listViewPlaned, &QListView::editTriggers, this, &TodoList::editTrigger);
	//ui.listViewPlaned->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

TodoList::~TodoList()
{

}

void TodoList::Add()
{
	AddDialog deltaDialog(this);
	deltaDialog.exec();
}

void TodoList::editTrigger()
{
	QString str = "Breake Here";
}