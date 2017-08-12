/***************************************************************************************************************
*"day.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po C_data"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     26.04.2017  Orginal design													  Mateusz Marchelewicz
*1.1	 02.05.2015	 shift name variable										      Lukasz Witek vel Witkowski
*1.2	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.3	 02.05.2015	 Adding a virtual methods									      Lukasz Witek vel Witkowski
*1.4	 02.05.2015	 Adding parameter constructors								      Lukasz Witek vel Witkowski
*1.5	 12.05.2015	 Redbuind m_is_there_contens									  Lukasz Witek vel Witkowski
*1.6	 13.05.2015	 Adding a method "m_set_variable()"							      Lukasz Witek vel Witkowski
****************************************************************************************************************/

#ifndef DAY_H
#define DAY_H
#include "../Personaly/data.h"
class C_day: public C_data
{
public:
	C_day(); //konstruktor bezparametrowy
	C_day(N_striing &day); //kostruktor parametrowy przyjmujacy stringa
	C_day(int day); //konstruktor parametrowy przyjmujacy inta
	C_day(const C_day &C); //konstruktor kopiujacy
	C_day& operator=(const C_day &C); //operator przypisania
	bool operator==(const C_day &C); //operator porownania ==
	bool operator!=(const C_day &C); //operator porownania !=
	virtual ~C_day(); //destruktor
	virtual bool m_wchat_is(); //metoda sprawdza czy istnieje wartosc i_data_day
	virtual void m_get_contens(N_striing &contens); //metoda przyjmuje za parametr n_striing ktory analizuje i
													//konwertuje ktory nastepnie przypisuje do i_data_day
	virtual int m_set_variable(); //metoda zwraca wartosc charakterystyczna dla typu dany day zapisana pod t_day
	N_striing m_day_set(); //metoda zwraca wartosc i_data_day w postaci N_striinga
	void m_get_day(N_striing &contens); //metoda podstawia po analizie wartosc skonwertowana do i_data_day 
										//(metoda powstala na skutek uwirtualnienia poprzedniej metody "void m_get_contens(N_striing &contens)")
private:
	virtual N_striing m_is_there_contens(N_striing &Word); //metoda analizuje i edytuje w razie potrzeby dane przychodzace w postaci N_striing
	virtual N_striing m_set_contens(); //metoda do konwersji typow
protected: 
	int m_set_value_day(); //metoda zwraca wartosc i_data_day
	void m_get_value_day(int value); //metoda przepisuje wartosc z value na i_data_day
	int i_data_day = NULL; // zmienna przechowujaca wartosc i_data_day
};
#endif // !day_H


