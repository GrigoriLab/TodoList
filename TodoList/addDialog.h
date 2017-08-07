#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "ui_addDialog.h"

class AddDialog : public QDialog
{
	Q_OBJECT

public:
	AddDialog(QWidget *parent = nullptr);
	~AddDialog();

	public slots:

signals :

protected:
	//
protected slots:
//

private slots :
//
private:
	Ui::AddDialogClass ui;
};

#endif // ADDDIALOG_H