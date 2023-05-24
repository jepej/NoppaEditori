#pragma once
#include <wx/wx.h>

class DiceCanvas : public wxWindow
{
public:
	DiceCanvas(wxWindow* parent, wxWindowID id);
	static int diceValue; // Julkinen tämän hetkinen nopan luku

private:
	void OnPaint(wxPaintEvent& evt);
	std::vector<wxPoint> GetDicePoints(int diceValue, wxSize canvasSize, wxSize diceSize);
};

