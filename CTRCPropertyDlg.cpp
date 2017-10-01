// CTRCPropertyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ITK+VTK+MFC_GUI.h"
#include "CTRCPropertyDlg.h"
#include "afxdialogex.h"


// CCTRCPropertyDlg 对话框

IMPLEMENT_DYNAMIC(CCTRCPropertyDlg, CDialogEx)

CCTRCPropertyDlg::CCTRCPropertyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCTRCPropertyDlg::IDD, pParent)
{
	/*CTRC_Style = RC;//默认情况下是RC

	CTRC_LungCT_pos = 140;
	CTRC_LungR_pos = 100;
	CTRC_LungG_pos = 19;
	CTRC_LungB_pos = 15;
	CTRC_LungOpacity_pos = 100;

	CTRC_InterCT_pos = 170;
	CTRC_InterR_pos = 100;
	CTRC_InterG_pos = 19;
	CTRC_InterB_pos = 15;
	CTRC_InterOpacity_pos = 100;

	CTRC_Ambient_pos = 30;
	CTRC_Diffuse_pos = 60;
	CTRC_Specular_pos = 20;
	CTRC_SpecularPower_pos = 20;*/

}

CCTRCPropertyDlg::~CCTRCPropertyDlg()
{
}

void CCTRCPropertyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_LungCT, m_scrollbar_CTRCProp_LungCT);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_LungR, m_scrollbar_CTRCProp_LungR);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_LungG, m_scrollbar_CTRCProp_LungG);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_LungB, m_scrollbar_CTRCProp_LungB);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_LungOpacity, m_scrollbar_CTRCProp_LungOpacity);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_InterCT, m_scrollbar_CTRCProp_InterCT);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_InterR, m_scrollbar_CTRCProp_InterR);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_InterG, m_scrollbar_CTRCProp_InterG);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_InterB, m_scrollbar_CTRCProp_InterB);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_InterOpacity, m_scrollbar_CTRCProp_InterOpacity);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_Ambient, m_scrollbar_CTRCProp_Ambient);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_Diffuse, m_scrollbar_CTRCProp_Diffuse);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_Specular, m_scrollbar_CTRCProp_Specular);
	DDX_Control(pDX, IDC_SCROLLBAR_CTRCProp_SpecularPower, m_scrollbar_CTRCProp_SpecularPower);
}


BEGIN_MESSAGE_MAP(CCTRCPropertyDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_RADIO_CTRCProp_RC, &CCTRCPropertyDlg::OnBnClickedRadioCtrcpropRc)
	ON_BN_CLICKED(IDC_RADIO_CTRCProp_FixRC, &CCTRCPropertyDlg::OnBnClickedRadioCtrcpropFixrc)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CCTRCPropertyDlg 消息处理程序


void CCTRCPropertyDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

	//初始化
	//设置对话框标题
	SetWindowText(m_strCaption);

	// 设置肺阈值水平滚动条的滚动范围为0到255   
    m_scrollbar_CTRCProp_LungCT.SetScrollRange(0, 255);   
    // 设置水平滚动条的初始位置为140   
    m_scrollbar_CTRCProp_LungCT.SetScrollPos(CTRC_LungCT_pos);   
    // 在编辑框中显示140   
    SetDlgItemInt(IDC_STATIC_CTRCProp_LungCT, CTRC_LungCT_pos); 

	// 设置肺颜色R水平滚动条的滚动范围为0到100 
    m_scrollbar_CTRCProp_LungR.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为100  
    m_scrollbar_CTRCProp_LungR.SetScrollPos(CTRC_LungR_pos);   
    // 在编辑框中显示100   
    SetDlgItemInt(IDC_STATIC_CTRCProp_LungR, CTRC_LungR_pos); 

	// 设置肺颜色G水平滚动条的滚动范围为0到100 
    m_scrollbar_CTRCProp_LungG.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为19  
    m_scrollbar_CTRCProp_LungG.SetScrollPos(CTRC_LungG_pos);   
    // 在编辑框中显示19   
    SetDlgItemInt(IDC_STATIC_CTRCProp_LungG, CTRC_LungG_pos); 

	// 设置肺颜色B水平滚动条的滚动范围为0到100 
    m_scrollbar_CTRCProp_LungB.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为15  
    m_scrollbar_CTRCProp_LungB.SetScrollPos(CTRC_LungB_pos);   
    // 在编辑框中显示15   
    SetDlgItemInt(IDC_STATIC_CTRCProp_LungB, CTRC_LungB_pos); 

	// 设置肺透明度水平滚动条的滚动范围为0到100 
    m_scrollbar_CTRCProp_LungOpacity.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为100  
    m_scrollbar_CTRCProp_LungOpacity.SetScrollPos(CTRC_LungOpacity_pos);   
    // 在编辑框中显示100   
    SetDlgItemInt(IDC_STATIC_CTRCProp_LungOpacity, CTRC_LungOpacity_pos); 


	// 设置肺内部阈值水平滚动条的滚动范围为0到255  
    m_scrollbar_CTRCProp_InterCT.SetScrollRange(0, 255);   
    // 设置水平滚动条的初始位置为170   
    m_scrollbar_CTRCProp_InterCT.SetScrollPos(CTRC_InterCT_pos);   
    // 在编辑框中显示170   
    SetDlgItemInt(IDC_STATIC_CTRCProp_InterCT, CTRC_InterCT_pos); 

	// 设置肺内部颜色R水平滚动条的滚动范围为0到100 
    m_scrollbar_CTRCProp_InterR.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为100  
    m_scrollbar_CTRCProp_InterR.SetScrollPos(CTRC_InterR_pos);   
    // 在编辑框中显示100   
    SetDlgItemInt(IDC_STATIC_CTRCProp_InterR, CTRC_InterR_pos); 

	// 设置肺内部颜色G水平滚动条的滚动范围为0到100 
    m_scrollbar_CTRCProp_InterG.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为19  
    m_scrollbar_CTRCProp_InterG.SetScrollPos(CTRC_InterG_pos);   
    // 在编辑框中显示19   
    SetDlgItemInt(IDC_STATIC_CTRCProp_InterG, CTRC_InterG_pos); 

	// 设置肺内部颜色B水平滚动条的滚动范围为0到100 
    m_scrollbar_CTRCProp_InterB.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为15  
    m_scrollbar_CTRCProp_InterB.SetScrollPos(CTRC_InterB_pos);   
    // 在编辑框中显示15   
    SetDlgItemInt(IDC_STATIC_CTRCProp_InterB, CTRC_InterB_pos); 

	// 设置肺内部透明度水平滚动条的滚动范围为0到100 
    m_scrollbar_CTRCProp_InterOpacity.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为100  
    m_scrollbar_CTRCProp_InterOpacity.SetScrollPos(CTRC_InterOpacity_pos);   
    // 在编辑框中显示100   
    SetDlgItemInt(IDC_STATIC_CTRCProp_InterOpacity, CTRC_InterOpacity_pos); 

	// 设置肺环境光系数水平滚动条的滚动范围为0到100 
    m_scrollbar_CTRCProp_Ambient.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为30  
    m_scrollbar_CTRCProp_Ambient.SetScrollPos(CTRC_Ambient_pos);   
    // 在编辑框中显示30   
    SetDlgItemInt(IDC_STATIC_CTRCProp_Ambient, CTRC_Ambient_pos); 

	// 设置肺漫射光系数水平滚动条的滚动范围为0到100 
    m_scrollbar_CTRCProp_Diffuse.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为60  
    m_scrollbar_CTRCProp_Diffuse.SetScrollPos(CTRC_Diffuse_pos);   
    // 在编辑框中显示60   
    SetDlgItemInt(IDC_STATIC_CTRCProp_Diffuse, CTRC_Diffuse_pos); 

	// 设置肺镜面光系数水平滚动条的滚动范围为0到100 
    m_scrollbar_CTRCProp_Specular.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为20  
    m_scrollbar_CTRCProp_Specular.SetScrollPos(CTRC_Specular_pos);   
    // 在编辑框中显示20   
    SetDlgItemInt(IDC_STATIC_CTRCProp_Specular, CTRC_Specular_pos); 

	// 设置肺镜面光强度水平滚动条的滚动范围为0到100 
    m_scrollbar_CTRCProp_SpecularPower.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为20  
    m_scrollbar_CTRCProp_SpecularPower.SetScrollPos(CTRC_SpecularPower_pos);   
    // 在编辑框中显示20   
    SetDlgItemInt(IDC_STATIC_CTRCProp_SpecularPower, CTRC_SpecularPower_pos); 

	if(CTRC_Style == RC)
	{
		// 默认选中“RC”单选按钮   
		CheckDlgButton(IDC_RADIO_CTRCProp_RC, 1);  
		OnBnClickedRadioCtrcpropRc();
	}
	else if(CTRC_Style == FIX_RC)
	{
		// 默认选中“FIX_RC”单选按钮   
		CheckDlgButton(IDC_RADIO_CTRCProp_FixRC, 1);  
		OnBnClickedRadioCtrcpropFixrc();
	}
	
}


//单击RC单选按钮事件
void CCTRCPropertyDlg::OnBnClickedRadioCtrcpropRc()
{
	// TODO: 在此添加控件通知处理程序代码
	CTRC_Style = RC;  //设置CTRC绘制类型为RC
}


//单击固定点RC单选按钮事件
void CCTRCPropertyDlg::OnBnClickedRadioCtrcpropFixrc()
{
	// TODO: 在此添加控件通知处理程序代码
	CTRC_Style = FIX_RC;  //设置CTRC绘制类型为FIX_RC
}


void CCTRCPropertyDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	// 根据CSliderCtrl ID 来判断是哪一个CSliderCtrl
	if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_LungCT)  //肺阈值
	{
		CTRC_LungCT_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTRC_LungCT_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTRC_LungCT_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTRC_LungCT_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTRC_LungCT_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTRC_LungCT_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTRC_LungCT_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTRC_LungCT_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_LungCT,CTRC_LungCT_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTRC_LungCT_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_LungR)//肺颜色R
	{
		CTRC_LungR_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTRC_LungR_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTRC_LungR_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTRC_LungR_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTRC_LungR_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTRC_LungR_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTRC_LungR_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTRC_LungR_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_LungR,CTRC_LungR_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTRC_LungR_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_LungG)//肺颜色G
	{
		CTRC_LungG_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTRC_LungG_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTRC_LungG_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTRC_LungG_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTRC_LungG_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTRC_LungG_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTRC_LungG_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTRC_LungG_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_LungG,CTRC_LungG_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTRC_LungG_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_LungB)//肺颜色B
	{
		CTRC_LungB_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTRC_LungB_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTRC_LungB_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTRC_LungB_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTRC_LungB_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTRC_LungB_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTRC_LungB_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTRC_LungB_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_LungB,CTRC_LungB_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTRC_LungB_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_LungOpacity)//肺透明度
	{
		CTRC_LungOpacity_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTRC_LungOpacity_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTRC_LungOpacity_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTRC_LungOpacity_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTRC_LungOpacity_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTRC_LungOpacity_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTRC_LungOpacity_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTRC_LungOpacity_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_LungOpacity,CTRC_LungOpacity_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTRC_LungOpacity_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_InterCT)//肺内部阈值
	{
		CTRC_InterCT_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTRC_InterCT_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTRC_InterCT_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTRC_InterCT_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTRC_InterCT_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTRC_InterCT_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTRC_InterCT_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTRC_InterCT_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_InterCT,CTRC_InterCT_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTRC_InterCT_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_InterR)//肺内部颜色R
	{
		CTRC_InterR_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTRC_InterR_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTRC_InterR_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTRC_InterR_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTRC_InterR_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTRC_InterR_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTRC_InterR_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTRC_InterR_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_InterR,CTRC_InterR_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTRC_InterR_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_InterG)//肺内部颜色G
	{
		CTRC_InterG_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTRC_InterG_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTRC_InterG_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTRC_InterG_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTRC_InterG_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTRC_InterG_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTRC_InterG_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTRC_InterG_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_InterG,CTRC_InterG_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTRC_InterG_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_InterB)//肺内部颜色B
	{
		CTRC_InterB_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTRC_InterB_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTRC_InterB_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTRC_InterB_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTRC_InterB_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTRC_InterB_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTRC_InterB_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTRC_InterB_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_InterB,CTRC_InterB_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTRC_InterB_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_InterOpacity)//肺内部透明度
	{
		CTRC_InterOpacity_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTRC_InterOpacity_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTRC_InterOpacity_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTRC_InterOpacity_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTRC_InterOpacity_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTRC_InterOpacity_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTRC_InterOpacity_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTRC_InterOpacity_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_InterOpacity,CTRC_InterOpacity_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTRC_InterOpacity_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_Ambient)//环境光系数
	{
		CTRC_Ambient_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTRC_Ambient_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTRC_Ambient_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTRC_Ambient_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTRC_Ambient_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTRC_Ambient_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTRC_Ambient_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTRC_Ambient_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_Ambient,CTRC_Ambient_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTRC_Ambient_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_Diffuse)//漫射光系数
	{
		CTRC_Diffuse_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTRC_Diffuse_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTRC_Diffuse_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTRC_Diffuse_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTRC_Diffuse_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTRC_Diffuse_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTRC_Diffuse_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTRC_Diffuse_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_Diffuse,CTRC_Diffuse_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTRC_Diffuse_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_Specular)//镜面光系数
	{
		CTRC_Specular_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTRC_Specular_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTRC_Specular_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTRC_Specular_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTRC_Specular_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTRC_Specular_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTRC_Specular_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTRC_Specular_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_Specular,CTRC_Specular_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTRC_Specular_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTRCProp_SpecularPower)//镜面光强度
	{
		CTRC_SpecularPower_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTRC_SpecularPower_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTRC_SpecularPower_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTRC_SpecularPower_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTRC_SpecularPower_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTRC_SpecularPower_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTRC_SpecularPower_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTRC_SpecularPower_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTRCProp_SpecularPower,CTRC_SpecularPower_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTRC_SpecularPower_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}
