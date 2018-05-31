#include <stdio.h> 
#include <windows.h> 
#include <winbase.h>
#include <iostream>
#include <tchar.h>
using namespace std;

int main_serial()
{

	int com = 'COM1';
	string data = "\n 010400 \n";
	char output[32];
	//unsigned int length = 0;
	DCB config = { 0 };
	bool abContinue = true;
	DWORD dwBytesWritten;
	DWORD  dwBytesRead;
	int isRead = false;

	HANDLE m_hCommPort = ::CreateFile(L"COM1",
		GENERIC_READ | GENERIC_WRITE,//access ( read and write)

		0,    //(share) 0:cannot share the COM port                        

		0,    //security  (None)                

		OPEN_EXISTING,// creation : open_existing

		0,    // we dont want overlapped operation

		0// no templates file for COM port...

		);

	config.DCBlength = sizeof(config);


	if ((GetCommState(m_hCommPort, &config) == 0))
	{
		printf("Get configuration port has a problem.");
		return FALSE;
	}

	config.BaudRate = 9600;
	config.StopBits = ONESTOPBIT;
	config.Parity = PARITY_NONE;
	config.ByteSize = DATABITS_8;
	config.fDtrControl = 0;
	config.fRtsControl = 0;

	if (!SetCommState(m_hCommPort, &config))
	{

		printf("Failed to Set Comm State Reason: %d\n", GetLastError());
		//return E_FAIL;
	}

	printf("Current Settings\n Baud Rate %d\n Parity %d\n Byte Size %d\n Stop Bits %d", config.BaudRate,
		config.Parity, config.ByteSize, config.StopBits);

	int isWritten = WriteFile(m_hCommPort, &data, (DWORD) sizeof(data), &dwBytesWritten, NULL);


	//memset(output, 0, sizeof(output));
	while (abContinue)
	{

		isRead = ReadFile(m_hCommPort, output, sizeof(output), &dwBytesRead, NULL);

		if (!isRead)
		{
			abContinue = false;
			break;
		}

	}

	cin.get();
}