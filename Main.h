#pragma once

#include "ValidBasic.h"
#include "frmForm1.h"
#pragma comment(lib,"ValidBasicLib.lib")

void Main();

//控制台模式
int main(int argc, _TCHAR* argv[])

{
    Main();

    Return 0;
}

//窗口模式
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)

{
    Debug.Print(L"");//有这行才能正常显示窗体

    Main();

    Return 0;
}