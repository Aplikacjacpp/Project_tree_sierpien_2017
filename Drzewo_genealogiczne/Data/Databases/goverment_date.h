/***************************************************************************************************************
*"goverment_date.h"
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
*1.4	 17.05.2017 Adding a method to return values ​​from date classes				  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef GOVERMENT_DATE_H
#define GOVERMENT_DATE_H
#include "goverment.h"
#include "../Date/date.h"
class C_goverment_date :
	public C_goverment
{
public:
	C_goverment_date(); //konstruktor bezparametrowy
	C_goverment_date(const C_goverment_date & goverment_date); //konstruktor kopiujacy
	C_goverment_date& operator=(const C_goverment_date& goverment_date); //operator przypisania =
	bool operator==(const C_goverment_date& goverment_date); //operator porownania == 
	bool operator!=(const C_goverment_date& goverment_date); //operator porownania !=
	virtual ~C_goverment_date(); //destruktor wirtualny
	virtual bool m_wchat_is(); //pokazuje czy istnieje jakis striing
	virtual void m_get_contens(N_striing &contens); //wprowadza striing do klasy
	virtual N_striing m_set_contens(); //zwraca caly striing
	int m_set_value_id(); //zwraca wyszukana wczesniej wartosc id
	C_day m_set_value_day(const char* value); //wyszukuje i zwraca wartosc day
	C_month m_set_value_month(const char* value); //wyszukuje i zwraca wartosc month
	C_year m_set_value_year(const char* value); //wyszukuje i zwraca wartosc year
	N_vektor<C_date> m_set_value_V_date(); // zwraca wektor obiektow C_date
	N_vektor<C_day> m_set_value_V_day(); //wyszukuje i zwraca wartosc day
	N_vektor<C_month> m_set_value_V_month(); //wyszukuje i zwraca wartosc month
	N_vektor<C_year> m_set_value_V_year(); //wyszukuje i zwraca wartosc year
private:
	virtual N_striing m_is_there_contens(N_striing &Word); //analizuje wprowadzany striing pod wzgledem poprawnej zawartosci
	N_striing s_goverment_data; //zmienna przechowujaca striing
	int m_id_value(); //wyszukuje id
	int i_value_id; //zmienna przechowujaca id
};
#endif // !GOVERMENT_DATE_H



