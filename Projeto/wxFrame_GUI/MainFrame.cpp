#include "MainFrame.h"
#include <wx/aboutdlg.h>

MainFrame::MainFrame(wxWindow* parent) : MainFrameBaseClass(parent) {InitFrame();}

MainFrame::~MainFrame() {}

void MainFrame::InitFrame() 
{
    BuildGrid();
    
    m_pgCorrente->Enable(false);
    m_pgTempo->Enable(false);
    m_pgITF->Enable(false);
    m_pgIAIF->Enable(false);
    m_pgRTC->Enable(false);
    m_pgTempoDefinido->Enable(false);
    m_pgTipoCurva->Enable(false);
    
    ChangePropertyText(m_pgCorrente,wxT("-"));
    ChangePropertyText(m_pgTempo,wxT("-"));
    ChangePropertyText(m_pgITF,wxT("-"));
    ChangePropertyText(m_pgIAIF,wxT("-"));
    ChangePropertyText(m_pgRTC,wxT("-"));
    ChangePropertyText(m_pgTempoDefinido,wxT("-"));
    ChangePropertyText(m_pgTipoCurva,wxT("-"));
}
void MainFrame::BuildGrid()
{
    m_grid->SetSelectionMode(wxGrid::wxGridSelectRows);
    m_grid->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
    
    m_grid->EnableGridLines(true);
    
    m_grid->SetRowLabelSize(wxGRID_AUTOSIZE);
    m_grid->AppendCols(11,true);
    
    m_grid->HideRowLabels();
    
    //Nome das colunas
    m_grid->SetColLabelValue(0,wxT("Nome"));
    m_grid->SetColLabelValue(1,wxT("Tipo"));
    m_grid->SetColLabelValue(2,wxT("Corrente [kA]"));
    m_grid->SetColLabelValue(3,wxT("Tempo [s]"));
    m_grid->SetColLabelValue(4,wxT("I partida [kA]"));
    m_grid->SetColLabelValue(5,wxT("Itf [A]"));
    m_grid->SetColLabelValue(6,wxT("RTC"));
    m_grid->SetColLabelValue(7,wxT("Iaif [kA]"));
    m_grid->SetColLabelValue(8,wxT("Temp. Def. [s]"));
    m_grid->SetColLabelValue(9,wxT("Tipo de Curva"));
    m_grid->SetColLabelValue(10,wxT("ID"));
    
    m_grid->HideCol(10);
    m_grid->SetColSize(0,140);
    m_grid->SetColSize(1,81);
    m_grid->SetColSize(2,88);
    m_grid->SetColSize(3,66);
    m_grid->SetColSize(4,84);
    m_grid->SetColSize(5,50);
    m_grid->SetColSize(6,50);
    m_grid->SetColSize(7,57);
    m_grid->SetColSize(8,88);
    m_grid->SetColSize(9,190);
    
    //Organizando casas das colunas floats
    m_grid->SetColFormatFloat(2, 7, 1);
    m_grid->SetColFormatFloat(3, 7, 2);
    m_grid->SetColFormatFloat(4, 7, 1);
    m_grid->SetColFormatFloat(5, 7, 2);
    m_grid->SetColFormatFloat(6, 7, 1);
    m_grid->SetColFormatFloat(7, 7, 2);
    m_grid->SetColFormatFloat(8, 7, 2);

}
void MainFrame::AttLineGrid(float itemID)
{
    int ID = itemID;
    for(int i = 0; i <= (m_grid->GetNumberRows() - 1); i++){
        if(wxString::Format("%d", ID) == m_grid->GetCellValue(i, 10)){
            if(m_Lista[i].m_Tipo == 1 || m_Lista[i].m_Tipo == 2){          //RELE 5051 5051TD
                m_grid->SetCellValue(i, 3, wxString::Format("%f", m_Lista[i].m_TMS));
                m_grid->SetCellValue(i, 5, wxString::Format("%f", m_Lista[i].m_Itf));
                m_grid->SetCellValue(i, 6, wxString::Format("%f", m_Lista[i].m_RTC));
                m_grid->SetCellValue(i, 7, wxString::Format("%f", (m_Lista[i].m_Iaif/1000)));
                if(m_Lista[i].m_Tipo == 2){m_grid->SetCellValue(i, 8, wxString::Format("%f", m_Lista[i].m_TempoDefinido));}
                
                if(m_Lista[i].m_TipoCurva == 1){m_grid->SetCellValue(i, 9, wxT("Curva Normalmente Inversa"));}
                else if(m_Lista[i].m_TipoCurva == 2){m_grid->SetCellValue(i, 9, wxT("Curva Muito Inversa"));}
                else if(m_Lista[i].m_TipoCurva == 3){m_grid->SetCellValue(i, 9, wxT("Curva Extremamente Inversa"));}
                else if(m_Lista[i].m_TipoCurva == 4){m_grid->SetCellValue(i, 9, wxT("Curva Inversa Longa"));}
                else if(m_Lista[i].m_TipoCurva == 5){m_grid->SetCellValue(i, 9, wxT("Curva Inversa Curta"));}
                else if(m_Lista[i].m_TipoCurva == 6){m_grid->SetCellValue(i, 9, wxT("Curva T??rmica IXT"));}
                else if(m_Lista[i].m_TipoCurva == 7){m_grid->SetCellValue(i, 9, wxT("Curva T??rmica I??XT"));}
            }
            
            else if(m_Lista[i].m_Tipo == 3 || m_Lista[i].m_Tipo == 4){                             //ANSI OU INRUSH
                m_grid->SetCellValue(i, 2, wxString::Format("%f", (m_Lista[i].m_Corrente/1000)));
                m_grid->SetCellValue(i, 3, wxString::Format("%f", m_Lista[i].m_Tempo));
            }
            
            else if(m_Lista[i].m_Tipo == 5){                                                       //CARGA
                m_grid->SetCellValue(i, 2, wxString::Format("%f", (m_Lista[i].m_Corrente/1000)));
                m_grid->SetCellValue(i, 3, wxString::Format("%f", m_Lista[i].m_Carga_Tpartida));
                m_grid->SetCellValue(i, 4, wxString::Format("%f", (m_Lista[i].m_Carga_Ipartida/1000)));
            }
            
            else if(m_Lista[i].m_Tipo == 6){m_grid->SetCellValue(i, 2, wxString::Format("%f", (m_Lista[i].m_Corrente/1000)));} //ICC
        }
    }
    m_grid->Refresh();
}
void MainFrame::btnClickAdicionar(wxCommandEvent& event)
{
    Item novoItem;
    novoItem.m_ID = m_IDatual;
    m_IDatual++;

    double aux;

    switch (m_pgTipo->GetValue().GetInteger()) {
        case 0: //Nenhum selecionado
            wxMessageBox(wxT("Selecione o tipo de dado"));
            m_IDatual--;
            break;
        case 1: //Rele 50/51
            novoItem.m_Nome = m_pgNome->GetDisplayedString();
            novoItem.m_Tipo = 1;                                          //Colocando os dados no struct
            aux = m_pgIAIF->GetValue();
            novoItem.m_Iaif = aux*1000;                                //Recebendo em kA
            novoItem.m_TMS = m_pgTempo->GetValue();
            novoItem.m_Itf = m_pgITF->GetValue();
            novoItem.m_RTC = m_pgRTC->GetValue();
            novoItem.m_TipoCurva = m_pgTipoCurva->GetValue().GetInteger();
            
            m_grid->AppendRows(1,true);                                  //Acrescentando a linha no grid e mostrando
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 3, wxString::Format("%f", novoItem.m_TMS));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 5, wxString::Format("%f", novoItem.m_Itf));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 6, wxString::Format("%f", novoItem.m_RTC));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 7, wxString::Format("%f", (novoItem.m_Iaif/1000)));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 9, m_pgTipoCurva->GetDisplayedString());
            
            if(m_pgNome->GetDisplayedString() == ""){novoItem.m_Nome = wxString::Format("%d - ", novoItem.m_ID) + m_pgTipo->GetDisplayedString();}
            
            break;
        case 2: //Rele 50/51 TD
            novoItem.m_Nome = m_pgNome->GetDisplayedString();
            novoItem.m_Tipo = 2;
            aux = m_pgIAIF->GetValue();
            novoItem.m_Iaif = aux*1000;
            novoItem.m_Itf = m_pgITF->GetValue();
            novoItem.m_TMS = m_pgTempo->GetValue();
            novoItem.m_RTC = m_pgRTC->GetValue();
            novoItem.m_TempoDefinido = m_pgTempoDefinido->GetValue();
            novoItem.m_TipoCurva = m_pgTipoCurva->GetValue().GetInteger();
            
            m_grid->AppendRows(1,true);
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 3, wxString::Format("%f", novoItem.m_TMS));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 5, wxString::Format("%f", novoItem.m_Itf));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 6, wxString::Format("%f", novoItem.m_RTC));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 7, wxString::Format("%f", (novoItem.m_Iaif/1000)));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 8, wxString::Format("%f", novoItem.m_TempoDefinido));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 9, m_pgTipoCurva->GetDisplayedString());
            
            if(m_pgNome->GetDisplayedString() == ""){novoItem.m_Nome = wxString::Format("%d - ", novoItem.m_ID) + m_pgTipo->GetDisplayedString();}
            
            break;
        case 3: //ANSI
            novoItem.m_Nome = m_pgNome->GetDisplayedString();
            novoItem.m_Tipo = 3;
            novoItem.m_Tempo = m_pgTempo->GetValue();
            aux = m_pgCorrente->GetValue();
            novoItem.m_Corrente = aux*1000;
            
            m_grid->AppendRows(1,true);
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 2, wxString::Format("%f", (novoItem.m_Corrente/1000)));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 3, wxString::Format("%f", novoItem.m_Tempo));
            
            if(m_pgNome->GetDisplayedString() == ""){novoItem.m_Nome = wxString::Format("%d - ", novoItem.m_ID) + m_pgTipo->GetDisplayedString();}
            
            break;
        case 4: //INRUSH
            novoItem.m_Nome = m_pgNome->GetDisplayedString();
            novoItem.m_Tipo = 4;
            novoItem.m_Tempo = m_pgTempo->GetValue();
            aux = m_pgCorrente->GetValue();
            novoItem.m_Corrente = aux*1000;
            
            m_grid->AppendRows(1,true);
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 2, wxString::Format("%f", (novoItem.m_Corrente/1000)));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 3, wxString::Format("%f", novoItem.m_Tempo));
            
            if(m_pgNome->GetDisplayedString() == ""){novoItem.m_Nome = wxString::Format("%d - ", novoItem.m_ID) + m_pgTipo->GetDisplayedString();}
            
            break;
        case 5: //CARGA
            novoItem.m_Nome = m_pgNome->GetDisplayedString();
            novoItem.m_Tipo = 5;
            aux = m_pgCorrente->GetValue();
            novoItem.m_Corrente = aux*1000;
            aux = m_pgITF->GetValue();
            novoItem.m_Carga_Ipartida = aux*1000;
            novoItem.m_Carga_Tpartida = m_pgTempo->GetValue();
            
            m_grid->AppendRows(1,true);
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 2, wxString::Format("%f", novoItem.m_Corrente/1000));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 3, wxString::Format("%f", novoItem.m_Carga_Tpartida));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 4, wxString::Format("%f", (novoItem.m_Carga_Ipartida)/1000));
            
            if(m_pgNome->GetDisplayedString() == ""){novoItem.m_Nome = wxString::Format("%d - ", novoItem.m_ID) + m_pgTipo->GetDisplayedString();}
            
            break;
        case 6: //ICC
            novoItem.m_Nome = m_pgNome->GetDisplayedString();
            novoItem.m_Tipo = 6;
            aux = m_pgCorrente->GetValue();
            novoItem.m_Corrente = aux*1000;
            
            m_grid->AppendRows(1,true);
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 2, wxString::Format("%f", (novoItem.m_Corrente/1000)));
            
            if(m_pgNome->GetDisplayedString() == ""){novoItem.m_Nome = wxString::Format("%d - ", novoItem.m_ID) + m_pgTipo->GetDisplayedString();}
    }
    
    if(m_pgTipo->GetValue().GetInteger() != 0){
        m_Lista.push_back(novoItem);
        
        m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 0, novoItem.m_Nome);
        m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 1, m_pgTipo->GetDisplayedString());
        m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 10, wxString::Format("%d", novoItem.m_ID));
    }
    
    m_pgCorrente->SetValue(0);              //Zerar os valores
    m_pgTempo->SetValue(0);
    m_pgITF->SetValue(0);
    m_pgRTC->SetValue(0);
    m_pgIAIF->SetValue(0);
    m_pgTempoDefinido->SetValue(0);
    
    m_btnCoord->Enable(true);
    
}
void MainFrame::btnClickCoordenograma(wxCommandEvent& event)
{
    std::vector<double> tempo;
    std::vector<ElementPlotData> plotDataList;
        
    ElementPlotData plotData;
    plotData.SetName(wxT("Coordenograma"));
    plotData.SetCurveType(ElementPlotData::CurveType::CT_TEST);
    
    double CorrenteInicioPlot = std::numeric_limits<double>::max();//Maior numero double
    double CorrenteFimPlot = 0;
    
    for(auto item : m_Lista){                                 //Define o come??o do plot a partir das correntes que vai usar
        if(item.m_Tipo == 1 || item.m_Tipo == 2){
           if(item.m_Itf*item.m_RTC <= (CorrenteInicioPlot + 100)){CorrenteInicioPlot = item.m_Itf*item.m_RTC - 100;}
           if(item.m_Itf*item.m_RTC >= (CorrenteFimPlot/120)){CorrenteFimPlot = item.m_Itf*item.m_RTC*120;} 
        }
        else{
            if(item.m_Corrente <= (CorrenteInicioPlot + 100)){CorrenteInicioPlot = item.m_Corrente - 100;}
            if(item.m_Corrente >= (CorrenteFimPlot - 1000)){CorrenteFimPlot = item.m_Corrente + 1000;}
        }
    }
    
    if (CorrenteInicioPlot < 1) {CorrenteInicioPlot = 1;}

    double Imtempo = CorrenteInicioPlot;   //Onde comeca o plot

    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {    //Vetor do tempo
        tempo.emplace_back(log10(Imtempo));                             
        Imtempo += 1;
    }

    double CorrenteAux;                   //Auxiliar no plot para nao mexer no valor inicial escolhido
    
    for(auto item : m_Lista){
        if(item.m_Tipo==1){ //Rele 50/51
            switch (item.m_TipoCurva) {
                case 1:{
                    std::vector<double> curvaNormInv;
                    CorrenteAux = CorrenteInicioPlot;
                    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                        if(CorrenteAux <= item.m_Iaif){curvaNormInv.emplace_back(log10(0.14*item.m_TMS/(pow((CorrenteAux/(item.m_Itf*item.m_RTC)),0.02)-1)));}
                        else{curvaNormInv.emplace_back(-10);} // Fazendo a ativa????o instantanea
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaNormInv, item.m_Nome);
                break;}
                case 2:{
                    std::vector<double> curvaMuitoInv;
                    CorrenteAux = CorrenteInicioPlot;
                    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                        if(CorrenteAux <= item.m_Iaif){curvaMuitoInv.emplace_back(log10(13.5*item.m_TMS/((CorrenteAux/(item.m_Itf*item.m_RTC))-1)));}
                        else{curvaMuitoInv.emplace_back(-10);}
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaMuitoInv, item.m_Nome);
                break;}
                case 3:{
                    std::vector<double> curvaExtInv;
                    CorrenteAux = CorrenteInicioPlot;
                    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                        if(CorrenteAux <= item.m_Iaif){curvaExtInv.emplace_back(log10(80*item.m_TMS/(pow((CorrenteAux/(item.m_Itf*item.m_RTC)),2)-1)));}
                        else{curvaExtInv.emplace_back(-10);}
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaExtInv, item.m_Nome);
                break;}
                case 4:{
                    std::vector<double> curvaInvLonga;
                    CorrenteAux = CorrenteInicioPlot;
                    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                        if(CorrenteAux <= item.m_Iaif){curvaInvLonga.emplace_back(log10(120*item.m_TMS/((CorrenteAux/(item.m_Itf*item.m_RTC))-1)));}
                        else{curvaInvLonga.emplace_back(-10);}
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaInvLonga, item.m_Nome);
                break;}
                case 5:{
                    std::vector<double> curvaInvCurta;
                    CorrenteAux = CorrenteInicioPlot; 
                    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                        if(CorrenteAux <= item.m_Iaif){curvaInvCurta.emplace_back(log10(0.05*item.m_TMS/(pow((CorrenteAux/(item.m_Itf*item.m_RTC)),0.04)-1)));}
                        else{curvaInvCurta.emplace_back(-10);}
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaInvCurta, item.m_Nome);
                break;}
                case 6:{
                    std::vector<double> curvaTermIT;
                    CorrenteAux = CorrenteInicioPlot; 
                    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                        if(CorrenteAux <= item.m_Iaif){curvaTermIT.emplace_back(log10(60*item.m_TMS/(CorrenteAux/(item.m_Itf*item.m_RTC))));}
                        else{curvaTermIT.emplace_back(-10);}
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaTermIT, item.m_Nome);
                break;}
                case 7:{
                    std::vector<double> curvaTermI2T;
                    CorrenteAux = CorrenteInicioPlot;
                    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                        if(CorrenteAux <= item.m_Iaif){curvaTermI2T.emplace_back(log10(540*item.m_TMS/(pow((CorrenteAux/(item.m_Itf*item.m_RTC)),2))));}
                        else{curvaTermI2T.emplace_back(-10);}
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaTermI2T, item.m_Nome);
                }
            }
        }
        else if(item.m_Tipo==2){//Rele 50/51 TD
            switch (item.m_TipoCurva) {
                case 1:{
                    std::vector<double> curvaNormInv;
                    CorrenteAux = CorrenteInicioPlot;
                    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                        if(CorrenteAux <= item.m_Iaif){curvaNormInv.emplace_back(log10(0.14*item.m_TMS/(pow((CorrenteAux/(item.m_Itf*item.m_RTC)),0.02)-1)));}
                        else{curvaNormInv.emplace_back(log10(item.m_TempoDefinido));}
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaNormInv, item.m_Nome);
                break;}
                case 2:{
                    std::vector<double> curvaMuitoInv;
                    CorrenteAux = CorrenteInicioPlot; 
                    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                        if(CorrenteAux <= item.m_Iaif){curvaMuitoInv.emplace_back(log10(13.5*item.m_TMS/((CorrenteAux/(item.m_Itf*item.m_RTC))-1)));}
                        else{curvaMuitoInv.emplace_back(log10(item.m_TempoDefinido));}
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaMuitoInv, item.m_Nome);
                break;}
                case 3:{
                    std::vector<double> curvaExtInv;
                    CorrenteAux = CorrenteInicioPlot;
                    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                        if(CorrenteAux <= item.m_Iaif){curvaExtInv.emplace_back(log10(80*item.m_TMS/(pow((CorrenteAux/(item.m_Itf*item.m_RTC)),2)-1)));}
                        else{curvaExtInv.emplace_back(log10(item.m_TempoDefinido));}
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaExtInv, item.m_Nome);
                break;}
                case 4:{
                    std::vector<double> curvaInvLonga;
                    CorrenteAux = CorrenteInicioPlot; 
                    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                        if(CorrenteAux <= item.m_Iaif){curvaInvLonga.emplace_back(log10(120*item.m_TMS/((CorrenteAux/(item.m_Itf*item.m_RTC))-1)));}
                        else{curvaInvLonga.emplace_back(log10(item.m_TempoDefinido));}
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaInvLonga, item.m_Nome);
                break;}
                case 5:{
                    std::vector<double> curvaInvCurta;
                    CorrenteAux = CorrenteInicioPlot; 
                    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                        if(CorrenteAux <= item.m_Iaif){curvaInvCurta.emplace_back(log10(0.05*item.m_TMS/(pow((CorrenteAux/(item.m_Itf*item.m_RTC)),0.04)-1)));}
                        else{curvaInvCurta.emplace_back(log10(item.m_TempoDefinido));}
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaInvCurta, item.m_Nome);
                break;}
                case 6:{
                    std::vector<double> curvaTermIT;
                    CorrenteAux = CorrenteInicioPlot;
                    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                        if(CorrenteAux <= item.m_Iaif){curvaTermIT.emplace_back(log10(60*item.m_TMS/(CorrenteAux/(item.m_Itf*item.m_RTC))));}
                        else{curvaTermIT.emplace_back(log10(item.m_TempoDefinido));}
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaTermIT, item.m_Nome);
                break;}
                case 7:{
                    std::vector<double> curvaTermI2T;
                    CorrenteAux = CorrenteInicioPlot;
                    for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                        if(CorrenteAux <= item.m_Iaif){curvaTermI2T.emplace_back(log10(540*item.m_TMS/(pow((CorrenteAux/(item.m_Itf*item.m_RTC)),2))));}
                        else{curvaTermI2T.emplace_back(log10(item.m_TempoDefinido));}
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaTermI2T, item.m_Nome);
                }
            }
        }
        else if(item.m_Tipo==3){//ANSI
            std::vector<double> pontoANSI;
            CorrenteAux = CorrenteInicioPlot;
            for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                if(CorrenteAux < item.m_Corrente){pontoANSI.emplace_back(-10);} //Assim n??o aparece no plot
                else if(round(CorrenteAux) == round(item.m_Corrente)){pontoANSI.emplace_back(log10(item.m_Tempo));}
                else{pontoANSI.emplace_back(1000);}                              //Assim n??o aparece no plot
                CorrenteAux += 1;
            }
            plotData.AddData(pontoANSI, item.m_Nome);
        }
        else if(item.m_Tipo==4){//INRUSH
            std::vector<double> pontoINRUSH;
            CorrenteAux = CorrenteInicioPlot;
            for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                if(CorrenteAux < item.m_Corrente){pontoINRUSH.emplace_back(-10);} //Assim n??o aparece no plot
                else if(round(CorrenteAux) == round(item.m_Corrente)){pontoINRUSH.emplace_back(log10(item.m_Tempo));}
                else{pontoINRUSH.emplace_back(1000);}                              //Assim n??o aparece no plot
                CorrenteAux += 1;
            }
            plotData.AddData(pontoINRUSH, item.m_Nome);
        }
        else if(item.m_Tipo==5){//CARGA
            //-----------------------------------------------------------------------------------------------------CORRENTE NOMINAL
            std::vector<double> correnteCarga;
            CorrenteAux = CorrenteInicioPlot;  
            for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                if(CorrenteAux <= item.m_Corrente){correnteCarga.emplace_back(-10);}
                else{correnteCarga.emplace_back(1000);}                              
                CorrenteAux += 1;
            }
            plotData.AddData(correnteCarga, item.m_Nome + wxString::Format(" - I nominal"));
            //-----------------------------------------------------------------------------------------------------PONTO PARTIDA
            std::vector<double> pontoCARGA;
            CorrenteAux = CorrenteInicioPlot;
            for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                if(CorrenteAux < item.m_Carga_Ipartida){pontoCARGA.emplace_back(-10);}
                else if(round(CorrenteAux) == round(item.m_Carga_Ipartida)){pontoCARGA.emplace_back(log10(item.m_Carga_Tpartida));}
                else{pontoCARGA.emplace_back(1000);}                              
                CorrenteAux += 1;
            }
            plotData.AddData(pontoCARGA, item.m_Nome + wxString::Format(" - Ponto de Partida"));
        }
        else if(item.m_Tipo==6){//ICC
            std::vector<double> correnteICC;
            CorrenteAux = CorrenteInicioPlot;
            for(int i = CorrenteInicioPlot; i < CorrenteFimPlot; ++i) {
                if(CorrenteAux <= item.m_Corrente){correnteICC.emplace_back(-10);} //Assim n??o aparece no plot
                else{correnteICC.emplace_back(1000);}                              //Assim n??o aparece no plot
                CorrenteAux += 1;
            }
            plotData.AddData(correnteICC, item.m_Nome);
        }
    }
    plotDataList.push_back(plotData);
    
    ChartView* cView = new ChartView(nullptr, plotDataList, tempo);
    
    //Alterar para os valores na ordem: M??nima corrente (x), M??xima corrente (x), M??nimoM??ximo Tempo (y), M??ximo tempo (y)
    cView->LockFit(log10(CorrenteInicioPlot), log10(CorrenteFimPlot), -1.5, log10(100)); // Ou log10(0.01) por exemplo 
    
    for(auto item : m_Lista){
        if(item.m_Tipo==5){
            cView->m_ListaTipo.push_back(item.m_Tipo);
            cView->m_ListaTipo.push_back(item.m_Tipo);
        }
        else {cView->m_ListaTipo.push_back(item.m_Tipo);}
    }
    
    //wxString texto = "";
    //texto += wxString::Format("%d\n", AUXILIAREXCLUIR);
    //wxMessageBox(texto);
    
    cView->Show();
                                                                         
    }
void MainFrame::onPGChange(wxPropertyGridEvent& event)
{
    m_pgCorrente->Enable(false);
    ChangePropertyText(m_pgCorrente,wxT("-"));
    m_pgTempo->Enable(false);
    ChangePropertyText(m_pgTempo,wxT("-"));
    m_pgITF->Enable(false);
    ChangePropertyText(m_pgITF,wxT("-"));
    m_pgIAIF->Enable(false);
    ChangePropertyText(m_pgIAIF,wxT("-"));
    m_pgRTC->Enable(false);
    ChangePropertyText(m_pgRTC,wxT("-"));
    m_pgTempoDefinido->Enable(false);
    ChangePropertyText(m_pgTempoDefinido,wxT("-"));
    m_pgTipoCurva->Enable(false);
    ChangePropertyText(m_pgTipoCurva,wxT("-"));
    
    switch(m_pgTipo->GetValue().GetInteger()){
        case 1:{ //Rel?? 50/51
            //ChangePropertyText(m_pgCorrente,wxT("Corrente"));
            ChangePropertyText(m_pgTempo,wxT("TMS"));
            ChangePropertyText(m_pgITF,wxT("Itf"));
            ChangePropertyText(m_pgIAIF,wxT("Iaif"));
            ChangePropertyText(m_pgRTC,wxT("RTC"));
            ChangePropertyText(m_pgTipoCurva,wxT("Tipo de Curva"));
            //m_pgCorrente->Enable(true);
            m_pgTempo->Enable(true);
            m_pgITF->Enable(true);
            m_pgIAIF->Enable(true);
            m_pgRTC->Enable(true);
            m_pgTipoCurva->Enable(true);
            break;
        }
        case 2:{ //Rel???? 50/51 TD
            //ChangePropertyText(m_pgCorrente,wxT("Corrente"));
            ChangePropertyText(m_pgTempo,wxT("TMS"));
            ChangePropertyText(m_pgRTC,wxT("RTC"));
            ChangePropertyText(m_pgTempoDefinido,wxT("Tempo Definido"));
            ChangePropertyText(m_pgITF,wxT("Itf"));
            ChangePropertyText(m_pgIAIF,wxT("Iaif"));
            ChangePropertyText(m_pgTipoCurva,wxT("Tipo de Curva"));
            //m_pgCorrente->Enable(true);
            m_pgTempo->Enable(true);
            m_pgITF->Enable(true);
            m_pgIAIF->Enable(true);
            m_pgRTC->Enable(true);
            m_pgTempoDefinido->Enable(true);
            m_pgTipoCurva->Enable(true);
            break;
        }
        case 3:{ //ANSI
            ChangePropertyText(m_pgCorrente,wxT("Corrente"));
            ChangePropertyText(m_pgTempo,wxT("Tempo"));
            m_pgCorrente->Enable(true);
            m_pgTempo->Enable(true);
            break;
        }
        case 4:{ //INRUSH
            ChangePropertyText(m_pgCorrente,wxT("Corrente"));
            ChangePropertyText(m_pgTempo,wxT("Tempo"));
            m_pgCorrente->Enable(true);
            m_pgTempo->Enable(true);
            break;
        }
        case 5:{ //Carga
            ChangePropertyText(m_pgCorrente,wxT("Corrente Nominal"));
            ChangePropertyText(m_pgTempo,wxT("Tempo de partida"));
            ChangePropertyText(m_pgITF,wxT("Corrente de partida"));
            m_pgCorrente->Enable(true);
            m_pgTempo->Enable(true);
            m_pgITF->Enable(true);
            break;
        }
        case 6:{ //ICC
            ChangePropertyText(m_pgCorrente,wxT("Corrente de curto-circuito"));
            m_pgCorrente->Enable(true);
        }
    }
    m_pgDados->Refresh();
}
void MainFrame::ChangePropertyText(wxPGProperty* property, wxString newText)
{
    wxPGCell cell = property->GetCell(0);
    cell.SetText(newText);
    property->SetCell(0, cell);
}
void MainFrame::grid_CellSelected(wxGridEvent& event)
{
    m_btnEdit->Enable(true);
    m_btnExcluir->Enable(true);
    for(int i = 0; i < m_Lista.size(); i++){
        if(wxString::Format("%d", m_Lista[i].m_ID) == m_grid->GetCellValue(event.GetRow(), 10)){m_Lista[i].m_StatusModify = 1;}
        else{m_Lista[i].m_StatusModify = 0;}
    }
}
void MainFrame::btnClickExcluir(wxCommandEvent& event)
{
    for(int i = 0; i < m_Lista.size(); i++){
        if(m_Lista[i].m_StatusModify == 1){
            m_Lista.erase(m_Lista.begin()+i);
            m_grid->DeleteRows(i);
        }
    }
    
    if(m_Lista.empty()){
        m_btnEdit->Enable(false);
        m_btnExcluir->Enable(false);
        m_btnCoord->Enable(false);
    }
}
void MainFrame::btnClickEditar(wxCommandEvent& event)
{
    std::vector<float> itemEdit;
    
    for(int i = 0; i < m_Lista.size(); i++){
        if(m_Lista[i].m_StatusModify == 1){
            
            itemEdit.push_back(m_Lista[i].m_ID);
            itemEdit.push_back(m_Lista[i].m_Tipo);
            
            if(m_Lista[i].m_Tipo == 1 || m_Lista[i].m_Tipo == 2){   //RELE 5051 E RELE5051TD
                itemEdit.push_back(m_Lista[i].m_TMS);
                itemEdit.push_back(m_Lista[i].m_Itf);
                itemEdit.push_back(m_Lista[i].m_RTC);
                itemEdit.push_back(m_Lista[i].m_Iaif);
                itemEdit.push_back(m_Lista[i].m_TipoCurva);
                if(m_Lista[i].m_Tipo == 2){itemEdit.push_back(m_Lista[i].m_TempoDefinido);} // RELETD
            }
            
            else{ 
                itemEdit.push_back(m_Lista[i].m_Corrente);                  //ICC
                if(m_Lista[i].m_Tipo == 3 || m_Lista[i].m_Tipo == 4){       //ANSI E INRUSH
                    itemEdit.push_back(m_Lista[i].m_Tempo);
                }
                else if(m_Lista[i].m_Tipo == 5){                           //CARGA
                    itemEdit.push_back(m_Lista[i].m_Carga_Ipartida);
                    itemEdit.push_back(m_Lista[i].m_Carga_Tpartida);
                }
            }
        }
    }
    
    edit_Dialog* eDialog = new edit_Dialog(nullptr, itemEdit);
    eDialog->ShowModal();
    
    for(int i = 0; i < m_Lista.size(); i++){
        if(m_Lista[i].m_ID == eDialog->m_itemEdit[0]){   //RELE 5051 E RELE5051TD
        
            if(m_Lista[i].m_Tipo == 1 || m_Lista[i].m_Tipo == 2){   //RELE 5051 E RELE5051TD
                m_Lista[i].m_TMS = eDialog->m_itemEdit[2];
                m_Lista[i].m_Itf = eDialog->m_itemEdit[3];
                m_Lista[i].m_RTC = eDialog->m_itemEdit[4];
                m_Lista[i].m_Iaif = eDialog->m_itemEdit[5];
                m_Lista[i].m_TipoCurva = eDialog->m_itemEdit[6];
                if(m_Lista[i].m_Tipo == 2){m_Lista[i].m_TempoDefinido = eDialog->m_itemEdit[7];} // RELETD
            }
            
            else{ 
                m_Lista[i].m_Corrente = eDialog->m_itemEdit[2];             //ICC
                if(m_Lista[i].m_Tipo == 3 || m_Lista[i].m_Tipo == 4){       //ANSI E INRUSH
                    m_Lista[i].m_Tempo = eDialog->m_itemEdit[3];
                }
                else if(m_Lista[i].m_Tipo == 5){                           //CARGA
                    m_Lista[i].m_Carga_Ipartida = eDialog->m_itemEdit[4];
                    m_Lista[i].m_Carga_Tpartida = eDialog->m_itemEdit[5];
                }
            }
        }
    }
    
    AttLineGrid(eDialog->m_itemEdit[0]);
    
    eDialog->Destroy();
}