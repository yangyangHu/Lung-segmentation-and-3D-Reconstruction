// AboutDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ITK+VTK+MFC_GUI.h"
#include "AboutDlg.h"
#include "afxdialogex.h"


// AboutDlg 对话框

IMPLEMENT_DYNAMIC(AboutDlg, CDialogEx)

AboutDlg::AboutDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AboutDlg::IDD, pParent)
{

}

AboutDlg::~AboutDlg()
{
}

void AboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AboutDlg, CDialogEx)
END_MESSAGE_MAP()


// AboutDlg 消息处理程序
