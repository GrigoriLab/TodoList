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
	ui.listViewInProgress->setModel(new QStringListModel(this));
	ui.listViewDone->setModel(new QStringListModel(this));


	ui.listViewPlaned->setEditTriggers(QAbstractItemView::AllEditTriggers);
	//ui.listViewPlaned->setFlags(ui.listViewPlaned->flags() | Qt::ItemIsEditable);
	connect(ui.listViewPlaned, &QListView::editTriggers, this, &TodoList::editTrigger);
	ui.listViewPlaned->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.listViewInProgress->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.listViewDone->setEditTriggers(QAbstractItemView::NoEditTriggers);

	ui.listViewPlaned->setDragDropMode(QAbstractItemView::DragDrop);
	ui.listViewInProgress->setDragDropMode(QAbstractItemView::DragDrop);
	ui.listViewDone->setDragDropMode(QAbstractItemView::DragDrop);
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