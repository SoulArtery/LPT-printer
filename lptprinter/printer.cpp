#include <Windows.h>
#include <iostream>
#include <string>
  
using namespace std;
  
int main() {
    HANDLE lpt = CreateFile((LPCWSTR)"LPT1", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (lpt != INVALID_HANDLE_VALUE) {
        cout << "LPT1 is opened" << endl;
        char buffer[255];
        memset(buffer, 0, sizeof(buffer));
		gets(buffer);
		strcat(buffer, "\n");
        DWORD dw;
        WriteFile(lpt, buffer, sizeof(buffer), &dw, NULL);
        CloseHandle(lpt);
    } else
        cout << "Error opening" << endl;
	system("pause");
    return 0;
}