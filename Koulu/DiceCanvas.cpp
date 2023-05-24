#include "DiceCanvas.h"
#include <wx/dcbuffer.h>

DiceCanvas::DiceCanvas(wxWindow* parent, wxWindowID id) : wxWindow(parent, id)
{
	// Asettaa taustan piirrett‰v‰ksi
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);

	// Liitt‰‰ OnPaint funktion paint tapahtumaan
	this->Bind(wxEVT_PAINT, &DiceCanvas::OnPaint, this);

	// Lis‰‰ resize tapahtumaan Refresh() funktion jotta kaikki skaalaus p‰ivittyy ikkunan koon mukana
	this->Bind(wxEVT_SIZE, [this](wxSizeEvent& evt) { Refresh(); evt.Skip(); });
}

void DiceCanvas::OnPaint(wxPaintEvent& evt)
{
	// Paint Device Context
	wxPaintDC dc(this);
	// Kaikki t‰ytyy tyhjent‰‰ ennen kuin piirret‰‰n jotta vanhat nopat ei n‰y
	dc.Clear();
	
	// Ottaa canvaksen koon
	wxSize canvasSize = GetClientSize();
	// Laskee nopan koon
	wxSize diceSize(canvasSize.GetHeight() * 0.35, canvasSize.GetHeight() * 0.35);
	// Laskee canvaksen koosta sen keskipisteen ja siirt‰‰ noppaa sivuun ett‰ sen keskipiste on canvaksen keskell‰
	wxPoint dicePoint((canvasSize.GetWidth() * 0.5 - (diceSize.GetWidth() * 0.5)), (canvasSize.GetHeight() * 0.5 - (diceSize.GetHeight() * 0.5)));
	
	// Piirt‰‰ nopan reunuksen
	wxRect diceRect(dicePoint, diceSize);
	dc.DrawRoundedRectangle(diceRect, 10);

	// Asettaa v‰rin mustaksi ett‰ nopan pisteet ovat t‰ytettyj‰
	dc.SetBrush(*wxBLACK_BRUSH);
	
	// Laskee mihin nopan pisteiden t‰ytyy tulla piirt‰‰ ne
	std::vector<wxPoint> points = GetDicePoints(diceValue, canvasSize, diceSize);
	for (int i = 0; i < points.size(); i++)
	{
		dc.DrawCircle(points[i], diceSize.GetHeight() * 0.1);
	}
}

// M‰‰ritt‰‰ ensimm‰isen nopan luvun
int DiceCanvas::diceValue = 5;

// Hankkii kaikki nopan pisteet sen mukaan mik‰ nopan luku on
std::vector<wxPoint> DiceCanvas::GetDicePoints(int diceValue, wxSize canvasSize, wxSize diceSize)
{
	std::vector<wxPoint> points;
	switch (diceValue)
	{
	case 1:
		points.push_back(wxPoint(canvasSize.GetWidth() * 0.5, canvasSize.GetHeight() * 0.5)); // Keski
		break;
	case 2:
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 - (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 - (diceSize.GetHeight() * 0.25)))); // Vasen yl‰
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 + (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 + (diceSize.GetHeight() * 0.25)))); // Oikea ala
		break;
	case 3:
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 - (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 - (diceSize.GetHeight() * 0.25)))); // Vasen yl‰
		points.push_back(wxPoint(canvasSize.GetWidth() * 0.5, canvasSize.GetHeight() * 0.5)); // Keski
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 + (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 + (diceSize.GetHeight() * 0.25)))); // Oikea ala
		break;
	case 4:
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 - (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 - (diceSize.GetHeight() * 0.25)))); // Vasen yl‰
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 + (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 - (diceSize.GetHeight() * 0.25)))); // Oikea yl‰
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 - (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 + (diceSize.GetHeight() * 0.25)))); // Vasen ala
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 + (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 + (diceSize.GetHeight() * 0.25)))); // Oikea ala
		break;
	case 5:
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 - (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 - (diceSize.GetHeight() * 0.25)))); // Vasen yl‰
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 + (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 - (diceSize.GetHeight() * 0.25)))); // Oikea yl‰
		points.push_back(wxPoint(canvasSize.GetWidth() * 0.5, canvasSize.GetHeight() * 0.5)); // Keski
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 - (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 + (diceSize.GetHeight() * 0.25)))); // Vasen ala
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 + (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 + (diceSize.GetHeight() * 0.25)))); // Oikea ala
		break;
	case 6:
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 - (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 - (diceSize.GetHeight() * 0.25)))); // Vasen yl‰
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 + (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 - (diceSize.GetHeight() * 0.25)))); // Oikea yl‰
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 - (diceSize.GetWidth() * 0.25)), canvasSize.GetHeight() * 0.5)); // Vasen keski
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 + (diceSize.GetWidth() * 0.25)), canvasSize.GetHeight() * 0.5)); // Oikea keski
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 - (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 + (diceSize.GetHeight() * 0.25)))); // Vasen ala
		points.push_back(wxPoint((canvasSize.GetWidth() * 0.5 + (diceSize.GetWidth() * 0.25)), (canvasSize.GetHeight() * 0.5 + (diceSize.GetHeight() * 0.25)))); // Oikea ala
		break;
	}
	return points;
}