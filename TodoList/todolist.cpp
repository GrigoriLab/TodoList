#include "todolist.h"
#include "addDialog.h"
#include <qapplication.h>
#include <QStringListModel.h>
#include <QListView>
#include "ListViewPlanned.h"

TodoList::TodoList(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButtonAdd, &QPushButton::clicked, this, &TodoList::Add);
	QStringListModel *model = new QStringListModel(this);

	QStringList list;

	list << "First Task"<<"Second Task"<<"";

	model->setStringList(list);

	ui.listViewPlanned->setModel(model);
	ui.listViewInProgress->setModel(new QStringListModel(this));
	ui.listViewDone->setModel(new QStringListModel(this));


	ui.listViewPlanned->setEditTriggers(QAbstractItemView::AllEditTriggers);
	//ui.listViewPlaned->setFlags(ui.listViewPlaned->flags() | Qt::ItemIsEditable);
	connect(ui.listViewPlanned, &QListView::editTriggers, this, &TodoList::editTrigger);
	connect(ui.listViewPlanned, &ListViewPlanned::dragEnterEvent, this, &TodoList::editTrigger);
	ui.listViewPlanned->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.listViewInProgress->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.listViewDone->setEditTriggers(QAbstractItemView::NoEditTriggers);

	ui.listViewPlanned->setDragDropMode(QAbstractItemView::DragDrop);
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