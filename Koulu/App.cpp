#include "App.h"
#include "Frame.h"

/*	Hoitaa main funktion oikealle käyttöjärjestelmälle(Windows, Linux tai macOS),
	luo App luokan ja kutsuu OnInit funktion										*/
wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	// Asettaa seedin rand() funktiota varten
	srand(time(NULL));

	// Luodaan pää kuvaruutu "frame"
	Frame* frame = new Frame("Koulu");
	// Asetaan kuvaruudun koko
	frame->SetClientSize(640, 720);
	// Keskitetään kuvaruutu näytölle
	frame->Center();
	// Asetetaan kuvaruutu näkyviin
	frame->Show();

	return true;
}