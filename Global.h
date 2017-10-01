#pragma once
#include "vtkDICOMImageReader.h" 
#include "vtkRenderer.h"
#include "vtkRenderWindow.h" 
#include "vtkRenderWindowInteractor.h" 
#include "vtkPolyDataMapper.h" 
#include "vtkActor.h" 
#include "vtkProperty.h" 
#include "vtkOutlineFilter.h" 
#include "vtkCamera.h" 
#include "vtkWin32OpenGLRenderWindow.h"
#include "vtkWin32RenderWindowInteractor.h"
#include "vtkMFCWindow.h"
#include <vtkImageData.h>
#include "afxwin.h"

//面绘制需要的头文件
#include "vtkPolyDataNormals.h" 
#include "vtkStripper.h" 
#include "vtkMarchingCubes.h"
#include "vtkFeatureEdges.h"
#include "vtkSmoothPolyDataFilter.h"
#include "vtkDecimatePro.h"
#include "vtkImageShrink3D.h"


//体绘制需要的头文件
#include "vtkFixedPointVolumeRayCastMapper.h"
#include "vtkColorTransferFunction.h"
#include "vtkPiecewiseFunction.h"
#include "vtkVolumeProperty.h"
#include "vtkImageShiftScale.h"
#include <vtkVolume.h>
#include <vtkVolumeRayCastMapper.h>
#include <vtkVolumeRayCastCompositeFunction.h>
#include <vtkVolumeProperty.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>


//2D任意面切割需要的头文件
#include "vtkCutter.h"
#include "vtkPlane.h"
#include "vtkImagePlaneWidget.h"
#include "vtkCellArray.h"
#include "vtkType.h"
#include "vtkPlaneWidget.h"
#include "vtkCommand.h"
#include "vtkProbeFilter.h"
#include "vtkImplicitPlaneWidget.h"
#include "vtkClipPolyData.h"

//2D横矢冠剖面需要的头文件
#include "vtkSmartPointer.h"
#include "vtkCellPicker.h"
#include "vtkImageActor.h"
#include "vtkImageReslice.h"
#include "vtkInteractorStyleImage.h"
#include "vtkImageMapToColors.h"
#include "vtkImagePlaneWidget.h"
#include "vtkImageReader.h"
#include "vtkInteractorEventRecorder.h"
#include "vtkLookupTable.h"
#include "vtkPointData.h"
#include "vtkPlaneSource.h"
#include "vtkPlane.h"
#include "vtkResliceCursorActor.h"
#include "vtkResliceCursorPolyDataAlgorithm.h"
#include "vtkResliceCursor.h"
#include "vtkResliceCursorWidget.h"
#include "vtkResliceCursorLineRepresentation.h"
#include "vtkBiDimensionalWidget.h"
#include "vtkTextActor.h"


//CTMC 3D任意面切割需要的头文件
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkClipPolyData.h>
#include <vtkPlane.h>
#include <vtkImplicitPlaneWidget2.h>
#include <vtkPlaneWidget.h>
#include <vtkImplicitPlaneRepresentation.h>
#include <vtkAngleRepresentation3D.h>
#include <vtkPointHandleRepresentation3D.h>

//直线测量、角度测量需要的头文件
#include <vtkAngleWidget.h>//角度
#include <vtkAngleRepresentation3D.h>

#include "vtkDistanceRepresentation3D.h"//直线
#include "vtkDistanceWidget.h"

//体数据预览需要的头文件
#include "vtkImageMapper.h"
#include "vtkActor2D.h"
#include "vtkActor2DCollection.h"
#include "vtkRendererCollection.h"

//肺部PET-CT序列分割需要的头文件
#include "itkImage.h" 
#include "itkImageFileReader.h" 
#include "itkImageFileWriter.h" 
#include "itkRescaleIntensityImageFilter.h"
#include "itkGDCMImageIO.h"

#include "itkConnectedThresholdImageFilter.h"

#include "itkCastImageFilter.h"


#include "itkBinaryErodeImageFilter.h"
#include "itkBinaryDilateImageFilter.h"
#include "itkBinaryBallStructuringElement.h"

#include "itkBinaryThresholdImageFilter.h"


#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkImageSeriesReader.h"
#include "itkImageSeriesWriter.h"

#include "itkResampleImageFilter.h"
#include "itkSimilarity2DTransform.h"

#include <vector>
#include "itksys/SystemTools.hxx"


#include <iostream>
#include <fstream>

#include <time.h>

#include<math.h>
#include<stdlib.h>
#include<stdio.h>

#include <string.h>
#include <malloc.h>
#include <conio.h>

#include<cstdlib>

using namespace std;