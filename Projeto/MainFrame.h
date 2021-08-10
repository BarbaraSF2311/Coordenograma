#ifndef MAINFRAME_H
#define MAINFRAME_H
#include "wxcrafter.h"
#include <wx/msgdlg.h>

class MainFrame : public MainFrameBaseClass
{
public:
    MainFrame(wxWindow* parent);
    virtual ~MainFrame();

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
protected:
    virtual void btnClickSoma(wxCommandEvent& event);
    virtual void btnClickSubtracao(wxCommandEvent& event);

};
#endif // MAINFRAME_H
