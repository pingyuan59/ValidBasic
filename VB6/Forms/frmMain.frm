VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "示例"
   ClientHeight    =   6120
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   8370
   LinkTopic       =   "Form1"
   ScaleHeight     =   6120
   ScaleWidth      =   8370
   StartUpPosition =   2  '屏幕中心
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   3360
      MaxLength       =   10
      TabIndex        =   7
      Text            =   "Text1"
      Top             =   2520
      Width           =   1695
   End
   Begin VB.CommandButton cmdRetry 
      Caption         =   "重试"
      Enabled         =   0   'False
      Height          =   495
      Left            =   1080
      TabIndex        =   6
      Top             =   2520
      Width           =   855
   End
   Begin VB.CommandButton cmdDo 
      Caption         =   "开始"
      Height          =   495
      Left            =   120
      TabIndex        =   4
      Top             =   2520
      Width           =   975
   End
   Begin VB.ListBox LstItems 
      Height          =   2040
      Left            =   120
      TabIndex        =   2
      Top             =   360
      Width           =   8175
   End
   Begin VB.TextBox txtLog 
      Height          =   2655
      Left            =   120
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   0
      Top             =   3360
      Width           =   8175
   End
   Begin VB.Label lblOperaInfo 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "就绪。"
      ForeColor       =   &H00FF0000&
      Height          =   180
      Left            =   2040
      TabIndex        =   5
      Top             =   2760
      Width           =   540
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "项目"
      Height          =   180
      Left            =   120
      TabIndex        =   3
      Top             =   120
      Width           =   360
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "日志"
      Height          =   180
      Left            =   120
      TabIndex        =   1
      Top             =   3120
      Width           =   360
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Sub FormEnabled(ByVal tEnabled As Boolean)
    LstItems.Enabled = tEnabled
    cmdDo.Enabled = tEnabled
    cmdRetry.Enabled = False
End Sub

Sub ShowLog(ByVal tLog As String, Optional ByVal ShowMsg As Boolean = False)
    lblOperaInfo.Caption = tLog
    txtLog.SelText = tLog & vbCrLf
    If ShowMsg = True Then MsgBox tLog
End Sub

Private Sub cmdDo_Click()
    FormEnabled False
    txtLog.Text = ""
    ShowLog "正在操作，请稍等"
    
    ShowLog "执行成功！", True
    FormEnabled True
End Sub

Private Sub Form_Resize()
    
    If WindowState = vbMinimized Then Exit Sub
    
    LstItems.Move 120, LstItems.Top, ScaleWidth - 240, LstItems.Height
    txtLog.Move 120, txtLog.Top, ScaleWidth - 240, ScaleHeight - txtLog.Top - 120
    
End Sub
