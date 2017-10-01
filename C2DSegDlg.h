#pragma once
#include "afxwin.h"
#include "Global.h"


//=============回调函数=========================================================
class vtkWidgetCall : public vtkCommand
{
public:

 static vtkWidgetCall *New()
 {
	return new vtkWidgetCall;
 }
public:
 virtual void Execute(vtkObject *caller, unsigned long eventId, void *callData)
 {
	vtkPlaneWidget *pWidget = vtkPlaneWidget::SafeDownCast(caller);
	pWidget->GetPlane(pPlane);// GetPlane() can be used to update a vtkPlane implicit function.
 }
public:
 vtkPlane *pPlane ;
 
};
//=======================================================================================

// C2DSegDlg 对话框

class C2DSegDlg : public CDialogEx
{
	DECLARE_DYNAMIC(C2DSegDlg)

public:
	C2DSegDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~C2DSegDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_2DSeg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	CString m_strCaption;//对话框标题
	vtkImageData  *TwoDSeg_dicm_data;//保存待2D任意面切割的dicm体数据

	vtkImageShiftScale *shiftScale;

	vtkFixedPointVolumeRayCastMapper *pMapper;  //固定点RC
	vtkColorTransferFunction* pColor;
	vtkPiecewiseFunction* pPiceFun;
	vtkPiecewiseFunction* pGradientFun;
	vtkVolumeProperty* pProperty;

	vtkVolume *volume;

	vtkRenderer *RC_ren;
	vtkWin32OpenGLRenderWindow *RC_renWin;
	vtkWin32RenderWindowInteractor *RC_iren;

	vtkRenderer *Plane_ren;
	vtkWin32OpenGLRenderWindow *Plane_renWin;
	vtkWin32RenderWindowInteractor *Plane_iren;

	vtkPlaneWidget *pWidget;
	vtkPlane *pPlane;
	vtkCutter *pCut;
	vtkPolyDataMapper *selectMapper;
	vtkActor *pActor; 
	vtkWidgetCall *pCall;

	afx_msg void OnPaint();

	void TwoDSeg(); //2D任意面实时切割
	afx_msg void OnDestroy();
};