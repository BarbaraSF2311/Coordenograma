#include "MainFrame.h"
#include <wx/aboutdlg.h>

MainFrame::MainFrame(wxWindow* parent)
    : MainFrameBaseClass(parent)
{
}

MainFrame::~MainFrame()
{
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxUnusedVar(event);
    wxAboutDialogInfo info;
    info.SetCopyright(_("My MainFrame"));
    info.SetLicence(_("GPL v2 or later"));
    info.SetDescription(_("Short description goes here"));
    ::wxAboutBox(info);
}

void MainFrame::btnClickSoma(wxCommandEvent& event)
{
    double v1 = 0.0;
    double v2 = 0.0;
    
    m_txtValor1->GetValue().ToDouble(&v1);
    m_txtValor2->GetValue().ToDouble(&v2);
    
    m_txtResultado->SetValue(wxString::FromDouble(v1+v2,2));
}
void MainFrame::btnClickSubtracao(wxCommandEvent& event)
{
    double v1 = 0.0;
    double v2 = 0.0;
    
    m_txtValor1->GetValue().ToDouble(&v1);
    m_txtValor2->GetValue().ToDouble(&v2);
    
    m_txtResultado->SetValue(wxString::FromDouble(v1-v2,2));
}
