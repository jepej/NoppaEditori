#include "Frame.h"
#include "Dice.h"

// Napit täytyy erotella tunnuksilla tapahtumia varten
enum ButtonIDs
{
	TEXT_ID = 2,
	DICE_ID = 3,
	THROW_ID = 4,
	EDIT_ID = 5
};

// Tapahtuma pöytä jossa luodaan tapahtumat
wxBEGIN_EVENT_TABLE(Frame, wxFrame)
	EVT_BUTTON(TEXT_ID, Frame::OnTextButtonClick)
	EVT_BUTTON(DICE_ID, Frame::OnDiceButtonClick)
	EVT_BUTTON(THROW_ID, Dice::OnThrowButtonClick)
	EVT_BUTTON(EDIT_ID, TextEditor::OnEditButtonClick)
wxEND_EVENT_TABLE()

Frame::Frame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	// Luo pääpaneelin
	wxPanel* panel = new wxPanel(this);

	// Lisää napit pääpaneeliin
	wxButton* textTabButton = new wxButton(panel, TEXT_ID, "Tekstieditori");
	wxButton* diceTabButton = new wxButton(panel, DICE_ID, "Noppa");

	// Tekee paneeli jossa sovellukset näkyvät
	wxPanel* appPanel = new wxPanel(panel);

	// Sizer joka erottelee ja mitottaa napit ja sovelluspaneelin toisistaan pystysuunnassa
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	// Napeille sizer joka asettaa ne vierekkäin
	wxSizer* tabButtonSizer = new wxBoxSizer(wxHORIZONTAL);
	tabButtonSizer->Add(textTabButton, 1, wxEXPAND | wxLEFT | wxTOP | wxRight, 0);
	tabButtonSizer->Add(diceTabButton, 1, wxEXPAND, 0);

	// Lisää pystysuunnan sizeriin vierekkäin olevat napit päälimmäisiksi
	sizer->Add(tabButtonSizer, 1, wxEXPAND | wxALL, 0);

	// Lisää sizeriin sovellus paneeli pohjalle
	sizer->Add(appPanel, 10, wxEXPAND | wxLEFT | wxBOTTOM | wxRIGHT);

	// Asettelee sizerin pääpaneeliin
	panel->SetSizerAndFit(sizer);

	// pageSizer asettelee teksti ja noppa sivut appPaneeliin
	pageSizer = new wxBoxSizer(wxVERTICAL);
	appPanel->SetSizer(pageSizer);

	// Luo teksti paneelin ja lisää sen sizeriin
	textPanel = new wxPanel(appPanel);
	pageSizer->Add(textPanel, 1, wxGROW);

	// Luo noppa paneelin ja lisää sen sizeriin
	dicePanel = new wxPanel(appPanel);
	pageSizer->Add(dicePanel, 1, wxGROW);
	dicePanel->Hide();

	// Asettaa teksti ja noppa paneeleille niille kuuluvat sisällöt
	TextEditor* textEditor = new TextEditor(textPanel);
	Dice* dice = new Dice(dicePanel);
}

/*	Tapahtumat jotka reagoivat kun nappeja painetaan,
	nappia painaessa toinen sivu menee piiloon ja toinen tulee esiin
	ja sitten sizer päivitetään jotta asetelma pysyy kunnossa			*/
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
