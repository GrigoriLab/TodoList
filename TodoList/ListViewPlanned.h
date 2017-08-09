#ifndef LISTVIEWPLANNED_H
#define LISTVIEWPLANNED_H
#include <QListView>
#include <QDragEnterEvent>

class ListViewPlanned : public QListView
{
	Q_OBJECT
public:
	ListViewPlanned(QWidget *parent = 0) :QListView(parent)
	{

	}
	~ListViewPlanned(){};
	void dragEnterEvent(QDragEnterEvent *event) override;


};

#endif /*LISTVIEWPLANNED_H*/