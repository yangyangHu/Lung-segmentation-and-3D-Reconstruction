// C2DThreePlaneDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ITK+VTK+MFC_GUI.h"
#include "C2DThreePlaneDlg.h"
#include "afxdialogex.h"


// C2DThreePlaneDlg 对话框

IMPLEMENT_DYNAMIC(C2DThreePlaneDlg, CDialogEx)

C2DThreePlaneDlg::C2DThreePlaneDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C2DThreePlaneDlg::IDD, pParent)
{
	//实例化对象
	outline = vtkSmartPointer<vtkOutlineFilter>::New();
	outlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	outlineActor = vtkSmartPointer<vtkActor> ::New();

	renWin = vtkSmartPointer<vtkWin32OpenGLRenderWindow>::New();
	for (int i = 0; i < 4; i++)
    {
		ren[i] = vtkSmartPointer<vtkRenderer>::New();
    }

	iren = vtkSmartPointer<vtkWin32RenderWindowInteractor>::New();

	picker = vtkSmartPointer<vtkCellPicker>::New();

	ipwProp = vtkSmartPointer<vtkProperty>::New();

	for (int i = 0; i < 3; i++)
    {
		planeWidget[i] = vtkSmartPointer<vtkImagePlaneWidget>::New();
	}

	cbk = vtkSmartPointer<vtkResliceCursorCallback>::New();

	resliceCursor = vtkSmartPointer< vtkResliceCursor >::New();

	for (int i = 0; i < 3; i++)
    {
		resliceCursorWidget[i] = vtkSmartPointer< vtkResliceCursorWidget >::New();
		resliceCursorRep[i] = vtkSmartPointer< vtkResliceCursorLineRepresentation >::New();
	}

	style = vtkSmartPointer< vtkInteractorStyleImage >::New();

	pTextActor_sagittal = vtkSmartPointer<vtkTextActor>::New();
	pTextActor_coronal = vtkSmartPointer<vtkTextActor>::New();
	pTextActor_transverse = vtkSmartPointer<vtkTextActor>::New();
	pTextActor_3D = vtkSmartPointer<vtkTextActor>::New();
}

C2DThreePlaneDlg::~C2DThreePlaneDlg()
{ 
	//使用了vtkSmartPointer智能指针后就不用显示的销毁对象，否者会中断程序
	//销毁对象
	/*outline->Delete();
	outlineMapper->Delete();
	outlineActor->Delete();

	renWin->Delete();
	for (int i = 0; i < 4; i++)
    {
		ren[i]->Delete();
    }

	iren->Delete();

	picker->Delete();

	ipwProp->Delete();

	for (int i = 0; i < 3; i++)
    {
		planeWidget[i]->Delete();
	}

	cbk->Delete();

	resliceCursor->Delete();

	for (int i = 0; i < 3; i++)
    {
		resliceCursorWidget[i]->Delete();
		resliceCursorRep[i]->Delete();
	}

	style->Delete();*/
}

void C2DThreePlaneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(C2DThreePlaneDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// C2DThreePlaneDlg 消息处理程序


void C2DThreePlaneDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

	if (!iren->GetInitialized())
	{
		for (int i = 0; i < 4; i++)
		{
			renWin->AddRenderer(ren[i]);
		}
		renWin->SetParentId(GetDlgItem(IDC_STATIC_2DThreePlane_VIEW)->m_hWnd); //注意这一步，设置绘制窗口
			
		iren->SetRenderWindow(renWin);
		CRect rect;
		GetDlgItem(IDC_STATIC_2DThreePlane_VIEW)->GetWindowRect(&rect);
		iren->Initialize();
		renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
		iren->SetInteractorStyle(style);
	
	}

	//调用ThreePlane() 
	ThreePlane(); 
	renWin->Render();
}


//2D横矢冠剖面
void C2DThreePlaneDlg::ThreePlane() 
{
	//=============文字显示==========================
	int *winSize;
	winSize = renWin->GetSize();

	pTextActor_sagittal->SetPosition(10, winSize[1]/2-20); //矢状面
	pTextActor_sagittal->SetInput("Sagittal");
	ren[0]->AddActor(pTextActor_sagittal);//文字表现者

	pTextActor_coronal->SetPosition(10, winSize[1]/2-20); //冠状面
	pTextActor_coronal->SetInput("Coronal");
	ren[1]->AddActor(pTextActor_coronal);//文字表现者

	pTextActor_transverse->SetPosition(10, winSize[1]/2-20); //横断面
	pTextActor_transverse->SetInput("Transverse");
	ren[2]->AddActor(pTextActor_transverse);//文字表现者

	pTextActor_3D->SetPosition(10, winSize[1]/2-20); //3D
	pTextActor_3D->SetInput("3D");
	ren[3]->AddActor(pTextActor_3D);//文字表现者
	//====================================================

	//外框
	outline->SetInputData(ThreePlane_dicm_data);
	outlineMapper->SetInputConnection(outline->GetOutputPort());
	outlineActor->SetMapper( outlineMapper);

	renWin->SetMultiSamples(0);

	picker->SetTolerance(0.005);

	//assign default props to the ipw's texture plane actor
	ThreePlane_dicm_data->GetDimensions(imageDims);

	for (int i = 0; i < 3; i++)
    {
		planeWidget[i]->SetInteractor( iren );
		planeWidget[i]->SetPicker(picker);
		planeWidget[i]->RestrictPlaneToVolumeOn();
		double color[3] = {0, 0, 0};
		color[i] = 1;
		planeWidget[i]->GetPlaneProperty()->SetColor(color);
		planeWidget[i]->SetTexturePlaneProperty(ipwProp);
		planeWidget[i]->TextureInterpolateOff();
		planeWidget[i]->SetResliceInterpolateToLinear();
		planeWidget[i]->SetInputData(ThreePlane_dicm_data);
		//Convenience method sets the plane orientation normal to the x, y, or z axes. Default is XAxes (0).
		planeWidget[i]->SetPlaneOrientation(i);
		//Set the slice position in terms of the data extent.
		planeWidget[i]->SetSliceIndex(imageDims[i]/2);
		//Enable/disable text display of window-level, image coordinates and scalar values in a render window.
		planeWidget[i]->DisplayTextOn();
		planeWidget[i]->SetDefaultRenderer(ren[3]);
		planeWidget[i]->SetWindowLevel(1358, -27);
		planeWidget[i]->On();
		planeWidget[i]->InteractionOn();
    }

	//Set/Get the internal lookuptable (lut) to one defined by the user, or, alternatively, 
	//to the lut of another vtkImgePlaneWidget. In this way, a set of three orthogonal planes can share the same lut so that window-levelling is performed uniformly among planes.
	//The default internal lut can be re- set/allocated by setting to 0 (NULL).
	planeWidget[1]->SetLookupTable(planeWidget[0]->GetLookupTable());
	planeWidget[2]->SetLookupTable(planeWidget[0]->GetLookupTable());

	// Create the reslice cursor, widget and rep

	resliceCursor->SetCenter(ThreePlane_dicm_data->GetCenter());
	resliceCursor->SetThickMode(0);
	resliceCursor->SetThickness(10, 10, 10);
	resliceCursor->SetImage(ThreePlane_dicm_data);

	for (int i = 0; i < 3; i++)
    {
		resliceCursorWidget[i]->SetInteractor(iren);

		resliceCursorWidget[i]->SetRepresentation(resliceCursorRep[i]);
		resliceCursorRep[i]->GetResliceCursorActor()->
			GetCursorAlgorithm()->SetResliceCursor(resliceCursor);
		resliceCursorRep[i]->GetResliceCursorActor()->
			GetCursorAlgorithm()->SetReslicePlaneNormal(i);

		const double minVal = ThreePlane_dicm_data->GetScalarRange()[0];
		if (vtkImageReslice *reslice =
				vtkImageReslice::SafeDownCast(resliceCursorRep[i]->GetReslice()))
		{
			reslice->SetBackgroundColor(minVal,minVal,minVal,minVal);
		}

		resliceCursorWidget[i]->SetDefaultRenderer(ren[i]);
		resliceCursorWidget[i]->SetEnabled(1);

		ren[i]->GetActiveCamera()->SetFocalPoint(0,0,0);
		double camPos[3] = {0,0,0};
		camPos[i] = 1;
		ren[i]->GetActiveCamera()->SetPosition(camPos);

		ren[i]->GetActiveCamera()->ParallelProjectionOn();
		ren[i]->ResetCamera();
		//ren[i]->ResetCameraClippingRange();

		// Tie the Image plane widget and the reslice cursor widget together
		cbk->IPW[i] = planeWidget[i];
		cbk->RCW[i] = resliceCursorWidget[i];
		resliceCursorWidget[i]->AddObserver(
				vtkResliceCursorWidget::ResliceAxesChangedEvent, cbk );

		// Initialize the window level to a sensible value
		double range[2];
		ThreePlane_dicm_data->GetScalarRange(range);
		resliceCursorRep[i]->SetWindowLevel(range[1]-range[0], (range[0]+range[1])/2.0);
		planeWidget[i]->SetWindowLevel(range[1]-range[0], (range[0]+range[1])/2.0);

		// Make them all share the same color map.
		resliceCursorRep[i]->SetLookupTable(resliceCursorRep[0]->GetLookupTable());
		planeWidget[i]->GetColorMap()->SetLookupTable(resliceCursorRep[0]->GetLookupTable());
    }

	// Add the actors
	//
	ren[0]->SetBackground( 0.3, 0.1, 0.1 );
	ren[1]->SetBackground( 0.1, 0.3, 0.1 );
	ren[2]->SetBackground( 0.1, 0.1, 0.3 );
	ren[3]->AddActor( outlineActor );
	ren[3]->SetBackground( 0.1, 0.1, 0.1 );

	ren[0]->GetActiveCamera()->SetViewUp( 0, 0, -1 );
	ren[1]->GetActiveCamera()->SetViewUp( 0, 0, 1 );
	ren[2]->GetActiveCamera()->SetViewUp( 0, 1, 0 );

	ren[0]->SetViewport(0,0,0.5,0.5);
	ren[1]->SetViewport(0.5,0,1,0.5);
	ren[2]->SetViewport(0,0.5,0.5,1);
	ren[3]->SetViewport(0.5,0.5,1,1);

	// Set the actors' postions
	 //

	ren[3]->GetActiveCamera()->Elevation(110);
	ren[3]->GetActiveCamera()->SetViewUp(0, 0, -1);
	ren[3]->GetActiveCamera()->Azimuth(45);
	ren[3]->GetActiveCamera()->Dolly(1.15);
	ren[3]->ResetCameraClippingRange();
}