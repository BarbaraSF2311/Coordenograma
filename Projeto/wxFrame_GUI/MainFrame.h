#ifndef MAINFRAME_H
#define MAINFRAME_H
#include "wxcrafter.h"
#include <wx/app.h>
#include <wx/event.h>
#include "ChartView.h"
#include "ElementPlotData.h"
#include <wx/image.h>
#include <wx/msgdlg.h>
#include <complex.h>

struct Item{
    
    int m_ID = 0;
    double m_Tipo = 0; //1=rele50/51;2=rele50/51TD;3=ANSI;4=inrush;5=carga;6=ICC;
    double m_RTC = 0;
    double m_Tempo = 0;
    double m_Corrente = 0;
    double m_Carga_Ipartida = 0;
    double m_Carga_Tpartida = 0;
    double m_Itf = 0;
    double m_TMS = 0;
    double m_Iaif = 0;
    double m_TempoDefinido = 0;  
    int m_TipoCurva = 0; //1=inversa;2=MI;3=EI;4=InvLonga;5=InvCurta;6=TÃ©rmica1;7=TÃ©rm.2;
    std::vector<double> m_tempo51;
    
    
};


class MainFrame : public MainFrameBaseClass
{
public:
    MainFrame(wxWindow* parent);
    virtual ~MainFrame();

protected:
    virtual void grid_CellSelected(wxGridEvent& event);
    virtual void grid_CellChanged(wxGridEvent& event);
    virtual void btnClickAdicionar(wxCommandEvent& event);
    virtual void onPGChange(wxPropertyGridEvent& event);
    virtual void btnClickCoordenograma(wxCommandEvent& event);
    
    virtual void InitFrame();
    virtual void BuildGrid();
    virtual void ChangePropertyText(wxPGProperty* property, wxString newText);
    
    std::vector<Item> m_Lista;
    
    int m_IDatual = 0;

};
#endif // MAINFRAME_H