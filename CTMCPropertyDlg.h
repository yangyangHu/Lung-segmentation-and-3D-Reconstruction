#pragma once
#include "afxwin.h"
#include "Macro.h"


// CCTMCPropertyDlg 对话框

class CCTMCPropertyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCTMCPropertyDlg)

public:
	CCTMCPropertyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCTMCPropertyDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_CT_MC_Property };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strCaption;//对话框标题

	CScrollBar m_scrollbar_CTMCProp_LungCT;  //CT面绘制属性对话框肺阈值滚动条
	CScrollBar m_scrollbar_CTMCProp_LungSmooth;//CT面绘制属性对话框肺平滑迭代次数滚动条
	CScrollBar m_scrollbar_CTMCProp_LungR;//CT面绘制属性对话框肺颜色R滚动条
	CScrollBar m_scrollbar_CTMCProp_LungG;//CT面绘制属性对话框肺颜色G滚动条
	CScrollBar m_scrollbar_CTMCProp_LungB;//CT面绘制属性对话框肺颜色B滚动条
	CScrollBar m_scrollbar_CTMCProp_LungOpacity;//CT面绘制属性对话框肺透明度滚动条

	CScrollBar m_scrollbar_CTMCProp_InterCT;//CT面绘制属性对话框肺内部阈值滚动条
	CScrollBar m_scrollbar_CTMCProp_InterSmooth;//CT面绘制属性对话框肺内部平滑迭代次数滚动条
	CScrollBar m_scrollbar_CTMCProp_InterR;//CT面绘制属性对话框肺内部颜色R滚动条
	CScrollBar m_scrollbar_CTMCProp_InterG;//CT面绘制属性对话框肺内部颜色G滚动条
	CScrollBar m_scrollbar_CTMCProp_InterB;//CT面绘制属性对话框肺内部颜色B滚动条
	CScrollBar m_scrollbar_CTMCProp_InterOpacity;//CT面绘制属性对话框肺内部透明度滚动条

	CScrollBar m_scrollbar_CTMCProp_Ambient;//CT面绘制属性对话框环境光系数滚动条
	CScrollBar m_scrollbar_CTMCProp_Diffuse;//CT面绘制属性对话框漫射光系数滚动条
	CScrollBar m_scrollbar_CTMCProp_Specular;//CT面绘制属性对话框镜面光系数滚动条
	CScrollBar m_scrollbar_CTMCProp_SpecularPower;//CT面绘制属性对话框镜面光强度滚动条
public:
	int CTMC_Style;  //CT面绘制类型（即：MC/加速MC）

	int CTMC_LungCT_pos;//肺阈值滚动条位置
	int CTMC_LungSmooth_pos;//肺平滑迭代次数滚动条位置
	int CTMC_LungR_pos;//肺颜色R滚动条位置
	int CTMC_LungG_pos;//肺颜色G滚动条位置
	int CTMC_LungB_pos;//肺颜色B滚动条位置
	int CTMC_LungOpacity_pos;//肺透明度滚动条位置

	int CTMC_InterCT_pos;//肺内部阈值滚动条位置
	int CTMC_InterSmooth_pos;//肺内部平滑迭代次数滚动条位置
	int CTMC_InterR_pos;//肺内部颜色R滚动条位置
	int CTMC_InterG_pos;//肺内部颜色G滚动条位置
	int CTMC_InterB_pos;//肺内部颜色B滚动条位置
	int CTMC_InterOpacity_pos;//肺内部透明度滚动条位置

	int CTMC_Ambient_pos;//CTMC环境光系数滚动条位置
	int CTMC_Diffuse_pos;//CTMC漫射光系数滚动条位置
	int CTMC_Specular_pos;//CTMC镜面光系数滚动条位置
	int CTMC_SpecularPower_pos;//CTMC镜面光强度滚动条位置

	afx_msg void OnPaint();
	afx_msg void OnBnClickedRadioCtmcpropMc();
	afx_msg void OnBnClickedRadioCtmcpropAccmc();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
