#include "todolist.h"
#include "addDialog.h"
#include <qapplication.h>
#include <QStringListModel.h>
#include <QListView>
#include "TasksListView.h"

TodoList::TodoList(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButtonAdd, &QPushButton::clicked, this, &TodoList::Add);
	plannedModel = new QStringListModel(this);
	inProgressModel = new QStringListModel(this);
	doneModel = new QStringListModel(this);

	QStringList list;

	list << "First Task"<<"Second Task"<<"";

	plannedModel->setStringList(list);
	doneModel->setStringList(list);
	inProgressModel->setStringList(list);

	ui.listViewPlanned->setModel(plannedModel);
	ui.listViewInProgress->setModel(inProgressModel);
	ui.listViewDone->setModel(doneModel);


	ui.listViewPlanned->setEditTriggers(QAbstractItemView::AllEditTriggers);
	//ui.listViewPlanned->setFlags(ui.listViewPlanned->flags() | Qt::ItemIsEditable);
	connect(ui.listViewPlanned, &QListView::editTriggers, this, &TodoList::editTrigger);
	connect(ui.listViewPlanned, &TasksListView::dragEnterEvent, this, &TodoList::editTrigger);

	connect(ui.listViewInProgress, &QListView::editTriggers, this, &TodoList::editTrigger);
	connect(ui.listViewInProgress, &TasksListView::dragEnterEvent, this, &TodoList::editTrigger);

	connect(ui.listViewDone, &QListView::editTriggers, this, &TodoList::editTrigger);
	connect(ui.listViewDone, &TasksListView::dragEnterEvent, this, &TodoList::editTrigger);

	ui.listViewPlanned->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.listViewInProgress->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.listViewDone->setEditTriggers(QAbstractItemView::NoEditTriggers);

	ui.listViewPlanned->setDragDropMode(QAbstractItemView::DragDrop);
	ui.listViewInProgress->setDragDropMode(QAbstractItemView::DragDrop);
	ui.listViewDone->setDragDropMode(QAbstractItemView::DragDrop);
}

TodoList::~TodoList()
{
	delete plannedModel;
	delete inProgressModel;
	delete doneModel;
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