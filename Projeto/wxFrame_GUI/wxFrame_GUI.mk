##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=wxFrame_GUI
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/Babala/Documents/GitHub/Coordenograma/Projeto
ProjectPath            :=C:/Users/Babala/Documents/GitHub/Coordenograma/Projeto/wxFrame_GUI
IntermediateDirectory  :=../build-$(ConfigurationName)/wxFrame_GUI
OutDir                 :=../build-$(ConfigurationName)/wxFrame_GUI
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Babala
Date                   :=23/09/2021
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
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
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
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
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cflags)  $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
WXWIN:=C:\wxWidgets
WXCFG:=gcc_lib\mswu
Objects0=../build-$(ConfigurationName)/wxFrame_GUI/win_resources.rc$(ObjectSuffix) ../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBase.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_wxMathPlot_mathplot.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartView.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBitmaps.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ElementPlotData.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter.cpp$(ObjectSuffix) \
	



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
	$(RcCompilerName) -i "C:/Users/Babala/Documents/GitHub/Coordenograma/Projeto/wxFrame_GUI/win_resources.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) $(RcIncludePath)
../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Babala/Documents/GitHub/Coordenograma/Projeto/wxFrame_GUI/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wxFrame_GUI/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBase.cpp$(ObjectSuffix): ../../ChartView-main/ChartView/ChartViewBase.cpp ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBase.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Babala/Documents/GitHub/Coordenograma/ChartView-main/ChartView/ChartViewBase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_ChartView-main_ChartView_ChartViewBase.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBase.cpp$(DependSuffix): ../../ChartView-main/ChartView/ChartViewBase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBase.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBase.cpp$(DependSuffix) -MM ../../ChartView-main/ChartView/ChartViewBase.cpp

../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBase.cpp$(PreprocessSuffix): ../../ChartView-main/ChartView/ChartViewBase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBase.cpp$(PreprocessSuffix) ../../ChartView-main/ChartView/ChartViewBase.cpp

../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_wxMathPlot_mathplot.cpp$(ObjectSuffix): ../../ChartView-main/ChartView/wxMathPlot/mathplot.cpp ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_wxMathPlot_mathplot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Babala/Documents/GitHub/Coordenograma/ChartView-main/ChartView/wxMathPlot/mathplot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_ChartView-main_ChartView_wxMathPlot_mathplot.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_wxMathPlot_mathplot.cpp$(DependSuffix): ../../ChartView-main/ChartView/wxMathPlot/mathplot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_wxMathPlot_mathplot.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_wxMathPlot_mathplot.cpp$(DependSuffix) -MM ../../ChartView-main/ChartView/wxMathPlot/mathplot.cpp

../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_wxMathPlot_mathplot.cpp$(PreprocessSuffix): ../../ChartView-main/ChartView/wxMathPlot/mathplot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_wxMathPlot_mathplot.cpp$(PreprocessSuffix) ../../ChartView-main/ChartView/wxMathPlot/mathplot.cpp

../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartView.cpp$(ObjectSuffix): ../../ChartView-main/ChartView/ChartView.cpp ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartView.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Babala/Documents/GitHub/Coordenograma/ChartView-main/ChartView/ChartView.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_ChartView-main_ChartView_ChartView.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartView.cpp$(DependSuffix): ../../ChartView-main/ChartView/ChartView.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartView.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartView.cpp$(DependSuffix) -MM ../../ChartView-main/ChartView/ChartView.cpp

../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartView.cpp$(PreprocessSuffix): ../../ChartView-main/ChartView/ChartView.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartView.cpp$(PreprocessSuffix) ../../ChartView-main/ChartView/ChartView.cpp

../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBitmaps.cpp$(ObjectSuffix): ../../ChartView-main/ChartView/ChartViewBitmaps.cpp ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBitmaps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Babala/Documents/GitHub/Coordenograma/ChartView-main/ChartView/ChartViewBitmaps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_ChartView-main_ChartView_ChartViewBitmaps.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBitmaps.cpp$(DependSuffix): ../../ChartView-main/ChartView/ChartViewBitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBitmaps.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBitmaps.cpp$(DependSuffix) -MM ../../ChartView-main/ChartView/ChartViewBitmaps.cpp

../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBitmaps.cpp$(PreprocessSuffix): ../../ChartView-main/ChartView/ChartViewBitmaps.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ChartViewBitmaps.cpp$(PreprocessSuffix) ../../ChartView-main/ChartView/ChartViewBitmaps.cpp

../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ElementPlotData.cpp$(ObjectSuffix): ../../ChartView-main/ChartView/ElementPlotData.cpp ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ElementPlotData.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Babala/Documents/GitHub/Coordenograma/ChartView-main/ChartView/ElementPlotData.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_ChartView-main_ChartView_ElementPlotData.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ElementPlotData.cpp$(DependSuffix): ../../ChartView-main/ChartView/ElementPlotData.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ElementPlotData.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ElementPlotData.cpp$(DependSuffix) -MM ../../ChartView-main/ChartView/ElementPlotData.cpp

../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ElementPlotData.cpp$(PreprocessSuffix): ../../ChartView-main/ChartView/ElementPlotData.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wxFrame_GUI/up_up_ChartView-main_ChartView_ElementPlotData.cpp$(PreprocessSuffix) ../../ChartView-main/ChartView/ElementPlotData.cpp

../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(ObjectSuffix): MainFrame.cpp ../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Babala/Documents/GitHub/Coordenograma/Projeto/wxFrame_GUI/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(DependSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(DependSuffix) -MM MainFrame.cpp

../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(PreprocessSuffix): MainFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wxFrame_GUI/MainFrame.cpp$(PreprocessSuffix) MainFrame.cpp

../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(ObjectSuffix): wxcrafter_bitmaps.cpp ../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Babala/Documents/GitHub/Coordenograma/Projeto/wxFrame_GUI/wxcrafter_bitmaps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(DependSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(DependSuffix) -MM wxcrafter_bitmaps.cpp

../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(PreprocessSuffix): wxcrafter_bitmaps.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter_bitmaps.cpp$(PreprocessSuffix) wxcrafter_bitmaps.cpp

../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter.cpp$(ObjectSuffix): wxcrafter.cpp ../build-$(ConfigurationName)/wxFrame_GUI/wxcrafter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Babala/Documents/GitHub/Coordenograma/Projeto/wxFrame_GUI/wxcrafter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IncludePath)
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


