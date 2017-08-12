/***************************************************************************************************************
*"sl_date.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_save_load"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef C_SL_PERSONALYS_H
#define C_SL_PERSONALYS_H
#include "save_load.h"
#include "../Personaly/id.h"
#include "../Databases/goverment_personaly.h"
#include "../narzedzia/Vektor.h"
class C_sl_personalys :
	public C_save_load
{
public:
	C_sl_personalys(); //konstruktor bezparametrowy
	C_sl_personalys(const C_sl_personalys & sl_personalys); // kostruktor kopiujacy
	C_sl_personalys& operator=(const C_sl_personalys& sl_personalys); //operator przypisania
	bool operator==(const C_sl_personalys& sl_personalys); //operator porownania ==
	bool operator!=(const C_sl_personalys& sl_personalys); //operator porownania !=
	virtual ~C_sl_personalys(); //destruktor virtualny
protected:
	bool m_what(int value);
	void m_load_file_personaly(bool what, N_striing Data); //czytanie z pliku
	virtual N_striing m_cypher_on(N_striing data); //odszyfrowywanie
	virtual N_striing m_cypher_off(N_striing data); //zaszyfrowywanie
	void m_update_personaly(C_id id, C_first_name first, N_vektor<C_last_name> V_last, C_gender gender); //uaktualnienie danych personalnych
	void m_add_new_personaly(C_id id, C_first_name first, N_vektor<C_last_name> Last, C_gender gender); //dodawanie nowych danych personalnych
	C_goverment_personaly& operator[](int i); //operator "dostepu" []
	N_vektor<C_goverment_personaly> V_goverment_personaly;
};
#endif // !C_SL_PERSOLALYS_H



