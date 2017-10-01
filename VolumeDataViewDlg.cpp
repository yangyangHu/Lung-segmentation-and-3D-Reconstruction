// VolumeDataViewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ITK+VTK+MFC_GUI.h"
#include "VolumeDataViewDlg.h"
#include "afxdialogex.h"


// VolumeDataViewDlg 对话框

IMPLEMENT_DYNAMIC(VolumeDataViewDlg, CDialogEx)

VolumeDataViewDlg::VolumeDataViewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(VolumeDataViewDlg::IDD, pParent)
{
	init_level_pos = 100;
	init_window_pos = 500;

	seg_level_pos = 128;
	seg_window_pos = 255;

	Init_CT_PET_dicm_data = vtkImageData::New();
	Seg_CT_PET_dicm_data = vtkImageData::New();

	//==============原始CT/PET预览成员对象=======================
	init_render = vtkRenderer::New();
	init_renWin = vtkWin32OpenGLRenderWindow::New();
	init_mapper = vtkImageMapper::New();
	init_actor = vtkActor2D::New();
	init_textActor = vtkTextActor::New();
	init_iren = vtkWin32RenderWindowInteractor::New();
	init_pCall = vtkNextDcmCallbk::New(); 
	//===========================================================

	//==============分割后CT/PET预览成员对象=======================
	seg_render = vtkRenderer::New();
	seg_renWin = vtkWin32OpenGLRenderWindow::New();
	seg_mapper = vtkImageMapper::New();
	seg_actor = vtkActor2D::New();
	seg_textActor = vtkTextActor::New();
	seg_iren = vtkWin32RenderWindowInteractor::New();
	seg_pCall = vtkNextDcmCallbk::New(); 
	//===========================================================

}

VolumeDataViewDlg::~VolumeDataViewDlg()
{
	//不建议在此销毁对象
	//Init_CT_PET_dicm_data->Delete();
	//Seg_CT_PET_dicm_data->Delete();

	////==============原始CT/PET预览成员对象=======================
	//init_render->Delete();
	//init_renWin->Delete();
	//init_mapper->Delete();
	//init_actor->Delete();
	//init_textActor->Delete();
	//init_iren->Delete();
	//init_pCall->Delete();
	////===========================================================

	////==============分割后CT/PET预览成员对象=======================
	//seg_render->Delete();
	//seg_renWin->Delete();
	//seg_mapper->Delete();
	//seg_actor->Delete();
	//seg_textActor->Delete();
	//seg_iren->Delete();
	//seg_pCall->Delete();
	////===========================================================
}

void VolumeDataViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_VIEW_Import, m_comboViewImport);
	DDX_Control(pDX, IDC_SCROLLBAR_Init_Level, m_scrollbar_init_level);
	DDX_Control(pDX, IDC_SCROLLBAR_Init_Window, m_scrollbar_init_window);
	DDX_Control(pDX, IDC_SCROLLBAR_Seg_Level, m_scrollbar_seg_level);
	DDX_Control(pDX, IDC_SCROLLBAR_Seg_Window, m_scrollbar_seg_window);
}


BEGIN_MESSAGE_MAP(VolumeDataViewDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_VIEW_RunStatus, &VolumeDataViewDlg::OnEnChangeEditViewRunstatus)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_CBN_SELENDOK(IDC_COMBO_VIEW_Import, &VolumeDataViewDlg::OnCbnSelendokComboViewImport)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// VolumeDataViewDlg 消息处理程序


void VolumeDataViewDlg::OnEnChangeEditViewRunstatus()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void VolumeDataViewDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

	// 为导入组合框控件的列表框添加列表项    
    m_comboViewImport.AddString(_T("一个分割后CT文件夹")); 
	m_comboViewImport.AddString(_T("一个分割后PET文件夹")); 
	m_comboViewImport.AddString(_T("一个原始CT文件夹"));   
	m_comboViewImport.AddString(_T("一个原始PET文件夹"));
    // 默认选择第一项   
    m_comboViewImport.SetCurSel(0);  

	// 设置原始CT/PET Level水平滚动条的滚动范围为-3201到1324   
	m_scrollbar_init_level.SetScrollRange(-3201, 1324);   
    // 设置水平滚动条的初始位置为100   
    m_scrollbar_init_level.SetScrollPos(init_level_pos);   
    // 在编辑框中显示100   
    SetDlgItemInt(IDC_STATIC_Init_Level, init_level_pos); 

	// 设置原始CT/PET Window水平滚动条的滚动范围为0到30000   
	m_scrollbar_init_window.SetScrollRange(0, 30000);   
    // 设置水平滚动条的初始位置为500   
    m_scrollbar_init_window.SetScrollPos(init_window_pos);   
    // 在编辑框中显示500   
    SetDlgItemInt(IDC_STATIC_Init_Window, init_window_pos); 

	// 设置分割后CT/PET Level水平滚动条的滚动范围为0到255   
	m_scrollbar_seg_level.SetScrollRange(0, 255);   
    // 设置水平滚动条的初始位置为128   
    m_scrollbar_seg_level.SetScrollPos(seg_level_pos);   
    // 在编辑框中显示128   
    SetDlgItemInt(IDC_STATIC_Seg_Level, seg_level_pos); 

	// 设置分割后CT/PET Window水平滚动条的滚动范围为0到10880 
	m_scrollbar_seg_window.SetScrollRange(0, 10880);   
    // 设置水平滚动条的初始位置为255   
    m_scrollbar_seg_window.SetScrollPos(seg_window_pos);   
    // 在编辑框中显示255   
    SetDlgItemInt(IDC_STATIC_Seg_Window, seg_window_pos); 

	//初始状态所有滚动条禁止使用
	m_scrollbar_init_level.EnableWindow(FALSE);
	m_scrollbar_init_window.EnableWindow(FALSE);

	m_scrollbar_seg_level.EnableWindow(FALSE);
	m_scrollbar_seg_window.EnableWindow(FALSE);
}


void VolumeDataViewDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	// 根据CSliderCtrl ID 来判断是哪一个CSliderCtrl
	if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_Init_Level)  //原始CT/PET Level
	{
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("原始CT/PET序列显示Level参数正在修改..."));
		init_level_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				init_level_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				init_level_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				init_level_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				init_level_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				init_level_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				init_level_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				init_level_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_Init_Level,init_level_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(init_level_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);

		//控制事件
		if (!init_iren->GetInitialized())
		{
			init_renWin->AddRenderer(init_render);
			init_renWin->SetParentId(GetDlgItem(IDC_STATIC_InitImage_View)->m_hWnd); //注意这一步，设置绘制窗口
			
			init_iren->SetRenderWindow(init_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_InitImage_View)->GetWindowRect(&rect);
			init_iren->Initialize();
			init_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			init_render->ResetCamera();
	
		}
		//调用Init_CT_PET_VIEW()
		Init_CT_PET_VIEW();
		init_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("原始CT/PET序列显示Level参数修改成功！"));

	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_Init_Window)  //原始CT/PET Window
	{
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("原始CT/PET序列显示Window参数正在修改..."));
		init_window_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				init_window_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				init_window_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				init_window_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				init_window_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				init_window_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				init_window_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				init_window_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_Init_Window,init_window_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(init_window_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);

		//控制事件
		if (!init_iren->GetInitialized())
		{
			init_renWin->AddRenderer(init_render);
			init_renWin->SetParentId(GetDlgItem(IDC_STATIC_InitImage_View)->m_hWnd); //注意这一步，设置绘制窗口
			
			init_iren->SetRenderWindow(init_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_InitImage_View)->GetWindowRect(&rect);
			init_iren->Initialize();
			init_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			init_render->ResetCamera();
	
		}
		//调用Init_CT_PET_VIEW()
		Init_CT_PET_VIEW();
		init_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("原始CT/PET序列显示Window参数修改成功！"));
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_Seg_Level)  //分割后CT/PET Level
	{
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("分割后CT/PET序列显示Level参数正在修改..."));
		seg_level_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				seg_level_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				seg_level_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				seg_level_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				seg_level_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				seg_level_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				seg_level_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				seg_level_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_Seg_Level,seg_level_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(seg_level_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);

		//控制事件
		if (!seg_iren->GetInitialized())
		{
			seg_renWin->AddRenderer(seg_render);
			seg_renWin->SetParentId(GetDlgItem(IDC_STATIC_SegImage_View)->m_hWnd); //注意这一步，设置绘制窗口
			
			seg_iren->SetRenderWindow(seg_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_SegImage_View)->GetWindowRect(&rect);
			seg_iren->Initialize();
			seg_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			seg_render->ResetCamera();
	
		}
		//调用Seg_CT_PET_VIEW()
		Seg_CT_PET_VIEW();
		seg_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("分割后CT/PET序列显示Level参数修改成功！"));
	}
	else if(pScrollBar->GetDlgCtrlID() == IDC_SCROLLBAR_Seg_Window)  //分割后CT/PET Window
	{
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("分割后CT/PET序列显示Window参数正在修改..."));
		seg_window_pos = pScrollBar->GetScrollPos();    // 获取水平滚动条当前位置   
  
		switch (nSBCode)    
		{    
			// 如果向左滚动一列，则pos减1   
			case SB_LINEUP:    
				seg_window_pos -= 1;    
				break;    
			// 如果向右滚动一列，则pos加1   
			case SB_LINEDOWN:    
				seg_window_pos  += 1;    
				break;    
			// 如果向左滚动一页，则pos减10   
			case SB_PAGEUP:    
				seg_window_pos -= 10;    
				break;    
			// 如果向右滚动一页，则pos加10   
			case SB_PAGEDOWN:    
				seg_window_pos  += 10;    
				break;    
			// 如果滚动到最左端，则pos为1   
			case SB_TOP:    
				seg_window_pos = 1;    
				break;    
			// 如果滚动到最右端，则pos为100   
			case SB_BOTTOM:    
				seg_window_pos = 100;    
				break;      
			// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值   
			case SB_THUMBPOSITION:    
				seg_window_pos = nPos;    
				break;    
			// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值   
			default:    
				SetDlgItemInt(IDC_STATIC_Seg_Window,seg_window_pos);   
				return;    
		}    
  
		// 设置滚动块位置   
		pScrollBar->SetScrollPos(seg_window_pos);   

		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);

		//控制事件
		if (!seg_iren->GetInitialized())
		{
			seg_renWin->AddRenderer(seg_render);
			seg_renWin->SetParentId(GetDlgItem(IDC_STATIC_SegImage_View)->m_hWnd); //注意这一步，设置绘制窗口
			
			seg_iren->SetRenderWindow(seg_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_SegImage_View)->GetWindowRect(&rect);
			seg_iren->Initialize();
			seg_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			seg_render->ResetCamera();
	
		}
		//调用Seg_CT_PET_VIEW()
		Seg_CT_PET_VIEW();
		seg_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("分割后CT/PET序列显示Window参数修改成功！"));
	}

}


//导入
void VolumeDataViewDlg::OnCbnSelendokComboViewImport()
{
	// TODO: 在此添加控件通知处理程序代码

	CString strImport;   
    int nSel;   
  
    // 获取组合框控件的列表框中选中项的索引   
    nSel = m_comboViewImport.GetCurSel();   
    // 根据选中项索引获取该项字符串   
    m_comboViewImport.GetLBText(nSel, strImport);   
	strImport +=_T("正在导入...");
	SetDlgItemText(IDC_EDIT_VIEW_RunStatus, strImport);
	if(nSel == 0) //导入一个分割后CT文件夹
	{
		//拓展功能
		BROWSEINFO bi;
		char chDir[MAX_PATH] = {0};
		memset((char *)&bi, 0, sizeof(bi));
		bi.hwndOwner = this->m_hWnd;
		bi.lpszTitle = "选择一个分割后CT文件夹";

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
	
		Seg_CT_PET_dicm_data = pRead->GetOutput();	

		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("导入成功！->分割后CT体数据序列显示正在运行..."));

		if (!seg_iren->GetInitialized())
		{
			seg_renWin->AddRenderer(seg_render);
			seg_renWin->SetParentId(GetDlgItem(IDC_STATIC_SegImage_View)->m_hWnd); //注意这一步，设置绘制窗口
			
			seg_iren->SetRenderWindow(seg_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_SegImage_View)->GetWindowRect(&rect);
			seg_iren->Initialize();
			seg_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			seg_render->ResetCamera();
	
		}
		//调用Seg_CT_PET_VIEW()
		Seg_CT_PET_VIEW();
		seg_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("分割后CT体数据序列显示成功！"));

		//滚动条启动使用
		m_scrollbar_seg_level.EnableWindow(TRUE);
		m_scrollbar_seg_window.EnableWindow(TRUE);

	}
	else if(nSel == 1)//导入一个分割后PET文件夹
	{
		//拓展功能
		BROWSEINFO bi;
		char chDir[MAX_PATH] = {0};
		memset((char *)&bi, 0, sizeof(bi));
		bi.hwndOwner = this->m_hWnd;
		bi.lpszTitle = "选择一个分割后PET文件夹";

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
	
		Seg_CT_PET_dicm_data = pRead->GetOutput();	

		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("导入成功！->分割后PET体数据序列显示正在运行..."));

		if (!seg_iren->GetInitialized())
		{
			seg_renWin->AddRenderer(seg_render);
			seg_renWin->SetParentId(GetDlgItem(IDC_STATIC_SegImage_View)->m_hWnd); //注意这一步，设置绘制窗口
			
			seg_iren->SetRenderWindow(seg_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_SegImage_View)->GetWindowRect(&rect);
			seg_iren->Initialize();
			seg_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			seg_render->ResetCamera();
	
		}
		//调用Seg_CT_PET_VIEW()
		Seg_CT_PET_VIEW();
		seg_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("分割后PET体数据序列显示成功！"));

		//滚动条启动使用
		m_scrollbar_seg_level.EnableWindow(TRUE);
		m_scrollbar_seg_window.EnableWindow(TRUE);
	}
	else if(nSel == 2)//导入一个原始CT文件夹
	{
		//拓展功能
		BROWSEINFO bi;
		char chDir[MAX_PATH] = {0};
		memset((char *)&bi, 0, sizeof(bi));
		bi.hwndOwner = this->m_hWnd;
		bi.lpszTitle = "选择一个原始CT文件夹";

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
	
		Init_CT_PET_dicm_data = pRead->GetOutput();	

		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("导入成功！->原始CT体数据序列显示正在运行..."));

		if (!init_iren->GetInitialized())
		{
			init_renWin->AddRenderer(init_render);
			init_renWin->SetParentId(GetDlgItem(IDC_STATIC_InitImage_View)->m_hWnd); //注意这一步，设置绘制窗口
			
			init_iren->SetRenderWindow(init_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_InitImage_View)->GetWindowRect(&rect);
			init_iren->Initialize();
			init_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			init_render->ResetCamera();
	
		}
		//调用Init_CT_PET_VIEW()
		Init_CT_PET_VIEW();
		init_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("原始CT体数据序列显示成功！"));

		//滚动条启动使用
		m_scrollbar_init_level.EnableWindow(TRUE);
		m_scrollbar_init_window.EnableWindow(TRUE);
	}
	else if(nSel == 3)//导入一个原始PET文件夹
	{
		//拓展功能
		BROWSEINFO bi;
		char chDir[MAX_PATH] = {0};
		memset((char *)&bi, 0, sizeof(bi));
		bi.hwndOwner = this->m_hWnd;
		bi.lpszTitle = "选择一个原始PET文件夹";

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
	
		Init_CT_PET_dicm_data = pRead->GetOutput();	

		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("导入成功！->原始PET体数据序列显示正在运行..."));

		if (!init_iren->GetInitialized())
		{
			init_renWin->AddRenderer(init_render);
			init_renWin->SetParentId(GetDlgItem(IDC_STATIC_InitImage_View)->m_hWnd); //注意这一步，设置绘制窗口
			
			init_iren->SetRenderWindow(init_renWin);
			CRect rect;
			GetDlgItem(IDC_STATIC_InitImage_View)->GetWindowRect(&rect);
			init_iren->Initialize();
			init_renWin->SetSize(rect.right-rect.left,rect.bottom-rect.top);
			init_render->ResetCamera();
	
		}
		//调用Init_CT_PET_VIEW()
		Init_CT_PET_VIEW();
		init_renWin->Render();
		SetDlgItemText(IDC_EDIT_VIEW_RunStatus, _T("原始PET体数据序列显示成功！"));

		//滚动条启动使用
		m_scrollbar_init_level.EnableWindow(TRUE);
		m_scrollbar_init_window.EnableWindow(TRUE);
	}
}


//原始CT/PET预览处理
void VolumeDataViewDlg::Init_CT_PET_VIEW()
{
	init_mapper->SetColorWindow(init_window_pos); // Set an initial window that makes sense for you.
	init_mapper->SetColorLevel(init_level_pos); // Set an initial level  that makes sense for you.

	init_mapper->SetInputData(Init_CT_PET_dicm_data);   

	init_actor->SetMapper(init_mapper); 
	init_render->AddActor(init_actor); //切片表现者

	init_textActor->SetPosition(0, 20); 
	char buf[64] = {0};
	sprintf(buf, "%d / %d", init_mapper->GetZSlice(), init_mapper->GetWholeZMax());
	init_textActor->SetInput(buf);
	init_render->AddActor(init_textActor);//文字表现者

	init_iren->AddObserver(vtkCommand::MouseWheelBackwardEvent, init_pCall); 
	init_iren->AddObserver(vtkCommand::MouseWheelForwardEvent, init_pCall);
}

//分割后CT/PET预览处理
void VolumeDataViewDlg::Seg_CT_PET_VIEW()
{
	seg_mapper->SetColorWindow(seg_window_pos); // Set an initial window that makes sense for you.
	seg_mapper->SetColorLevel(seg_level_pos); // Set an initial level  that makes sense for you.

	seg_mapper->SetInputData(Seg_CT_PET_dicm_data);   

	seg_actor->SetMapper(seg_mapper); 
	seg_render->AddActor(seg_actor); //切片表现者

	seg_textActor->SetPosition(0, 20); 
	char buf[64] = {0};
	sprintf(buf, "%d / %d", seg_mapper->GetZSlice(), seg_mapper->GetWholeZMax());
	seg_textActor->SetInput(buf);
	seg_render->AddActor(seg_textActor);//文字表现者

	seg_iren->AddObserver(vtkCommand::MouseWheelBackwardEvent, seg_pCall); 
	seg_iren->AddObserver(vtkCommand::MouseWheelForwardEvent, seg_pCall);
}

void VolumeDataViewDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	Init_CT_PET_dicm_data->Delete();
	Seg_CT_PET_dicm_data->Delete();

	//==============原始CT/PET预览成员对象=======================
	init_render->Delete();
	init_renWin->Delete();
	init_mapper->Delete();
	init_actor->Delete();
	init_textActor->Delete();
	init_iren->Delete();
	init_pCall->Delete();
	//===========================================================

	//==============分割后CT/PET预览成员对象=======================
	seg_render->Delete();
	seg_renWin->Delete();
	seg_mapper->Delete();
	seg_actor->Delete();
	seg_textActor->Delete();
	seg_iren->Delete();
	seg_pCall->Delete();
	//===========================================================
}
