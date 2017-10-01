#pragma once
#include "afxwin.h"
#include "Global.h"

//====================回调函数=============================
class vtkResliceCursorCallback : public vtkCommand
{
public:
  static vtkResliceCursorCallback *New()
  { return new vtkResliceCursorCallback; }

  void Execute( vtkObject *caller, unsigned long /*ev*/,
                void *callData )
    {
		vtkImagePlaneWidget* ipw =
			dynamic_cast< vtkImagePlaneWidget* >( caller );
		if (ipw)
		{
			double* wl = static_cast<double*>( callData );

			if ( ipw == this->IPW[0] )
			{
				this->IPW[1]->SetWindowLevel(wl[0],wl[1],1);
				this->IPW[2]->SetWindowLevel(wl[0],wl[1],1);
			}
			else if( ipw == this->IPW[1] )
			{
				this->IPW[0]->SetWindowLevel(wl[0],wl[1],1);
				this->IPW[2]->SetWindowLevel(wl[0],wl[1],1);
			}
			else if (ipw == this->IPW[2])
			{
				this->IPW[0]->SetWindowLevel(wl[0],wl[1],1);
				this->IPW[1]->SetWindowLevel(wl[0],wl[1],1);
			}
		}

		vtkResliceCursorWidget *rcw = dynamic_cast<
			vtkResliceCursorWidget * >(caller);
		if (rcw)
		{
			vtkResliceCursorLineRepresentation *rep = dynamic_cast<
				vtkResliceCursorLineRepresentation * >(rcw->GetRepresentation());
			vtkResliceCursor *rc = rep->GetResliceCursorActor()->
                  GetCursorAlgorithm()->GetResliceCursor();
			for (int i = 0; i < 3; i++)
			{
				vtkPlaneSource *ps = static_cast< vtkPlaneSource * >(
					this->IPW[i]->GetPolyDataAlgorithm());
				ps->SetNormal(rc->GetPlane(i)->GetNormal());
				ps->SetCenter(rc->GetPlane(i)->GetOrigin());

				// If the reslice plane has modified, update it on the 3D widget
				 this->IPW[i]->UpdatePlacement();
			}
		 }

		// Render everything
		this->RCW[0]->Render();
	}

  vtkResliceCursorCallback() {}
  vtkImagePlaneWidget* IPW[3];
  vtkResliceCursorWidget *RCW[3];
};
//=========================================================


// C2DThreePlaneDlg 对话框

class C2DThreePlaneDlg : public CDialogEx
{
	DECLARE_DYNAMIC(C2DThreePlaneDlg)

public:
	C2DThreePlaneDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~C2DThreePlaneDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_2DThreePlane };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	CString m_strCaption;//对话框标题
	vtkImageData  *ThreePlane_dicm_data;//保存待2D横矢冠切割的dicm体数据

	vtkSmartPointer<vtkOutlineFilter> outline;
	vtkSmartPointer<vtkPolyDataMapper> outlineMapper;
	vtkSmartPointer<vtkActor> outlineActor;

	vtkSmartPointer<vtkRenderer> ren[4];
	vtkSmartPointer<vtkWin32OpenGLRenderWindow> renWin;
	vtkSmartPointer<vtkWin32RenderWindowInteractor> iren;

	vtkSmartPointer<vtkCellPicker> picker;

	vtkSmartPointer<vtkProperty> ipwProp;

	vtkSmartPointer<vtkImagePlaneWidget> planeWidget[3];
	int imageDims[3];

	vtkSmartPointer<vtkResliceCursorCallback> cbk;

	vtkSmartPointer< vtkResliceCursor > resliceCursor;
	vtkSmartPointer< vtkResliceCursorWidget > resliceCursorWidget[3];
	vtkSmartPointer< vtkResliceCursorLineRepresentation > resliceCursorRep[3];

	vtkSmartPointer< vtkInteractorStyleImage > style;

	vtkSmartPointer<vtkTextActor> pTextActor_sagittal;
	vtkSmartPointer<vtkTextActor> pTextActor_coronal;
	vtkSmartPointer<vtkTextActor> pTextActor_transverse;
	vtkSmartPointer<vtkTextActor> pTextActor_3D;

	void ThreePlane(); //2D横矢冠剖面
	afx_msg void OnPaint();
};
