// C2DSegDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ITK+VTK+MFC_GUI.h"
#include "C2DSegDlg.h"
#include "afxdialogex.h"


// C2DSegDlg 对话框

IMPLEMENT_DYNAMIC(C2DSegDlg, CDialogEx)

C2DSegDlg::C2DSegDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C2DSegDlg::IDD, pParent)
{
	//实例化对象
	//TwoDSeg_dicm_data = vtkImageData::New();//保存待2D任意面切割的dicm体数据,不用实例化作为引用

	shiftScale = vtkImageShiftScale::New();

	pMapper = vtkFixedPointVolumeRayCastMapper::New();  //固定点RC
	pColor = vtkColorTransferFunction::New();
	pPiceFun = vtkPiecewiseFunction::New();
	pGradientFun = vtkPiecewiseFunction::New();
	pProperty = vtkVolumeProperty::New();

	volume = vtkVolume::New();

	RC_ren = vtkRenderer::New();
	RC_renWin = vtkWin32OpenGLRenderWindow::New();
	RC_iren = vtkWin32RenderWindowInteractor::New();

	Plane_ren = vtkRenderer::New();
	Plane_renWin = vtkWin32OpenGLRenderWindow::New();
	Plane_iren = vtkWin32RenderWindowInteractor::New();

	pWidget = vtkPlaneWidget::New();
	pPlane = vtkPlane::New();
	pCut = vtkCutter::New();
	selectMapper = vtkPolyDataMapper::New();
	pActor = vtkActor::New(); 
	pCall = vtkWidgetCall::New();
}

C2DSegDlg::~C2DSegDlg()
{
	////销毁对象
	//TwoDSeg_dicm_data->Delete();//保存待2D任意面切割的dicm体数据

	//shiftScale->Delete();

	//pMapper->Delete();  //固定点RC
	//pColor->Delete();
	//pPiceFun->Delete();
	//pGradientFun->Delete();
	//pProperty->Delete();

	//volume->Delete();

	//RC_ren->Delete();
	//renWin->Delete();
	//iren->Delete();
}

void C2DSegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(C2DSegDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// C2DSegDlg 消息处理程序


void C2DSegDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

	if (!RC_iren->GetInitialized())
	{
		RC_renWin->AddRenderer(RC_ren);
		RC_renWin->SetParentId(GetDlgItem(IDC_STATIC_2DSEG_RCVIEW)->m_hWnd); //注意这一步，设置绘制窗口
			
		RC_iren->SetRenderWindow(RC_renWin);
		CRect rect;
		GetDlgItem(IDC_STATIC_2DSEG_RCVIEW)->GetWindowRect(&rect);
		RC_iren->Initialize();
		RC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
		RC_ren->ResetCamera();
	
	}

	if (!Plane_iren->GetInitialized())
	{
		Plane_renWin->AddRenderer(Plane_ren);
		Plane_renWin->SetParentId(GetDlgItem(IDC_STATIC_2DSEG_PlaneVIEW)->m_hWnd); //注意这一步，设置绘制窗口
			
		Plane_iren->SetRenderWindow(Plane_renWin);
		CRect rect;
		GetDlgItem(IDC_STATIC_2DSEG_PlaneVIEW)->GetWindowRect(&rect);
		Plane_iren->Initialize();
		Plane_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
		Plane_ren->ResetCamera();
	
	}
	//调用TwoDSeg()
	TwoDSeg();
	RC_renWin->Render();
	Plane_renWin->Render();
}


//2D任意面实时切割
void C2DSegDlg::TwoDSeg()
{
	 //shift and scale an input image
    double range[2];
	TwoDSeg_dicm_data->GetScalarRange(range);
	shiftScale->SetShift(-1.0*range[0]);
    shiftScale->SetScale(255.0/(range[1]-range[0]));
	shiftScale->SetInputData(TwoDSeg_dicm_data);
	shiftScale->SetOutputScalarTypeToUnsignedChar();
	shiftScale->ReleaseDataFlagOff();
	shiftScale->Update();

	pMapper->SetInputData(TwoDSeg_dicm_data);

	//创建颜色转化函数vtkColorTransferFunction用于将像素的强烈程度转化成不同的颜色
	pColor->AddRGBSegment(0, 1, 1, 1, 255, 1, 1, 1);
	pColor->AddRGBPoint(103,1.0,0.1,0.1);//设置转化的肺颜色

	// The opacity transfer function is used to control the opacity
	// of different tissue（组织） types.
	//创建分段函数设置不同组织的透明度
	pPiceFun->AddSegment(0, 0, 3000, 1);
	pPiceFun->AddPoint(103,1.0); //设置肺的透明度（1.0完全不透明）

	// The gradient(梯度) opacity function is used to decrease the opacity
	// in the "flat" regions of the volume while maintaining the opacity
	// at the boundaries between tissue types.  The gradient is measured
	// as the amount by which the intensity changes over unit distance.
	// For most medical data, the unit distance is 1mm.

	//同上，设置不同坡度的透明度（梯度）
	pGradientFun->AddPoint(0,   0.0);
	pGradientFun->AddPoint(90,  0.5);
	pGradientFun->AddPoint(100, 1.0);

	pMapper->SetBlendModeToMaximumIntensity();

	//创建vtkVolumeProperty将颜色、及透明度联系起来
	pProperty->SetColor(pColor);
	pProperty->SetScalarOpacity(pPiceFun);
	pProperty->SetGradientOpacity(pGradientFun);
	pProperty->SetInterpolationTypeToLinear();//设置插入提数据的插入类型
	pProperty->ShadeOn();//对阴阴暗部分进行计算
	pProperty->SetAmbient(0.3);
	pProperty->SetDiffuse(0.6);
	pProperty->SetSpecular(0.2);
	pProperty->SetSpecularPower(20);

	volume ->SetProperty(pProperty);
	volume ->SetMapper(pMapper);

	//RC_ren->SetViewport(0, 0, .5, 1);
	RC_ren->SetBackground(0.5,0.5,0.5);  
	RC_ren->ResetCameraClippingRange(); 
	RC_ren->AddVolume(volume);

	pWidget->SetInteractor(RC_iren);
	pWidget->SetInputConnection(shiftScale->GetOutputPort());
	pWidget->SetResolution(10);
	pWidget->GetPlaneProperty()->SetColor(.9, .4, .4);
	pWidget->GetHandleProperty()->SetColor(0, .4, .7);
	pWidget->GetHandleProperty()->SetLineWidth(1.5);
	pWidget->NormalToYAxisOn();
	pWidget->SetRepresentationToSurface();
	pWidget->SetCenter(shiftScale->GetOutput()->GetCenter());
	pWidget->PlaceWidget();//You may also wish to invoke "PlaceWidget()" to initially position the widget
 
	pWidget->On();//Turn on the widget

	pPlane->SetOrigin(TwoDSeg_dicm_data->GetCenter());
	pPlane->SetNormal(1, 0, 0);

	pCut->SetCutFunction(pPlane);//Specify the implicit function to perform the cutting.
	pCut->SetInputConnection(shiftScale->GetOutputPort());   
	pCut->Update();

	selectMapper->SetInputConnection(pCut->GetOutputPort());
	pActor->SetMapper(selectMapper);
	//Plane_ren->SetViewport(0.5, 0, 1, 1);
	Plane_ren->SetBackground(.3, .3, .3);
	Plane_ren->AddActor(pActor);

	pCall->pPlane = pPlane; 
	pWidget->AddObserver(vtkCommand::EndInteractionEvent, pCall);
}

void C2DSegDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码

	//销毁对象
	//TwoDSeg_dicm_data->Delete();//保存待2D任意面切割的dicm体数据

	shiftScale->Delete();

	pMapper->Delete();  //固定点RC
	pColor->Delete();
	pPiceFun->Delete();
	pGradientFun->Delete();
	pProperty->Delete();

	volume->Delete();

	RC_ren->Delete();
	RC_renWin->Delete();
	RC_iren->Delete();

	Plane_ren->Delete();
	Plane_renWin->Delete();
	Plane_iren->Delete();

	pWidget->Delete();
	pPlane->Delete();
	pCut->Delete();
	selectMapper->Delete();
	pActor->Delete(); 
	pCall->Delete();
}
