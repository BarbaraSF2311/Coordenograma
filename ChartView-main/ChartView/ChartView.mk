##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ChartView
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/ChartView-main
ProjectPath            :=C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/ChartView-main/ChartView
IntermediateDirectory  :=../build-$(ConfigurationName)/ChartView
OutDir                 :=../build-$(ConfigurationName)/ChartView
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Barbara
Date                   :=17/05/2021
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
LinkOptions            :=  $(shell wx-config --libs std,aui,propgrid) -mwindows
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
Objects0=../build-$(ConfigurationName)/ChartView/ChartView.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/ChartView/win_resources.rc$(ObjectSuffix) ../build-$(ConfigurationName)/ChartView/ElementPlotData.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/ChartView/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/ChartView/ChartViewBase.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/ChartView/wxMathPlot_mathplot.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/ChartView/ChartViewBitmaps.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/ChartView/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\ChartView" mkdir "..\build-$(ConfigurationName)\ChartView"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\ChartView" mkdir "..\build-$(ConfigurationName)\ChartView"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/ChartView/.d:
	@if not exist "..\build-$(ConfigurationName)\ChartView" mkdir "..\build-$(ConfigurationName)\ChartView"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/ChartView/ChartView.cpp$(ObjectSuffix): ChartView.cpp ../build-$(ConfigurationName)/ChartView/ChartView.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/ChartView-main/ChartView/ChartView.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ChartView.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/ChartView/ChartView.cpp$(DependSuffix): ChartView.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/ChartView/ChartView.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/ChartView/ChartView.cpp$(DependSuffix) -MM ChartView.cpp

../build-$(ConfigurationName)/ChartView/ChartView.cpp$(PreprocessSuffix): ChartView.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/ChartView/ChartView.cpp$(PreprocessSuffix) ChartView.cpp

../build-$(ConfigurationName)/ChartView/win_resources.rc$(ObjectSuffix): win_resources.rc
	$(RcCompilerName) -i "C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/ChartView-main/ChartView/win_resources.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) $(RcIncludePath)
../build-$(ConfigurationName)/ChartView/ElementPlotData.cpp$(ObjectSuffix): ElementPlotData.cpp ../build-$(ConfigurationName)/ChartView/ElementPlotData.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/ChartView-main/ChartView/ElementPlotData.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ElementPlotData.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/ChartView/ElementPlotData.cpp$(DependSuffix): ElementPlotData.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/ChartView/ElementPlotData.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/ChartView/ElementPlotData.cpp$(DependSuffix) -MM ElementPlotData.cpp

../build-$(ConfigurationName)/ChartView/ElementPlotData.cpp$(PreprocessSuffix): ElementPlotData.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/ChartView/ElementPlotData.cpp$(PreprocessSuffix) ElementPlotData.cpp

../build-$(ConfigurationName)/ChartView/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/ChartView/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/ChartView-main/ChartView/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/ChartView/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/ChartView/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/ChartView/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/ChartView/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/ChartView/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/ChartView/ChartViewBase.cpp$(ObjectSuffix): ChartViewBase.cpp ../build-$(ConfigurationName)/ChartView/ChartViewBase.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/ChartView-main/ChartView/ChartViewBase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ChartViewBase.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/ChartView/ChartViewBase.cpp$(DependSuffix): ChartViewBase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/ChartView/ChartViewBase.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/ChartView/ChartViewBase.cpp$(DependSuffix) -MM ChartViewBase.cpp

../build-$(ConfigurationName)/ChartView/ChartViewBase.cpp$(PreprocessSuffix): ChartViewBase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/ChartView/ChartViewBase.cpp$(PreprocessSuffix) ChartViewBase.cpp

../build-$(ConfigurationName)/ChartView/wxMathPlot_mathplot.cpp$(ObjectSuffix): wxMathPlot/mathplot.cpp ../build-$(ConfigurationName)/ChartView/wxMathPlot_mathplot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/ChartView-main/ChartView/wxMathPlot/mathplot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxMathPlot_mathplot.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/ChartView/wxMathPlot_mathplot.cpp$(DependSuffix): wxMathPlot/mathplot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/ChartView/wxMathPlot_mathplot.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/ChartView/wxMathPlot_mathplot.cpp$(DependSuffix) -MM wxMathPlot/mathplot.cpp

../build-$(ConfigurationName)/ChartView/wxMathPlot_mathplot.cpp$(PreprocessSuffix): wxMathPlot/mathplot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/ChartView/wxMathPlot_mathplot.cpp$(PreprocessSuffix) wxMathPlot/mathplot.cpp

../build-$(ConfigurationName)/ChartView/ChartViewBitmaps.cpp$(ObjectSuffix): ChartViewBitmaps.cpp ../build-$(ConfigurationName)/ChartView/ChartViewBitmaps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Barbara/Desktop/IFG-Works/TCCei/CodeLiteTry/ChartView-main/ChartView/ChartViewBitmaps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ChartViewBitmaps.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/ChartView/ChartViewBitmaps.cpp$(DependSuffix): ChartViewBitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/ChartView/ChartViewBitmaps.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/ChartView/ChartViewBitmaps.cpp$(DependSuffix) -MM ChartViewBitmaps.cpp

../build-$(ConfigurationName)/ChartView/ChartViewBitmaps.cpp$(PreprocessSuffix): ChartViewBitmaps.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/ChartView/ChartViewBitmaps.cpp$(PreprocessSuffix) ChartViewBitmaps.cpp


-include ../build-$(ConfigurationName)/ChartView//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


