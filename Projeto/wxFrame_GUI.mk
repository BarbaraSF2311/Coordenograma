##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=wxFrame_GUI
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/wxFrame_GUI/wxFrame_GUI
ProjectPath            :=C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/wxFrame_GUI/wxFrame_GUI/wxFrame_GUI
IntermediateDirectory  :=../build-$(ConfigurationName)/wxFrame_GUI
OutDir                 :=../build-$(ConfigurationName)/wxFrame_GUI
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Barbara
Date                   :=15/05/2021
CodeLitePath           :=C:/CodeLite
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := $(shell wx-config --rcflags)
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  $(shell wx-config --libs) -mwindows
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cflags)  $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\CodeLite
WXWIN:=C:\wxWidgets
WXCFG:=gcc_lib\mswu
Objects0=../build-$(ConfigurationName)/wxFrame_GUI/win_resources.rc$(ObjectSuffix) ../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/wxFrame_GUI/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\wxFrame_GUI" mkdir "..\build-$(ConfigurationName)\wxFrame_GUI"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\wxFrame_GUI" mkdir "..\build-$(ConfigurationName)\wxFrame_GUI"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/wxFrame_GUI/.d:
	@if not exist "..\build-$(ConfigurationName)\wxFrame_GUI" mkdir "..\build-$(ConfigurationName)\wxFrame_GUI"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/wxFrame_GUI/win_resources.rc$(ObjectSuffix): win_resources.rc
	$(RcCompilerName) -i "C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/wxFrame_GUI/wxFrame_GUI/wxFrame_GUI/win_resources.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) $(RcIncludePath)
../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(ObjectSuffix): MainFrame.cpp ../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/wxFrame_GUI/wxFrame_GUI/wxFrame_GUI/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(DependSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(DependSuffix) -MM MainFrame.cpp

../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(PreprocessSuffix): MainFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(PreprocessSuffix) MainFrame.cpp

../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(ObjectSuffix): wxcrafter_bitmaps.cpp ../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/wxFrame_GUI/wxFrame_GUI/wxFrame_GUI/wxcrafter_bitmaps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(DependSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(DependSuffix) -MM wxcrafter_bitmaps.cpp

../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(PreprocessSuffix): wxcrafter_bitmaps.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(PreprocessSuffix) wxcrafter_bitmaps.cpp

../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/wxFrame_GUI/wxFrame_GUI/wxFrame_GUI/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter.cpp$(ObjectSuffix): wxcrafter.cpp ../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/wxFrame_GUI/wxFrame_GUI/wxFrame_GUI/wxcrafter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter.cpp$(DependSuffix): wxcrafter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter.cpp$(DependSuffix) -MM wxcrafter.cpp

../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter.cpp$(PreprocessSuffix): wxcrafter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter.cpp$(PreprocessSuffix) wxcrafter.cpp


-include ../build-$(ConfigurationName)/wxFrame_GUI//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


