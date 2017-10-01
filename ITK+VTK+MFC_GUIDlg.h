
// ITK+VTK+MFC_GUIDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "Global.h"
#include "CTMCPropertyDlg.h"
#include "CTRCPropertyDlg.h"
#include "C2DSegDlg.h"
#include "C2DThreePlaneDlg.h"
#include "VolumeDataViewDlg.h"
#include "LungPETCTSeriesSegDlg.h"
#include "AboutDlg.h"
#include "Macro.h"


//===============CTMC 3D任意面切割回调函数========================
class VTKWidgetCallCTMC3DSeg : public vtkCommand
{
public:
    static VTKWidgetCallCTMC3DSeg *New()
    {
		return new VTKWidgetCallCTMC3DSeg;
    }
public:
    virtual void Execute(vtkObject *caller, unsigned long eventId, void *callData)
    {
        vtkImplicitPlaneWidget2 *pWidget = reinterpret_cast<vtkImplicitPlaneWidget2*>(caller);
        if (pWidget)
        {
            // update the clip plane and the renderer
             vtkImplicitPlaneRepresentation *rep = 
				reinterpret_cast<vtkImplicitPlaneRepresentation*>(pWidget->GetRepresentation());

            vtkSmartPointer<vtkPlane> planeNew = vtkPlane::New();
            rep->GetPlane(planeNew);
        
            lung_surface_cliper->SetClipFunction(planeNew);
            lung_surface_cliper->Update();

			inter_surface_cliper->SetClipFunction(planeNew);
            inter_surface_cliper->Update();

            vtkSmartPointer<vtkPolyData> clipedData = vtkPolyData::New();
            clipedData->DeepCopy(lung_surface_cliper->GetOutput());

            vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::New();
            mapper->SetInputData(clipedData);
            lung_surface_actor->SetMapper(mapper); //actor肺表面

			lung_surface_actor->GetProperty()->SetColor((double)CTMC3DSeg_LungR_pos/100, (double)CTMC3DSeg_LungG_pos/100, (double)CTMC3DSeg_LungB_pos/100);

			lung_surface_actor->GetProperty()->SetAmbient((double)CTMC3DSeg_Ambient_pos/100);
			lung_surface_actor->GetProperty()->SetDiffuse((double)CTMC3DSeg_Diffuse_pos/100);
			lung_surface_actor->GetProperty()->SetSpecular((double)CTMC3DSeg_Specular_pos/100);
			lung_surface_actor->GetProperty()->SetSpecularPower(CTMC3DSeg_SpecularPower_pos);
			lung_surface_actor->GetProperty()->SetOpacity((double)CTMC3DSeg_LungOpacity_pos/100);

			vtkSmartPointer<vtkPolyData> clipedData2 = vtkPolyData::New();
            clipedData2->DeepCopy(inter_surface_cliper->GetOutput());

            vtkSmartPointer<vtkPolyDataMapper> mapper2 = vtkPolyDataMapper::New();
            mapper2->SetInputData(clipedData2);
            inter_surface_actor->SetMapper(mapper2);//actor2肺内部

			inter_surface_actor->GetProperty()->SetColor((double)CTMC3DSeg_InterR_pos/100, (double)CTMC3DSeg_InterG_pos/100, (double)CTMC3DSeg_InterB_pos/100);

			inter_surface_actor->GetProperty()->SetAmbient((double)CTMC3DSeg_Ambient_pos/100);
			inter_surface_actor->GetProperty()->SetDiffuse((double)CTMC3DSeg_Diffuse_pos/100);
			inter_surface_actor->GetProperty()->SetSpecular((double)CTMC3DSeg_Specular_pos/100);
			inter_surface_actor->GetProperty()->SetSpecularPower(CTMC3DSeg_SpecularPower_pos);
			inter_surface_actor->GetProperty()->SetOpacity((double)CTMC3DSeg_InterOpacity_pos/100);
        }
    }
	void setPlane(vtkSmartPointer<vtkPlane> other){pPlane = other;}

    void setCliper_lung_surface(vtkSmartPointer<vtkClipPolyData> other){lung_surface_cliper = other;}
    void setActor_lung_surface(vtkSmartPointer<vtkActor> other){lung_surface_actor = other;}

	void setCliper_inter_surface(vtkSmartPointer<vtkClipPolyData> other){inter_surface_cliper = other;}
	void setActor_inter_surface(vtkSmartPointer<vtkActor> other){inter_surface_actor = other;}

	void SetProperty_CTMC3DSeg(int CTMC_LungR_pos1,int CTMC_LungG_pos1,int CTMC_LungB_pos1,int CTMC_LungOpacity_pos1,int CTMC_InterR_pos1,int CTMC_InterG_pos1,int CTMC_InterB_pos1,int CTMC_InterOpacity_pos1,int CTMC_Ambient_pos1,int CTMC_Diffuse_pos1,int CTMC_Specular_pos1,int CTMC_SpecularPower_pos1)
	{
		CTMC3DSeg_LungR_pos = CTMC_LungR_pos1;
		CTMC3DSeg_LungG_pos = CTMC_LungG_pos1;
		CTMC3DSeg_LungB_pos = CTMC_LungB_pos1;
		CTMC3DSeg_LungOpacity_pos = CTMC_LungOpacity_pos1;

		CTMC3DSeg_InterR_pos = CTMC_InterR_pos1;
		CTMC3DSeg_InterG_pos = CTMC_InterG_pos1;
		CTMC3DSeg_InterB_pos = CTMC_InterB_pos1;
		CTMC3DSeg_InterOpacity_pos = CTMC_InterOpacity_pos1;

		CTMC3DSeg_Ambient_pos = CTMC_Ambient_pos1;
		CTMC3DSeg_Diffuse_pos = CTMC_Diffuse_pos1;
		CTMC3DSeg_Specular_pos = CTMC_Specular_pos1;
		CTMC3DSeg_SpecularPower_pos = CTMC_SpecularPower_pos1;
	}

private:
    vtkSmartPointer<vtkPlane> pPlane;
    vtkSmartPointer<vtkActor> lung_surface_actor;
    vtkSmartPointer<vtkClipPolyData> lung_surface_cliper;

	vtkSmartPointer<vtkActor> inter_surface_actor;
    vtkSmartPointer<vtkClipPolyData> inter_surface_cliper;

	int CTMC3DSeg_LungR_pos;//肺颜色R滚动条位置
	int CTMC3DSeg_LungG_pos;//肺颜色G滚动条位置
	int CTMC3DSeg_LungB_pos;//肺颜色B滚动条位置
	int CTMC3DSeg_LungOpacity_pos;//肺透明度滚动条位置

	int CTMC3DSeg_InterR_pos;//肺内部颜色R滚动条位置
	int CTMC3DSeg_InterG_pos;//肺内部颜色G滚动条位置
	int CTMC3DSeg_InterB_pos;//肺内部颜色B滚动条位置
	int CTMC3DSeg_InterOpacity_pos;//肺内部透明度滚动条位置

	int CTMC3DSeg_Ambient_pos;//CTMC环境光系数滚动条位置
	int CTMC3DSeg_Diffuse_pos;//CTMC漫射光系数滚动条位置
	int CTMC3DSeg_Specular_pos;//CTMC镜面光系数滚动条位置
	int CTMC3DSeg_SpecularPower_pos;//CTMC镜面光强度滚动条位置
};
//================================================================



// CITKVTKMFC_GUIDlg 对话框
class CITKVTKMFC_GUIDlg : public CDialogEx
{
// 构造
public:
	CITKVTKMFC_GUIDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ITKVTKMFC_GUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboImport;  //导入组合框的控制变量
	CComboBox m_combo3DRebuild;//3D重建组合框的控制变量
	CComboBox m_comboProperty;//属性组合框的控制变量
	CComboBox m_comboHelp;//帮助组合框的控制变量
	CComboBox m_comboPrevious;//历史数据组合框的控制变量

public: //CT面绘制属性对话框
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

public: //PET面绘制属性对话框
	int PETMC_Style;  //PET面绘制类型（即：MC/加速MC）

	int PETMC_LungCT_pos;//肺阈值滚动条位置
	int PETMC_LungSmooth_pos;//肺平滑迭代次数滚动条位置
	int PETMC_LungR_pos;//肺颜色R滚动条位置
	int PETMC_LungG_pos;//肺颜色G滚动条位置
	int PETMC_LungB_pos;//肺颜色B滚动条位置
	int PETMC_LungOpacity_pos;//肺透明度滚动条位置

	int PETMC_InterCT_pos;//肺内部阈值滚动条位置
	int PETMC_InterSmooth_pos;//肺内部平滑迭代次数滚动条位置
	int PETMC_InterR_pos;//肺内部颜色R滚动条位置
	int PETMC_InterG_pos;//肺内部颜色G滚动条位置
	int PETMC_InterB_pos;//肺内部颜色B滚动条位置
	int PETMC_InterOpacity_pos;//肺内部透明度滚动条位置

	int PETMC_Ambient_pos;//CTMC环境光系数滚动条位置
	int PETMC_Diffuse_pos;//CTMC漫射光系数滚动条位置
	int PETMC_Specular_pos;//CTMC镜面光系数滚动条位置
	int PETMC_SpecularPower_pos;//CTMC镜面光强度滚动条位置

public: //CT体绘制属性对话框
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

	int CTRC_Ambient_pos;//CTMC环境光系数滚动条位置
	int CTRC_Diffuse_pos;//CTMC漫射光系数滚动条位置
	int CTRC_Specular_pos;//CTMC镜面光系数滚动条位置
	int CTRC_SpecularPower_pos;//CTMC镜面光强度滚动条位置

public: //PET体绘制属性对话框
	int PETRC_Style;  //PET体绘制类型（即：RC/固定点RC）

	int PETRC_LungCT_pos;//肺阈值滚动条位置
	int PETRC_LungR_pos;//肺颜色R滚动条位置
	int PETRC_LungG_pos;//肺颜色G滚动条位置
	int PETRC_LungB_pos;//肺颜色B滚动条位置
	int PETRC_LungOpacity_pos;//肺透明度滚动条位置

	int PETRC_InterCT_pos;//肺内部阈值滚动条位置
	int PETRC_InterR_pos;//肺内部颜色R滚动条位置
	int PETRC_InterG_pos;//肺内部颜色G滚动条位置
	int PETRC_InterB_pos;//肺内部颜色B滚动条位置
	int PETRC_InterOpacity_pos;//肺内部透明度滚动条位置

	int PETRC_Ambient_pos;//CTMC环境光系数滚动条位置
	int PETRC_Diffuse_pos;//CTMC漫射光系数滚动条位置
	int PETRC_Specular_pos;//CTMC镜面光系数滚动条位置
	int PETRC_SpecularPower_pos;//CTMC镜面光强度滚动条位置

public:
	//vtkImageData  *CTRebuild_dicm_data;//保存待重建的CT_dicm体数据

	typedef struct DicmDataNode   //dicm体数据结点,保存历史数据
	{
		int dataStyle;
		vtkImageData  *data;//保存CT_dicm体数据
		struct DicmDataNode *next;
	}DicmDataNode,*DicmDataLinkList;
	
	DicmDataNode *head,*rear;//定义历史数据链表的头结点指针、尾结点指针
	DicmDataLinkList dataList;//定义历史链表

	DicmDataNode  *CTRebuild_dicm_data;//保存待重建的CT_dicm体数据
	DicmDataNode  *PETRebuild_dicm_data;//保存待重建的PET_dicm体数据

	//==============CT面绘制成员==========================
	vtkMarchingCubes *CT_lungExtractor;
	vtkDecimatePro *CT_lungDeci;
	vtkSmoothPolyDataFilter *CT_lungSmooth;
	vtkPolyDataNormals *CT_lungNormals;
	vtkStripper *CT_lungStripper;
	vtkPolyDataMapper *CT_lung_surface_Mapper;
	vtkActor *CT_lung_surface_actor;


	vtkMarchingCubes *CT_interExtractor;
	vtkDecimatePro *CT_interDeci;
	vtkSmoothPolyDataFilter *CT_interSmooth;
	vtkPolyDataNormals *CT_interNormals;
	vtkStripper *CT_interStripper;
	vtkPolyDataMapper *CT_inter_surface_Mapper;
	vtkActor *CT_inter_surface_actor;

	vtkImageShrink3D *CT_shrink;//二次采样  抽取样点，显示数量减少速达加快

	vtkRenderer *CT_MC_ren;
	vtkWin32OpenGLRenderWindow *CT_MC_renWin;
	vtkWin32RenderWindowInteractor *CT_MC_iren;

	//====================================================

	//==============PET面绘制成员==========================
	vtkMarchingCubes *PET_lungExtractor;
	vtkDecimatePro *PET_lungDeci;
	vtkSmoothPolyDataFilter *PET_lungSmooth;
	vtkPolyDataNormals *PET_lungNormals;
	vtkStripper *PET_lungStripper;
	vtkPolyDataMapper *PET_lung_surface_Mapper;
	vtkActor *PET_lung_surface_actor;


	vtkMarchingCubes *PET_interExtractor;
	vtkDecimatePro *PET_interDeci;
	vtkSmoothPolyDataFilter *PET_interSmooth;
	vtkPolyDataNormals *PET_interNormals;
	vtkStripper *PET_interStripper;
	vtkPolyDataMapper *PET_inter_surface_Mapper;
	vtkActor *PET_inter_surface_actor;

	vtkImageShrink3D *PET_shrink;//二次采样  抽取样点，显示数量减少速达加快

	vtkRenderer *PET_MC_ren;
	vtkWin32OpenGLRenderWindow *PET_MC_renWin;
	vtkWin32RenderWindowInteractor *PET_MC_iren;

	//====================================================

	//=====================CT体绘制成员===================
	vtkImageShiftScale *CT_shiftScale;

	vtkVolumeRayCastCompositeFunction *CT_rayCastFunction;  //RC
	vtkVolumeRayCastMapper *CT_volumeMapper;
	vtkColorTransferFunction *CT_volumeColor;
	vtkPiecewiseFunction *CT_volumeScalarOpacity;
	vtkPiecewiseFunction *CT_volumeGradientOpacity;
	vtkVolumeProperty *CT_volumeProperty;

	vtkFixedPointVolumeRayCastMapper *CT_pMapper;  //固定点RC
	vtkColorTransferFunction* CT_pColor;
	vtkPiecewiseFunction* CT_pPiceFun;
	vtkPiecewiseFunction* CT_pGradientFun;
	vtkVolumeProperty* CT_pProperty;

	vtkVolume *CT_volume;

	vtkRenderer *CT_RC_ren;
	vtkWin32OpenGLRenderWindow *CT_RC_renWin;
	vtkWin32RenderWindowInteractor *CT_RC_iren;
	//====================================================

	//=====================PET体绘制成员===================
	vtkImageShiftScale *PET_shiftScale;

	vtkVolumeRayCastCompositeFunction *PET_rayCastFunction;  //RC
	vtkVolumeRayCastMapper *PET_volumeMapper;
	vtkColorTransferFunction *PET_volumeColor;
	vtkPiecewiseFunction *PET_volumeScalarOpacity;
	vtkPiecewiseFunction *PET_volumeGradientOpacity;
	vtkVolumeProperty *PET_volumeProperty;

	vtkFixedPointVolumeRayCastMapper *PET_pMapper;  //固定点RC
	vtkColorTransferFunction* PET_pColor;
	vtkPiecewiseFunction* PET_pPiceFun;
	vtkPiecewiseFunction* PET_pGradientFun;
	vtkVolumeProperty* PET_pProperty;

	vtkVolume *PET_volume;

	vtkRenderer *PET_RC_ren;
	vtkWin32OpenGLRenderWindow *PET_RC_renWin;
	vtkWin32RenderWindowInteractor *PET_RC_iren;
	//====================================================

	//==================CTMC 3D任意面切割成员==============
	vtkImplicitPlaneRepresentation *CTMC3DSeg_rep;
	vtkImplicitPlaneWidget2 *CTMC3DSeg_implicitPlaneWidget;
	vtkPlane *CTMC3DSeg_planeNew;
	vtkClipPolyData *CTMC3DSeg_cliper;
	vtkPolyData *CTMC3DSeg_clipedData;
	VTKWidgetCallCTMC3DSeg *CTMC3DSeg_pCall;

	vtkClipPolyData *CTMC3DSegInter_cliper;
	vtkPolyData *CTMC3DSegInter_clipedData;

	int CTMC3DSeg_CheckButtonStatus;//CTMC 3D任意面切割复选框选中状态

	int CTMC3DSeg_YesOrNoMC;//CTMC面绘制是否重建

	//=====================================================

	//==================CT面绘制直线测量成员===============
	int CTMCLine_CheckButtonStatus;//CT面绘制直线测量复选框选中状态
	vtkDistanceRepresentation3D *CTMCLine_rep;
	vtkDistanceWidget *CTMCLine_distanceWidget;
	//=====================================================

	//==================CT体绘制直线测量成员===============
	int CTRCLine_CheckButtonStatus;//CT体绘制直线测量复选框选中状态
	vtkDistanceRepresentation3D *CTRCLine_rep;
	vtkDistanceWidget *CTRCLine_distanceWidget;

	int CTRC3DSeg_YesOrNoRC;//CTRC体绘制是否重建
	//=====================================================

	//==================CT面绘制角度测量成员===============
	int CTMCAngle_CheckButtonStatus;//CT面绘制角度测量复选框选中状态
	vtkAngleRepresentation3D *CTMCAngle_rep;
	vtkAngleWidget *CTMCAngle_angleWidget;
	//=====================================================

	//==================CT体绘制角度测量成员===============
	int CTRCAngle_CheckButtonStatus;//CT体绘制角度测量复选框选中状态
	vtkAngleRepresentation3D *CTRCAngle_rep;
	vtkAngleWidget *CTRCAngle_angleWidget;
	//=====================================================


	CCTMCPropertyDlg CTMCPropDlg;           // 构造对话框类CCTMCPropertyDlg的实例 
	CCTRCPropertyDlg CTRCPropDlg;           // 构造对话框类CCTRCPropertyDlg的实例

	CCTMCPropertyDlg PETMCPropDlg;           // 构造对话框类CCTMCPropertyDlg的实例
	CCTRCPropertyDlg PETRCPropDlg;           // 构造对话框类CCTRCPropertyDlg的实例

	//C2DSegDlg TwoDSegDlg;                   // 构造对话框类C2DSegDlg的实例


	afx_msg void OnDestroy();
	afx_msg void OnCbnSelendokComboImport();//导入组合框选中选项事件
	afx_msg void OnCbnSelendokCombo3drebuild();//3D重建组合框选中选项事件
	void Pipeline_CT_MC();//CT面绘制数据管道处理
	void SetProperty_CT_MC(int CTMC_Style1,int CTMC_LungCT_pos1,int CTMC_LungSmooth_pos1,int CTMC_LungR_pos1,int CTMC_LungG_pos1,int CTMC_LungB_pos1,int CTMC_LungOpacity_pos1,int CTMC_InterCT_pos1,int CTMC_InterSmooth_pos1,int CTMC_InterR_pos1,int CTMC_InterG_pos1,int CTMC_InterB_pos1,int CTMC_InterOpacity_pos1,int CTMC_Ambient_pos1,int CTMC_Diffuse_pos1,int CTMC_Specular_pos1,int CTMC_SpecularPower_pos1);
	
	void Pipeline_PET_MC();//PET面绘制数据管道处理
	void SetProperty_PET_MC(int PETMC_Style1,int PETMC_LungCT_pos1,int PETMC_LungSmooth_pos1,int PETMC_LungR_pos1,int PETMC_LungG_pos1,int PETMC_LungB_pos1,int PETMC_LungOpacity_pos1,int PETMC_InterCT_pos1,int PETMC_InterSmooth_pos1,int PETMC_InterR_pos1,int PETMC_InterG_pos1,int PETMC_InterB_pos1,int PETMC_InterOpacity_pos1,int PETMC_Ambient_pos1,int PETMC_Diffuse_pos1,int PETMC_Specular_pos1,int PETMC_SpecularPower_pos1);

	void Pipeline_CT_RC();//CT体绘制数据管道处理
	void SetProperty_CT_RC(int CTRC_Style1,int CTRC_LungCT_pos1,int CTRC_LungR_pos1,int CTRC_LungG_pos1,int CTRC_LungB_pos1,int CTRC_LungOpacity_pos1,int CTRC_InterCT_pos1,int CTRC_InterR_pos1,int CTRC_InterG_pos1,int CTRC_InterB_pos1,int CTRC_InterOpacity_pos1,int CTRC_Ambient_pos1,int CTRC_Diffuse_pos1,int CTRC_Specular_pos1,int CTRC_SpecularPower_pos1);

	void Pipeline_PET_RC();//PET体绘制数据管道处理
	void SetProperty_PET_RC(int PETRC_Style1,int PETRC_LungCT_pos1,int PETRC_LungR_pos1,int PETRC_LungG_pos1,int PETRC_LungB_pos1,int PETRC_LungOpacity_pos1,int PETRC_InterCT_pos1,int PETRC_InterR_pos1,int PETRC_InterG_pos1,int PETRC_InterB_pos1,int PETRC_InterOpacity_pos1,int PETRC_Ambient_pos1,int PETRC_Diffuse_pos1,int PETRC_Specular_pos1,int PETRC_SpecularPower_pos1);

	afx_msg void OnCbnSelendokComboProperty();//属性组合框选中选项事件
	
	afx_msg void OnCbnSelendokComboPrevious();//历史数据组合框选中选项事件
	afx_msg void OnBnClickedRadio2dseg(); //点击2D任意面切割事件
	afx_msg void OnBnClickedRadio2dthreeplane();//点击2D横矢冠剖面事件
	afx_msg void OnBnClickedRadioVolumesliceview();//点击体数据切片序列显示事件
	afx_msg void OnBnClickedCheck3dctmcseg();//点击CTMC 3D任意面切割事件
	CButton m_check_3DCTMCSeg;//CTMC 3D任意面切割复选框变量
	CButton m_check_3DCTMCSeg_Hide;//CTMC 3D任意面切割切面隐藏复选框变量
	afx_msg void OnBnClickedCheck3dctmcsegHide();//点击CTMC 3D任意面切割切面隐藏事件

	afx_msg void OnBnClickedCheckCtmcLine();//点击CT面绘制直线测量事件
	CButton m_check_CTMC_Line;//CT面绘制直线测量复选框变量

	afx_msg void OnBnClickedCheckCtrcLine();//点击CT体绘制直线测量事件
	CButton m_check_CTRC_Line;//CT体绘制直线测量复选框变量

	afx_msg void OnBnClickedCheckCtmcAngle();//点击CT面绘制角度测量事件
	CButton m_check_CTMC_Angle;//CT面绘制角度测量复选框变量

	afx_msg void OnBnClickedCheckCtrcAngle();//点击CT体绘制角度测量事件
	CButton m_check_CTRC_Angle;//CT体绘制角度测量复选框变量
	afx_msg void OnBnClickedButtonSeg();//点击肺部PET-CT序列分割事件

	afx_msg void OnCbnSelendokComboHelp();//帮助组合框选中选项事件
};
