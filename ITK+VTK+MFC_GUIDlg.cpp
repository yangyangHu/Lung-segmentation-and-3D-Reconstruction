
// ITK+VTK+MFC_GUIDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ITK+VTK+MFC_GUI.h"
#include "ITK+VTK+MFC_GUIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CITKVTKMFC_GUIDlg 对话框




CITKVTKMFC_GUIDlg::CITKVTKMFC_GUIDlg(CWnd* pParent /*=NULL*/)//构造函数
	: CDialogEx(CITKVTKMFC_GUIDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//实例化对象
	//CTRebuild_dicm_data = vtkImageData::New();
	CTRebuild_dicm_data = (DicmDataNode *)malloc(sizeof(DicmDataNode));
	CTRebuild_dicm_data->data = vtkImageData::New();
	CTRebuild_dicm_data->next = NULL;
	CTRebuild_dicm_data->dataStyle = -1;

	PETRebuild_dicm_data = (DicmDataNode *)malloc(sizeof(DicmDataNode));
	PETRebuild_dicm_data->data = vtkImageData::New();
	PETRebuild_dicm_data->next = NULL;
	PETRebuild_dicm_data->dataStyle = -1;

	 //历史数据头结点初始化
	head = (DicmDataNode *)malloc(sizeof(DicmDataNode));
	head->next = NULL;
	dataList = head;
	rear = head;

	//==============CT面绘制成员实例化======================
	CT_lungExtractor = vtkMarchingCubes::New();
	CT_lungDeci = vtkDecimatePro::New();
	CT_lungSmooth = vtkSmoothPolyDataFilter::New();
	CT_lungNormals = vtkPolyDataNormals::New();
	CT_lungStripper = vtkStripper::New();
	CT_lung_surface_Mapper = vtkPolyDataMapper::New();
	CT_lung_surface_actor = vtkActor::New();

	CT_interExtractor = vtkMarchingCubes::New();
	CT_interDeci = vtkDecimatePro::New();
	CT_interSmooth = vtkSmoothPolyDataFilter::New();
	CT_interNormals = vtkPolyDataNormals::New();
	CT_interStripper = vtkStripper::New();
	CT_inter_surface_Mapper = vtkPolyDataMapper::New();
	CT_inter_surface_actor = vtkActor::New();

	CT_shrink = vtkImageShrink3D::New();

	CT_MC_ren = vtkRenderer::New();
	CT_MC_renWin = vtkWin32OpenGLRenderWindow::New();
	CT_MC_iren = vtkWin32RenderWindowInteractor::New();
	//======================================================

	//==============PET面绘制成员实例化======================
	PET_lungExtractor = vtkMarchingCubes::New();
	PET_lungDeci = vtkDecimatePro::New();
	PET_lungSmooth = vtkSmoothPolyDataFilter::New();
	PET_lungNormals = vtkPolyDataNormals::New();
	PET_lungStripper = vtkStripper::New();
	PET_lung_surface_Mapper = vtkPolyDataMapper::New();
	PET_lung_surface_actor = vtkActor::New();

	PET_interExtractor = vtkMarchingCubes::New();
	PET_interDeci = vtkDecimatePro::New();
	PET_interSmooth = vtkSmoothPolyDataFilter::New();
	PET_interNormals = vtkPolyDataNormals::New();
	PET_interStripper = vtkStripper::New();
	PET_inter_surface_Mapper = vtkPolyDataMapper::New();
	PET_inter_surface_actor = vtkActor::New();

	PET_shrink = vtkImageShrink3D::New();

	PET_MC_ren = vtkRenderer::New();
	PET_MC_renWin = vtkWin32OpenGLRenderWindow::New();
	PET_MC_iren = vtkWin32RenderWindowInteractor::New();
	//======================================================

	//================CT体绘制成员实例化====================
	CT_shiftScale = vtkImageShiftScale::New();

	CT_rayCastFunction = vtkVolumeRayCastCompositeFunction::New();
	CT_volumeMapper = vtkVolumeRayCastMapper::New();
	CT_volumeColor = vtkColorTransferFunction::New();
	CT_volumeScalarOpacity = vtkPiecewiseFunction::New();
	CT_volumeGradientOpacity = vtkPiecewiseFunction::New();
	CT_volumeProperty = vtkVolumeProperty::New();

	CT_pMapper = vtkFixedPointVolumeRayCastMapper::New();  //固定点RC
	CT_pColor = vtkColorTransferFunction::New();
	CT_pPiceFun = vtkPiecewiseFunction::New();
	CT_pGradientFun = vtkPiecewiseFunction::New();
	CT_pProperty = vtkVolumeProperty::New();

	CT_volume = vtkVolume::New();

	CT_RC_ren = vtkRenderer::New();
	CT_RC_renWin = vtkWin32OpenGLRenderWindow::New();
	CT_RC_iren = vtkWin32RenderWindowInteractor::New();
	//======================================================

	//================PET体绘制成员实例化====================
	PET_shiftScale = vtkImageShiftScale::New();

	PET_rayCastFunction = vtkVolumeRayCastCompositeFunction::New();
	PET_volumeMapper = vtkVolumeRayCastMapper::New();
	PET_volumeColor = vtkColorTransferFunction::New();
	PET_volumeScalarOpacity = vtkPiecewiseFunction::New();
	PET_volumeGradientOpacity = vtkPiecewiseFunction::New();
	PET_volumeProperty = vtkVolumeProperty::New();

	PET_pMapper = vtkFixedPointVolumeRayCastMapper::New();  //固定点RC
	PET_pColor = vtkColorTransferFunction::New();
	PET_pPiceFun = vtkPiecewiseFunction::New();
	PET_pGradientFun = vtkPiecewiseFunction::New();
	PET_pProperty = vtkVolumeProperty::New();

	PET_volume = vtkVolume::New();

	PET_RC_ren = vtkRenderer::New();
	PET_RC_renWin = vtkWin32OpenGLRenderWindow::New();
	PET_RC_iren = vtkWin32RenderWindowInteractor::New();
	//======================================================

	//===========CT面绘制属性对话框=========================
	CTMC_Style = MC;//默认情况下是MC

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
	CTMC_SpecularPower_pos = 20;
	//======================================================

	//===========PET面绘制属性对话框=========================
	PETMC_Style = MC;//默认情况下是MC

	PETMC_LungCT_pos = 3;
	PETMC_LungSmooth_pos = 500;
	PETMC_LungR_pos = 100;
	PETMC_LungG_pos = 19;
	PETMC_LungB_pos = 15;
	PETMC_LungOpacity_pos = 100;

	PETMC_InterCT_pos = 170;
	PETMC_InterSmooth_pos = 100;
	PETMC_InterR_pos = 100;
	PETMC_InterG_pos = 19;
	PETMC_InterB_pos = 15;
	PETMC_InterOpacity_pos = 100;

	PETMC_Ambient_pos = 30;
	PETMC_Diffuse_pos = 60;
	PETMC_Specular_pos = 20;
	PETMC_SpecularPower_pos = 20;
	//======================================================

	//===========CT体绘制属性对话框=========================
	CTRC_Style = RC;//默认情况下是RC

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
	CTRC_SpecularPower_pos = 20;

	//======================================================

	//===========PET体绘制属性对话框=========================
	PETRC_Style = RC;//默认情况下是RC

	PETRC_LungCT_pos = 4;
	PETRC_LungR_pos = 100;
	PETRC_LungG_pos = 19;
	PETRC_LungB_pos = 15;
	PETRC_LungOpacity_pos = 100;

	PETRC_InterCT_pos = 200;
	PETRC_InterR_pos = 100;
	PETRC_InterG_pos = 19;
	PETRC_InterB_pos = 15;
	PETRC_InterOpacity_pos = 100;

	PETRC_Ambient_pos = 30;
	PETRC_Diffuse_pos = 60;
	PETRC_Specular_pos = 20;
	PETRC_SpecularPower_pos = 20;

	//======================================================

	//=======CT面绘制属性对话框成员变量初始化===============
	CTMCPropDlg.CTMC_Style = MC;//默认情况下是MC

	CTMCPropDlg.CTMC_LungCT_pos = 103;
	CTMCPropDlg.CTMC_LungSmooth_pos = 500;
	CTMCPropDlg.CTMC_LungR_pos = 100;
	CTMCPropDlg.CTMC_LungG_pos = 19;
	CTMCPropDlg.CTMC_LungB_pos = 15;
	CTMCPropDlg.CTMC_LungOpacity_pos = 100;

	CTMCPropDlg.CTMC_InterCT_pos = 160;
	CTMCPropDlg.CTMC_InterSmooth_pos = 100;
	CTMCPropDlg.CTMC_InterR_pos = 100;
	CTMCPropDlg.CTMC_InterG_pos = 19;
	CTMCPropDlg.CTMC_InterB_pos = 15;
	CTMCPropDlg.CTMC_InterOpacity_pos = 100;

	CTMCPropDlg.CTMC_Ambient_pos = 30;
	CTMCPropDlg.CTMC_Diffuse_pos = 60;
	CTMCPropDlg.CTMC_Specular_pos = 20;
	CTMCPropDlg.CTMC_SpecularPower_pos = 20;
	//======================================================

	//=======PET面绘制属性对话框成员变量初始化===============
	PETMCPropDlg.CTMC_Style = MC;//默认情况下是MC

	PETMCPropDlg.CTMC_LungCT_pos = 3;
	PETMCPropDlg.CTMC_LungSmooth_pos = 500;
	PETMCPropDlg.CTMC_LungR_pos = 100;
	PETMCPropDlg.CTMC_LungG_pos = 19;
	PETMCPropDlg.CTMC_LungB_pos = 15;
	PETMCPropDlg.CTMC_LungOpacity_pos = 100;

	PETMCPropDlg.CTMC_InterCT_pos = 170;
	PETMCPropDlg.CTMC_InterSmooth_pos = 100;
	PETMCPropDlg.CTMC_InterR_pos = 100;
	PETMCPropDlg.CTMC_InterG_pos = 19;
	PETMCPropDlg.CTMC_InterB_pos = 15;
	PETMCPropDlg.CTMC_InterOpacity_pos = 100;

	PETMCPropDlg.CTMC_Ambient_pos = 30;
	PETMCPropDlg.CTMC_Diffuse_pos = 60;
	PETMCPropDlg.CTMC_Specular_pos = 20;
	PETMCPropDlg.CTMC_SpecularPower_pos = 20;
	//======================================================

	//=======CT体绘制属性对话框成员变量初始化===============
	CTRCPropDlg.CTRC_Style = RC;//默认情况下是RC

	CTRCPropDlg.CTRC_LungCT_pos = 140;
	CTRCPropDlg.CTRC_LungR_pos = 100;
	CTRCPropDlg.CTRC_LungG_pos = 19;
	CTRCPropDlg.CTRC_LungB_pos = 15;
	CTRCPropDlg.CTRC_LungOpacity_pos = 100;

	CTRCPropDlg.CTRC_InterCT_pos = 170;
	CTRCPropDlg.CTRC_InterR_pos = 100;
	CTRCPropDlg.CTRC_InterG_pos = 19;
	CTRCPropDlg.CTRC_InterB_pos = 15;
	CTRCPropDlg.CTRC_InterOpacity_pos = 100;

	CTRCPropDlg.CTRC_Ambient_pos = 30;
	CTRCPropDlg.CTRC_Diffuse_pos = 60;
	CTRCPropDlg.CTRC_Specular_pos = 20;
	CTRCPropDlg.CTRC_SpecularPower_pos = 20;
	//======================================================

	//=======PET体绘制属性对话框成员变量初始化===============
	PETRCPropDlg.CTRC_Style = RC;//默认情况下是RC

	PETRCPropDlg.CTRC_LungCT_pos = 4;
	PETRCPropDlg.CTRC_LungR_pos = 100;
	PETRCPropDlg.CTRC_LungG_pos = 19;
	PETRCPropDlg.CTRC_LungB_pos = 15;
	PETRCPropDlg.CTRC_LungOpacity_pos = 100;

	PETRCPropDlg.CTRC_InterCT_pos = 200;
	PETRCPropDlg.CTRC_InterR_pos = 100;
	PETRCPropDlg.CTRC_InterG_pos = 19;
	PETRCPropDlg.CTRC_InterB_pos = 15;
	PETRCPropDlg.CTRC_InterOpacity_pos = 100;

	PETRCPropDlg.CTRC_Ambient_pos = 30;
	PETRCPropDlg.CTRC_Diffuse_pos = 60;
	PETRCPropDlg.CTRC_Specular_pos = 20;
	PETRCPropDlg.CTRC_SpecularPower_pos = 20;
	//======================================================

	//==================CTMC 3D任意面切割成员实例化==============
	CTMC3DSeg_rep = vtkImplicitPlaneRepresentation::New();
	CTMC3DSeg_implicitPlaneWidget = vtkImplicitPlaneWidget2::New();
	CTMC3DSeg_planeNew = vtkPlane::New();
	CTMC3DSeg_cliper = vtkClipPolyData::New();
	CTMC3DSeg_clipedData = vtkPolyData::New();
	CTMC3DSeg_pCall = VTKWidgetCallCTMC3DSeg::New();

	CTMC3DSegInter_cliper = vtkClipPolyData::New();
	CTMC3DSegInter_clipedData = vtkPolyData::New();

	CTMC3DSeg_CheckButtonStatus = CTMC3DSEG_UNCHECK;//CTMC 3D任意面切割复选框选中状态初始未选中

	CTMC3DSeg_YesOrNoMC = NO;//CTMC面绘制是否重建初始状态为未三维重建

	CTRC3DSeg_YesOrNoRC = NO;//CTRC体绘制是否重建初始状态为未三维重建

	//=====================================================

	//==============CT面绘制直线测量成员实例化=====================
	CTMCLine_CheckButtonStatus = NO;//CT面绘制直线测量复选框选中状态初始未选中
	CTMCLine_rep = vtkDistanceRepresentation3D::New();
	CTMCLine_distanceWidget = vtkDistanceWidget::New();
	//=====================================================

	//==============CT体绘制直线测量成员实例化=====================
	CTRCLine_CheckButtonStatus = NO;//CT体绘制直线测量复选框选中状态初始未选中
	CTRCLine_rep = vtkDistanceRepresentation3D::New();
	CTRCLine_distanceWidget = vtkDistanceWidget::New();
	//=====================================================

	//==================CT面绘制角度测量成员实例化===============
	CTMCAngle_CheckButtonStatus = NO;//CT面绘制角度测量复选框选中状态初始未选中
	CTMCAngle_rep = vtkAngleRepresentation3D::New();
	CTMCAngle_angleWidget = vtkAngleWidget::New();
	//=====================================================

	//==================CT体绘制角度测量成员实例化===============
	CTRCAngle_CheckButtonStatus = NO;//CT体绘制角度测量复选框选中状态初始未选中
	CTRCAngle_rep = vtkAngleRepresentation3D::New();
	CTRCAngle_angleWidget = vtkAngleWidget::New();
	//=====================================================

}

void CITKVTKMFC_GUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_Import, m_comboImport);
	DDX_Control(pDX, IDC_COMBO_3DRebuild, m_combo3DRebuild);
	DDX_Control(pDX, IDC_COMBO_Property, m_comboProperty);
	DDX_Control(pDX, IDC_COMBO_Help, m_comboHelp);
	DDX_Control(pDX, IDC_COMBO_Previous, m_comboPrevious);
	DDX_Control(pDX, IDC_CHECK_3DCTMCSeg, m_check_3DCTMCSeg);
	DDX_Control(pDX, IDC_CHECK_3DCTMCSeg_Hide, m_check_3DCTMCSeg_Hide);
	DDX_Control(pDX, IDC_CHECK_CTMC_Line, m_check_CTMC_Line);
	DDX_Control(pDX, IDC_CHECK_CTRC_Line, m_check_CTRC_Line);
	DDX_Control(pDX, IDC_CHECK_CTMC_Angle, m_check_CTMC_Angle);
	DDX_Control(pDX, IDC_CHECK_CTRC_Angle, m_check_CTRC_Angle);
}

BEGIN_MESSAGE_MAP(CITKVTKMFC_GUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_CBN_SELENDOK(IDC_COMBO_Import, &CITKVTKMFC_GUIDlg::OnCbnSelendokComboImport)
	ON_CBN_SELENDOK(IDC_COMBO_3DRebuild, &CITKVTKMFC_GUIDlg::OnCbnSelendokCombo3drebuild)
	ON_CBN_SELENDOK(IDC_COMBO_Property, &CITKVTKMFC_GUIDlg::OnCbnSelendokComboProperty)
	ON_CBN_SELENDOK(IDC_COMBO_Previous, &CITKVTKMFC_GUIDlg::OnCbnSelendokComboPrevious)
	ON_BN_CLICKED(IDC_RADIO_2DSeg, &CITKVTKMFC_GUIDlg::OnBnClickedRadio2dseg)
	ON_BN_CLICKED(IDC_RADIO_2DThreePlane, &CITKVTKMFC_GUIDlg::OnBnClickedRadio2dthreeplane)
	ON_BN_CLICKED(IDC_RADIO_VolumeSliceView, &CITKVTKMFC_GUIDlg::OnBnClickedRadioVolumesliceview)
	ON_BN_CLICKED(IDC_CHECK_3DCTMCSeg, &CITKVTKMFC_GUIDlg::OnBnClickedCheck3dctmcseg)
	ON_BN_CLICKED(IDC_CHECK_3DCTMCSeg_Hide, &CITKVTKMFC_GUIDlg::OnBnClickedCheck3dctmcsegHide)
	ON_BN_CLICKED(IDC_CHECK_CTMC_Line, &CITKVTKMFC_GUIDlg::OnBnClickedCheckCtmcLine)
	ON_BN_CLICKED(IDC_CHECK_CTRC_Line, &CITKVTKMFC_GUIDlg::OnBnClickedCheckCtrcLine)
	ON_BN_CLICKED(IDC_CHECK_CTMC_Angle, &CITKVTKMFC_GUIDlg::OnBnClickedCheckCtmcAngle)
	ON_BN_CLICKED(IDC_CHECK_CTRC_Angle, &CITKVTKMFC_GUIDlg::OnBnClickedCheckCtrcAngle)
	ON_BN_CLICKED(IDC_BUTTON_Seg, &CITKVTKMFC_GUIDlg::OnBnClickedButtonSeg)
	ON_CBN_SELENDOK(IDC_COMBO_Help, &CITKVTKMFC_GUIDlg::OnCbnSelendokComboHelp)
END_MESSAGE_MAP()


// CITKVTKMFC_GUIDlg 消息处理程序

BOOL CITKVTKMFC_GUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	// 为导入组合框控件的列表框添加列表项  
   /* m_comboImport.AddString(_T("一个待分割的CT文件夹"));     
    m_comboImport.AddString(_T("一个待分割的PET文件夹")); */
	m_comboImport.AddString(_T("一个待重建的CT文件夹"));
	m_comboImport.AddString(_T("一个待重建的PET文件夹")); 
    // 默认选择第一项   
    m_comboImport.SetCurSel(0);  

	// 为3D重建组合框控件的列表框添加列表项  
    m_combo3DRebuild.AddString(_T("CT面绘制"));     
    m_combo3DRebuild.AddString(_T("PET面绘制")); 
	m_combo3DRebuild.AddString(_T("CT体绘制"));
	m_combo3DRebuild.AddString(_T("PET体绘制")); 
    // 默认选择第一项   
    m_combo3DRebuild.SetCurSel(0);  

	// 为属性组合框控件的列表框添加列表项  
    m_comboProperty.AddString(_T("CT面绘制"));     
    m_comboProperty.AddString(_T("PET面绘制")); 
	m_comboProperty.AddString(_T("CT体绘制"));
	m_comboProperty.AddString(_T("PET体绘制")); 
    // 默认选择第一项   
    m_comboProperty.SetCurSel(0);  

	// 为帮助组合框控件的列表框添加列表项  
    m_comboHelp.AddString(_T("手册"));     
    m_comboHelp.AddString(_T("关于")); 
    // 默认选择第一项   
    m_comboHelp.SetCurSel(0);  

	m_check_3DCTMCSeg_Hide.EnableWindow(FALSE);//CTMC 3D任意面切割切面隐藏复选框禁止使用

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CITKVTKMFC_GUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CITKVTKMFC_GUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CITKVTKMFC_GUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CITKVTKMFC_GUIDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码

	//销毁对象
	//CTRebuild_dicm_data->Delete();
	free(CTRebuild_dicm_data);
	free(PETRebuild_dicm_data);

	//==========CT面绘制销毁对象===================
	CT_lungExtractor->Delete();
	CT_lungDeci->Delete();
	CT_lungSmooth->Delete();
	CT_lungNormals->Delete();
	CT_lungStripper->Delete();
	CT_lung_surface_Mapper->Delete();
	CT_lung_surface_actor->Delete();

	CT_interExtractor->Delete();
	CT_interDeci->Delete();
	CT_interSmooth->Delete();
	CT_interNormals->Delete();
	CT_interStripper->Delete();
	CT_inter_surface_Mapper->Delete();
	CT_inter_surface_actor->Delete();

	CT_shrink->Delete();


	CT_MC_ren->Delete();
	CT_MC_renWin->Delete();
	CT_MC_iren->Delete();
	//=============================================

	//==========PET面绘制销毁对象===================
	PET_lungExtractor->Delete();
	PET_lungDeci->Delete();
	PET_lungSmooth->Delete();
	PET_lungNormals->Delete();
	PET_lungStripper->Delete();
	PET_lung_surface_Mapper->Delete();
	PET_lung_surface_actor->Delete();

	PET_interExtractor->Delete();
	PET_interDeci->Delete();
	PET_interSmooth->Delete();
	PET_interNormals->Delete();
	PET_interStripper->Delete();
	PET_inter_surface_Mapper->Delete();
	PET_inter_surface_actor->Delete();

	PET_shrink->Delete();


	PET_MC_ren->Delete();
	PET_MC_renWin->Delete();
	PET_MC_iren->Delete();
	//=============================================

	//=============CT体绘制销毁对象================
	CT_shiftScale->Delete();

	CT_rayCastFunction->Delete();
	CT_volumeMapper->Delete();
	CT_volumeColor->Delete();
	CT_volumeScalarOpacity->Delete();
	CT_volumeGradientOpacity->Delete();
	CT_volumeProperty->Delete();

	CT_pMapper->Delete();  //固定点RC
	CT_pColor->Delete();
	CT_pPiceFun->Delete();
	CT_pGradientFun->Delete();
	CT_pProperty->Delete();

	CT_volume->Delete();

	CT_RC_ren->Delete();
	CT_RC_renWin->Delete();
	CT_RC_iren->Delete();
	//=============================================

	//=============PET体绘制销毁对象================
	PET_shiftScale->Delete();

	PET_rayCastFunction->Delete();
	PET_volumeMapper->Delete();
	PET_volumeColor->Delete();
	PET_volumeScalarOpacity->Delete();
	PET_volumeGradientOpacity->Delete();
	PET_volumeProperty->Delete();

	PET_pMapper->Delete();  //固定点RC
	PET_pColor->Delete();
	PET_pPiceFun->Delete();
	PET_pGradientFun->Delete();
	PET_pProperty->Delete();

	PET_volume->Delete();

	PET_RC_ren->Delete();
	PET_RC_renWin->Delete();
	PET_RC_iren->Delete();
	//=============================================

	delete CTMCPropDlg;
	delete CTRCPropDlg;

	delete PETMCPropDlg;
	delete PETRCPropDlg;

	//=============释放历史数据链表================
	DicmDataNode *temp,*temp1;//移动指针
	temp = dataList;
	while(temp!=NULL)
	{
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}
	//=============================================

	//==================CTMC 3D任意面切割销毁对象==============
	CTMC3DSeg_rep->Delete();
	CTMC3DSeg_implicitPlaneWidget->Delete();
	CTMC3DSeg_planeNew->Delete();
	CTMC3DSeg_cliper->Delete();
	CTMC3DSeg_clipedData->Delete();
	CTMC3DSeg_pCall->Delete();

	CTMC3DSegInter_cliper->Delete();
	CTMC3DSegInter_clipedData->Delete();

	//=====================================================

	//==============CT面绘制直线测量销毁对象=====================
	CTMCLine_rep->Delete();
	CTMCLine_distanceWidget->Delete();
	//=====================================================

	//==============CT体绘制直线测量销毁对象=====================
	CTRCLine_rep->Delete();
	CTRCLine_distanceWidget->Delete();
	//=====================================================

	//==================CT面绘制角度测量销毁对象===============
	CTMCAngle_rep->Delete();
	CTMCAngle_angleWidget->Delete();
	//=====================================================

	//==================CT体绘制角度测量销毁对象===============
	CTRCAngle_rep->Delete();
	CTRCAngle_angleWidget->Delete();
	//=====================================================

}


//导入组合框选中选项事件
void CITKVTKMFC_GUIDlg::OnCbnSelendokComboImport()
{
	// TODO: 在此添加控件通知处理程序代码

	CString strImport;   
    int nSel;   
  
    // 获取组合框控件的列表框中选中项的索引   
    nSel = m_comboImport.GetCurSel();   
    // 根据选中项索引获取该项字符串   
    m_comboImport.GetLBText(nSel, strImport);   
	strImport +=_T("正在导入...");
	SetDlgItemText(IDC_EDIT_RunStatus, strImport);
	//if(nSel == 0) //导入一个待分割的CT文件夹
	//{
	//	//拓展功能
	//}
	//else if(nSel == 1)//导入一个待分割的PET文件夹
	//{
	//	//拓展功能
	//}
	if(nSel == 0)//导入一个待重建的CT文件夹
	{
		//拓展功能
		BROWSEINFO bi;
		char chDir[MAX_PATH] = {0};
		memset((char *)&bi, 0, sizeof(bi));
		bi.hwndOwner = this->m_hWnd;
		bi.lpszTitle = "选择一个待重建的CT文件夹";

		bi.ulFlags = BIF_BROWSEFORCOMPUTER | BIF_RETURNONLYFSDIRS;	
			ITEMIDLIST *pList = NULL;
		pList = SHBrowseForFolder(&bi);

		if (pList == NULL)
		{
			return;		
		}
		SHGetPathFromIDList(pList, chDir);
		vtkDICOMImageReader *pRead = vtkDICOMImageReader::New();
		pRead->SetDirectoryName(chDir);
		pRead->SetDataByteOrderToLittleEndian();
		
		pRead->Update();

		if (pRead->GetDataExtent()[5] == -1)
		{
			MessageBox("读取出错");
			return;
		}
	
		CTRebuild_dicm_data->data = pRead->GetOutput();	
		CTRebuild_dicm_data->dataStyle = REBUILD_CT;

		SetDlgItemText(IDC_EDIT_RunStatus, _T("导入成功！"));

		//把导入的dicm数据添加到历史数据组合框中
		m_comboPrevious.AddString(_T(chDir));     
		// 默认选择第一项   
		m_comboPrevious.SetCurSel(0);  

		//把导入的体数据添加到历史数据链表的表尾
		DicmDataNode *p;//开辟新节点指针
		p = (DicmDataNode *)malloc(sizeof(DicmDataNode));
		p->data = CTRebuild_dicm_data->data;
		p->dataStyle = REBUILD_CT;
		p->next = NULL;
		rear->next = p;
		rear = p;
	}
	else if(nSel == 1)//导入一个待重建的PET文件夹
	{
		//拓展功能
		BROWSEINFO bi;
		char chDir[MAX_PATH] = {0};
		memset((char *)&bi, 0, sizeof(bi));
		bi.hwndOwner = this->m_hWnd;
		bi.lpszTitle = "选择一个待重建的PET文件夹";

		bi.ulFlags = BIF_BROWSEFORCOMPUTER | BIF_RETURNONLYFSDIRS;	
		ITEMIDLIST *pList = NULL;
		pList = SHBrowseForFolder(&bi);

		if (pList == NULL)
		{
			return;		
		}
		SHGetPathFromIDList(pList, chDir);
		vtkDICOMImageReader *pRead = vtkDICOMImageReader::New();
		pRead->SetDirectoryName(chDir);
		pRead->SetDataByteOrderToLittleEndian();
		
		pRead->Update();

		if (pRead->GetDataExtent()[5] == -1)
		{
			MessageBox("读取出错");
			return;
		}
	
		PETRebuild_dicm_data->data = pRead->GetOutput();	
		PETRebuild_dicm_data->dataStyle = REBUILD_PET;

		SetDlgItemText(IDC_EDIT_RunStatus, _T("导入成功！"));

		//把导入的dicm数据添加到历史数据组合框中
		m_comboPrevious.AddString(_T(chDir));     
		// 默认选择第一项   
		m_comboPrevious.SetCurSel(0);  

		//把导入的体数据添加到历史数据链表的表尾
		DicmDataNode *p;//开辟新节点指针
		p = (DicmDataNode *)malloc(sizeof(DicmDataNode));
		p->data = PETRebuild_dicm_data->data;
		p->dataStyle = REBUILD_PET;
		p->next = NULL;
		rear->next = p;
		rear = p;
	}
}


//3D重建组合框选中选项事件
void CITKVTKMFC_GUIDlg::OnCbnSelendokCombo3drebuild()
{
	// TODO: 在此添加控件通知处理程序代码

	CString str3DRebuild;   
    int nSel;   
  
    // 获取组合框控件的列表框中选中项的索引   
    nSel = m_combo3DRebuild.GetCurSel();   
    // 根据选中项索引获取该项字符串   
    m_combo3DRebuild.GetLBText(nSel, str3DRebuild);   
	str3DRebuild +=_T("正在绘制...");
	SetDlgItemText(IDC_EDIT_RunStatus, str3DRebuild);
	if(nSel == 0) //3D重建CT面绘制
	{
		//拓展功能
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //首次操作时判断是否导入了一个待重建的CT文件夹
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先导入一个待重建的CT文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的CT文件夹！"));
			return;
		}
		if (!CT_MC_iren->GetInitialized())
		{
			CT_MC_renWin->AddRenderer(CT_MC_ren);
			CT_MC_renWin->SetParentId(GetDlgItem(IDC_STATIC_CT_MCVIEW)->m_hWnd); //注意这一步，设置绘制窗口
			
			CT_MC_iren->SetRenderWindow(CT_MC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_CT_MCVIEW)->GetWindowRect(&rect);
			CT_MC_iren->Initialize();
			CT_MC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			CT_MC_ren->ResetCamera();
	
		}
		//调用管道线pipeline()
		Pipeline_CT_MC();
		CT_MC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT面绘制成功！"));
	}
	else if(nSel == 1) //3D重建PET面绘制
	{
		//拓展功能
		if(PETRebuild_dicm_data->dataStyle!=REBUILD_PET) //首次操作时判断是否导入了一个待重建的PET文件夹
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先导入一个待重建的PET文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的PET文件夹！"));
			return;
		}
		if (!PET_MC_iren->GetInitialized())
		{
			PET_MC_renWin->AddRenderer(PET_MC_ren);
			PET_MC_renWin->SetParentId(GetDlgItem(IDC_STATIC_PET_MCVIEW)->m_hWnd); //注意这一步，设置绘制窗口
			
			PET_MC_iren->SetRenderWindow(PET_MC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_PET_MCVIEW)->GetWindowRect(&rect);
			PET_MC_iren->Initialize();
			PET_MC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			PET_MC_ren->ResetCamera();
	
		}
		//调用管道线pipeline()
		Pipeline_PET_MC();
		PET_MC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("PET面绘制成功！"));
	}
	else if(nSel == 2) //3D重建CT体绘制
	{
		//拓展功能
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //首次操作时判断是否导入了一个待重建的CT文件夹
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先导入一个待重建的CT文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的CT文件夹！"));
			return;
		}
		if (!CT_RC_iren->GetInitialized())
		{
			CT_RC_renWin->AddRenderer(CT_RC_ren);
			CT_RC_renWin->SetParentId(GetDlgItem(IDC_STATIC_CT_RCVIEW)->m_hWnd); //注意这一步，设置绘制窗口
			
			CT_RC_iren->SetRenderWindow(CT_RC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_CT_RCVIEW)->GetWindowRect(&rect);
			CT_RC_iren->Initialize();
			CT_RC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			CT_RC_ren->ResetCamera();
	
		}
		//调用管道线pipeline()
		Pipeline_CT_RC();
		CT_RC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT体绘制成功！"));
	}
	else if(nSel == 3) //3D重建PET体绘制
	{
		//拓展功能
		if(PETRebuild_dicm_data->dataStyle!=REBUILD_PET) //首次操作时判断是否导入了一个待重建的PET文件夹
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先导入一个待重建的PET文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的PET文件夹！"));
			return;
		}
		if (!PET_RC_iren->GetInitialized())
		{
			PET_RC_renWin->AddRenderer(PET_RC_ren);
			PET_RC_renWin->SetParentId(GetDlgItem(IDC_STATIC_PET_RCVIEW)->m_hWnd); //注意这一步，设置绘制窗口
			
			PET_RC_iren->SetRenderWindow(PET_RC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_PET_RCVIEW)->GetWindowRect(&rect);
			PET_RC_iren->Initialize();
			PET_RC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			PET_RC_ren->ResetCamera();
	
		}
		//调用管道线pipeline()
		Pipeline_PET_RC();
		PET_RC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("PET体绘制成功！"));
	}
}

void CITKVTKMFC_GUIDlg::SetProperty_CT_MC(int CTMC_Style1,int CTMC_LungCT_pos1,int CTMC_LungSmooth_pos1,int CTMC_LungR_pos1,int CTMC_LungG_pos1,int CTMC_LungB_pos1,int CTMC_LungOpacity_pos1,int CTMC_InterCT_pos1,int CTMC_InterSmooth_pos1,int CTMC_InterR_pos1,int CTMC_InterG_pos1,int CTMC_InterB_pos1,int CTMC_InterOpacity_pos1,int CTMC_Ambient_pos1,int CTMC_Diffuse_pos1,int CTMC_Specular_pos1,int CTMC_SpecularPower_pos1)
{
	CTMC_Style = CTMC_Style1;

	CTMC_LungCT_pos = CTMC_LungCT_pos1;
	CTMC_LungSmooth_pos = CTMC_LungSmooth_pos1;
	CTMC_LungR_pos = CTMC_LungR_pos1;
	CTMC_LungG_pos = CTMC_LungG_pos1;
	CTMC_LungB_pos = CTMC_LungB_pos1;
	CTMC_LungOpacity_pos = CTMC_LungOpacity_pos1;

	CTMC_InterCT_pos = CTMC_InterCT_pos1;
	CTMC_InterSmooth_pos = CTMC_InterSmooth_pos1;
	CTMC_InterR_pos = CTMC_InterR_pos1;
	CTMC_InterG_pos = CTMC_InterG_pos1;
	CTMC_InterB_pos = CTMC_InterB_pos1;
	CTMC_InterOpacity_pos = CTMC_InterOpacity_pos1;

	CTMC_Ambient_pos = CTMC_Ambient_pos1;
	CTMC_Diffuse_pos = CTMC_Diffuse_pos1;
	CTMC_Specular_pos = CTMC_Specular_pos1;
	CTMC_SpecularPower_pos = CTMC_SpecularPower_pos1;
}

void CITKVTKMFC_GUIDlg::SetProperty_PET_MC(int PETMC_Style1,int PETMC_LungCT_pos1,int PETMC_LungSmooth_pos1,int PETMC_LungR_pos1,int PETMC_LungG_pos1,int PETMC_LungB_pos1,int PETMC_LungOpacity_pos1,int PETMC_InterCT_pos1,int PETMC_InterSmooth_pos1,int PETMC_InterR_pos1,int PETMC_InterG_pos1,int PETMC_InterB_pos1,int PETMC_InterOpacity_pos1,int PETMC_Ambient_pos1,int PETMC_Diffuse_pos1,int PETMC_Specular_pos1,int PETMC_SpecularPower_pos1)
{
	PETMC_Style = PETMC_Style1;

	PETMC_LungCT_pos = PETMC_LungCT_pos1;
	PETMC_LungSmooth_pos = PETMC_LungSmooth_pos1;
	PETMC_LungR_pos = PETMC_LungR_pos1;
	PETMC_LungG_pos = PETMC_LungG_pos1;
	PETMC_LungB_pos = PETMC_LungB_pos1;
	PETMC_LungOpacity_pos = PETMC_LungOpacity_pos1;

	PETMC_InterCT_pos = PETMC_InterCT_pos1;
	PETMC_InterSmooth_pos = PETMC_InterSmooth_pos1;
	PETMC_InterR_pos = PETMC_InterR_pos1;
	PETMC_InterG_pos = PETMC_InterG_pos1;
	PETMC_InterB_pos = PETMC_InterB_pos1;
	PETMC_InterOpacity_pos = PETMC_InterOpacity_pos1;

	PETMC_Ambient_pos = PETMC_Ambient_pos1;
	PETMC_Diffuse_pos = PETMC_Diffuse_pos1;
	PETMC_Specular_pos = PETMC_Specular_pos1;
	PETMC_SpecularPower_pos = PETMC_SpecularPower_pos1;
}

void CITKVTKMFC_GUIDlg::SetProperty_CT_RC(int CTRC_Style1,int CTRC_LungCT_pos1,int CTRC_LungR_pos1,int CTRC_LungG_pos1,int CTRC_LungB_pos1,int CTRC_LungOpacity_pos1,int CTRC_InterCT_pos1,int CTRC_InterR_pos1,int CTRC_InterG_pos1,int CTRC_InterB_pos1,int CTRC_InterOpacity_pos1,int CTRC_Ambient_pos1,int CTRC_Diffuse_pos1,int CTRC_Specular_pos1,int CTRC_SpecularPower_pos1)
{
	CTRC_Style = CTRC_Style1;

	CTRC_LungCT_pos = CTRC_LungCT_pos1;
	CTRC_LungR_pos = CTRC_LungR_pos1;
	CTRC_LungG_pos = CTRC_LungG_pos1;
	CTRC_LungB_pos = CTRC_LungB_pos1;
	CTRC_LungOpacity_pos = CTRC_LungOpacity_pos1;

	CTRC_InterCT_pos = CTRC_InterCT_pos1;
	CTRC_InterR_pos = CTRC_InterR_pos1;
	CTRC_InterG_pos = CTRC_InterG_pos1;
	CTRC_InterB_pos = CTRC_InterB_pos1;
	CTRC_InterOpacity_pos = CTRC_InterOpacity_pos1;

	CTRC_Ambient_pos = CTRC_Ambient_pos1;
	CTRC_Diffuse_pos = CTRC_Diffuse_pos1;
	CTRC_Specular_pos = CTRC_Specular_pos1;
	CTRC_SpecularPower_pos = CTRC_SpecularPower_pos1;
}

void CITKVTKMFC_GUIDlg::SetProperty_PET_RC(int PETRC_Style1,int PETRC_LungCT_pos1,int PETRC_LungR_pos1,int PETRC_LungG_pos1,int PETRC_LungB_pos1,int PETRC_LungOpacity_pos1,int PETRC_InterCT_pos1,int PETRC_InterR_pos1,int PETRC_InterG_pos1,int PETRC_InterB_pos1,int PETRC_InterOpacity_pos1,int PETRC_Ambient_pos1,int PETRC_Diffuse_pos1,int PETRC_Specular_pos1,int PETRC_SpecularPower_pos1)
{
	PETRC_Style = PETRC_Style1;

	PETRC_LungCT_pos = PETRC_LungCT_pos1;
	PETRC_LungR_pos = PETRC_LungR_pos1;
	PETRC_LungG_pos = PETRC_LungG_pos1;
	PETRC_LungB_pos = PETRC_LungB_pos1;
	PETRC_LungOpacity_pos = PETRC_LungOpacity_pos1;

	PETRC_InterCT_pos = PETRC_InterCT_pos1;
	PETRC_InterR_pos = PETRC_InterR_pos1;
	PETRC_InterG_pos = PETRC_InterG_pos1;
	PETRC_InterB_pos = PETRC_InterB_pos1;
	PETRC_InterOpacity_pos = PETRC_InterOpacity_pos1;

	PETRC_Ambient_pos = PETRC_Ambient_pos1;
	PETRC_Diffuse_pos = PETRC_Diffuse_pos1;
	PETRC_Specular_pos = PETRC_Specular_pos1;
	PETRC_SpecularPower_pos = PETRC_SpecularPower_pos1;
}

void CITKVTKMFC_GUIDlg::Pipeline_CT_MC()
{
	CTMC3DSeg_YesOrNoMC = YES; //CTMC面绘制三维重建

	if(CTMC_Style == MC)//MC
	{
		CT_lungExtractor->SetInputData(CTRebuild_dicm_data->data);  //获得所读取的CT 数据
		CT_lungExtractor->SetValue(0,CTMC_LungCT_pos);//肺CT值  
		CT_lungExtractor->ComputeNormalsOn();   
		CT_lungExtractor->ComputeGradientsOn();

		CT_lungSmooth->SetInputConnection(CT_lungExtractor->GetOutputPort());
		CT_lungSmooth->SetNumberOfIterations(CTMC_LungSmooth_pos) ;//设置Laplace平滑的迭代次数

		CT_lungNormals->SetInputConnection(CT_lungSmooth->GetOutputPort());  
		CT_lungNormals->SetFeatureAngle(60.0);  // 指定在锋利边缘的角度值
		CT_lungStripper->SetInputConnection(CT_lungNormals->GetOutputPort());   //将生成的三角片连接成三角带

		CT_lung_surface_Mapper->SetInputConnection(CT_lungStripper->GetOutputPort());   //将三角带映射为几何数据
		CT_lung_surface_Mapper->ScalarVisibilityOff(); 

		CT_lung_surface_actor->SetMapper(CT_lung_surface_Mapper);  
	
		CT_lung_surface_actor->GetProperty()->SetColor((double)CTMC_LungR_pos/100, (double)CTMC_LungG_pos/100, (double)CTMC_LungB_pos/100);

		CT_lung_surface_actor->GetProperty()->SetAmbient((double)CTMC_Ambient_pos/100);
		CT_lung_surface_actor->GetProperty()->SetDiffuse((double)CTMC_Diffuse_pos/100);
		CT_lung_surface_actor->GetProperty()->SetSpecular((double)CTMC_Specular_pos/100);
		CT_lung_surface_actor->GetProperty()->SetSpecularPower(CTMC_SpecularPower_pos);
		CT_lung_surface_actor->GetProperty()->SetOpacity((double)CTMC_LungOpacity_pos/100);


		CT_interExtractor->SetInputData(CTRebuild_dicm_data->data);  //获得所读取的CT 数据
		CT_interExtractor->SetValue(0,CTMC_InterCT_pos);//肺内部血管结节CT值  
		CT_interExtractor->ComputeNormalsOn();   
		CT_interExtractor->ComputeGradientsOn();

		CT_interSmooth->SetInputConnection(CT_interExtractor->GetOutputPort());
		CT_interSmooth->SetNumberOfIterations(CTMC_InterSmooth_pos) ;//设置Laplace平滑的迭代次数

		//通过vtkPolyDataNormals在等值面上产生法向量
		CT_interNormals->SetInputConnection(CT_interSmooth->GetOutputPort());  
		CT_interNormals->SetFeatureAngle(60.0);  // 指定在锋利边缘的角度值

		// 剔除旧的或废除的数据单元，提高绘制速度
		//通过vtkStripper在等值面上产生纹理或三角面片
		CT_interStripper->SetInputConnection(CT_interNormals->GetOutputPort());   //将生成的三角片连接成三角带

		CT_inter_surface_Mapper->SetInputConnection(CT_interStripper->GetOutputPort());   //将三角带映射为几何数据
		CT_inter_surface_Mapper->ScalarVisibilityOff(); 

		CT_inter_surface_actor->SetMapper(CT_inter_surface_Mapper);  

		CT_inter_surface_actor->GetProperty()->SetColor((double)CTMC_InterR_pos/100, (double)CTMC_InterG_pos/100, (double)CTMC_InterB_pos/100);

		CT_inter_surface_actor->GetProperty()->SetAmbient((double)CTMC_Ambient_pos/100);
		CT_inter_surface_actor->GetProperty()->SetDiffuse((double)CTMC_Diffuse_pos/100);
		CT_inter_surface_actor->GetProperty()->SetSpecular((double)CTMC_Specular_pos/100);
		CT_inter_surface_actor->GetProperty()->SetSpecularPower(CTMC_SpecularPower_pos);
		CT_inter_surface_actor->GetProperty()->SetOpacity((double)CTMC_InterOpacity_pos/100);

		CT_MC_ren->SetBackground(0.5,0.5,0.5);  
		CT_MC_ren->ResetCameraClippingRange();  
		CT_MC_ren->AddActor(CT_lung_surface_actor);
		CT_MC_ren->AddActor(CT_inter_surface_actor);
	}
	else if(CTMC_Style == ACC_MC)//加速MC
	{
		CT_shrink->SetInputData(CTRebuild_dicm_data->data);
		CT_shrink->SetShrinkFactors(4,4,1);//采样因子

		CT_lungExtractor->SetInputConnection(CT_shrink->GetOutputPort());  //获得所读取的CT 数据
		CT_lungExtractor->SetValue(0,CTMC_LungCT_pos);//肺CT值  
		CT_lungExtractor->ComputeNormalsOn();   
		CT_lungExtractor->ComputeGradientsOn();

		CT_lungDeci->SetInputConnection(CT_lungExtractor->GetOutputPort());
		CT_lungDeci->SetTargetReduction(0.3);//将原先的三角面片减少到原来的百分之七十

		CT_lungSmooth->SetInputConnection(CT_lungDeci->GetOutputPort());
		CT_lungSmooth->SetNumberOfIterations(CTMC_LungSmooth_pos) ;//设置Laplace平滑的迭代次数

		CT_lungNormals->SetInputConnection(CT_lungSmooth->GetOutputPort());  
		CT_lungNormals->SetFeatureAngle(60.0);  // 指定在锋利边缘的角度值
		CT_lungStripper->SetInputConnection(CT_lungNormals->GetOutputPort());   //将生成的三角片连接成三角带

		CT_lung_surface_Mapper->SetInputConnection(CT_lungStripper->GetOutputPort());   //将三角带映射为几何数据
		CT_lung_surface_Mapper->ScalarVisibilityOff(); 

		CT_lung_surface_actor->SetMapper(CT_lung_surface_Mapper);  
	
		CT_lung_surface_actor->GetProperty()->SetColor((double)CTMC_LungR_pos/100, (double)CTMC_LungG_pos/100, (double)CTMC_LungB_pos/100);

		CT_lung_surface_actor->GetProperty()->SetAmbient((double)CTMC_Ambient_pos/100);
		CT_lung_surface_actor->GetProperty()->SetDiffuse((double)CTMC_Diffuse_pos/100);
		CT_lung_surface_actor->GetProperty()->SetSpecular((double)CTMC_Specular_pos/100);
		CT_lung_surface_actor->GetProperty()->SetSpecularPower(CTMC_SpecularPower_pos);
		CT_lung_surface_actor->GetProperty()->SetOpacity((double)CTMC_LungOpacity_pos/100);

		CT_interExtractor->SetInputData(CTRebuild_dicm_data->data);  //获得所读取的CT 数据
		CT_interExtractor->SetValue(0,CTMC_InterCT_pos);//肺内部血管结节CT值  
		CT_interExtractor->ComputeNormalsOn();   
		CT_interExtractor->ComputeGradientsOn();

		CT_interSmooth->SetInputConnection(CT_interExtractor->GetOutputPort());
		CT_interSmooth->SetNumberOfIterations(CTMC_InterSmooth_pos) ;//设置Laplace平滑的迭代次数

		//通过vtkPolyDataNormals在等值面上产生法向量
		CT_interNormals->SetInputConnection(CT_interSmooth->GetOutputPort());  
		CT_interNormals->SetFeatureAngle(60.0);  // 指定在锋利边缘的角度值

		// 剔除旧的或废除的数据单元，提高绘制速度
		//通过vtkStripper在等值面上产生纹理或三角面片
		CT_interStripper->SetInputConnection(CT_interNormals->GetOutputPort());   //将生成的三角片连接成三角带

		CT_inter_surface_Mapper->SetInputConnection(CT_interStripper->GetOutputPort());   //将三角带映射为几何数据
		CT_inter_surface_Mapper->ScalarVisibilityOff(); 

		CT_inter_surface_actor->SetMapper(CT_inter_surface_Mapper);  

		CT_inter_surface_actor->GetProperty()->SetColor((double)CTMC_InterR_pos/100, (double)CTMC_InterG_pos/100, (double)CTMC_InterB_pos/100);

		CT_inter_surface_actor->GetProperty()->SetAmbient((double)CTMC_Ambient_pos/100);
		CT_inter_surface_actor->GetProperty()->SetDiffuse((double)CTMC_Diffuse_pos/100);
		CT_inter_surface_actor->GetProperty()->SetSpecular((double)CTMC_Specular_pos/100);
		CT_inter_surface_actor->GetProperty()->SetSpecularPower(CTMC_SpecularPower_pos);
		CT_inter_surface_actor->GetProperty()->SetOpacity((double)CTMC_InterOpacity_pos/100);

		CT_MC_ren->SetBackground(0.5,0.5,0.5);  
		CT_MC_ren->ResetCameraClippingRange();  
		CT_MC_ren->AddActor(CT_lung_surface_actor);
		CT_MC_ren->AddActor(CT_inter_surface_actor);
	}

	if(CTMC3DSeg_CheckButtonStatus == CTMC3DSEG_CHECKED)//启动CTMC 3D任意面切割
	{
		CTMC3DSeg_rep->SetPlaceFactor(1.25); // This must be set prior to placing the widget
		CTMC3DSeg_rep->PlaceWidget(CT_lung_surface_actor->GetBounds());

		CTMC3DSeg_implicitPlaneWidget->SetInteractor(CT_MC_iren);
		CTMC3DSeg_implicitPlaneWidget->SetRepresentation(CTMC3DSeg_rep);

		CTMC3DSeg_cliper->SetInputConnection(CT_lungStripper->GetOutputPort());
		CTMC3DSeg_cliper->SetClipFunction(CTMC3DSeg_planeNew);
		CTMC3DSeg_cliper->Update();

		CTMC3DSegInter_cliper->SetInputConnection(CT_interStripper->GetOutputPort());
		CTMC3DSegInter_cliper->SetClipFunction(CTMC3DSeg_planeNew);
		CTMC3DSegInter_cliper->Update();

		CTMC3DSeg_clipedData->DeepCopy(CTMC3DSeg_cliper->GetOutput());

		CTMC3DSegInter_clipedData->DeepCopy(CTMC3DSegInter_cliper->GetOutput());

		CTMC3DSeg_pCall->setPlane(CTMC3DSeg_planeNew);
		CTMC3DSeg_pCall->setActor_lung_surface(CT_lung_surface_actor);
		CTMC3DSeg_pCall->setCliper_lung_surface(CTMC3DSeg_cliper);

		CTMC3DSeg_pCall->setActor_inter_surface(CT_inter_surface_actor);
		CTMC3DSeg_pCall->setCliper_inter_surface(CTMC3DSegInter_cliper);

		CTMC3DSeg_pCall->SetProperty_CTMC3DSeg(CTMC_LungR_pos,CTMC_LungG_pos,CTMC_LungB_pos,CTMC_LungOpacity_pos,CTMC_InterR_pos,CTMC_InterG_pos,CTMC_InterB_pos,CTMC_InterOpacity_pos,CTMC_Ambient_pos,CTMC_Diffuse_pos,CTMC_Specular_pos,CTMC_SpecularPower_pos);

		CTMC3DSeg_implicitPlaneWidget->AddObserver(vtkCommand::EndInteractionEvent, CTMC3DSeg_pCall);
		CTMC3DSeg_implicitPlaneWidget->On();
	}
	else if(CTMC3DSeg_CheckButtonStatus == CTMC3DSEG_UNCHECK)//取消CTMC 3D任意面切割
	{
		CTMC3DSeg_implicitPlaneWidget->Off();
	}
	
}

void CITKVTKMFC_GUIDlg::Pipeline_PET_MC()
{
	if(PETMC_Style == MC)//MC
	{
		PET_lungExtractor->SetInputData(PETRebuild_dicm_data->data);  //获得所读取的PET 数据
		PET_lungExtractor->SetValue(0,PETMC_LungCT_pos);//肺CT值  
		PET_lungExtractor->ComputeNormalsOn();   
		PET_lungExtractor->ComputeGradientsOn();

		PET_lungSmooth->SetInputConnection(PET_lungExtractor->GetOutputPort());
		PET_lungSmooth->SetNumberOfIterations(PETMC_LungSmooth_pos) ;//设置Laplace平滑的迭代次数

		PET_lungNormals->SetInputConnection(PET_lungSmooth->GetOutputPort());  
		PET_lungNormals->SetFeatureAngle(60.0);  // 指定在锋利边缘的角度值
		PET_lungStripper->SetInputConnection(PET_lungNormals->GetOutputPort());   //将生成的三角片连接成三角带

		PET_lung_surface_Mapper->SetInputConnection(PET_lungStripper->GetOutputPort());   //将三角带映射为几何数据
		PET_lung_surface_Mapper->ScalarVisibilityOff(); 

		PET_lung_surface_actor->SetMapper(PET_lung_surface_Mapper);  
	
		PET_lung_surface_actor->GetProperty()->SetColor((double)PETMC_LungR_pos/100, (double)PETMC_LungG_pos/100, (double)PETMC_LungB_pos/100);

		PET_lung_surface_actor->GetProperty()->SetAmbient((double)PETMC_Ambient_pos/100);
		PET_lung_surface_actor->GetProperty()->SetDiffuse((double)PETMC_Diffuse_pos/100);
		PET_lung_surface_actor->GetProperty()->SetSpecular((double)PETMC_Specular_pos/100);
		PET_lung_surface_actor->GetProperty()->SetSpecularPower(PETMC_SpecularPower_pos);
		PET_lung_surface_actor->GetProperty()->SetOpacity((double)PETMC_LungOpacity_pos/100);


		PET_interExtractor->SetInputData(PETRebuild_dicm_data->data);  //获得所读取的PET 数据
		PET_interExtractor->SetValue(0,PETMC_InterCT_pos);//肺内部血管结节CT值  
		PET_interExtractor->ComputeNormalsOn();   
		PET_interExtractor->ComputeGradientsOn();

		PET_interSmooth->SetInputConnection(PET_interExtractor->GetOutputPort());
		PET_interSmooth->SetNumberOfIterations(PETMC_InterSmooth_pos) ;//设置Laplace平滑的迭代次数

		//通过vtkPolyDataNormals在等值面上产生法向量
		PET_interNormals->SetInputConnection(PET_interSmooth->GetOutputPort());  
		PET_interNormals->SetFeatureAngle(60.0);  // 指定在锋利边缘的角度值

		// 剔除旧的或废除的数据单元，提高绘制速度
		//通过vtkStripper在等值面上产生纹理或三角面片
		PET_interStripper->SetInputConnection(PET_interNormals->GetOutputPort());   //将生成的三角片连接成三角带

		PET_inter_surface_Mapper->SetInputConnection(PET_interStripper->GetOutputPort());   //将三角带映射为几何数据
		PET_inter_surface_Mapper->ScalarVisibilityOff(); 

		PET_inter_surface_actor->SetMapper(PET_inter_surface_Mapper);  

		PET_inter_surface_actor->GetProperty()->SetColor((double)PETMC_InterR_pos/100, (double)PETMC_InterG_pos/100, (double)PETMC_InterB_pos/100);

		PET_inter_surface_actor->GetProperty()->SetAmbient((double)PETMC_Ambient_pos/100);
		PET_inter_surface_actor->GetProperty()->SetDiffuse((double)PETMC_Diffuse_pos/100);
		PET_inter_surface_actor->GetProperty()->SetSpecular((double)PETMC_Specular_pos/100);
		PET_inter_surface_actor->GetProperty()->SetSpecularPower(PETMC_SpecularPower_pos);
		PET_inter_surface_actor->GetProperty()->SetOpacity((double)PETMC_InterOpacity_pos/100);

		PET_MC_ren->SetBackground(0.5,0.5,0.5);  
		PET_MC_ren->ResetCameraClippingRange();  
		PET_MC_ren->AddActor(PET_lung_surface_actor);
		PET_MC_ren->AddActor(PET_inter_surface_actor);
	}
	else if(PETMC_Style == ACC_MC)//加速MC
	{
		PET_shrink->SetInputData(PETRebuild_dicm_data->data);
		PET_shrink->SetShrinkFactors(4,4,1);//采样因子

		PET_lungExtractor->SetInputConnection(PET_shrink->GetOutputPort());  //获得所读取的PET 数据
		PET_lungExtractor->SetValue(0,PETMC_LungCT_pos);//肺CT值  
		PET_lungExtractor->ComputeNormalsOn();   
		PET_lungExtractor->ComputeGradientsOn();

		PET_lungDeci->SetInputConnection(PET_lungExtractor->GetOutputPort());
		PET_lungDeci->SetTargetReduction(0.3);//将原先的三角面片减少到原来的百分之七十

		PET_lungSmooth->SetInputConnection(PET_lungDeci->GetOutputPort());
		PET_lungSmooth->SetNumberOfIterations(PETMC_LungSmooth_pos) ;//设置Laplace平滑的迭代次数

		PET_lungNormals->SetInputConnection(PET_lungSmooth->GetOutputPort());  
		PET_lungNormals->SetFeatureAngle(60.0);  // 指定在锋利边缘的角度值
		PET_lungStripper->SetInputConnection(PET_lungNormals->GetOutputPort());   //将生成的三角片连接成三角带

		PET_lung_surface_Mapper->SetInputConnection(PET_lungStripper->GetOutputPort());   //将三角带映射为几何数据
		PET_lung_surface_Mapper->ScalarVisibilityOff(); 

		PET_lung_surface_actor->SetMapper(PET_lung_surface_Mapper);  
	
		PET_lung_surface_actor->GetProperty()->SetColor((double)PETMC_LungR_pos/100, (double)PETMC_LungG_pos/100, (double)PETMC_LungB_pos/100);

		PET_lung_surface_actor->GetProperty()->SetAmbient((double)PETMC_Ambient_pos/100);
		PET_lung_surface_actor->GetProperty()->SetDiffuse((double)PETMC_Diffuse_pos/100);
		PET_lung_surface_actor->GetProperty()->SetSpecular((double)PETMC_Specular_pos/100);
		PET_lung_surface_actor->GetProperty()->SetSpecularPower(PETMC_SpecularPower_pos);
		PET_lung_surface_actor->GetProperty()->SetOpacity((double)PETMC_LungOpacity_pos/100);

		PET_interExtractor->SetInputData(PETRebuild_dicm_data->data);  //获得所读取的PET 数据
		PET_interExtractor->SetValue(0,PETMC_InterCT_pos);//肺内部血管结节CT值  
		PET_interExtractor->ComputeNormalsOn();   
		PET_interExtractor->ComputeGradientsOn();

		PET_interSmooth->SetInputConnection(PET_interExtractor->GetOutputPort());
		PET_interSmooth->SetNumberOfIterations(PETMC_InterSmooth_pos) ;//设置Laplace平滑的迭代次数

		//通过vtkPolyDataNormals在等值面上产生法向量
		PET_interNormals->SetInputConnection(PET_interSmooth->GetOutputPort());  
		PET_interNormals->SetFeatureAngle(60.0);  // 指定在锋利边缘的角度值

		// 剔除旧的或废除的数据单元，提高绘制速度
		//通过vtkStripper在等值面上产生纹理或三角面片
		PET_interStripper->SetInputConnection(PET_interNormals->GetOutputPort());   //将生成的三角片连接成三角带

		PET_inter_surface_Mapper->SetInputConnection(PET_interStripper->GetOutputPort());   //将三角带映射为几何数据
		PET_inter_surface_Mapper->ScalarVisibilityOff(); 

		PET_inter_surface_actor->SetMapper(PET_inter_surface_Mapper);  

		PET_inter_surface_actor->GetProperty()->SetColor((double)PETMC_InterR_pos/100, (double)PETMC_InterG_pos/100, (double)PETMC_InterB_pos/100);

		PET_inter_surface_actor->GetProperty()->SetAmbient((double)PETMC_Ambient_pos/100);
		PET_inter_surface_actor->GetProperty()->SetDiffuse((double)PETMC_Diffuse_pos/100);
		PET_inter_surface_actor->GetProperty()->SetSpecular((double)PETMC_Specular_pos/100);
		PET_inter_surface_actor->GetProperty()->SetSpecularPower(PETMC_SpecularPower_pos);
		PET_inter_surface_actor->GetProperty()->SetOpacity((double)PETMC_InterOpacity_pos/100);

		PET_MC_ren->SetBackground(0.5,0.5,0.5);  
		PET_MC_ren->ResetCameraClippingRange();  
		PET_MC_ren->AddActor(PET_lung_surface_actor);
		PET_MC_ren->AddActor(PET_inter_surface_actor);
	}
	
}

void CITKVTKMFC_GUIDlg::Pipeline_CT_RC()
{
	CTRC3DSeg_YesOrNoRC = YES; //CTRC面绘制三维重建
	if(CTRC_Style == RC)//RC
	{
		CT_shiftScale->SetInputData(CTRebuild_dicm_data->data);
		CT_shiftScale->SetOutputScalarTypeToUnsignedChar();

		//创建用于vtkVolumeRayCastMapper的光线函数vtkVolumeRayCastCompositeFunction 
		CT_volumeMapper->SetInputConnection(CT_shiftScale->GetOutputPort());
		CT_volumeMapper->SetVolumeRayCastFunction(CT_rayCastFunction);

		//创建颜色转化函数vtkColorTransferFunction用于将像素的强烈程度转化成不同的颜色
		CT_volumeColor->AddRGBSegment(0, 1, 1, 1, 255, 1, 1, 1);//...............

		CT_volumeColor->AddRGBPoint(0,    0.0, 0.0, 0.0);//灰度值为零的，设为黑色
		CT_volumeColor->AddRGBPoint(CTRC_LungCT_pos,  (double)CTRC_LungR_pos/100, (double)CTRC_LungG_pos/100, (double)CTRC_LungB_pos/100);///设置肺的颜色
		CT_volumeColor->AddRGBPoint(CTRC_InterCT_pos, (double)CTRC_InterR_pos/100, (double)CTRC_InterG_pos/100, (double)CTRC_InterB_pos/100);//肺内部颜色

		//创建分段函数设置不同组织的透明度

		CT_volumeScalarOpacity->AddSegment(0, 0, 3000, 1);//......................

		CT_volumeScalarOpacity->AddPoint(0,    0.00);
		CT_volumeScalarOpacity->AddPoint(CTRC_LungCT_pos,  (double)CTRC_LungOpacity_pos/100);
		CT_volumeScalarOpacity->AddPoint(CTRC_InterCT_pos, (double)CTRC_InterOpacity_pos/100);

		//同上，设置不同坡度的透明度（梯度）
		CT_volumeGradientOpacity->AddPoint(0,   0.0);
		CT_volumeGradientOpacity->AddPoint(90,  0.5);
		CT_volumeGradientOpacity->AddPoint(100, 1.0);


		/*Set/Get the blend mode. 
		Currently this is only supported by the vtkFixedPointVolumeRayCastMapper - other mappers have different 
		ways to set this (supplying a function to a vtkVolumeRayCastMapper) or don't have any options (vtkVolumeTextureMapper2D supports only compositing).
		Additive blend mode adds scalars along the ray and multiply them by their opacity mapping value.
		*/
		CT_volumeMapper->SetBlendModeToMaximumIntensity();//去除保留效果...................

		//创建vtkVolumeProperty将颜色、及透明度联系起来
		CT_volumeProperty->SetColor(CT_volumeColor);
		CT_volumeProperty->SetScalarOpacity(CT_volumeScalarOpacity);
		CT_volumeProperty->SetGradientOpacity(CT_volumeGradientOpacity);
		CT_volumeProperty->SetInterpolationTypeToLinear();//设置插入提数据的插入类型
		CT_volumeProperty->ShadeOn();//对阴阴暗部分进行计算
		CT_volumeProperty->SetAmbient((double)CTRC_Ambient_pos/100);//设置环境照明系数。
		CT_volumeProperty->SetDiffuse((double)CTRC_Diffuse_pos/100);//设置漫射照明系数。
		CT_volumeProperty->SetSpecular((double)CTRC_Specular_pos/100);//设置镜面照明系数。
		CT_volumeProperty->SetSpecularPower(CTRC_SpecularPower_pos); //设置镜面光的强度。

		// The vtkVolume is a vtkProp3D (like a vtkActor) and controls the position
		// and orientation of the volume in world coordinates.
		CT_volume->SetMapper(CT_volumeMapper);
		CT_volume->SetProperty(CT_volumeProperty);

		CT_RC_ren->SetBackground(0.5,0.5,0.5);  
		CT_RC_ren->ResetCameraClippingRange();  
		CT_RC_ren->AddVolume(CT_volume);
	}
	else if(CTRC_Style == FIX_RC)//固定点RC
	{
		CT_shiftScale->SetInputData(CTRebuild_dicm_data->data);
		CT_shiftScale->SetOutputScalarTypeToUnsignedChar();

		CT_pMapper->SetInputConnection(CT_shiftScale->GetOutputPort());

		//创建颜色转化函数vtkColorTransferFunction用于将像素的强烈程度转化成不同的颜色
		CT_pColor->AddRGBSegment(0, 1, 1, 1, 255, 1, 1, 1);
		CT_pColor->AddRGBPoint(CTRC_LungCT_pos,  (double)CTRC_LungR_pos/100, (double)CTRC_LungG_pos/100, (double)CTRC_LungB_pos/100);//设置转化的肺颜色
		CT_pColor->AddRGBPoint(CTRC_InterCT_pos, (double)CTRC_InterR_pos/100, (double)CTRC_InterG_pos/100, (double)CTRC_InterB_pos/100);//设置转化的肺内部（结节、血管）颜色

		// The opacity transfer function is used to control the opacity
		// of different tissue（组织） types.
		 //创建分段函数设置不同组织的透明度
		CT_pPiceFun->AddSegment(0, 0, 3000, 1);
		CT_pPiceFun->AddPoint(CTRC_LungCT_pos,  (double)CTRC_LungOpacity_pos/100); //设置肺的透明度（1.0完全不透明）
		CT_pPiceFun->AddPoint(CTRC_InterCT_pos, (double)CTRC_InterOpacity_pos/100); //设置肺内部（结节、血管）的透明度

		// The gradient(梯度) opacity function is used to decrease the opacity
		// in the "flat" regions of the volume while maintaining the opacity
		// at the boundaries between tissue types.  The gradient is measured
		// as the amount by which the intensity changes over unit distance.
		// For most medical data, the unit distance is 1mm.

		//同上，设置不同坡度的透明度（梯度）
		CT_pGradientFun->AddPoint(0,   0.0);
		CT_pGradientFun->AddPoint(90,  0.5);
		CT_pGradientFun->AddPoint(100, 1.0);

		CT_pMapper->SetBlendModeToMaximumIntensity();

		//创建vtkVolumeProperty将颜色、及透明度联系起来
		CT_pProperty->SetColor(CT_pColor);
		CT_pProperty->SetScalarOpacity(CT_pPiceFun);
		CT_pProperty->SetGradientOpacity(CT_pGradientFun);
		CT_pProperty->SetInterpolationTypeToLinear();//设置插入提数据的插入类型
		CT_pProperty->ShadeOn();//对阴阴暗部分进行计算
		CT_pProperty->SetAmbient((double)CTRC_Ambient_pos/100);
		CT_pProperty->SetDiffuse((double)CTRC_Diffuse_pos/100);
		CT_pProperty->SetSpecular((double)CTRC_Specular_pos/100);
		CT_pProperty->SetSpecularPower(CTRC_SpecularPower_pos);

		CT_volume ->SetProperty(CT_pProperty);
		CT_volume ->SetMapper(CT_pMapper);

		CT_RC_ren->SetBackground(0.5,0.5,0.5);  
		CT_RC_ren->ResetCameraClippingRange(); 
		CT_RC_ren->AddVolume(CT_volume);
	}
}

void CITKVTKMFC_GUIDlg::Pipeline_PET_RC()
{
	if(PETRC_Style == RC)//RC
	{
		PET_shiftScale->SetInputData(PETRebuild_dicm_data->data);
		PET_shiftScale->SetOutputScalarTypeToUnsignedChar();

		//创建用于vtkVolumeRayCastMapper的光线函数vtkVolumeRayCastCompositeFunction 
		PET_volumeMapper->SetInputConnection(PET_shiftScale->GetOutputPort());
		PET_volumeMapper->SetVolumeRayCastFunction(PET_rayCastFunction);

		//创建颜色转化函数vtkColorTransferFunction用于将像素的强烈程度转化成不同的颜色
		PET_volumeColor->AddRGBSegment(0, 1, 1, 1, 255, 1, 1, 1);//...............

		PET_volumeColor->AddRGBPoint(0,    0.0, 0.0, 0.0);//灰度值为零的，设为黑色
		PET_volumeColor->AddRGBPoint(PETRC_LungCT_pos,  (double)PETRC_LungR_pos/100, (double)PETRC_LungG_pos/100, (double)PETRC_LungB_pos/100);///设置肺的颜色
		PET_volumeColor->AddRGBPoint(PETRC_InterCT_pos, (double)PETRC_InterR_pos/100, (double)PETRC_InterG_pos/100, (double)PETRC_InterB_pos/100);//肺内部颜色

		//创建分段函数设置不同组织的透明度

		PET_volumeScalarOpacity->AddSegment(0, 0, 3000, 1);//......................

		PET_volumeScalarOpacity->AddPoint(0,    0.00);
		PET_volumeScalarOpacity->AddPoint(PETRC_LungCT_pos,  (double)PETRC_LungOpacity_pos/100);
		PET_volumeScalarOpacity->AddPoint(PETRC_InterCT_pos, (double)PETRC_InterOpacity_pos/100);

		//同上，设置不同坡度的透明度（梯度）
		PET_volumeGradientOpacity->AddPoint(0,   0.0);
		PET_volumeGradientOpacity->AddPoint(90,  0.5);
		PET_volumeGradientOpacity->AddPoint(100, 1.0);


		/*Set/Get the blend mode. 
		Currently this is only supported by the vtkFixedPointVolumeRayCastMapper - other mappers have different 
		ways to set this (supplying a function to a vtkVolumeRayCastMapper) or don't have any options (vtkVolumeTextureMapper2D supports only compositing).
		Additive blend mode adds scalars along the ray and multiply them by their opacity mapping value.
		*/
		PET_volumeMapper->SetBlendModeToMaximumIntensity();//去除保留效果...................

		//创建vtkVolumeProperty将颜色、及透明度联系起来
		PET_volumeProperty->SetColor(PET_volumeColor);
		PET_volumeProperty->SetScalarOpacity(PET_volumeScalarOpacity);
		PET_volumeProperty->SetGradientOpacity(PET_volumeGradientOpacity);
		PET_volumeProperty->SetInterpolationTypeToLinear();//设置插入提数据的插入类型
		PET_volumeProperty->ShadeOn();//对阴阴暗部分进行计算
		PET_volumeProperty->SetAmbient((double)PETRC_Ambient_pos/100);//设置环境照明系数。
		PET_volumeProperty->SetDiffuse((double)PETRC_Diffuse_pos/100);//设置漫射照明系数。
		PET_volumeProperty->SetSpecular((double)PETRC_Specular_pos/100);//设置镜面照明系数。
		PET_volumeProperty->SetSpecularPower(PETRC_SpecularPower_pos); //设置镜面光的强度。

		// The vtkVolume is a vtkProp3D (like a vtkActor) and controls the position
		// and orientation of the volume in world coordinates.
		PET_volume->SetMapper(PET_volumeMapper);
		PET_volume->SetProperty(PET_volumeProperty);

		PET_RC_ren->SetBackground(0.5,0.5,0.5);  
		PET_RC_ren->ResetCameraClippingRange();  
		PET_RC_ren->AddVolume(PET_volume);
	}
	else if(PETRC_Style == FIX_RC)//固定点RC
	{
		PET_shiftScale->SetInputData(PETRebuild_dicm_data->data);
		PET_shiftScale->SetOutputScalarTypeToUnsignedChar();

		PET_pMapper->SetInputConnection(PET_shiftScale->GetOutputPort());

		//创建颜色转化函数vtkColorTransferFunPETion用于将像素的强烈程度转化成不同的颜色
		PET_pColor->AddRGBSegment(0, 1, 1, 1, 255, 1, 1, 1);
		PET_pColor->AddRGBPoint(PETRC_LungCT_pos,  (double)PETRC_LungR_pos/100, (double)PETRC_LungG_pos/100, (double)PETRC_LungB_pos/100);//设置转化的肺颜色
		PET_pColor->AddRGBPoint(PETRC_InterCT_pos, (double)PETRC_InterR_pos/100, (double)PETRC_InterG_pos/100, (double)PETRC_InterB_pos/100);//设置转化的肺内部（结节、血管）颜色

		// The opacity transfer function is used to control the opacity
		// of different tissue（组织） types.
		 //创建分段函数设置不同组织的透明度
		PET_pPiceFun->AddSegment(0, 0, 3000, 1);
		PET_pPiceFun->AddPoint(PETRC_LungCT_pos,  (double)PETRC_LungOpacity_pos/100); //设置肺的透明度（1.0完全不透明）
		PET_pPiceFun->AddPoint(PETRC_InterCT_pos, (double)PETRC_InterOpacity_pos/100); //设置肺内部（结节、血管）的透明度

		// The gradient(梯度) opacity funPETion is used to decrease the opacity
		// in the "flat" regions of the volume while maintaining the opacity
		// at the boundaries between tissue types.  The gradient is measured
		// as the amount by which the intensity changes over unit distance.
		// For most medical data, the unit distance is 1mm.

		//同上，设置不同坡度的透明度（梯度）
		PET_pGradientFun->AddPoint(0,   0.0);
		PET_pGradientFun->AddPoint(90,  0.5);
		PET_pGradientFun->AddPoint(100, 1.0);

		PET_pMapper->SetBlendModeToMaximumIntensity();

		//创建vtkVolumeProperty将颜色、及透明度联系起来
		PET_pProperty->SetColor(PET_pColor);
		PET_pProperty->SetScalarOpacity(PET_pPiceFun);
		PET_pProperty->SetGradientOpacity(PET_pGradientFun);
		PET_pProperty->SetInterpolationTypeToLinear();//设置插入提数据的插入类型
		PET_pProperty->ShadeOn();//对阴阴暗部分进行计算
		PET_pProperty->SetAmbient((double)PETRC_Ambient_pos/100);
		PET_pProperty->SetDiffuse((double)PETRC_Diffuse_pos/100);
		PET_pProperty->SetSpecular((double)PETRC_Specular_pos/100);
		PET_pProperty->SetSpecularPower(PETRC_SpecularPower_pos);

		PET_volume ->SetProperty(PET_pProperty);
		PET_volume ->SetMapper(PET_pMapper);

		PET_RC_ren->SetBackground(0.5,0.5,0.5);  
		PET_RC_ren->ResetCameraClippingRange(); 
		PET_RC_ren->AddVolume(PET_volume);
	}
}

//属性组合框选中选项事件
void CITKVTKMFC_GUIDlg::OnCbnSelendokComboProperty()
{
	// TODO: 在此添加控件通知处理程序代码

	CString strProperty;   
    int nSel;   
  
    // 获取组合框控件的列表框中选中项的索引   
    nSel = m_comboProperty.GetCurSel();   
    // 根据选中项索引获取该项字符串   
    m_comboProperty.GetLBText(nSel, strProperty);   
	strProperty +=_T("正在修改属性...");
	SetDlgItemText(IDC_EDIT_RunStatus, strProperty);
	if(nSel == 0) //CT_面绘制
	{
		//拓展功能
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //首次操作时判断是否导入了一个待重建的CT文件夹
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先导入一个待重建的CT文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的CT文件夹！"));
			return;
		}

		INT_PTR nRes;             // 用于保存DoModal函数的返回值   

		CTMCPropDlg.m_strCaption = _T("CT面绘制属性对话框");//设置对话框标题
  
		//CCTMCPropertyDlg CTMCPropDlg;           // 构造对话框类CCTMCPropertyDlg的实例   
		nRes = CTMCPropDlg.DoModal();  // 弹出对话框   
		if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		{
			SetDlgItemText(IDC_EDIT_RunStatus, _T("CT面绘制属性修改取消！"));
			return;
		}
			  
		SetProperty_CT_MC(CTMCPropDlg.CTMC_Style,CTMCPropDlg.CTMC_LungCT_pos,CTMCPropDlg.CTMC_LungSmooth_pos,CTMCPropDlg.CTMC_LungR_pos,CTMCPropDlg.CTMC_LungG_pos,CTMCPropDlg.CTMC_LungB_pos,CTMCPropDlg.CTMC_LungOpacity_pos,CTMCPropDlg.CTMC_InterCT_pos,CTMCPropDlg.CTMC_InterSmooth_pos,CTMCPropDlg.CTMC_InterR_pos,CTMCPropDlg.CTMC_InterG_pos,CTMCPropDlg.CTMC_InterB_pos,CTMCPropDlg.CTMC_InterOpacity_pos,CTMCPropDlg.CTMC_Ambient_pos,CTMCPropDlg.CTMC_Diffuse_pos,CTMCPropDlg.CTMC_Specular_pos,CTMCPropDlg.CTMC_SpecularPower_pos);
		
		if (!CT_MC_iren->GetInitialized())
		{
			CT_MC_renWin->AddRenderer(CT_MC_ren);
			CT_MC_renWin->SetParentId(GetDlgItem(IDC_STATIC_CT_MCVIEW)->m_hWnd); //注意这一步，设置绘制窗口
			
			CT_MC_iren->SetRenderWindow(CT_MC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_CT_MCVIEW)->GetWindowRect(&rect);
			CT_MC_iren->Initialize();
			CT_MC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			CT_MC_ren->ResetCamera();
	
		}
		//调用管道线pipeline()
		Pipeline_CT_MC();
		CT_MC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT面绘制属性修改成功！"));

	}
	else if(nSel == 1) //PET_面绘制
	{
		//拓展功能
		if(PETRebuild_dicm_data->dataStyle!=REBUILD_PET) //首次操作时判断是否导入了一个待重建的PET文件夹
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先导入一个待重建的PET文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的PET文件夹！"));
			return;
		}

		INT_PTR nRes;             // 用于保存DoModal函数的返回值   

		PETMCPropDlg.m_strCaption = _T("PET面绘制属性对话框");//设置对话框标题
  
		//CCTMCPropertyDlg CTMCPropDlg;           // 构造对话框类CCTMCPropertyDlg的实例   
		nRes = PETMCPropDlg.DoModal();  // 弹出对话框   
		if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		{
			SetDlgItemText(IDC_EDIT_RunStatus, _T("PET面绘制属性修改取消！"));
			return;
		}
			  
		SetProperty_PET_MC(PETMCPropDlg.CTMC_Style,PETMCPropDlg.CTMC_LungCT_pos,PETMCPropDlg.CTMC_LungSmooth_pos,PETMCPropDlg.CTMC_LungR_pos,PETMCPropDlg.CTMC_LungG_pos,PETMCPropDlg.CTMC_LungB_pos,PETMCPropDlg.CTMC_LungOpacity_pos,PETMCPropDlg.CTMC_InterCT_pos,PETMCPropDlg.CTMC_InterSmooth_pos,PETMCPropDlg.CTMC_InterR_pos,PETMCPropDlg.CTMC_InterG_pos,PETMCPropDlg.CTMC_InterB_pos,PETMCPropDlg.CTMC_InterOpacity_pos,PETMCPropDlg.CTMC_Ambient_pos,PETMCPropDlg.CTMC_Diffuse_pos,PETMCPropDlg.CTMC_Specular_pos,PETMCPropDlg.CTMC_SpecularPower_pos);
		
		if (!PET_MC_iren->GetInitialized())
		{
			PET_MC_renWin->AddRenderer(PET_MC_ren);
			PET_MC_renWin->SetParentId(GetDlgItem(IDC_STATIC_PET_MCVIEW)->m_hWnd); //注意这一步，设置绘制窗口
			
			PET_MC_iren->SetRenderWindow(PET_MC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_PET_MCVIEW)->GetWindowRect(&rect);
			PET_MC_iren->Initialize();
			PET_MC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			PET_MC_ren->ResetCamera();
	
		}
		//调用管道线pipeline()
		Pipeline_PET_MC();
		PET_MC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("PET面绘制属性修改成功！"));

	}
	else if(nSel == 2) //CT_体绘制
	{
		//拓展功能
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //首次操作时判断是否导入了一个待重建的CT文件夹
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先导入一个待重建的CT文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的CT文件夹！"));
			return;
		}

		INT_PTR nRes;             // 用于保存DoModal函数的返回值   

		CTRCPropDlg.m_strCaption = _T("CT体绘制属性对话框");//设置对话框标题
  
		//CCTRCPropertyDlg CTRCPropDlg;           // 构造对话框类CCTRCPropertyDlg的实例   
		nRes = CTRCPropDlg.DoModal();  // 弹出对话框   
		if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		{
			SetDlgItemText(IDC_EDIT_RunStatus, _T("CT体绘制属性修改取消！"));
			return;
		}

		SetProperty_CT_RC(CTRCPropDlg.CTRC_Style,CTRCPropDlg.CTRC_LungCT_pos,CTRCPropDlg.CTRC_LungR_pos,CTRCPropDlg.CTRC_LungG_pos,CTRCPropDlg.CTRC_LungB_pos,CTRCPropDlg.CTRC_LungOpacity_pos,CTRCPropDlg.CTRC_InterCT_pos,CTRCPropDlg.CTRC_InterR_pos,CTRCPropDlg.CTRC_InterG_pos,CTRCPropDlg.CTRC_InterB_pos,CTRCPropDlg.CTRC_InterOpacity_pos,CTRCPropDlg.CTRC_Ambient_pos,CTRCPropDlg.CTRC_Diffuse_pos,CTRCPropDlg.CTRC_Specular_pos,CTRCPropDlg.CTRC_SpecularPower_pos);
		
		if (!CT_RC_iren->GetInitialized())
		{
			CT_RC_renWin->AddRenderer(CT_RC_ren);
			CT_RC_renWin->SetParentId(GetDlgItem(IDC_STATIC_CT_RCVIEW)->m_hWnd); //注意这一步，设置绘制窗口
			
			CT_RC_iren->SetRenderWindow(CT_RC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_CT_RCVIEW)->GetWindowRect(&rect);
			CT_RC_iren->Initialize();
			CT_RC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			CT_RC_ren->ResetCamera();
	
		}
		//调用管道线pipeline()
		Pipeline_CT_RC();
		CT_RC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT体绘制属性修改成功！"));
	}
	else if(nSel == 3) //PET体绘制
	{
		//拓展功能
		if(PETRebuild_dicm_data->dataStyle!=REBUILD_PET) //首次操作时判断是否导入了一个待重建的PET文件夹
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先导入一个待重建的PET文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的PET文件夹！"));
			return;
		}

		INT_PTR nRes;             // 用于保存DoModal函数的返回值   

		PETRCPropDlg.m_strCaption = _T("PET体绘制属性对话框");//设置对话框标题
  
		//CCTRCPropertyDlg CTRCPropDlg;           // 构造对话框类CCTRCPropertyDlg的实例   
		nRes = PETRCPropDlg.DoModal();  // 弹出对话框   
		if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		{
			SetDlgItemText(IDC_EDIT_RunStatus, _T("PET体绘制属性修改取消！"));
			return;
		}

		SetProperty_PET_RC(PETRCPropDlg.CTRC_Style,PETRCPropDlg.CTRC_LungCT_pos,PETRCPropDlg.CTRC_LungR_pos,PETRCPropDlg.CTRC_LungG_pos,PETRCPropDlg.CTRC_LungB_pos,PETRCPropDlg.CTRC_LungOpacity_pos,PETRCPropDlg.CTRC_InterCT_pos,PETRCPropDlg.CTRC_InterR_pos,PETRCPropDlg.CTRC_InterG_pos,PETRCPropDlg.CTRC_InterB_pos,PETRCPropDlg.CTRC_InterOpacity_pos,PETRCPropDlg.CTRC_Ambient_pos,PETRCPropDlg.CTRC_Diffuse_pos,PETRCPropDlg.CTRC_Specular_pos,PETRCPropDlg.CTRC_SpecularPower_pos);
		
		if (!PET_RC_iren->GetInitialized())
		{
			PET_RC_renWin->AddRenderer(PET_RC_ren);
			PET_RC_renWin->SetParentId(GetDlgItem(IDC_STATIC_PET_RCVIEW)->m_hWnd); //注意这一步，设置绘制窗口
			
			PET_RC_iren->SetRenderWindow(PET_RC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_PET_RCVIEW)->GetWindowRect(&rect);
			PET_RC_iren->Initialize();
			PET_RC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			PET_RC_ren->ResetCamera();
	
		}
		//调用管道线pipeline()
		Pipeline_PET_RC();
		PET_RC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("PET体绘制属性修改成功！"));
	}
}


//历史数据组合框选中选项事件
void CITKVTKMFC_GUIDlg::OnCbnSelendokComboPrevious()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strPrevious;   
    int nSel;   
  
    // 获取组合框控件的列表框中选中项的索引   
    nSel = m_comboPrevious.GetCurSel();   
    // 根据选中项索引获取该项字符串   
    m_comboPrevious.GetLBText(nSel, strPrevious);   
	//strPrevious +=_T("体数据正在被选择...");
	SetDlgItemText(IDC_EDIT_RunStatus, "体数据正在被选择...");

	//修改当前正在使用的体数据
	int i;//计数
	DicmDataNode *q;//移动指针
	i=0;
	q = dataList->next;
	while((q!=NULL)&&(i!=nSel))
	{
		q = q->next;
		i++;
	}
	if(i==nSel)
	{
		if(q->dataStyle == REBUILD_CT)//修改待重建的CT体数据
		{
			CTRebuild_dicm_data->data = q->data;
			strPrevious +=_T(":CT体数据修改成功！");
			SetDlgItemText(IDC_EDIT_RunStatus,strPrevious);
		}
		else if(q->dataStyle == REBUILD_PET)//修改待重建的PET体数据....
		{
			//拓展
			PETRebuild_dicm_data->data = q->data;
			strPrevious +=_T(":PET体数据修改成功！");
			SetDlgItemText(IDC_EDIT_RunStatus, strPrevious);
		}
		else if(q->dataStyle == SEG_CT)//修改待分割的CT体数据
		{
			//拓展
		}
		else if(q->dataStyle == SEG_PET)//修改待分割的PET体数据
		{
			//拓展
		}
	}
}


//点击2D任意面切割事件
void CITKVTKMFC_GUIDlg::OnBnClickedRadio2dseg()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT_RunStatus, _T("2D任意面切割正在运行..."));
	if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //首次操作时判断是否导入了一个待重建的CT文件夹
	{  
  
		// 显示消息对话框   
		MessageBox(_T("请先导入一个待重建的CT文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

		SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的CT文件夹！"));

		CheckDlgButton(IDC_RADIO_2DSeg, 0); //不选中2D任意面切割单选按钮
		return;
	}

	C2DSegDlg TwoDSegDlg;                   // 构造对话框类C2DSegDlg的实例

	INT_PTR nRes;             // 用于保存DoModal函数的返回值   

	TwoDSegDlg.m_strCaption = _T("2D任意面切割对话框");//设置对话框标题

	TwoDSegDlg.TwoDSeg_dicm_data = CTRebuild_dicm_data->data; //设置待2D任意面切割的体数据
   
	nRes = TwoDSegDlg.DoModal();  // 弹出对话框   
	if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("2D任意面切割已取消！"));
		CheckDlgButton(IDC_RADIO_2DSeg, 0); //不选中2D任意面切割单选按钮

		delete TwoDSegDlg;

		return;
	}

}


//点击2D横矢冠剖面事件
void CITKVTKMFC_GUIDlg::OnBnClickedRadio2dthreeplane()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT_RunStatus, _T("2D横矢冠剖面切割正在运行..."));
	if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //首次操作时判断是否导入了一个待重建的CT文件夹
	{  
  
		// 显示消息对话框   
		MessageBox(_T("请先导入一个待重建的CT文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

		SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的CT文件夹！"));

		CheckDlgButton(IDC_RADIO_2DThreePlane, 0); //不选中2D横矢冠剖面切割单选按钮
		return;
	}

	C2DThreePlaneDlg ThreePlaneDlg;                   // 构造对话框类C2DThreePlaneDlg的实例

	INT_PTR nRes;             // 用于保存DoModal函数的返回值   

	ThreePlaneDlg.m_strCaption = _T("2D横矢冠剖面对话框");//设置对话框标题

	ThreePlaneDlg.ThreePlane_dicm_data = CTRebuild_dicm_data->data; //设置待2D任意面切割的体数据
   
	nRes = ThreePlaneDlg.DoModal();  // 弹出对话框   
	if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("2D横矢冠剖面切割已取消！"));
		CheckDlgButton(IDC_RADIO_2DThreePlane, 0); //不选中2D横矢冠剖面单选按钮

		delete ThreePlaneDlg;

		return;
	}
}


//点击体数据切片序列显示事件
void CITKVTKMFC_GUIDlg::OnBnClickedRadioVolumesliceview()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT_RunStatus, _T("体数据切片序列显示正在运行..."));
	
	VolumeDataViewDlg VolumeViewDlg;                   // 构造对话框类VolumeDataViewDlg的实例

	INT_PTR nRes;             // 用于保存DoModal函数的返回值   
   
	nRes = VolumeViewDlg.DoModal();  // 弹出对话框   
	if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
	{
		delete VolumeViewDlg;

		SetDlgItemText(IDC_EDIT_RunStatus, _T("体数据切片序列显示已取消！"));
		CheckDlgButton(IDC_RADIO_VolumeSliceView, 0); //不选中体数据切片序列显示单选按钮

		return;
	}
}


//点击CTMC 3D任意面切割事件
void CITKVTKMFC_GUIDlg::OnBnClickedCheck3dctmcseg()
{
	// TODO: 在此添加控件通知处理程序代码
	CTMC3DSeg_CheckButtonStatus = m_check_3DCTMCSeg.GetCheck();//获取CTMC 3D任意面切割复选框选中状态
	if(CTMC3DSeg_CheckButtonStatus == CTMC3DSEG_CHECKED)//启动CTMC 3D任意面切割
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CTMC 3D任意面切割正在运行..."));
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //首次操作时判断是否导入了一个待重建的CT文件夹
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先导入一个待重建的CT文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的CT文件夹！"));

			CheckDlgButton(IDC_CHECK_3DCTMCSeg, 0); //不选中CTMC 3D任意面切割复选按钮
			CTMC3DSeg_CheckButtonStatus = CTMC3DSEG_UNCHECK;//CTMC 3D任意面切割复选按钮未选中状态
			return;
		}

		if(CTMC3DSeg_YesOrNoMC == NO) //首次操作时判断是否已经CTMC三维重建
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先进行CTMC面绘制！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先进行CTMC面绘制！"));

			CheckDlgButton(IDC_CHECK_3DCTMCSeg, 0); //不选中CTMC 3D任意面切割复选按钮
			CTMC3DSeg_CheckButtonStatus = CTMC3DSEG_UNCHECK;//CTMC 3D任意面切割复选按钮未选中状态
			return;
		}

		m_check_3DCTMCSeg_Hide.EnableWindow(TRUE);//CTMC 3D任意面切割切面隐藏复选框启动使用

		if (!CT_MC_iren->GetInitialized())
		{
			CT_MC_renWin->AddRenderer(CT_MC_ren);
			CT_MC_renWin->SetParentId(GetDlgItem(IDC_STATIC_CT_MCVIEW)->m_hWnd); //注意这一步，设置绘制窗口
			
			CT_MC_iren->SetRenderWindow(CT_MC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_CT_MCVIEW)->GetWindowRect(&rect);
			CT_MC_iren->Initialize();
			CT_MC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			CT_MC_ren->ResetCamera();
	
		}
		//调用管道线pipeline()
		Pipeline_CT_MC();
		CT_MC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("处在CTMC 3D任意面切割功能下！"));

	}
	else if(CTMC3DSeg_CheckButtonStatus == CTMC3DSEG_UNCHECK)//取消CTMC 3D任意面切割
	{
		//拓展
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CTMC 3D任意面切割正在取消..."));
		m_check_3DCTMCSeg_Hide.EnableWindow(FALSE);//CTMC 3D任意面切割切面隐藏复选框禁止使用

		if (!CT_MC_iren->GetInitialized())
		{
			CT_MC_renWin->AddRenderer(CT_MC_ren);
			CT_MC_renWin->SetParentId(GetDlgItem(IDC_STATIC_CT_MCVIEW)->m_hWnd); //注意这一步，设置绘制窗口
			
			CT_MC_iren->SetRenderWindow(CT_MC_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_CT_MCVIEW)->GetWindowRect(&rect);
			CT_MC_iren->Initialize();
			CT_MC_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			CT_MC_ren->ResetCamera();
	
		}
		//调用管道线pipeline()
		Pipeline_CT_MC();
		CT_MC_renWin->Render();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CTMC 3D任意面切割成功取消！"));
	}
	

}


//点击CTMC 3D任意面切割切面隐藏事件
void CITKVTKMFC_GUIDlg::OnBnClickedCheck3dctmcsegHide()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_check_3DCTMCSeg_Hide.GetCheck() == 1)//CTMC 3D任意面切割切面隐藏复选框被选中
	{
		CTMC3DSeg_implicitPlaneWidget->Off();
	}
	else if(m_check_3DCTMCSeg_Hide.GetCheck() == 0)//CTMC 3D任意面切割切面隐藏复选框未被选中
	{
		CTMC3DSeg_implicitPlaneWidget->On();
	}
}


//点击CT面绘制直线测量事件
void CITKVTKMFC_GUIDlg::OnBnClickedCheckCtmcLine()
{
	// TODO: 在此添加控件通知处理程序代码
	CTMCLine_CheckButtonStatus = m_check_CTMC_Line.GetCheck();//获取CT面绘制直线测量复选框选中状态
	if(CTMCLine_CheckButtonStatus == YES)//启动CT面绘制直线测量
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT面绘制直线测量正在运行..."));
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //首次操作时判断是否导入了一个待重建的CT文件夹
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先导入一个待重建的CT文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的CT文件夹！"));

			CheckDlgButton(IDC_CHECK_CTMC_Line, 0); //不选中CT面绘制直线测量复选按钮
			CTMCLine_CheckButtonStatus = NO;//CT面绘制直线测量复选按钮未选中状态
			return;
		}

		if(CTMC3DSeg_YesOrNoMC == NO) //首次操作时判断是否已经CTMC三维重建
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先进行CTMC面绘制！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先进行CTMC面绘制！"));

			CheckDlgButton(IDC_CHECK_CTMC_Line, 0); //不选中CT面绘制直线测量复选按钮
			CTMCLine_CheckButtonStatus = NO;//CT面绘制直线测量复选按钮未选中状态
			return;
		}

		CTMCLine_rep->SetLabelFormat("%-#6.3g mm");
		CTMCLine_rep->GetLabelProperty()->SetColor(1,1,1);//白色在一般情况下显示效果较好
		CTMCLine_distanceWidget->SetRepresentation(CTMCLine_rep);
		CTMCLine_distanceWidget->SetInteractor(CT_MC_iren);
		CTMCLine_distanceWidget->CreateDefaultRepresentation();
		
		CT_MC_ren->Render();
		CTMCLine_distanceWidget->On();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("处在CT面绘制直线测量功能下！"));

	}
	else if(CTMCLine_CheckButtonStatus == NO)//取消CT面绘制直线测量
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT面绘制直线测量正在取消..."));
		CT_MC_ren->Render();
		CTMCLine_distanceWidget->Off();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT面绘制直线测量成功取消！"));
	}
}


//点击CT体绘制直线测量事件
void CITKVTKMFC_GUIDlg::OnBnClickedCheckCtrcLine()
{
	// TODO: 在此添加控件通知处理程序代码
	CTRCLine_CheckButtonStatus = m_check_CTRC_Line.GetCheck();//获取CT体绘制直线测量复选框选中状态
	if(CTRCLine_CheckButtonStatus == YES)//启动CT体绘制直线测量
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT体绘制直线测量正在运行..."));
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //首次操作时判断是否导入了一个待重建的CT文件夹
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先导入一个待重建的CT文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的CT文件夹！"));

			CheckDlgButton(IDC_CHECK_CTRC_Line, 0); //不选中CT体绘制直线测量复选按钮
			CTRCLine_CheckButtonStatus = NO;//CT体绘制直线测量复选按钮未选中状态
			return;
		}

		if(CTRC3DSeg_YesOrNoRC == NO) //首次操作时判断是否已经CTRC三维重建
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先进行CTRC体绘制！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先进行CTRC体绘制！"));

			CheckDlgButton(IDC_CHECK_CTRC_Line, 0); //不选中CT体绘制直线测量复选按钮
			CTRCLine_CheckButtonStatus = NO;//CT体绘制直线测量复选按钮未选中状态
			return;
		}

		CTRCLine_rep->SetLabelFormat("%-#6.3g mm");
		CTRCLine_rep->GetLabelProperty()->SetColor(1,1,1);//白色在一般情况下显示效果较好
		CTRCLine_distanceWidget->SetRepresentation(CTRCLine_rep);
		CTRCLine_distanceWidget->SetInteractor(CT_RC_iren);
		CTRCLine_distanceWidget->CreateDefaultRepresentation();
		
		CT_RC_ren->Render();
		CTRCLine_distanceWidget->On();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("处在CT体绘制直线测量功能下！"));

	}
	else if(CTRCLine_CheckButtonStatus == NO)//取消CT体绘制直线测量
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT体绘制直线测量正在取消..."));
		CT_RC_ren->Render();
		CTRCLine_distanceWidget->Off();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT体绘制直线测量成功取消！"));
	}
}


//点击CT面绘制角度测量事件
void CITKVTKMFC_GUIDlg::OnBnClickedCheckCtmcAngle()
{
	// TODO: 在此添加控件通知处理程序代码
	CTMCAngle_CheckButtonStatus = m_check_CTMC_Angle.GetCheck();//获取CT面绘制角度测量复选框选中状态
	if(CTMCAngle_CheckButtonStatus == YES)//启动CT面绘制角度测量
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT面绘制角度测量正在运行..."));
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //首次操作时判断是否导入了一个待重建的CT文件夹
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先导入一个待重建的CT文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的CT文件夹！"));

			CheckDlgButton(IDC_CHECK_CTMC_Angle, 0); //不选中CT面绘制角度测量复选按钮
			CTMCAngle_CheckButtonStatus = NO;//CT面绘制角度测量复选按钮未选中状态
			return;
		}

		if(CTMC3DSeg_YesOrNoMC == NO) //首次操作时判断是否已经CTMC三维重建
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先进行CTMC面绘制！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先进行CTMC面绘制！"));

			CheckDlgButton(IDC_CHECK_CTMC_Angle, 0); //不选中CT面绘制角度测量复选按钮
			CTMCAngle_CheckButtonStatus = NO;//CT面绘制角度测量复选按钮未选中状态
			return;
		}

		CTMCAngle_rep->ArcVisibilityOn();
		CTMCAngle_angleWidget->SetRepresentation(CTMCAngle_rep);
		CTMCAngle_angleWidget->SetInteractor(CT_MC_iren);
		CTMCAngle_angleWidget->CreateDefaultRepresentation();
	
		CT_MC_ren->Render();
		CTMCAngle_angleWidget->On();

		SetDlgItemText(IDC_EDIT_RunStatus, _T("处在CT面绘制角度测量功能下！"));

	}
	else if(CTMCAngle_CheckButtonStatus == NO)//取消CT面绘制角度测量
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT面绘制角度测量正在取消..."));
		CT_MC_ren->Render();
		CTMCAngle_angleWidget->Off();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT面绘制角度测量成功取消！"));
	}
}


//点击CT体绘制角度测量事件
void CITKVTKMFC_GUIDlg::OnBnClickedCheckCtrcAngle()
{
	// TODO: 在此添加控件通知处理程序代码
	CTRCAngle_CheckButtonStatus = m_check_CTRC_Angle.GetCheck();//获取CT体绘制角度测量复选框选中状态
	if(CTRCAngle_CheckButtonStatus == YES)//启动CT体绘制角度测量
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT体绘制角度测量正在运行..."));
		if(CTRebuild_dicm_data->dataStyle!=REBUILD_CT) //首次操作时判断是否导入了一个待重建的CT文件夹
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先导入一个待重建的CT文件夹！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先导入一个待重建的CT文件夹！"));

			CheckDlgButton(IDC_CHECK_CTRC_Angle, 0); //不选中CT体绘制角度测量复选按钮
			CTRCAngle_CheckButtonStatus = NO;//CT体绘制角度测量复选按钮未选中状态
			return;
		}

		if(CTRC3DSeg_YesOrNoRC == NO) //首次操作时判断是否已经CTRC三维重建
		{  
  
			// 显示消息对话框   
			MessageBox(_T("请先进行CTRC体绘制！"), _T("提示"), MB_OK | MB_ICONWARNING);    

			SetDlgItemText(IDC_EDIT_RunStatus, _T("请先进行CTRC体绘制！"));

			CheckDlgButton(IDC_CHECK_CTRC_Angle, 0); //不选中CT体绘制角度测量复选按钮
			CTRCAngle_CheckButtonStatus = NO;//CT体绘制角度测量复选按钮未选中状态
			return;
		}

		CTRCAngle_rep->ArcVisibilityOn();
		CTRCAngle_angleWidget->SetRepresentation(CTRCAngle_rep);
		CTRCAngle_angleWidget->SetInteractor(CT_RC_iren);
		CTRCAngle_angleWidget->CreateDefaultRepresentation();
	
		CT_RC_ren->Render();
		CTRCAngle_angleWidget->On();

		SetDlgItemText(IDC_EDIT_RunStatus, _T("处在CT体绘制角度测量功能下！"));

	}
	else if(CTRCAngle_CheckButtonStatus == NO)//取消CT体绘制角度测量
	{
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT体绘制角度测量正在取消..."));
		CT_RC_ren->Render();
		CTRCAngle_angleWidget->Off();
		SetDlgItemText(IDC_EDIT_RunStatus, _T("CT体绘制角度测量成功取消！"));
	}
}


//点击肺部PET-CT序列分割事件
void CITKVTKMFC_GUIDlg::OnBnClickedButtonSeg()
{
	// TODO: 在此添加控件通知处理程序代码

	SetDlgItemText(IDC_EDIT_RunStatus, _T("肺部PET-CT序列分割正在运行..."));
	
	CLungPETCTSeriesSegDlg LungSeriesSegDlg;                   // 构造对话框类CLungPETCTSeriesSegDlg的实例

	INT_PTR nRes;             // 用于保存DoModal函数的返回值   
   
	nRes = LungSeriesSegDlg.DoModal();  // 弹出对话框   
	if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
	{
		delete LungSeriesSegDlg;

		SetDlgItemText(IDC_EDIT_RunStatus, _T("肺部PET-CT序列分割已取消！"));

		return;
	}
}


//帮助组合框选中选项事件
void CITKVTKMFC_GUIDlg::OnCbnSelendokComboHelp()
{
	// TODO: 在此添加控件通知处理程序代码 
    int nSel;   
  
    // 获取组合框控件的列表框中选中项的索引   
    nSel = m_comboHelp.GetCurSel();   
	if(nSel == 0) //手册
	{
		//拓展功能
		ShellExecute(NULL,_T("open"),"E:\\vtk_cmake\\MyProject\\MFC\\ITK+VTK+MFC_GUI\\help\\help_handbook.pdf",NULL,NULL,SW_SHOW);
	}
	else if(nSel == 1)//关于
	{
		//拓展功能
	
		AboutDlg aboutDlg;                   // 构造对话框类AboutDlg的实例

		INT_PTR nRes;             // 用于保存DoModal函数的返回值   
   
		nRes = aboutDlg.DoModal();  // 弹出对话框   
		if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		{
			delete aboutDlg;
			return;
		}
	}
}
