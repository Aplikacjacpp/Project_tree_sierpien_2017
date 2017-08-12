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
#ifndef C_SL_DATE_H
#define C_SL_DATE_H
#include "save_load.h"
#include "../narzedzia/Vektor.h"
#include "../Databases/goverment_date.h"
#include "../Personaly/id.h"
class C_sl_date :public C_save_load
{
public:
	C_sl_date(); //konstruktor bezparametrowy
	C_sl_date(const C_sl_date & sl_date); //konstruktor kopiujacy
	C_sl_date& operator=(const C_sl_date& sl_date); //operator przypisania
	bool operator==(const C_sl_date& sl_date); //operator porownania ==
	bool operator!=(const C_sl_date& sl_date); //operator porownania !=
	virtual ~C_sl_date(); //wirtualny destruktor
protected:
	void m_file_date(bool what, N_striing Data); //czytanie z pliku bez
	bool m_what(int value);
	virtual N_striing m_cypher_on(N_striing data); //odszyfrowywanie
	virtual N_striing m_cypher_off(N_striing data); //zaszyfrowywanie
	void m_update_date(C_id id, N_vektor<C_date> V_date); //uaktualnienie dat 
	void m_get_new_date(C_id id, N_vektor<C_date> V_date); //dodawanie nowych dat
	C_goverment_date& operator[](int i);
	C_goverment_date m_set_gover_date(int i);
	N_vektor<C_goverment_date> V_goverment_date;
	//trzeba dodac czyszcenie govermentow
};
#endif // !C_SL_DATE_H



