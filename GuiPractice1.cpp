//윈도우 창 키 나오게 하기 
#include <windows.h> 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
 LPSTR lpCmdLine, int nCmdShow) 
{ 
 MessageBox(NULL, "Goodbye, cruel world!", "Note", MB_OK); 
 MessageBox(NULL, "Hello", "Note", MB_OK); 
 return 0; 
} 
