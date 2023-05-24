#include "TextEditor.h"

wxTextCtrl* TextEditor::textBox;
wxTextCtrl* TextEditor::findBox;
wxTextCtrl* TextEditor::replaceBox;

TextEditor::TextEditor(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	// Lisätään eri tekstilaatikot
	textBox = new wxTextCtrl(parent, wxID_ANY, "Tekstieditori", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxHSCROLL);
	findBox = new wxTextCtrl(parent, wxID_ANY, "Etsi");
	replaceBox = new wxTextCtrl(parent, wxID_ANY, "Korvaa");

	// Muokkaa nappi ID:llä 5 (EDIT_ID)
	wxButton* button = new wxButton(parent, 5, "Muokkaa");

	// Sizer joka hoitaa pystysyynnan sijoittelun
	wxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(textBox, 5, wxEXPAND | wxALL, 15);

	// Etsi ja korvaa laatikoille sizer joka asettaa ne vierekkäin
	wxSizer* boxSizer = new wxBoxSizer(wxHORIZONTAL);
	boxSizer->Add(findBox, 1, wxALL, 15);
	boxSizer->Add(replaceBox, 1, wxALL, 15);

	sizer->Add(boxSizer, 1, wxEXPAND | wxALL, 15);
	sizer->Add(button, 2, wxEXPAND | wxALL, 15);

	parent->SetSizerAndFit(sizer);
}

void TextEditor::OnEditButtonClick(wxCommandEvent& evt)
{
	// Muuntaa wxString:istä std::stringiin helpottaakseen käsittelyä
	std::string textBoxString = textBox->GetValue().ToStdString();
	std::string findBoxString = findBox->GetValue().ToStdString();
	std::string replaceBoxString = replaceBox->GetValue().ToStdString();

	// Vaihtaa merkit käyttäen ReplaceString
	std::string editedString = ReplaceString(textBoxString, findBoxString, replaceBoxString);

	// Asettaa uuden arvon tekstilaatikkoon
	textBox->SetValue(wxString(editedString));
}

// Käy läpi tekstin ja etsii sieltä osuvat sanat ja muokkaa ne
std::string TextEditor::ReplaceString(std::string textString, const std::string& findString, const std::string& replaceString) 
{
	size_t pos = 0;
	while ((pos = textString.find(findString, pos)) != std::string::npos) 
	{
		textString.replace(pos, findString.length(), replaceString);
		pos += replaceString.length();
	}
	return textString;
}