#ifndef EDIT_DIALOG_H
#define EDIT_DIALOG_H
#include "wxcrafter.h"
#include <wx/msgdlg.h>

class edit_Dialog : public editDialog
{
public:
    edit_Dialog(wxWindow* parent, std::vector<float> itemEdit);
    virtual ~edit_Dialog();
    
    std::vector<float> m_itemEdit;
protected:
    virtual void btnClickCancelar(wxCommandEvent& event);
    virtual void btnClickEditar(wxCommandEvent& event);
};
#endif // EDIT_DIALOG_H
