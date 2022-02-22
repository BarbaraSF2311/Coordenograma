#include "edit_Dialog.h"

edit_Dialog::edit_Dialog(wxWindow* parent, std::vector<float> itemEdit)
    : editDialog(parent)
{
    m_itemEdit = itemEdit;
    
    
    //wxString texto = "";
    //for(int i = 0; i < m_itemEdit.size(); i++){texto += wxString::Format("%d: %d\n", i, m_itemEdit[i]);}
    //wxMessageBox(texto);
    
    int intaux = m_itemEdit[1];
    
    switch (intaux) {
        case 1:  //RELE 5051
            
            //LABELS UTILIZADOS
            m_lbl1->SetLabel(wxT("TMS [s]"));
            m_txt1->ChangeValue(wxString::Format("%.2f", m_itemEdit[2]));
            
            m_lbl2->SetLabel(wxT("Itf [A]"));
            m_txt2->ChangeValue(wxString::Format("%.2f", m_itemEdit[3]));
            
            m_lbl3->SetLabel(wxT("RTC"));
            m_txt3->ChangeValue(wxString::Format("%.0f", m_itemEdit[4]));
            
            m_lbl4->SetLabel(wxT("Iaif [kA]"));
            m_txt4->ChangeValue(wxString::Format("%.3f", m_itemEdit[5]/1000));
            
            m_lbl5->SetLabel(wxT("Tipo de Curva"));
            intaux = m_itemEdit[6];
            m_choiceTC->SetSelection(intaux);
            
            //LABELS NAO UTILIZADOS
            m_txt5->Hide();
            m_lbl6->Hide();
            
            break;
            
        case 2:  //RELE 5051 TD

            //LABELS UTILIZADOS
            m_lbl1->SetLabel(wxT("TMS [s]"));
            m_txt1->ChangeValue(wxString::Format("%.2f", m_itemEdit[2]));
            
            m_lbl2->SetLabel(wxT("Itf [A]"));
            m_txt2->ChangeValue(wxString::Format("%.2f", m_itemEdit[3]));
            
            m_lbl3->SetLabel(wxT("RTC"));
            m_txt3->ChangeValue(wxString::Format("%.0f", m_itemEdit[4]));
            
            m_lbl4->SetLabel(wxT("Iaif [kA]"));
            m_txt4->ChangeValue(wxString::Format("%.3f", m_itemEdit[5]/1000));
            
            m_lbl5->SetLabel(wxT("Tempo Definido [s]"));
            m_txt5->ChangeValue(wxString::Format("%.2f", m_itemEdit[7]));
            
            m_lbl6->SetLabel(wxT("Tipo de Curva"));
            intaux = m_itemEdit[6];
            m_choiceTC->SetSelection(intaux);
            
            break;
        
        case 3: //ANSI
            
            //LABELS UTILIZADOS
            m_lbl1->SetLabel(wxT("Corrente [kA]"));
            m_txt1->ChangeValue(wxString::Format("%.2f", m_itemEdit[2]/1000));
            
            m_lbl2->SetLabel(wxT("Tempo [s]"));
            m_txt2->ChangeValue(wxString::Format("%.2f", m_itemEdit[3]));
            
            //LABELS NAO UTILIZADOS
            m_txt3->Hide();
            m_lbl3->Hide();
            m_txt4->Hide();
            m_lbl4->Hide();
            m_txt5->Hide();
            m_lbl5->Hide();
            m_lbl6->Hide();
            m_choiceTC->Hide();

            break;
            
        case 4: //INRUSH
            
            //LABELS UTILIZADOS
            m_lbl1->SetLabel(wxT("Corrente [kA]"));
            m_txt1->ChangeValue(wxString::Format("%.2f", m_itemEdit[2]/1000));
            
            m_lbl2->SetLabel(wxT("Tempo [s]"));
            m_txt2->ChangeValue(wxString::Format("%.2f", m_itemEdit[3]));
            
            //LABELS NAO UTILIZADOS
            m_txt3->Hide();
            m_lbl3->Hide();
            m_txt4->Hide();
            m_lbl4->Hide();
            m_txt5->Hide();
            m_lbl5->Hide();
            m_lbl6->Hide();
            m_choiceTC->Hide();
            
            break;
            
        case 5: //CARGA
            
            //LABELS UTILIZADOS
            m_lbl1->SetLabel(wxT("Corrente nominal [kA]"));
            m_txt1->ChangeValue(wxString::Format("%.2f", m_itemEdit[2]/1000));
            
            m_lbl2->SetLabel(wxT("Corrente de partida [kA]"));
            m_txt2->ChangeValue(wxString::Format("%.2f", m_itemEdit[3]/1000));
            
            m_lbl3->SetLabel(wxT("Tempo de partida [s]"));
            m_txt3->ChangeValue(wxString::Format("%.2f", m_itemEdit[4]));
            
            //LABELS NAO UTILIZADOS
            m_txt4->Hide();
            m_lbl4->Hide();
            m_txt5->Hide();
            m_lbl5->Hide();
            m_lbl6->Hide();
            m_choiceTC->Hide();
            
            break;
            
        case 6: //ICC
        
            //LABELS UTILIZADOS
            m_lbl1->SetLabel(wxT("Corrente de curto-circuito [kA]"));
            m_txt1->ChangeValue(wxString::Format("%.2f", m_itemEdit[2]/1000));
        
            //LABELS NAO UTILIZADOS
            m_txt2->Hide();
            m_lbl2->Hide();
            m_txt3->Hide();
            m_lbl3->Hide();
            m_txt4->Hide();
            m_lbl4->Hide();
            m_txt5->Hide();
            m_lbl5->Hide();
            m_lbl6->Hide();
            m_choiceTC->Hide();
    }
}

edit_Dialog::~edit_Dialog() {}

void edit_Dialog::btnClickCancelar(wxCommandEvent& event)
{
    EndModal(wxID_CANCEL);
}
void edit_Dialog::btnClickEditar(wxCommandEvent& event)
{
    int intaux = m_itemEdit[1];
    
    switch (intaux) {
        case 1:  //RELE 5051
            
            m_itemEdit[2] = wxAtof(m_txt1->GetValue()); //TMS
            m_itemEdit[3] = wxAtof(m_txt2->GetValue()); //Itf
            m_itemEdit[4] = wxAtoi(m_txt3->GetValue()); //RTC
            m_itemEdit[5] = wxAtof(m_txt4->GetValue())*1000; //Iaif
            m_itemEdit[6] = m_choiceTC->GetSelection(); //TipoCurva
            
            break;
            
        case 2:  //RELE 5051 TD

            m_itemEdit[2] = wxAtof(m_txt1->GetValue()); //TMS
            m_itemEdit[3] = wxAtof(m_txt2->GetValue()); //Itf
            m_itemEdit[4] = wxAtoi(m_txt3->GetValue()); //RTC
            m_itemEdit[5] = wxAtof(m_txt4->GetValue())*1000; //Iaif
            m_itemEdit[6] = wxAtof(m_txt5->GetValue()); //TD
            m_itemEdit[7] = m_choiceTC->GetSelection(); //TipoCurva
            
            break;
        
        case 3: //ANSI
            
            m_itemEdit[2] = wxAtof(m_txt1->GetValue())*1000; //Corrente
            m_itemEdit[3] = wxAtof(m_txt2->GetValue()); //Tempo
            
            break;
            
        case 4: //INRUSH
            
            m_itemEdit[2] = wxAtof(m_txt1->GetValue())*1000; //Corrente
            m_itemEdit[3] = wxAtof(m_txt2->GetValue()); //Tempo
            
            break;
            
        case 5: //CARGA
            
            m_itemEdit[2] = wxAtof(m_txt1->GetValue())*1000; //Corrente nominal
            m_itemEdit[3] = wxAtof(m_txt2->GetValue())*1000; //Corrente de partida
            m_itemEdit[4] = wxAtof(m_txt3->GetValue()); //Tempo de partida
            
            break;
            
        case 6: //ICC
        
            m_itemEdit[2] = wxAtof(m_txt1->GetValue())*1000; //Corrente
        
    }

    Close();
}
