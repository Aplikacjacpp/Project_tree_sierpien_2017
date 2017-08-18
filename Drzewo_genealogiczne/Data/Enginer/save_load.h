/***************************************************************************************************************
*"save_load.h"
*
*
*
*
*
*CONTENTS:
* "Klasa bazowa dla innych klas do wczytywania"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef C_SAVE_LOAD_H
#define C_SAVE_LOAD_H
#include "alphabet.h"
#include "../narzedzia/striing.h"
#include "../narzedzia/Vektor.h"
#include "../Helpful/definition.h"
#include <fstream>
class C_save_load
{
public:
	C_save_load();
	C_save_load(const C_save_load & save_load);
	C_save_load& operator=(const C_save_load& save_load);
	//bool operator==(const C_save_load& save_load);
	//bool operator!=(const C_save_load& save_load);
	virtual ~C_save_load();
	virtual N_striing m_cypher_on(N_striing data)=0; //odszyfrowywanie
	virtual N_striing m_cypher_off(N_striing data)=0; //zaszyfrowywanie
	/*void wczytuj_sz(N_striing& slowo, N_vektor<N_striing>& s);
	void zapis_sz(N_striing a, N_striing& haslo, int* s);
	N_striing m_encryption_sz(N_vektor<alfabet>& v, N_striing& haslo, N_vektor<N_striing>& s);
	int main_m_encryption(N_striing a, N_striing tablica, int X);
	void m_analyzing(N_vektor <N_striing> &date, N_striing files);
	int main_rozkowowywanie(N_striing a);
	void wczytuj(N_striing& haslo, bool& istnieje);
	void zapis(N_striing a, N_striing& haslo);
	void wczytaj(N_striing a, N_striing& slowo);
	N_striing m_encryption(N_striing& slowo, N_vektor<alfabet>& v, N_striing& haslo);
	void wczytaj_rozkodowacz(N_striing a, N_vektor <N_striing> &date, bool& istnieje);
	N_striing m_decryption(N_striing a, N_striing tablica, int X);*/
};
#endif // !C_SAVE_LOAD_H