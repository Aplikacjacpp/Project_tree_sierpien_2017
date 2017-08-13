/***************************************************************************************************************
*"Date.h"
*
*
*
*
*
*CONTENTS:
* "Klasa zawierajaca klasy: C_day, C_month, C_year"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     30.04.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 12.05.2015  Adding methods													  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef C_DATE_H
#define C_DATE_H 
#include "day.h"
#include "month.h"
#include "year.h"
class C_date : virtual public C_day,virtual public C_month,virtual public C_year
{
public:
	C_date();  //konstruktor bezparametrowy
	C_date(char value); //konstruktor parametrowy
	C_date(const C_date &d); //konstruktor kopiujacy
	C_date& operator=(const C_date &d); //operator przypisania
	bool operator==(const C_date &d); //operator poronania ==
	bool operator!=(const C_date &d); //operator porownania !=
	bool operator<(const C_date &d); //operator mniejsze <
	bool operator>(const C_date &d); //operator wieksze >
	bool operator<=(const C_date &d); //operator mniejsze rowne <=
	bool operator>=(const C_date &d); //operator wieksze rowne >=
	C_day m_set_day();  //staw dzien do daty
	C_month m_set_month(); //wstaw miesiac do daty
	C_year m_set_year(); //wstaw rok do daty
	N_striing  m_set_DD_MM_YYYY(); //zwroc date w postaci stringa typu dzien - miesiac - rok
	N_striing  m_set_MM_DD_YYYY(); //zwroc date w postaci stringa typu miesiac - dzien - rok
	N_striing  m_set_YYYY_MM_DD(); //zwroc date w postaci stringa typu rok - miesiac - dzien
	N_striing  m_set_YYYY_DD_MM(); //zwroc date w postaci stringa typu rok - dzien - miesiac
	void m_get_DD_MM_YYYY(C_day& day, C_month& month, C_year & year); //wstaw date z dniem miesiacem i rokiem
	void m_shift_day(C_day day); //zmien dzien
	void m_shift_day(int day); //zmien dzien
	void m_shift_day(N_striing day); //zmien dzien
	void m_shift_month(C_month month); //zmien miesiac
	void m_shift_month(int month); //zmien miesiac
	void m_shift_month(N_striing month); //zmien miesiac
	void m_shift_year(C_year year); //zmien rok
	void m_shift_year(int year); //zmien rok
	void m_shift_year(N_striing year); //zmien rok
	void m_clear(); //wyczysc wszystkie dane daty
	N_striing m_what_type_date(); //zwroc typ daty np. malzenstwa, smierci czy urodzenia
	void m_shift_char(char value);
	void m_get_type(N_striing value); //wstaw typ daty
	virtual ~C_date(); //destruktor wirtualny
	friend std::ostream& operator<<(std::ostream &is, const C_date &d); //przeciazenie operatora przesuniecia bitowego na wyjscie
private:
	char c_value; //zmienna typu char do podzialki
	N_striing s_value; //zmienna typu striing do typu daty
	void m_analitic_date(bool b_what); //analiza daty
};
#endif //!C_DATE
