#include "MainFrame.h"
#include <wx/aboutdlg.h>

MainFrame::MainFrame(wxWindow* parent)
    : MainFrameBaseClass(parent)
{
}

MainFrame::~MainFrame()
{
}

void MainFrame::btnClickAdicionar(wxCommandEvent& event)
{
    Item novoItem;
    novoItem.m_ID = m_IDatual;
    m_IDatual++;
    
    switch (m_pgTipo->GetValue().GetInteger()) {
        case 1: //Rele 50/51
            novoItem.m_Tipo = 1;
            novoItem.m_Corrente = m_pgCorrente->GetValue();
            novoItem.m_Iaif = m_pgIAIF->GetValue();
            novoItem.m_TMS = m_pgTempo->GetValue();
            novoItem.m_Iatf = m_pgIATF->GetValue();
            novoItem.m_F = m_pgF->GetValue();
            novoItem.m_TipoCurva = m_pgTipoCurva->GetValue().GetInteger();
            break;
        case 2: //Rele 50/51 TD
            novoItem.m_Tipo = 2;
            novoItem.m_Corrente = m_pgCorrente->GetValue();
            novoItem.m_Iaif = m_pgIAIF->GetValue();
            novoItem.m_Iatf = m_pgIATF->GetValue();
            novoItem.m_TMS = m_pgTempo->GetValue();
            novoItem.m_TempoDefinido = m_pgIATF->GetValue();
            novoItem.m_TipoCurva = m_pgTipoCurva->GetValue().GetInteger();
            break;
        case 3: //ANSI
            novoItem.m_Tipo = 3;
            novoItem.m_Tempo = m_pgTempo->GetValue();
            novoItem.m_Corrente = m_pgCorrente->GetValue();
            break;
        case 4: //INRUSH
            novoItem.m_Tipo = 4;
            novoItem.m_Tempo = m_pgTempo->GetValue();
            novoItem.m_Corrente = m_pgCorrente->GetValue();
            break;
        case 5: //CARGA
            novoItem.m_Tipo = 5;
            novoItem.m_Corrente = m_pgCorrente->GetValue();
            novoItem.m_Carga_Ipartida = m_pgIATF->GetValue();
            novoItem.m_Carga_Tpartida = m_pgTempo->GetValue();
            break;
        case 6: //ICC
            novoItem.m_Tipo = 6;
            novoItem.m_Corrente = m_pgCorrente->GetValue();
    }

    m_Lista.push_back(novoItem);
    
}

void MainFrame::btnClickCoordenograma(wxCommandEvent& event)
{
    std::vector<double> tempo;
    std::vector<ElementPlotData> plotDataList;
        
    ElementPlotData plotData;
    plotData.SetName(wxT("Teste att"));
    plotData.SetCurveType(ElementPlotData::CurveType::CT_TEST);

    double Imtempo = 200;

    for(int i = 0; i < 1800; ++i) {
        tempo.emplace_back(Imtempo);
        Imtempo += 1;
    }
    
    wxString texto = "";
    for(auto item : m_Lista){
        if(item.m_Tipo==1){ //Rele 50/51
            texto += wxString::Format("Rele 50/51\nID = %d, TMS = %.2f, Corrente = %.2f\n",item.m_ID,item.m_TMS,item.m_Corrente);
            switch (item.m_TipoCurva) {
                case 1:{
                    std::vector<double> curvaNormInv;
                    for(int i = 0; i < 1800; ++i) {
                        item.m_tempo51.emplace_back(item.m_Corrente);
                        curvaNormInv.emplace_back(0.14*item.m_TMS/(pow((item.m_Corrente/(item.m_Iatf)),0.02)-1));
                        item.m_Corrente += 1;
                    }
                    plotData.AddData(curvaNormInv, wxT("Curva Normalmente Inversa"));
                break;}
                case 2:{
                    std::vector<double> curvaMuitoInv;
                    for(int i = 0; i < 1800; ++i) {
                        item.m_tempo51.emplace_back(item.m_Corrente);
                        curvaMuitoInv.emplace_back(13.5*item.m_TMS/((item.m_Corrente/item.m_Iatf)-1));
                        item.m_Corrente += 1;
                    }
                    plotData.AddData(curvaMuitoInv, wxT("Curva Muito Inversa"));
                break;}
                case 3:{
                    std::vector<double> curvaExtInv;
                    for(int i = 0; i < 1800; ++i) {
                        item.m_tempo51.emplace_back(item.m_Corrente);
                        curvaExtInv.emplace_back(80*item.m_TMS/(pow((item.m_Corrente/item.m_Iatf),2)-1));
                        item.m_Corrente += 1;
                    }
                    plotData.AddData(curvaExtInv, wxT("Curva Extremamente Inversa"));
                break;}
                case 4:{
                    std::vector<double> curvaInvLonga;
                    for(int i = 0; i < 1800; ++i) {
                        item.m_tempo51.emplace_back(item.m_Corrente);
                        curvaInvLonga.emplace_back(120*item.m_TMS/((item.m_Corrente/item.m_Iatf)-1));
                        item.m_Corrente += 1;
                    }
                    plotData.AddData(curvaInvLonga, wxT("Curva Inversa Longa - Tempo definido"));
                break;}
                case 5:{
                    std::vector<double> curvaInvCurta;
                    for(int i = 0; i < 1800; ++i) {
                        item.m_tempo51.emplace_back(item.m_Corrente);
                        curvaInvCurta.emplace_back(0.05*item.m_TMS/(pow((item.m_Corrente/item.m_Iatf),0.04)-1));
                        item.m_Corrente += 1;
                    }
                    plotData.AddData(curvaInvCurta, wxT("Curva Inversa Curta"));
                break;}
                case 6:{
                    std::vector<double> curvaTermIT;
                    for(int i = 0; i < 1800; ++i) {
                        item.m_tempo51.emplace_back(item.m_Corrente);
                        curvaTermIT.emplace_back(60*item.m_TMS/(item.m_Corrente/item.m_Iatf));
                        item.m_Corrente += 1;
                    }
                    plotData.AddData(curvaTermIT, wxT("Curva Térmica IxT"));
                break;}
                case 7:{
                    std::vector<double> curvaTermI2T;
                    for(int i = 0; i < 1800; ++i) {
                        item.m_tempo51.emplace_back(item.m_Corrente);
                        curvaTermI2T.emplace_back(540*item.m_TMS/(pow((item.m_Corrente/item.m_Iatf),2)));
                        item.m_Corrente += 1;
                    }
                    plotData.AddData(curvaTermI2T, wxT("Curva Térmica I2xT"));
                }
            }

        }
        else if(item.m_Tipo==2){//Rele 50/51 TD
            texto += wxString::Format("Rele 50/51TD\nID = %d, TMS = %.2f, F = %.2f\n",item.m_ID,item.m_TMS,item.m_F);
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
    m_pgTempo->Enable(false);
    m_pgIATF->Enable(false);
    m_pgIAIF->Enable(false);
    m_pgF->Enable(false);
    m_pgTipoCurva->Enable(false);
    
    switch(m_pgTipo->GetValue().GetInteger()){
        case 1:{ //Relé 50/51
            ChangePropertyText(m_pgCorrente,wxT("Corrente"));
            ChangePropertyText(m_pgTempo,wxT("TMS"));
            ChangePropertyText(m_pgIATF,wxT("Iatf"));
            ChangePropertyText(m_pgF,wxT("F"));
            m_pgTempo->Enable(true);
            m_pgIATF->Enable(true);
            m_pgIAIF->Enable(true);
            //m_pgF->Enable(true);
            m_pgTipoCurva->Enable(true);
            break;
        }
        case 2:{ //Relé 50/51 TD
            ChangePropertyText(m_pgCorrente,wxT("Corrente"));
            ChangePropertyText(m_pgTempo,wxT("TMS"));
            ChangePropertyText(m_pgF,wxT("Tempo Definido"));
            ChangePropertyText(m_pgIATF,wxT("Iatf"));
            m_pgTempo->Enable(true);
            m_pgIATF->Enable(true);
            m_pgIAIF->Enable(true);
            m_pgF->Enable(true);
            m_pgTipoCurva->Enable(true);
            break;
        }
        case 3:{ //ANSI
            ChangePropertyText(m_pgCorrente,wxT("Corrente"));
            ChangePropertyText(m_pgTempo,wxT("Tempo"));
            m_pgTempo->Enable(true);
            break;
        }
        case 4:{ //INRUSH
            ChangePropertyText(m_pgCorrente,wxT("Corrente"));
            ChangePropertyText(m_pgTempo,wxT("Tempo"));
            m_pgTempo->Enable(true);
            break;
        }
        case 5:{ //Carga
            ChangePropertyText(m_pgCorrente,wxT("Corrente Nominal"));
            ChangePropertyText(m_pgTempo,wxT("Tempo de partida"));
            ChangePropertyText(m_pgIATF,wxT("Corrente de partida"));
            m_pgTempo->Enable(true);
            m_pgIATF->Enable(true);
            break;
        }
        case 6:{ //ICC
            ChangePropertyText(m_pgCorrente,wxT("Corrente de curto-circuito"));
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

