#include "Frame.h"
#include "Dice.h"

// Napit t�ytyy erotella tunnuksilla tapahtumia varten
enum ButtonIDs
{
	TEXT_ID = 2,
	DICE_ID = 3,
	THROW_ID = 4,
	EDIT_ID = 5
};

// Tapahtuma p�yt� jossa luodaan tapahtumat
wxBEGIN_EVENT_TABLE(Frame, wxFrame)
	EVT_BUTTON(TEXT_ID, Frame::OnTextButtonClick)
	EVT_BUTTON(DICE_ID, Frame::OnDiceButtonClick)
	EVT_BUTTON(THROW_ID, Dice::OnThrowButtonClick)
	EVT_BUTTON(EDIT_ID, TextEditor::OnEditButtonClick)
wxEND_EVENT_TABLE()

Frame::Frame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	// Luo p��paneelin
	wxPanel* panel = new wxPanel(this);

	// Lis�� napit p��paneeliin
	wxButton* textTabButton = new wxButton(panel, TEXT_ID, "Tekstieditori");
	wxButton* diceTabButton = new wxButton(panel, DICE_ID, "Noppa");

	// Tekee paneeli jossa sovellukset n�kyv�t
	wxPanel* appPanel = new wxPanel(panel);

	// Sizer joka erottelee ja mitottaa napit ja sovelluspaneelin toisistaan pystysuunnassa
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	// Napeille sizer joka asettaa ne vierekk�in
	wxSizer* tabButtonSizer = new wxBoxSizer(wxHORIZONTAL);
	tabButtonSizer->Add(textTabButton, 1, wxEXPAND | wxLEFT | wxTOP | wxRight, 0);
	tabButtonSizer->Add(diceTabButton, 1, wxEXPAND, 0);

	// Lis�� pystysuunnan sizeriin vierekk�in olevat napit p��limm�isiksi
	sizer->Add(tabButtonSizer, 1, wxEXPAND | wxALL, 0);

	// Lis�� sizeriin sovellus paneeli pohjalle
	sizer->Add(appPanel, 10, wxEXPAND | wxLEFT | wxBOTTOM | wxRIGHT);

	// Asettelee sizerin p��paneeliin
	panel->SetSizerAndFit(sizer);

	// pageSizer asettelee teksti ja noppa sivut appPaneeliin
	pageSizer = new wxBoxSizer(wxVERTICAL);
	appPanel->SetSizer(pageSizer);

	// Luo teksti paneelin ja lis�� sen sizeriin
	textPanel = new wxPanel(appPanel);
	pageSizer->Add(textPanel, 1, wxGROW);

	// Luo noppa paneelin ja lis�� sen sizeriin
	dicePanel = new wxPanel(appPanel);
	pageSizer->Add(dicePanel, 1, wxGROW);
	dicePanel->Hide();

	// Asettaa teksti ja noppa paneeleille niille kuuluvat sis�ll�t
	TextEditor* textEditor = new TextEditor(textPanel);
	Dice* dice = new Dice(dicePanel);
}

/*	Tapahtumat jotka reagoivat kun nappeja painetaan,
	nappia painaessa toinen sivu menee piiloon ja toinen tulee esiin
	ja sitten sizer p�ivitet��n jotta asetelma pysyy kunnossa			*/
void Frame::OnTextButtonClick(wxCommandEvent& evt)
{
	dicePanel->Hide();
	textPanel->Show();
	pageSizer->Layout();
}
void Frame::OnDiceButtonClick(wxCommandEvent& evt)
{
	textPanel->Hide();
	dicePanel->Show();
	pageSizer->Layout();
}
