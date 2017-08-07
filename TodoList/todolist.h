#ifndef TODOLIST_H
#define TODOLIST_H

#include <QtWidgets/QMainWindow>
#include "ui_todolist.h"

class TodoList : public QMainWindow
{
	Q_OBJECT

public:
	TodoList(QWidget *parent = 0);
	~TodoList();
private slots:

	void Add();

private:
	Ui::TodoListClass ui;
};

#endif // TODOLIST_H
