# Microsoft Developer Studio Project File - Name="OrderDishSystem" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=OrderDishSystem - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "OrderDishSystem.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "OrderDishSystem.mak" CFG="OrderDishSystem - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "OrderDishSystem - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "OrderDishSystem - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "OrderDishSystem - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "OrderDishSystem - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "OrderDishSystem - Win32 Release"
# Name "OrderDishSystem - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "app"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\app\CadminWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CCheckCreateWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CCheckerWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CCheckGoodsRecord.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CCheckMenuWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CCheckReportWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CFile.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CGoods.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CGoodsAddWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CGoodSearchWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CGoodsStockRecord.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CLoginWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CRegisterWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CStaff.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CStartWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\CTipsWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\InStockMenuWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\InStockRecord.cpp
# End Source File
# Begin Source File

SOURCE=.\app\InStockRecordWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\InStockWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\OutStockMenuWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\OutStockRecordWin.cpp
# End Source File
# Begin Source File

SOURCE=.\app\OutStockWin.cpp
# End Source File
# End Group
# Begin Group "core"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\core\CButton.cpp
# End Source File
# Begin Source File

SOURCE=.\core\CControlBase.cpp
# End Source File
# Begin Source File

SOURCE=.\core\CEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\core\CGoodsFound.cpp
# End Source File
# Begin Source File

SOURCE=.\core\CLabel.cpp
# End Source File
# Begin Source File

SOURCE=.\core\CList.cpp
# End Source File
# Begin Source File

SOURCE=.\core\CTable.cpp
# End Source File
# Begin Source File

SOURCE=.\core\CTool.cpp
# End Source File
# Begin Source File

SOURCE=.\core\CWinBase.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "include"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\core\CButton.h
# End Source File
# Begin Source File

SOURCE=.\core\CControlBase.h
# End Source File
# Begin Source File

SOURCE=.\core\CEdit.h
# End Source File
# Begin Source File

SOURCE=.\core\CGoodsFound.h
# End Source File
# Begin Source File

SOURCE=.\core\CLabel.h
# End Source File
# Begin Source File

SOURCE=.\core\CList.h
# End Source File
# Begin Source File

SOURCE=.\core\CTable.h
# End Source File
# Begin Source File

SOURCE=.\core\CTool.h
# End Source File
# Begin Source File

SOURCE=.\core\CWinBase.h
# End Source File
# End Group
# Begin Group "application"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\app\CadminWin.h
# End Source File
# Begin Source File

SOURCE=.\app\CCheckCreateWin.h
# End Source File
# Begin Source File

SOURCE=.\app\CCheckerWin.h
# End Source File
# Begin Source File

SOURCE=.\app\CCheckMenuWin.h
# End Source File
# Begin Source File

SOURCE=.\app\CCheckRecord.h
# End Source File
# Begin Source File

SOURCE=.\app\CCheckReportWin.h
# End Source File
# Begin Source File

SOURCE=.\app\CCheckWin.h
# End Source File
# Begin Source File

SOURCE=.\app\CFile.h
# End Source File
# Begin Source File

SOURCE=.\app\CGoods.h
# End Source File
# Begin Source File

SOURCE=.\app\CGoodsAddWin.h
# End Source File
# Begin Source File

SOURCE=.\app\CGoodSearchWin.h
# End Source File
# Begin Source File

SOURCE=.\app\CGoodsStockRecord.h
# End Source File
# Begin Source File

SOURCE=.\app\CLoginWin.h
# End Source File
# Begin Source File

SOURCE=.\app\CRegisterWin.h
# End Source File
# Begin Source File

SOURCE=.\app\CStaff.h
# End Source File
# Begin Source File

SOURCE=.\app\CStartWin.h
# End Source File
# Begin Source File

SOURCE=.\app\CTipsWin.h
# End Source File
# Begin Source File

SOURCE=.\app\InStockMenuWin.h
# End Source File
# Begin Source File

SOURCE=.\app\InStockRecord.h
# End Source File
# Begin Source File

SOURCE=.\app\InStockRecordWin.h
# End Source File
# Begin Source File

SOURCE=.\app\InStockWin.h
# End Source File
# Begin Source File

SOURCE=.\app\OutStockMenuWin.h
# End Source File
# Begin Source File

SOURCE=.\app\OutStockRecordWin.h
# End Source File
# Begin Source File

SOURCE=.\app\OutStockWin.h
# End Source File
# End Group
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
