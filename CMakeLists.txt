cmake_minimum_required( VERSION 2.8 )
PROJECT(ITK+VTK+MFC_GUI)

FIND_PACKAGE(VTK)
IF(NOT VTK_DIR)
  MESSAGE(FATAL_ERROR "Please set VTK_DIR.")
ENDIF(NOT VTK_DIR)
INCLUDE(${VTK_USE_FILE})

FIND_PACKAGE(ITK)
IF(NOT ITK_DIR)
  MESSAGE(FATAL_ERROR "Please set ITK_DIR.")
ENDIF(NOT ITK_DIR)
INCLUDE(${ITK_USE_FILE})

# This VTK_DIR usage only works in the VTK build tree...
# Make it work in the "make install" tree, too.
#
INCLUDE("${VTK_DIR}/GUISupport/MFC/VTKMFCSettings.cmake")
IF(VTK_MFC_DELAYLOAD_VTK_DLLS)
  VTK_MFC_ADD_DELAYLOAD_FLAGS(CMAKE_EXE_LINKER_FLAGS
    vtkRendering.dll
    vtkIO.dll
    vtkFiltering.dll
    vtkCommon.dll
    )
ENDIF(VTK_MFC_DELAYLOAD_VTK_DLLS)

SET(SRCS
C2DSegDlg.h
C2DThreePlaneDlg.h
VolumeDataViewDlg.h
CTMCPropertyDlg.h
CTRCPropertyDlg.h
Global.h
ITK+VTK+MFC_GUI.h
ITK+VTK+MFC_GUIDlg.h
Macro.h
resource.h
stdafx.h
targetver.h
C2DSegDlg.cpp
C2DThreePlaneDlg.cpp
VolumeDataViewDlg.cpp
CTMCPropertyDlg.cpp
CTRCPropertyDlg.cpp
ITK+VTK+MFC_GUI.cpp
ITK+VTK+MFC_GUIDlg.cpp
stdafx.cpp
ITK+VTK+MFC_GUI.rc
res/bitmap1.bmp
res/bitmap2.bmp
res/bitmap3.bmp
res/bitmap4.bmp
res/ITK+VTK+MFC_GUI.ico
res/ITKVTKMFC_GUI.rc2
)

ADD_EXECUTABLE(ITK+VTK+MFC_GUI WIN32 ${SRCS})

IF(VTK_MFC_EXTRA_LIBS)
  TARGET_LINK_LIBRARIES(ITK+VTK+MFC_GUI ${VTK_MFC_EXTRA_LIBS})
ENDIF(VTK_MFC_EXTRA_LIBS)

TARGET_LINK_LIBRARIES(ITK+VTK+MFC_GUI ${VTK_LIBRARIES} ${ITK_LIBRARIES})
