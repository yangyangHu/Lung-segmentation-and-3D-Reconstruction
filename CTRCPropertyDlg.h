#pragma once
#include "afxwin.h"
#include "Macro.h"

// CCTRCPropertyDlg 对话框

class CCTRCPropertyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCTRCPropertyDlg)

public:
	CCTRCPropertyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCTRCPropertyDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_CT_RC_Property };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strCaption;//设置对话框标题

	CScrollBar m_scrollbar_CTRCProp_LungCT;//CT体绘制属性对话框肺阈值滚动条
	CScrollBar m_scrollbar_CTRCProp_LungR;//颜色R
	CScrollBar m_scrollbar_CTRCProp_LungG;//颜色G
	CScrollBar m_scrollbar_CTRCProp_LungB;//颜色B
	CScrollBar m_scrollbar_CTRCProp_LungOpacity;//透明度


	CScrollBar m_scrollbar_CTRCProp_InterCT;//CT体绘制属性对话框肺内部阈值滚动条
	CScrollBar m_scrollbar_CTRCProp_InterR;//颜色R
	CScrollBar m_scrollbar_CTRCProp_InterG;//颜色G
	CScrollBar m_scrollbar_CTRCProp_InterB;//颜色B
	CScrollBar m_scrollbar_CTRCProp_InterOpacity;//透明度

	CScrollBar m_scrollbar_CTRCProp_Ambient;//CT体绘制属性对话框环境光系数滚动条
	CScrollBar m_scrollbar_CTRCProp_Diffuse;//漫射光系数
	CScrollBar m_scrollbar_CTRCProp_Specular;//镜面光系数
	CScrollBar m_scrollbar_CTRCProp_SpecularPower;//镜面光强度

public:
	int CTRC_Style;  //CT体绘制类型（即：RC/固定点RC）

	int CTRC_LungCT_pos;//肺阈值滚动条位置
	int CTRC_LungR_pos;//肺颜色R滚动条位置
	int CTRC_LungG_pos;//肺颜色G滚动条位置
	int CTRC_LungB_pos;//肺颜色B滚动条位置
	int CTRC_LungOpacity_pos;//肺透明度滚动条位置

	int CTRC_InterCT_pos;//肺内部阈值滚动条位置
	int CTRC_InterR_pos;//肺内部颜色R滚动条位置
	int CTRC_InterG_pos;//肺内部颜色G滚动条位置
	int CTRC_InterB_pos;//肺内部颜色B滚动条位置
	int CTRC_InterOpacity_pos;//肺内部透明度滚动条位置

	int CTRC_Ambient_pos;//CTRC环境光系数滚动条位置
	int CTRC_Diffuse_pos;//CTRC漫射光系数滚动条位置
	int CTRC_Specular_pos;//CTRC镜面光系数滚动条位置
	int CTRC_SpecularPower_pos;//CTRC镜面光强度滚动条位置

	afx_msg void OnPaint();
	afx_msg void OnBnClickedRadioCtrcpropRc();
	afx_msg void OnBnClickedRadioCtrcpropFixrc();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
