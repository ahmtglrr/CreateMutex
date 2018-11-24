#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{

	HANDLE hmutex = CreateMutex(NULL,TRUE,"Mutexornek");
	if (hmutex == NULL)
	{
		printf("Mutex Kurulamadý \n");
		return 0;
	}
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		printf("Mutex zaten var\n");
		return 0;
	}
	else
	{
		printf("Mutex kuruldu\n");
		ReleaseMutex(hmutex);
	}
	CloseHandle(hmutex);
	system("pause");
	return 0;

}