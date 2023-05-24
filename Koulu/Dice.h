#pragma once
#include <wx/wx.h>
#include "DiceCanvas.h"

class Dice : public wxPanel
{
public:
	Dice(wxWindow* parent);
	void OnThrowButtonClick(wxCommandEvent& evt);
};

