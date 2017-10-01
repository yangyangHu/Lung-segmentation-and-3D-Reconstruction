#pragma once
#include "afxwin.h"
#include "Global.h"


// CLungPETCTSeriesSegDlg 对话框

class CLungPETCTSeriesSegDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLungPETCTSeriesSegDlg)

public:
	CLungPETCTSeriesSegDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLungPETCTSeriesSegDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_LungPETCT_SeriesSeg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString strInitCT;   //存放选择某人待分割的CT文件夹路径
	CString strInitPET;   //存放选择该人待分割的PET文件夹路径

	CString strSegCT;   //存放存储该人序列分割后的CT文件夹路径
	CString strSegPET;   //存放存储该人序列分割后的PET文件夹路径

	CString strPETCTSeriesSeg;   //存放肺部PET-CT序列分割运行状态
	
public:
	//==============肺部PET-CT序列分割变量与函数定义========================

	typedef struct QNode   //队列结点
	{
		int x;//图像x方向索引
		int y;//图像y方向索引
		struct QNode *next;
	}QNode,*QueuePtr;

	typedef struct
	{
		QNode *front;//队列头
		QNode *rear;//队列尾
	}LinkQueue;

	bool flag[1000][1000];    //图像每个像素点是否被访问标志

	void InitQueue(LinkQueue &Q);  //队列初始化

	bool IsEmpty(LinkQueue Q);//队列判空

	void EnQueue(LinkQueue &Q,int x,int y);//入队

	bool DeQueue(LinkQueue &Q,int &x,int &y);//出队

	int LungPET_CTSeriesSeg();//肺部PET-CT序列分割

	//======================================================================

public:
	afx_msg void OnPaint();
	CEdit m_editInitCT; //选择某人待分割的CT文件夹文本编辑框变量
	CEdit m_editInitPET;//选择该人待分割的PET文件夹文本编辑框变量
	CEdit m_editSegCT;//存储该人序列分割后的CT文件夹文本编辑框变量
	CEdit m_editSegPET;//存储该人序列分割后的PET文件夹文本编辑框变量
	CEdit m_editPETCTSeriesSeg_View;//肺部PET-CT序列分割运行状态观察框文本编辑框变量
	afx_msg void OnBnClickedButtonInitct();//点击选择某人待分割的CT文件夹按钮事件
	afx_msg void OnBnClickedButtonInitpet();//点击选择该人待分割的PET文件夹按钮事件
	afx_msg void OnBnClickedButtonSegct();//点击存储该人序列分割后的CT文件夹按钮事件
	afx_msg void OnBnClickedButtonSegpet();//点击存储该人序列分割后的PET文件夹按钮事件
	afx_msg void OnBnClickedButtonPetctseriessegStart();//点击肺部PET-CT序列分割启动按钮事件

	CButton m_buttonPETCTSeriesSegStart;//肺部PET-CT序列分割启动按钮变量
};
