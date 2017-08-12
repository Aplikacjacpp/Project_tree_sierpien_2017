/***************************************************************************************************************
*"goverment_personaly.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klascie C_goverment"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1     09.05.2017  Pure Virtual Methods Added										  Mateusz Marchelewicz
*1.2     12.05.2017  redbuild m_is_there_contens							   		  Lukasz Witek vel Witkowski
*1.3	 12.05.2017  Adding new mothods												  Lukasz Witek vel Witkowski
*1.4	 17.05.2017 Adding a method to return values ​​from personaly classes			  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef GOVERMENT_PERSONALY_H
#define GOVERMENT_PERSONALY_H
#include "goverment.h"
#include "../Personaly/first_name.h"
#include "../Personaly/gender.h"
#include "../Personaly//last_name.h"
class C_goverment_personaly :
	public C_goverment
{
public:
	C_goverment_personaly(); //konstruktor beparametrowy
	C_goverment_personaly(const C_goverment_personaly & goverment_personaly); //konstruktor kopiujacy
	C_goverment_personaly& operator=(const C_goverment_personaly& goverment_personaly); //operator przypisania
	bool operator==(const C_goverment_personaly& goverment_personaly); //operator porownania ==
	bool operator!=(const C_goverment_personaly& goverment_personaly); //operator porownania !=
	virtual ~C_goverment_personaly(); //wirtualny destruktor
	virtual bool m_wchat_is(); //
	virtual void m_get_contens(N_striing &contens) ; //sluzy do wprowadzabia striinga
	virtual N_striing m_set_contens(); //zwraca caly striing bez obrobki
	int m_set_value_id(); //zwraca wyszukana wczesniej wartosc id
	C_first_name m_set_value_first_name(); //wyszukuje i zwraca wartosz first_name
	N_vektor<C_last_name> m_set_value_last_name(); //wyszukuje i zwraca wyszukana wartosc last_name
	C_gender m_set_value_gender(); //wyszukuje i zwraca wartosc gender
private:
	virtual N_striing m_is_there_contens(N_striing &Word); //analizuje pod wzgledem poprawnosci wprowadzany striing
	N_striing s_goverment_personaly; //zmienna przechowujaca striing
	int i_value_id; //zmienna przechowujaca znalezione id
	int m_id_value(); //metoda prywatna do wyszukiwania wartosci id
};
#endif // !GOVERMENT_PERSONALY_H



