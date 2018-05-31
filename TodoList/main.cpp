#include "todolist.h"
#include <QtWidgets/QApplication>

#include <windows.h>
#include <QMessageBox>
bool isRunning()
{
	HANDLE hHandle = CreateMutex(NULL, FALSE, L"TodoListRunningMutex");

	if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		QMessageBox messageBox;
		messageBox.warning(0, "Already running", "TodoList is already running!");
		return true;
	}
	return false;
}
#include <serialport.h>

int main(int argc, char *argv[])
{
	main_serial();
	QApplication a(argc, argv);
	if (isRunning())
		return 0;

	a.setApplicationName("TodoList");
	a.setWindowIcon(QIcon(":/TodoList/Resources/icon.png"));

	TodoList w;
	w.show();
	return a.exec();
}
