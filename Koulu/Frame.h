#pragma once
#include <wx/wx.h>
#include "TextEditor.h"
#include "Dice.h"

class Frame : public wxFrame
{
public:
	Frame(const wxString& title);
	
private:
	wxPanel* textPanel;
	wxPanel* dicePanel;
	wxSizer* pageSizer;
	void OnTextButtonClick(wxCommandEvent& evt);
	void OnDiceButtonClick(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};