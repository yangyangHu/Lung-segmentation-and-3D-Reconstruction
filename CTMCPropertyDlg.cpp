// CTMCPropertyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ITK+VTK+MFC_GUI.h"
#include "CTMCPropertyDlg.h"
#include "afxdialogex.h"


// CCTMCPropertyDlg 对话框

IMPLEMENT_DYNAMIC(CCTMCPropertyDlg, CDialogEx)

CCTMCPropertyDlg::CCTMCPropertyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCTMCPropertyDlg::IDD, pParent)
{
	/*CTMC_Style = MC;//默认情况下是MC

	CTMC_LungCT_pos = 103;
	CTMC_LungSmooth_pos = 500;
	CTMC_LungR_pos = 100;
	CTMC_LungG_pos = 19;
	CTMC_LungB_pos = 15;
	CTMC_LungOpacity_pos = 100;

	CTMC_InterCT_pos = 160;
	CTMC_InterSmooth_pos = 100;
	CTMC_InterR_pos = 100;
	CTMC_InterG_pos = 19;
	CTMC_InterB_pos = 15;
	CTMC_InterOpacity_pos = 100;

	CTMC_Ambient_pos = 30;
	CTMC_Diffuse_pos = 60;
	CTMC_Specular_pos = 20;
	CTMC_SpecularPower_pos = 20;*/
}

CCTMCPropertyDlg::~CCTMCPropertyDlg()
{
}

void CCTMCPropertyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_LungCT, m_scrollbar_CTMCProp_LungCT);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_LungSmooth, m_scrollbar_CTMCProp_LungSmooth);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_LungR, m_scrollbar_CTMCProp_LungR);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_LungG, m_scrollbar_CTMCProp_LungG);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_LungB, m_scrollbar_CTMCProp_LungB);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_LungOpacity, m_scrollbar_CTMCProp_LungOpacity);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_InterCT, m_scrollbar_CTMCProp_InterCT);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_InterSmooth, m_scrollbar_CTMCProp_InterSmooth);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_InterR, m_scrollbar_CTMCProp_InterR);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_InterG, m_scrollbar_CTMCProp_InterG);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_InterB, m_scrollbar_CTMCProp_InterB);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_InterOpacity, m_scrollbar_CTMCProp_InterOpacity);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_Ambient, m_scrollbar_CTMCProp_Ambient);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_Diffuse, m_scrollbar_CTMCProp_Diffuse);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_Specular, m_scrollbar_CTMCProp_Specular);
	DDX_Control(pDX, IDC_SCROLLBAR_CTMCProp_SpecularPower, m_scrollbar_CTMCProp_SpecularPower);
}


BEGIN_MESSAGE_MAP(CCTMCPropertyDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_RADIO_CTMCProp_MC, &CCTMCPropertyDlg::OnBnClickedRadioCtmcpropMc)
	ON_BN_CLICKED(IDC_RADIO_CTMCProp_AccMC, &CCTMCPropertyDlg::OnBnClickedRadioCtmcpropAccmc)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CCTMCPropertyDlg 消息处理程序


void CCTMCPropertyDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

	//初始化
	//动态设置对话框标题
	SetWindowText(m_strCaption);

	// 设置肺阈值水平滚动条的滚动范围为0到255   
    m_scrollbar_CTMCProp_LungCT.SetScrollRange(0, 255);   
    // 设置水平滚动条的初始位置为103   
    m_scrollbar_CTMCProp_LungCT.SetScrollPos(CTMC_LungCT_pos);   
    // 在编辑框中显示103   
    SetDlgItemInt(IDC_STATIC_CTMCProp_LungCT, CTMC_LungCT_pos); 

	// 设置肺平滑迭代次数水平滚动条的滚动范围为0到1000   
    m_scrollbar_CTMCProp_LungSmooth.SetScrollRange(0, 1000);   
    // 设置水平滚动条的初始位置为500  
    m_scrollbar_CTMCProp_LungSmooth.SetScrollPos(CTMC_LungSmooth_pos);   
    // 在编辑框中显示500   
    SetDlgItemInt(IDC_STATIC_CTMCProp_LungSmooth, CTMC_LungSmooth_pos); 

	// 设置肺颜色R水平滚动条的滚动范围为0到100 
    m_scrollbar_CTMCProp_LungR.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为100  
    m_scrollbar_CTMCProp_LungR.SetScrollPos(CTMC_LungR_pos);   
    // 在编辑框中显示100   
    SetDlgItemInt(IDC_STATIC_CTMCProp_LungR, CTMC_LungR_pos); 

	// 设置肺颜色G水平滚动条的滚动范围为0到100 
    m_scrollbar_CTMCProp_LungG.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为19  
    m_scrollbar_CTMCProp_LungG.SetScrollPos(CTMC_LungG_pos);   
    // 在编辑框中显示19   
    SetDlgItemInt(IDC_STATIC_CTMCProp_LungG, CTMC_LungG_pos); 

	// 设置肺颜色B水平滚动条的滚动范围为0到100 
    m_scrollbar_CTMCProp_LungB.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为15  
    m_scrollbar_CTMCProp_LungB.SetScrollPos(CTMC_LungB_pos);   
    // 在编辑框中显示15   
    SetDlgItemInt(IDC_STATIC_CTMCProp_LungB, CTMC_LungB_pos); 

	// 设置肺透明度水平滚动条的滚动范围为0到100 
    m_scrollbar_CTMCProp_LungOpacity.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为100  
    m_scrollbar_CTMCProp_LungOpacity.SetScrollPos(CTMC_LungOpacity_pos);   
    // 在编辑框中显示100   
    SetDlgItemInt(IDC_STATIC_CTMCProp_LungOpacity, CTMC_LungOpacity_pos); 


	// 设置肺内部阈值水平滚动条的滚动范围为0到255  
    m_scrollbar_CTMCProp_InterCT.SetScrollRange(0, 255);   
    // 设置水平滚动条的初始位置为160   
    m_scrollbar_CTMCProp_InterCT.SetScrollPos(CTMC_InterCT_pos);   
    // 在编辑框中显示160   
    SetDlgItemInt(IDC_STATIC_CTMCProp_InterCT, CTMC_InterCT_pos); 

	// 设置肺内部平滑迭代次数水平滚动条的滚动范围为0到1000   
    m_scrollbar_CTMCProp_InterSmooth.SetScrollRange(0, 1000);   
    // 设置水平滚动条的初始位置为100  
    m_scrollbar_CTMCProp_InterSmooth.SetScrollPos(CTMC_InterSmooth_pos);   
    // 在编辑框中显示100   
    SetDlgItemInt(IDC_STATIC_CTMCProp_InterSmooth, CTMC_InterSmooth_pos); 

	// 设置肺内部颜色R水平滚动条的滚动范围为0到100 
    m_scrollbar_CTMCProp_InterR.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为100  
    m_scrollbar_CTMCProp_InterR.SetScrollPos(CTMC_InterR_pos);   
    // 在编辑框中显示100   
    SetDlgItemInt(IDC_STATIC_CTMCProp_InterR, CTMC_InterR_pos); 

	// 设置肺内部颜色G水平滚动条的滚动范围为0到100 
    m_scrollbar_CTMCProp_InterG.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为19  
    m_scrollbar_CTMCProp_InterG.SetScrollPos(CTMC_InterG_pos);   
    // 在编辑框中显示19   
    SetDlgItemInt(IDC_STATIC_CTMCProp_InterG, CTMC_InterG_pos); 

	// 设置肺内部颜色B水平滚动条的滚动范围为0到100 
    m_scrollbar_CTMCProp_InterB.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为15  
    m_scrollbar_CTMCProp_InterB.SetScrollPos(CTMC_InterB_pos);   
    // 在编辑框中显示15   
    SetDlgItemInt(IDC_STATIC_CTMCProp_InterB, CTMC_InterB_pos); 

	// 设置肺内部透明度水平滚动条的滚动范围为0到100 
    m_scrollbar_CTMCProp_InterOpacity.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为100  
    m_scrollbar_CTMCProp_InterOpacity.SetScrollPos(CTMC_InterOpacity_pos);   
    // 在编辑框中显示100   
    SetDlgItemInt(IDC_STATIC_CTMCProp_InterOpacity, CTMC_InterOpacity_pos); 

	// 设置肺环境光系数水平滚动条的滚动范围为0到100 
    m_scrollbar_CTMCProp_Ambient.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为30  
    m_scrollbar_CTMCProp_Ambient.SetScrollPos(CTMC_Ambient_pos);   
    // 在编辑框中显示30   
    SetDlgItemInt(IDC_STATIC_CTMCProp_Ambient, CTMC_Ambient_pos); 

	// 设置肺漫射光系数水平滚动条的滚动范围为0到100 
    m_scrollbar_CTMCProp_Diffuse.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为60  
    m_scrollbar_CTMCProp_Diffuse.SetScrollPos(CTMC_Diffuse_pos);   
    // 在编辑框中显示60   
    SetDlgItemInt(IDC_STATIC_CTMCProp_Diffuse, CTMC_Diffuse_pos); 

	// 设置肺镜面光系数水平滚动条的滚动范围为0到100 
    m_scrollbar_CTMCProp_Specular.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为20  
    m_scrollbar_CTMCProp_Specular.SetScrollPos(CTMC_Specular_pos);   
    // 在编辑框中显示20   
    SetDlgItemInt(IDC_STATIC_CTMCProp_Specular, CTMC_Specular_pos); 

	// 设置肺镜面光强度水平滚动条的滚动范围为0到100 
    m_scrollbar_CTMCProp_SpecularPower.SetScrollRange(0, 100);   
    // 设置水平滚动条的初始位置为20  
    m_scrollbar_CTMCProp_SpecularPower.SetScrollPos(CTMC_SpecularPower_pos);   
    // 在编辑框中显示20   
    SetDlgItemInt(IDC_STATIC_CTMCProp_SpecularPower, CTMC_SpecularPower_pos); 

	if(CTMC_Style == MC)
	{
		// 默认选中“MC”单选按钮   
		CheckDlgButton(IDC_RADIO_CTMCProp_MC, 1);  
		OnBnClickedRadioCtmcpropMc();
	}
	else if(CTMC_Style == ACC_MC)
	{
		// 默认选中“ACC_MC”单选按钮   
		CheckDlgButton(IDC_RADIO_CTMCProp_AccMC, 1);  
		OnBnClickedRadioCtmcpropAccmc();
	}
	

}


//单击MC单选按钮事件
void CCTMCPropertyDlg::OnBnClickedRadioCtmcpropMc()
{
	// TODO: 在此添加控件通知处理程序代码
	 CTMC_Style = MC;  //设置CTMC绘制类型为MC
}


//单击加速MC单选按钮事件
void CCTMCPropertyDlg::OnBnClickedRadioCtmcpropAccmc()
{
	// TODO: 在此添加控件通知处理程序代码
	CTMC_Style = ACC_MC;  //设置CTMC绘制类型为加速MC
}


void CCTMCPropertyDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	// 根据CSliderCtrl ID 来判断是哪一个CSliderCtrl
	if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_LungCT)  //肺阈值
	{
		CTMC_LungCT_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_LungCT_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_LungCT_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_LungCT_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_LungCT_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_LungCT_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_LungCT_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_LungCT_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_LungCT,CTMC_LungCT_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_LungCT_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_LungSmooth)//平滑迭代次数
	{
		CTMC_LungSmooth_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_LungSmooth_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_LungSmooth_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_LungSmooth_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_LungSmooth_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_LungSmooth_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_LungSmooth_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_LungSmooth_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_LungSmooth,CTMC_LungSmooth_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_LungSmooth_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_LungR)//肺颜色R
	{
		CTMC_LungR_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_LungR_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_LungR_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_LungR_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_LungR_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_LungR_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_LungR_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_LungR_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_LungR,CTMC_LungR_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_LungR_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_LungG)//肺颜色G
	{
		CTMC_LungG_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_LungG_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_LungG_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_LungG_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_LungG_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_LungG_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_LungG_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_LungG_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_LungG,CTMC_LungG_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_LungG_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_LungB)//肺颜色B
	{
		CTMC_LungB_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_LungB_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_LungB_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_LungB_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_LungB_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_LungB_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_LungB_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_LungB_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_LungB,CTMC_LungB_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_LungB_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_LungOpacity)//肺透明度
	{
		CTMC_LungOpacity_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_LungOpacity_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_LungOpacity_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_LungOpacity_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_LungOpacity_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_LungOpacity_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_LungOpacity_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_LungOpacity_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_LungOpacity,CTMC_LungOpacity_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_LungOpacity_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_InterCT)//肺内部阈值
	{
		CTMC_InterCT_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_InterCT_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_InterCT_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_InterCT_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_InterCT_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_InterCT_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_InterCT_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_InterCT_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_InterCT,CTMC_InterCT_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_InterCT_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_InterSmooth)//肺内部平滑迭代次数
	{
		CTMC_InterSmooth_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_InterSmooth_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_InterSmooth_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_InterSmooth_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_InterSmooth_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_InterSmooth_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_InterSmooth_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_InterSmooth_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_InterSmooth,CTMC_InterSmooth_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_InterSmooth_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_InterR)//肺内部颜色R
	{
		CTMC_InterR_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_InterR_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_InterR_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_InterR_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_InterR_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_InterR_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_InterR_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_InterR_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_InterR,CTMC_InterR_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_InterR_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_InterG)//肺内部颜色G
	{
		CTMC_InterG_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_InterG_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_InterG_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_InterG_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_InterG_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_InterG_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_InterG_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_InterG_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_InterG,CTMC_InterG_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_InterG_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_InterB)//肺内部颜色B
	{
		CTMC_InterB_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_InterB_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_InterB_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_InterB_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_InterB_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_InterB_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_InterB_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_InterB_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_InterB,CTMC_InterB_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_InterB_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_InterOpacity)//肺内部透明度
	{
		CTMC_InterOpacity_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_InterOpacity_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_InterOpacity_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_InterOpacity_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_InterOpacity_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_InterOpacity_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_InterOpacity_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_InterOpacity_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_InterOpacity,CTMC_InterOpacity_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_InterOpacity_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_Ambient)//环境光系数
	{
		CTMC_Ambient_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_Ambient_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_Ambient_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_Ambient_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_Ambient_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_Ambient_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_Ambient_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_Ambient_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_Ambient,CTMC_Ambient_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_Ambient_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_Diffuse)//漫射光系数
	{
		CTMC_Diffuse_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_Diffuse_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_Diffuse_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_Diffuse_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_Diffuse_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_Diffuse_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_Diffuse_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_Diffuse_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_Diffuse,CTMC_Diffuse_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_Diffuse_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_Specular)//镜面光系数
	{
		CTMC_Specular_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_Specular_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_Specular_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_Specular_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_Specular_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_Specular_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_Specular_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_Specular_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_Specular,CTMC_Specular_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_Specular_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_CTMCProp_SpecularPower)//镜面光强度
	{
		CTMC_SpecularPower_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				CTMC_SpecularPower_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				CTMC_SpecularPower_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				CTMC_SpecularPower_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				CTMC_SpecularPower_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				CTMC_SpecularPower_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				CTMC_SpecularPower_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				CTMC_SpecularPower_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_CTMCProp_SpecularPower,CTMC_SpecularPower_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(CTMC_SpecularPower_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}


	
}
