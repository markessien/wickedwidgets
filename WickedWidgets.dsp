# Microsoft Developer Studio Project File - Name="WickedWidgets" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=WickedWidgets - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "WickedWidgets.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WickedWidgets.mak" CFG="WickedWidgets - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WickedWidgets - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "WickedWidgets - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WickedWidgets - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 comctl32.lib msimg32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Performing registration
OutDir=.\Debug
TargetPath=.\Debug\WickedWidgets.dll
InputPath=.\Debug\WickedWidgets.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "WickedWidgets - Win32 Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMinDependency"
# PROP BASE Intermediate_Dir "ReleaseMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMinDependency"
# PROP Intermediate_Dir "ReleaseMinDependency"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 comctl32.lib msimg32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\WickedWidgets.dll
InputPath=.\ReleaseMinDependency\WickedWidgets.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "WickedWidgets - Win32 Debug"
# Name "WickedWidgets - Win32 Release MinDependency"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BitmapButton.cpp
# End Source File
# Begin Source File

SOURCE=.\GDIMonster.cpp
# End Source File
# Begin Source File

SOURCE=.\Label.cpp
# End Source File
# Begin Source File

SOURCE=.\Slider.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Tooltip.cpp
# End Source File
# Begin Source File

SOURCE=.\WickedWidgets.cpp
# End Source File
# Begin Source File

SOURCE=.\WickedWidgets.def
# End Source File
# Begin Source File

SOURCE=.\WickedWidgets.idl
# ADD MTL /tlb ".\WickedWidgets.tlb" /h "WickedWidgets.h" /iid "WickedWidgets_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\WickedWidgets.rc
# End Source File
# Begin Source File

SOURCE=.\WindowSkinner.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BitmapButton.h
# End Source File
# Begin Source File

SOURCE=.\GDIMonster.h
# End Source File
# Begin Source File

SOURCE=.\Label.h
# End Source File
# Begin Source File

SOURCE=.\ObjectTable.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Slider.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Tooltip.h
# End Source File
# Begin Source File

SOURCE=.\WickedWidgetsCP.h
# End Source File
# Begin Source File

SOURCE=.\WindowSkinner.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\Images\ball.bmp
# End Source File
# Begin Source File

SOURCE=.\Images\ball_hor.bmp
# End Source File
# Begin Source File

SOURCE=.\Images\ball_pressed.bmp
# End Source File
# Begin Source File

SOURCE=.\Images\ball_pressed_hor.bmp
# End Source File
# Begin Source File

SOURCE=.\Images\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\Images\bitmap2.bmp
# End Source File
# Begin Source File

SOURCE=.\Images\bitmapbu.bmp
# End Source File
# Begin Source File

SOURCE=.\BitmapButton.rgs
# End Source File
# Begin Source File

SOURCE=.\Images\Buttons.bmp
# End Source File
# Begin Source File

SOURCE=.\Images\hor_slider_path.bmp
# End Source File
# Begin Source File

SOURCE=.\Images\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\Images\label.bmp
# End Source File
# Begin Source File

SOURCE=.\Label.rgs
# End Source File
# Begin Source File

SOURCE=.\Images\numbers.bmp
# End Source File
# Begin Source File

SOURCE=.\Images\Path.bmp
# End Source File
# Begin Source File

SOURCE=.\Images\path_hor.bmp
# End Source File
# Begin Source File

SOURCE=.\Images\pshbtn.ico
# End Source File
# Begin Source File

SOURCE=.\Silder.rgs
# End Source File
# Begin Source File

SOURCE=.\Images\slider.bmp
# End Source File
# Begin Source File

SOURCE=.\Slider.rgs
# End Source File
# Begin Source File

SOURCE=.\Images\templates.bmp
# End Source File
# Begin Source File

SOURCE=.\Images\text.bmp
# End Source File
# Begin Source File

SOURCE=.\Images\ver_slider_path.bmp
# End Source File
# Begin Source File

SOURCE=.\Images\windowsk.bmp
# End Source File
# Begin Source File

SOURCE=.\WindowSkinner.rgs
# End Source File
# End Group
# Begin Source File

SOURCE=.\OldCode.txt
# End Source File
# End Target
# End Project
