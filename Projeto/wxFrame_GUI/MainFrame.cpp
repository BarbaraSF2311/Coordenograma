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
    m_grid->AppendCols(8,true);
    //m_grid->SetColMinimalAcceptableWidth(100);
    
    //Nome das colunas
    m_grid->SetColLabelValue(0,wxT("ID"));
    m_grid->SetColLabelValue(1,wxT("Tipo"));
    m_grid->SetColLabelValue(2,wxT("Corrente"));
    m_grid->SetColLabelValue(3,wxT("Tempo"));
    m_grid->SetColLabelValue(4,wxT("Itf/Icarga"));
    m_grid->SetColLabelValue(5,wxT("RTC/TD"));
    m_grid->SetColLabelValue(6,wxT("Iaif"));
    m_grid->SetColLabelValue(7,wxT("Tipo de Curva"));
    
    //m_grid->HideCol(0);
    m_grid->SetColSize(0,30);
    m_grid->SetColSize(1,85);
    m_grid->SetColSize(2,70);
    m_grid->SetColSize(3,50);
    m_grid->SetColSize(4,70);
    m_grid->SetColSize(5,60);
    m_grid->SetColSize(6,50);
    m_grid->SetColSize(7,190);
    
    
    //Organizando casas das colunas floats
    m_grid->SetColFormatFloat(2, 7, 1);
    m_grid->SetColFormatFloat(3, 7, 2);
    m_grid->SetColFormatFloat(4, 7, 2);
    m_grid->SetColFormatFloat(5, 7, 2);
    m_grid->SetColFormatFloat(6, 7, 2);

    //m_grid->SetCellValue(1,2,wxT("Teste 1x2"));
    
    //m_grid->AutoSizeColumns();
    //m_grid->Refresh();
}

void MainFrame::btnClickAdicionar(wxCommandEvent& event)
{
    Item novoItem;
    novoItem.m_ID = m_IDatual;
    m_IDatual++;
    
    switch (m_pgTipo->GetValue().GetInteger()) {
        case 0: //Nenhum selecionado
            wxMessageBox(wxT("Selecione o tipo de dado"));
            break;
        case 1: //Rele 50/51
            novoItem.m_Tipo = 1;                                          //Colocando os dados no struct
            novoItem.m_Corrente = m_pgCorrente->GetValue();
            novoItem.m_Iaif = m_pgIAIF->GetValue();
            novoItem.m_TMS = m_pgTempo->GetValue();
            novoItem.m_Itf = m_pgITF->GetValue();
            novoItem.m_RTC = m_pgRTC->GetValue();
            novoItem.m_TipoCurva = m_pgTipoCurva->GetValue().GetInteger();
            
            m_grid->AppendRows(1,true);                                  //Acrescentando a linha no grid e mostrando
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 2, wxString::Format("%f", novoItem.m_Corrente));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 3, wxString::Format("%f", novoItem.m_TMS));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 4, wxString::Format("%f", novoItem.m_Itf));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 5, wxString::Format("%f", novoItem.m_RTC));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 6, wxString::Format("%f", novoItem.m_Iaif));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 7, m_pgTipoCurva->GetDisplayedString());
            
            break;
        case 2: //Rele 50/51 TD
            novoItem.m_Tipo = 2;
            novoItem.m_Corrente = m_pgCorrente->GetValue();
            novoItem.m_Iaif = m_pgIAIF->GetValue();
            novoItem.m_Itf = m_pgITF->GetValue();
            novoItem.m_TMS = m_pgTempo->GetValue();
            novoItem.m_RTC = m_pgRTC->GetValue();
            novoItem.m_TempoDefinido = m_pgTempoDefinido->GetValue();
            novoItem.m_TipoCurva = m_pgTipoCurva->GetValue().GetInteger();
            
            m_grid->AppendRows(1,true);
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 2, wxString::Format("%f", novoItem.m_Corrente));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 3, wxString::Format("%f", novoItem.m_TMS));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 4, wxString::Format("%f", novoItem.m_Itf));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 5, wxString::Format("%f", novoItem.m_TempoDefinido));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 6, wxString::Format("%f", novoItem.m_Iaif));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 7, m_pgTipoCurva->GetDisplayedString());
            
            break;
        case 3: //ANSI
            novoItem.m_Tipo = 3;
            novoItem.m_Tempo = m_pgTempo->GetValue();
            novoItem.m_Corrente = m_pgCorrente->GetValue();
            
            m_grid->AppendRows(1,true);
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 2, wxString::Format("%f", novoItem.m_Corrente));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 3, wxString::Format("%f", novoItem.m_Tempo));
            
            break;
        case 4: //INRUSH
            novoItem.m_Tipo = 4;
            novoItem.m_Tempo = m_pgTempo->GetValue();
            novoItem.m_Corrente = m_pgCorrente->GetValue();
            
            m_grid->AppendRows(1,true);
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 2, wxString::Format("%f", novoItem.m_Corrente));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 3, wxString::Format("%f", novoItem.m_Tempo));
            
            break;
        case 5: //CARGA
            novoItem.m_Tipo = 5;
            novoItem.m_Corrente = m_pgCorrente->GetValue();
            novoItem.m_Carga_Ipartida = m_pgITF->GetValue();
            novoItem.m_Carga_Tpartida = m_pgTempo->GetValue();
            
            m_grid->AppendRows(1,true);
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 2, wxString::Format("%f", novoItem.m_Corrente));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 3, wxString::Format("%f", novoItem.m_Carga_Tpartida));
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 4, wxString::Format("%f", novoItem.m_Carga_Ipartida));
            
            break;
        case 6: //ICC
            novoItem.m_Tipo = 6;
            novoItem.m_Corrente = m_pgCorrente->GetValue();
            
            m_grid->AppendRows(1,true);
            m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 2, wxString::Format("%f", novoItem.m_Corrente));
    }

    m_Lista.push_back(novoItem);
    
    m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 0, wxString::Format("%d", novoItem.m_ID));
    m_grid->SetCellValue(m_grid->GetNumberRows() - 1, 1, m_pgTipo->GetDisplayedString());
    
    
}

void MainFrame::btnClickCoordenograma(wxCommandEvent& event)
{
    std::vector<double> tempo;
    std::vector<ElementPlotData> plotDataList;
        
    ElementPlotData plotData;
    plotData.SetName(wxT("Teste att"));
    plotData.SetCurveType(ElementPlotData::CurveType::CT_TEST);

    double Imtempo = 200;               //Onde comeÃ§a o plot

    for(int i = 0; i < 1800; ++i) {    //Quanto mais vai plotar
        tempo.emplace_back(Imtempo);
        Imtempo += 1;
    }
    
    double CorrenteAux;                   //Auxiliar no plot para nÃ£o mexer no valor inicial escolhido
    
    wxString texto = "";
    for(auto item : m_Lista){
        if(item.m_Tipo==1){ //Rele 50/51
            texto += wxString::Format("Rele 50/51\nID = %d, TMS = %.2f, Corrente = %.2f\n",item.m_ID,item.m_TMS,item.m_Corrente);
            switch (item.m_TipoCurva) {
                case 1:{
                    std::vector<double> curvaNormInv;
                    CorrenteAux = item.m_Corrente;
                    for(int i = 0; i < 1800; ++i) {
                        item.m_tempo51.emplace_back(CorrenteAux);
                        curvaNormInv.emplace_back(0.14*item.m_TMS/(pow((CorrenteAux/(item.m_Itf*item.m_RTC)),0.02)-1));
                        CorrenteAux += 1;
                    }
                    plotData.AddData(curvaNormInv, wxT("Curva Normalmente Inversa"));
                break;}
                case 2:{
                    std::vector<double> curvaMuitoInv;
                    for(int i = 0; i < 1800; ++i) {
                        item.m_tempo51.emplace_back(item.m_Corrente);
                        curvaMuitoInv.emplace_back(13.5*item.m_TMS/((item.m_Corrente/(item.m_Itf*item.m_RTC))-1));
                        item.m_Corrente += 1;
                    }
                    plotData.AddData(curvaMuitoInv, wxT("Curva Muito Inversa"));
                break;}
                case 3:{
                    std::vector<double> curvaExtInv;
                    for(int i = 0; i < 1800; ++i) {
                        item.m_tempo51.emplace_back(item.m_Corrente);
                        curvaExtInv.emplace_back(80*item.m_TMS/(pow((item.m_Corrente/(item.m_Itf*item.m_RTC)),2)-1));
                        item.m_Corrente += 1;
                    }
                    plotData.AddData(curvaExtInv, wxT("Curva Extremamente Inversa"));
                break;}
                case 4:{
                    std::vector<double> curvaInvLonga;
                    for(int i = 0; i < 1800; ++i) {
                        item.m_tempo51.emplace_back(item.m_Corrente);
                        curvaInvLonga.emplace_back(120*item.m_TMS/((item.m_Corrente/(item.m_Itf*item.m_RTC))-1));
                        item.m_Corrente += 1;
                    }
                    plotData.AddData(curvaInvLonga, wxT("Curva Inversa Longa - Tempo definido"));
                break;}
                case 5:{
                    std::vector<double> curvaInvCurta;
                    for(int i = 0; i < 1800; ++i) {
                        item.m_tempo51.emplace_back(item.m_Corrente);
                        curvaInvCurta.emplace_back(0.05*item.m_TMS/(pow((item.m_Corrente/(item.m_Itf*item.m_RTC)),0.04)-1));
                        item.m_Corrente += 1;
                    }
                    plotData.AddData(curvaInvCurta, wxT("Curva Inversa Curta"));
                break;}
                case 6:{
                    std::vector<double> curvaTermIT;
                    for(int i = 0; i < 1800; ++i) {
                        item.m_tempo51.emplace_back(item.m_Corrente);
                        curvaTermIT.emplace_back(60*item.m_TMS/(item.m_Corrente/(item.m_Itf*item.m_RTC)));
                        item.m_Corrente += 1;
                    }
                    plotData.AddData(curvaTermIT, wxT("Curva TÃ©rmica IxT"));
                break;}
                case 7:{
                    std::vector<double> curvaTermI2T;
                    for(int i = 0; i < 1800; ++i) {
                        item.m_tempo51.emplace_back(item.m_Corrente);
                        curvaTermI2T.emplace_back(540*item.m_TMS/(pow((item.m_Corrente/(item.m_Itf*item.m_RTC)),2)));
                        item.m_Corrente += 1;
                    }
                    plotData.AddData(curvaTermI2T, wxT("Curva TÃ©rmica I2xT"));
                }
            }

        }
        else if(item.m_Tipo==2){//Rele 50/51 TD
            texto += wxString::Format("Rele 50/51TD\nID = %d, TMS = %.2f, RTC = %.2f\n",item.m_ID,item.m_TMS,item.m_RTC);
        }
        else if(item.m_Tipo==3){//ANSI
            texto += wxString::Format("ANSI\nID = %d, Corrente = %.2f, Tempo = %.2f\n",item.m_ID,item.m_Corrente,item.m_Tempo);
        }
        else if(item.m_Tipo==4){//INRUSH
            texto += wxString::Format("ANSI\nID = %d, Corrente = %.2f, Tempo = %.2f\n",item.m_ID,item.m_Corrente,item.m_Tempo);
        }
        else if(item.m_Tipo==5){//CARGA
            texto += wxString::Format("ANSI\nID = %d, Corrente = %.2f, Tempo = %.2f\n",item.m_ID,item.m_Corrente,item.m_Tempo);
        }
        else if(item.m_Tipo==6){//ICC
            texto += wxString::Format("ICC\nID = %d, Corrente = %.2f\n",item.m_ID,item.m_Corrente);
        }
    }
    wxMessageBox(texto);
    plotDataList.push_back(plotData);
    
    ChartView* cView = new ChartView(nullptr, plotDataList, tempo);
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
        case 1:{ //RelÃ© 50/51
            ChangePropertyText(m_pgCorrente,wxT("Corrente"));
            ChangePropertyText(m_pgTempo,wxT("TMS"));
            ChangePropertyText(m_pgITF,wxT("Itf"));
            ChangePropertyText(m_pgIAIF,wxT("Iaif"));
            ChangePropertyText(m_pgRTC,wxT("RTC"));
            ChangePropertyText(m_pgTipoCurva,wxT("Tipo de Curva"));
            m_pgCorrente->Enable(true);
            m_pgTempo->Enable(true);
            m_pgITF->Enable(true);
            m_pgIAIF->Enable(true);
            m_pgRTC->Enable(true);
            m_pgTipoCurva->Enable(true);
            break;
        }
        case 2:{ //RelÃ© 50/51 TD
            ChangePropertyText(m_pgCorrente,wxT("Corrente"));
            ChangePropertyText(m_pgTempo,wxT("TMS"));
            ChangePropertyText(m_pgRTC,wxT("RTC"));
            ChangePropertyText(m_pgTempoDefinido,wxT("Tempo Definido"));
            ChangePropertyText(m_pgITF,wxT("Itf"));
            ChangePropertyText(m_pgIAIF,wxT("Iaif"));
            ChangePropertyText(m_pgTipoCurva,wxT("Tipo de Curva"));
            m_pgCorrente->Enable(true);
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

void MainFrame::grid_CellChanged(wxGridEvent& event)
{
    //int row;
    //row = m_grid->GetSelectedRows()[0];
    //wxMessageBox(wxT("A linha selecionada Ã© %d", row))
    //printf("A linha selecionada Ã© %d", row);Ã§
    
    long int id = -1;
    m_grid->GetCellValue(event.GetRow(), 0).ToLong(&id);
    //FillPG(id);
    printf("O id selecionado foi: %d", id);
    
    event.Skip();
}
void MainFrame::grid_CellSelected(wxGridEvent& event)
{
    long int id = -1;
    m_grid->GetCellValue(event.GetRow(), 0).ToLong(&id);
    //FillPG(id);
    printf("O id selecionado foi: %d", id);
}