#include "addDialog.h"
#include <QDialogButtonBox.h>

AddDialog::AddDialog(QWidget *parent)
: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.buttonBox, &QDialogButtonBox::accepted, this, &AddDialog::accept);
	connect(ui.buttonBox, &QDialogButtonBox::rejected, this, &AddDialog::reject);
}

AddDialog::~AddDialog()
{
}
