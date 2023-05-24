#include "Dice.h"

Dice::Dice(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	// Canvas jolle noppa piirret‰‰n
	DiceCanvas* canvas = new DiceCanvas(parent, wxID_ANY);

	// Heit‰ nappi ID:ll‰ 4 (THROW_ID)
	wxButton* button = new wxButton(parent, 4, "Heit‰");

	// Sizer joka hoitaa canvaksen ja napin p‰‰llekk‰in
	wxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	// Lis‰‰ canvaksen ja napin sizeriin, canvas vie sizerista 5 osaa ja nappi 1
	sizer->Add(canvas, 5, wxEXPAND | wxALL, 0);
	sizer->Add(button, 1, wxEXPAND | wxALL, 10);

	parent->SetSizerAndFit(sizer);
}

void Dice::OnThrowButtonClick(wxCommandEvent& evt)
{
	// Luo satunnaisen numeron 1-6 kun nappia painetaan
	DiceCanvas::diceValue = rand() % 6 + 1;

	// P‰ivitt‰‰ ikkunan ett‰ uusi nopan luku tulee n‰kyviin
	Refresh();
}