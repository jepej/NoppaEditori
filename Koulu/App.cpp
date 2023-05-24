#include "App.h"
#include "Frame.h"

/*	Hoitaa main funktion oikealle k�ytt�j�rjestelm�lle(Windows, Linux tai macOS),
	luo App luokan ja kutsuu OnInit funktion										*/
wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	// Asettaa seedin rand() funktiota varten
	srand(time(NULL));

	// Luodaan p�� kuvaruutu "frame"
	Frame* frame = new Frame("Koulu");
	// Asetaan kuvaruudun koko
	frame->SetClientSize(640, 720);
	// Keskitet��n kuvaruutu n�yt�lle
	frame->Center();
	// Asetetaan kuvaruutu n�kyviin
	frame->Show();

	return true;
}