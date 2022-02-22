//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "wxcrafter.h"

// Declare the bitmap loading function
extern void wxC9ED9InitBitmapResources();

static bool bBitmapLoaded = false;

MainFrameBaseClass::MainFrameBaseClass(wxWindow* parent,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer1);

    m_mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    boxSizer1->Add(m_mainPanel, 1, wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    m_mainPanel->SetSizer(boxSizer11);

    wxBoxSizer* boxSizer15 = new wxBoxSizer(wxVERTICAL);

    boxSizer11->Add(boxSizer15, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer125 = new wxBoxSizer(wxVERTICAL);

    boxSizer15->Add(boxSizer125, 1, wxEXPAND, WXC_FROM_DIP(5));

    wxArrayString m_pgDadosArr;
    wxUnusedVar(m_pgDadosArr);
    wxArrayInt m_pgDadosIntArr;
    wxUnusedVar(m_pgDadosIntArr);
    m_pgDados =
        new wxPropertyGridManager(m_mainPanel, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_mainPanel, wxSize(200, 200)),
            wxPG_DESCRIPTION | wxPG_STATIC_LAYOUT | wxPG_SPLITTER_AUTO_CENTER | wxPG_BOLD_MODIFIED);

    boxSizer125->Add(m_pgDados, 1, wxLEFT | wxEXPAND, WXC_FROM_DIP(5));

    m_pgNome = m_pgDados->Append(new wxStringProperty(_("Nome"), wxPG_LABEL, wxT("")));
    m_pgNome->SetHelpString(wxT("Nome do item a ser incluido no coordenograma."));

    m_pgDadosArr.Clear();
    m_pgDadosIntArr.Clear();
    m_pgDadosArr.Add(_("Selecione o tipo"));
    m_pgDadosArr.Add(wxT("Relé 50/51"));
    m_pgDadosArr.Add(wxT("Relé 50/51 TD"));
    m_pgDadosArr.Add(_("ANSI"));
    m_pgDadosArr.Add(_("INRUSH"));
    m_pgDadosArr.Add(_("Carga"));
    m_pgDadosArr.Add(_("ICC"));
    m_pgTipo = m_pgDados->Append(new wxEnumProperty(_("Tipo"), wxPG_LABEL, m_pgDadosArr, m_pgDadosIntArr, 0));
    m_pgTipo->SetHelpString(_("Tipo de elemento a ser acrescentado no coordenograma."));
    m_pgTipo->SetEditor(wxT("Choice"));

    m_pgCorrente = m_pgDados->Append(new wxFloatProperty(_("Corrente [kA]"), wxPG_LABEL, 0));
    m_pgCorrente->SetHelpString(
        wxT("Corrente máxima que o transformador suporta para o ponto ANSI;\nCorrente de magnetização do transformador "
          "para o ponto INRUSH;\nCorrente nominal da carga;\nCorrente de curto-circuito."));
    m_pgCorrente->SetEditor(wxT("TextCtrl"));

    m_pgTempo = m_pgDados->Append(new wxFloatProperty(_("Tempo [s]"), wxPG_LABEL, 0));
    m_pgTempo->SetHelpString(
        wxT("TMS - Ajuste do multiplicador de tempo do relé;\nTempo máximo que o transformador suporta para a corrente ANSI;"
          "\nTempo de magnetização do transformador para o ponto INRUSH;\nTempo de partida da carga."));

    m_pgITF = m_pgDados->Append(new wxFloatProperty(_("Itf [A]/Corrente de partida [kA]"), wxPG_LABEL, 0));
    m_pgITF->SetHelpString(
        wxT("Itf - Corrente de tape da unidade temporizada de fase;\nCorrente de partida da carga."));

    m_pgRTC = m_pgDados->Append(new wxFloatProperty(_("RTC"), wxPG_LABEL, 0));
    m_pgRTC->SetHelpString(
        wxT("RTC - Relação de transformação do transformador de corrente."));

    m_pgIAIF = m_pgDados->Append(new wxFloatProperty(_("Iaif [kA]"), wxPG_LABEL, 0));
    m_pgIAIF->SetHelpString(
        wxT("Iaif - Corrente de acionamento da unidade instantânea de fase."));

    m_pgTempoDefinido = m_pgDados->Append(new wxFloatProperty(_("Tempo Definido [s]"), wxPG_LABEL, 0));
    m_pgTempoDefinido->SetHelpString(
        wxT("Tempo programado para acionamento do relé."));

    m_pgDadosArr.Clear();
    m_pgDadosIntArr.Clear();
    m_pgDadosArr.Add(_("Tipo de curva"));
    m_pgDadosArr.Add(_("Curva Normalmente Inversa"));
    m_pgDadosArr.Add(_("Curva Muito Inversa"));
    m_pgDadosArr.Add(_("Curva Extremamente Inversa"));
    m_pgDadosArr.Add(_("Curva Inversa Longa"));
    m_pgDadosArr.Add(_("Curva Inversa Curta"));
    m_pgDadosArr.Add(wxT("Curva Térmica IXT"));
    m_pgDadosArr.Add(wxT("Curva Térmica I²XT"));
    m_pgTipoCurva =
        m_pgDados->Append(new wxEnumProperty(_("Tipo de Curva"), wxPG_LABEL, m_pgDadosArr, m_pgDadosIntArr, 0));
    m_pgTipoCurva->SetHelpString(wxT("Tipo de curva do Relé 51."));
    m_pgTipoCurva->SetEditor(wxT("Choice"));

    wxBoxSizer* boxSizer127 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer15->Add(boxSizer127, 0, wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_btnAdd = new wxButton(
        m_mainPanel, wxID_ANY, _("Adicionar"), wxDefaultPosition, wxDLG_UNIT(m_mainPanel, wxSize(-1, -1)), 0);

    boxSizer127->Add(m_btnAdd, 0, wxLEFT | wxTOP | wxBOTTOM | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_btnEdit =
        new wxButton(m_mainPanel, wxID_ANY, _("Editar"), wxDefaultPosition, wxDLG_UNIT(m_mainPanel, wxSize(-1, -1)), 0);
    m_btnEdit->Enable(false);

    boxSizer127->Add(m_btnEdit, 0, wxLEFT | wxTOP | wxBOTTOM, WXC_FROM_DIP(5));

    m_btnExcluir = new wxButton(
        m_mainPanel, wxID_ANY, _("Excluir"), wxDefaultPosition, wxDLG_UNIT(m_mainPanel, wxSize(-1, -1)), 0);
    m_btnExcluir->Enable(false);

    boxSizer127->Add(m_btnExcluir, 0, wxLEFT | wxTOP | wxBOTTOM, WXC_FROM_DIP(5));

    m_btnCoord = new wxButton(
        m_mainPanel, wxID_ANY, _("Coordenograma"), wxDefaultPosition, wxDLG_UNIT(m_mainPanel, wxSize(-1, -1)), 0);
    m_btnCoord->Enable(false);

    boxSizer127->Add(m_btnCoord, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer13 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer11->Add(boxSizer13, 1, wxEXPAND | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_grid = new wxGrid(m_mainPanel, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_mainPanel, wxSize(520, 200)),
        wxWANTS_CHARS | wxALWAYS_SHOW_SB);
    m_grid->CreateGrid(0, 0);
    m_grid->SetRowLabelAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
    m_grid->SetColLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
#if wxVERSION_NUMBER >= 2904
    m_grid->UseNativeColHeader(true);
#endif
    m_grid->EnableEditing(false);

    boxSizer13->Add(m_grid, 1, wxLEFT | wxEXPAND, WXC_FROM_DIP(5));

    SetName(wxT("MainFrameBaseClass"));
    SetSize(wxDLG_UNIT(this, wxSize(1000, 400)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
    // Connect events
    m_pgDados->Connect(wxEVT_PG_CHANGED, wxPropertyGridEventHandler(MainFrameBaseClass::onPGChange), NULL, this);
    m_btnAdd->Connect(
        wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::btnClickAdicionar), NULL, this);
    m_btnEdit->Connect(
        wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::btnClickEditar), NULL, this);
    m_btnExcluir->Connect(
        wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::btnClickExcluir), NULL, this);
    m_btnCoord->Connect(
        wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::btnClickCoordenograma), NULL, this);
    m_grid->Connect(wxEVT_GRID_SELECT_CELL, wxGridEventHandler(MainFrameBaseClass::grid_CellSelected), NULL, this);
}

MainFrameBaseClass::~MainFrameBaseClass()
{
    m_pgDados->Disconnect(wxEVT_PG_CHANGED, wxPropertyGridEventHandler(MainFrameBaseClass::onPGChange), NULL, this);
    m_btnAdd->Disconnect(
        wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::btnClickAdicionar), NULL, this);
    m_btnEdit->Disconnect(
        wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::btnClickEditar), NULL, this);
    m_btnExcluir->Disconnect(
        wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::btnClickExcluir), NULL, this);
    m_btnCoord->Disconnect(
        wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameBaseClass::btnClickCoordenograma), NULL, this);
    m_grid->Disconnect(wxEVT_GRID_SELECT_CELL, wxGridEventHandler(MainFrameBaseClass::grid_CellSelected), NULL, this);
}

editDialog::editDialog(wxWindow* parent,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer1371 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer1371);

    m_panel1392 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    boxSizer1371->Add(m_panel1392, 1, wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer1413 = new wxBoxSizer(wxVERTICAL);
    m_panel1392->SetSizer(boxSizer1413);

    wxBoxSizer* CIMA4 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer1413->Add(CIMA4, 1, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    wxBoxSizer* LAYERS5 = new wxBoxSizer(wxVERTICAL);

    CIMA4->Add(LAYERS5, 0, wxRIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_lbl1 = new wxStaticText(
        m_panel1392, wxID_ANY, _("Label1"), wxDefaultPosition, wxDLG_UNIT(m_panel1392, wxSize(-1, -1)), 0);

    LAYERS5->Add(m_lbl1, 1, wxLEFT | wxRIGHT | wxTOP | wxALIGN_RIGHT, WXC_FROM_DIP(10));

    m_lbl2 = new wxStaticText(
        m_panel1392, wxID_ANY, _("Label2"), wxDefaultPosition, wxDLG_UNIT(m_panel1392, wxSize(-1, -1)), 0);

    LAYERS5->Add(m_lbl2, 0, wxALL | wxALIGN_RIGHT, WXC_FROM_DIP(10));

    m_lbl3 = new wxStaticText(
        m_panel1392, wxID_ANY, _("Label3"), wxDefaultPosition, wxDLG_UNIT(m_panel1392, wxSize(-1, -1)), 0);

    LAYERS5->Add(m_lbl3, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxALIGN_RIGHT, WXC_FROM_DIP(10));

    m_lbl4 = new wxStaticText(
        m_panel1392, wxID_ANY, _("Label4"), wxDefaultPosition, wxDLG_UNIT(m_panel1392, wxSize(-1, -1)), 0);

    LAYERS5->Add(m_lbl4, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxALIGN_RIGHT, WXC_FROM_DIP(10));

    m_lbl5 = new wxStaticText(
        m_panel1392, wxID_ANY, _("Label5"), wxDefaultPosition, wxDLG_UNIT(m_panel1392, wxSize(-1, -1)), 0);

    LAYERS5->Add(m_lbl5, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxALIGN_RIGHT, WXC_FROM_DIP(10));

    m_lbl6 = new wxStaticText(
        m_panel1392, wxID_ANY, _("Label6"), wxDefaultPosition, wxDLG_UNIT(m_panel1392, wxSize(-1, -1)), 0);

    LAYERS5->Add(m_lbl6, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxALIGN_RIGHT, WXC_FROM_DIP(10));

    wxBoxSizer* TEXTO12 = new wxBoxSizer(wxVERTICAL);

    CIMA4->Add(TEXTO12, 1, wxLEFT | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_txt1 =
        new wxTextCtrl(m_panel1392, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panel1392, wxSize(120, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_txt1->SetHint(wxT(""));
#endif

    TEXTO12->Add(m_txt1, 0, wxTOP | wxALIGN_LEFT, WXC_FROM_DIP(5));

    m_txt2 =
        new wxTextCtrl(m_panel1392, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panel1392, wxSize(120, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_txt2->SetHint(wxT(""));
#endif

    TEXTO12->Add(m_txt2, 0, wxTOP | wxALIGN_LEFT, WXC_FROM_DIP(5));

    m_txt3 =
        new wxTextCtrl(m_panel1392, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panel1392, wxSize(120, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_txt3->SetHint(wxT(""));
#endif

    TEXTO12->Add(m_txt3, 0, wxTOP | wxALIGN_LEFT, WXC_FROM_DIP(5));

    m_txt4 =
        new wxTextCtrl(m_panel1392, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panel1392, wxSize(120, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_txt4->SetHint(wxT(""));
#endif

    TEXTO12->Add(m_txt4, 0, wxTOP | wxALIGN_LEFT, WXC_FROM_DIP(5));

    m_txt5 =
        new wxTextCtrl(m_panel1392, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panel1392, wxSize(120, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_txt5->SetHint(wxT(""));
#endif

    TEXTO12->Add(m_txt5, 0, wxTOP | wxALIGN_LEFT, WXC_FROM_DIP(5));

    wxArrayString m_choiceTCArr;
    m_choiceTCArr.Add(wxT("Tipo de curva"));
    m_choiceTCArr.Add(wxT("Curva Normalmente Inversa"));
    m_choiceTCArr.Add(wxT("Curva Muito Inversa"));
    m_choiceTCArr.Add(wxT("Curva Extremamente Inversa"));
    m_choiceTCArr.Add(wxT("Curva Inversa Longa"));
    m_choiceTCArr.Add(wxT("Curva Inversa Curta"));
    m_choiceTCArr.Add(wxT("Curva Térmica IXT"));
    m_choiceTCArr.Add(wxT("Curva Térmica I²XT"));
    m_choiceTC = new wxChoice(
        m_panel1392, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel1392, wxSize(-1, -1)), m_choiceTCArr, 0);

    TEXTO12->Add(m_choiceTC, 0, wxTOP, WXC_FROM_DIP(5));

    wxBoxSizer* BAIXO19 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer1413->Add(BAIXO19, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    btnCancelar20 = new wxButton(
        m_panel1392, wxID_ANY, _("Cancelar"), wxDefaultPosition, wxDLG_UNIT(m_panel1392, wxSize(-1, -1)), 0);

    BAIXO19->Add(btnCancelar20, 0, wxALL, WXC_FROM_DIP(5));

    m_button16721 =
        new wxButton(m_panel1392, wxID_ANY, _("Editar"), wxDefaultPosition, wxDLG_UNIT(m_panel1392, wxSize(-1, -1)), 0);

    BAIXO19->Add(m_button16721, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("editDialog"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
    // Connect events
    btnCancelar20->Connect(
        wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(editDialog::btnClickCancelar), NULL, this);
    m_button16721->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(editDialog::btnClickEditar), NULL, this);
}

editDialog::~editDialog()
{
    btnCancelar20->Disconnect(
        wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(editDialog::btnClickCancelar), NULL, this);
    m_button16721->Disconnect(
        wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(editDialog::btnClickEditar), NULL, this);
}
