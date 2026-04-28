#pragma once

#include "ValidBasic.h"

Imports VBA;

class FormForm1 :public Form
{
public:
    Form *Me = this;

    void FormEnabled(Boolean tEnabled);
    void ShowLog(String tLog, Boolean ShowMsg = False);

private:

    CommandButton cmdRetry;
    CommandButton cmdDo;
    ListBox LstItems;
    TextBox txtLog;
    Label lblOperaInfo;
    Label Label1;
    Label Label2;

    void OnInit() {
        InitForm(L"frmForm1", L"frmForm1", L"示例", 0, 0, 8370, 6120, 1);
        Is_Event_Form_Resize = true;     //响应窗体Resize事件
        Is_Event_Click = true;           //响应控件Click事件
    }

    void OnCreateUI() {
        cmdRetry.InitControl(Me, &Me->Obj, L"重试", 1080, 2520, 855, 495, true);
		cmdRetry.set_enabled(false);
        cmdDo.InitControl(Me, &Me->Obj, L"开始", 120, 2520, 975, 495, true);
        LstItems.InitControl(Me, &Me->Obj, L"", 120, 360, 8175, 2040, true);
        txtLog.InitControl(Me, &Me->Obj, L"", 120, 3360, 8175, 2655, true, 0, 0, 1, 1);
        lblOperaInfo.InitControl(Me, &Me->Obj, L"就绪。", 2040, 2760, 6000, 180, true);
        Label1.InitControl(Me, &Me->Obj, L"项目", 120, 120, 360, 180, true);
        Label2.InitControl(Me, &Me->Obj, L"日志", 120, 3120, 360, 180, true);
    }

    void OnClick(HWND hWnd) {
        if(hWnd == cmdDo.hwnd){
            cmdDo_Click();
        }
    }

    void Form_Resize();
    void cmdDo_Click();
};