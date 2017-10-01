#pragma once
#include "afxwin.h"
#include "Global.h"


class vtkNextDcmCallbk : public vtkCommand
{
public:
 static vtkNextDcmCallbk *New()
 {
	return new vtkNextDcmCallbk;
 }
 virtual void Execute(vtkObject *caller, unsigned long eventId, void *callData)
 {
	vtkWin32RenderWindowInteractor *pInt = vtkWin32RenderWindowInteractor::SafeDownCast(caller); //转换为相应的类型
	vtkRendererCollection *pRenders = pInt->GetRenderWindow()->GetRenderers();//得到Renderwindow所有的render
	vtkRenderer *pRender = pRenders->GetFirstRenderer();
	vtkActor2DCollection *pActors = pRender->GetActors2D();//得到 Render里所有actor
 
	vtkActor2D *pActor = (vtkActor2D *)pActors->GetItemAsObject(0);//得到Render里第一个Actor
	//以上是我自己转换的方法，不知道对不对，如果有人有更好的方法给我说一下，
	int max = ((vtkImageMapper *)pActor->GetMapper())->GetWholeZMax();//得到所有切片的索引
	int cur = ((vtkImageMapper *)pActor->GetMapper())->GetZSlice();//得到当前切片的索引
	if (eventId == vtkCommand::MouseWheelForwardEvent && (cur - 1) >=0)
	{
		((vtkImageMapper *)pActor->GetMapper())->SetZSlice(--cur);//设置当前索引
	 } 
	if (eventId == vtkCommand::MouseWheelBackwardEvent && (cur + 1) <= max)
	{
		((vtkImageMapper *)pActor->GetMapper())->SetZSlice(++cur);
	}
	char buf[64] = {0};
	sprintf(buf, "%d / %d", cur, max);
	vtkTextActor *pTextActor = (vtkTextActor *)pActors->GetItemAsObject(1);
	pTextActor->SetInput(buf);
  
 }
};


// VolumeDataViewDlg 对话框

class VolumeDataViewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(VolumeDataViewDlg)

public:
	VolumeDataViewDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~VolumeDataViewDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_VolumeVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	long init_level_pos;//原始CT/PET Level滚动条位置
	long init_window_pos;//原始CT/PET window滚动条位置

	long seg_level_pos;//分割后CT/PET Level滚动条位置
	long seg_window_pos;//分割后CT/PET window滚动条位置

	vtkImageData  *Init_CT_PET_dicm_data;//保存原始CT/PET体数据
	vtkImageData  *Seg_CT_PET_dicm_data;//保存原始CT/PET体数据

	//==============原始CT/PET预览成员对象=======================
	vtkRenderer *init_render;
	vtkWin32OpenGLRenderWindow *init_renWin;
	vtkImageMapper *init_mapper;
	vtkActor2D *init_actor;
	vtkTextActor *init_textActor;
	vtkWin32RenderWindowInteractor *init_iren;
	vtkNextDcmCallbk *init_pCall; 
	//===========================================================

	//==============分割后CT/PET预览成员对象=======================
	vtkRenderer *seg_render;
	vtkWin32OpenGLRenderWindow *seg_renWin;
	vtkImageMapper *seg_mapper;
	vtkActor2D *seg_actor;
	vtkTextActor *seg_textActor;
	vtkWin32RenderWindowInteractor *seg_iren;
	vtkNextDcmCallbk *seg_pCall; 
	//===========================================================

public:
	CComboBox m_comboViewImport;//导入组合框的控制变量

	CScrollBar m_scrollbar_init_level; //原始CT/PET预览Level滚动条
	CScrollBar m_scrollbar_init_window;//原始CT/PET预览Window滚动条

	CScrollBar m_scrollbar_seg_level;//分割CT/PET预览Level滚动条
	CScrollBar m_scrollbar_seg_window;//分割CT/PET预览Window滚动条
	afx_msg void OnEnChangeEditViewRunstatus();
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnCbnSelendokComboViewImport();//导入

	void Init_CT_PET_VIEW();//原始CT/PET预览处理

	void Seg_CT_PET_VIEW();//分割后CT/PET预览处理
	afx_msg void OnDestroy();
};
