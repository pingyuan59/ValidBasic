#include "frmForm1.h"

Sub FormForm1::FormEnabled(Boolean tEnabled)
BEGIN

    LstItems.Enabled = tEnabled;
    cmdDo.Enabled = tEnabled;
    cmdRetry.Enabled = False;
END

Sub FormForm1::ShowLog(String tLog, Boolean ShowMsg)
BEGIN

    lblOperaInfo.Caption = tLog;
    txtLog.SelText = tLog & vbCrLf;
    If ShowMsg == True Then
        MsgBox(tLog);
    EndIf
END

Sub FormForm1::cmdDo_Click()
BEGIN

    FormEnabled(False);
    txtLog.Text = L"";
    ShowLog(L"正在操作，请稍等");
    ShowLog(L"执行成功！", True);
    FormEnabled(True);
END


Sub FormForm1::Form_Resize()
BEGIN

    If WindowState == vbMinimized Then
        return;
    EndIf
    LstItems.Move(120, LstItems.Top, ScaleWidth - 240, LstItems.Height);
    txtLog.Move(120, txtLog.Top, ScaleWidth - 240, ScaleHeight - txtLog.Top - 120);
END