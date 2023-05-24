#pragma once
#include <wx/wx.h>

class TextEditor : public wxPanel
{
public:
	TextEditor(wxWindow* parent);
	void OnEditButtonClick(wxCommandEvent& evt);
	std::string ReplaceString(std::string text, const std::string& find, const std::string& replace);
	static wxTextCtrl* textBox;
	static wxTextCtrl* findBox;
	static wxTextCtrl* replaceBox;
};

