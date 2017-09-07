#ifndef LISTVIEWPLANNED_H
#define LISTVIEWPLANNED_H
#include <QListView>
#include <QDragEnterEvent>

class TasksListView : public QListView
{
	Q_OBJECT
public:
	TasksListView(QWidget *parent = 0) :QListView(parent)
	{

	}
	~TasksListView(){};
	void dragEnterEvent(QDragEnterEvent *event) override;


};

#endif /*LISTVIEWPLANNED_H*/