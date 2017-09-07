#ifndef TODOLIST_H
#define TODOLIST_H

#include <QtWidgets/QMainWindow>
#include "ui_todolist.h"
#include <QStringListModel.h>

class TodoList : public QMainWindow
{
	Q_OBJECT

public:
	TodoList(QWidget *parent = 0);
	~TodoList();
private slots:

	void Add();
	void editTrigger();

private:
	Ui::TodoListClass ui;
	QStringListModel *plannedModel;
	QStringListModel *inProgressModel;
	QStringListModel *doneModel;
};

#endif // TODOLIST_H
