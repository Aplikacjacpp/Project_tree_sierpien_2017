/***************************************************************************************************************
*"year.h"
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
//

#ifndef YEAR_H
#define YEAR_H
#include "../Personaly/data.h"
class C_year: public C_data
{
public:
	C_year(); //konstruktor bezparametrowy
	C_year(N_striing &year); //kostruktor parametrowy konwertujacy wartosc year i przypisujacy do zmiennej i_data_year
	C_year(int year); //konstruktor parametrowy przypisujacy wartosc year do zmiennei i_data_year
	C_year(const C_year &C); //konstruktor kopiujacy
	C_year& operator=(const C_year &C); //konstruktor przypisania
	bool operator==(const C_year &C); //konstruktor porownania typu ==
	bool operator!=(const C_year &C); //konstruktor porownania typu !=
	virtual ~C_year(); //destruktor
	virtual bool m_wchat_is(); //metoda sprawdzajaca czy istnieje juz wartosc w zmienej i_data_year
	virtual void m_get_contens(N_striing &contens); //metoda przyjmuje za parametr n_striing ktory analizuje i
													//konwertuje ktory nastepnie przypisuje do i_data_year
	virtual int m_set_variable(); //metoda zwraca wartosc charakterystyczna dla typu dany year zapisana pod t_year
	void m_get_year(N_striing &contens); //metoda podstawia po analizie wartosc skonwertowana do i_data_year 
										 //(metoda powstala na skutek uwirtualnienia poprzedniej metody "void m_get_contens(N_striing &contens)")
	N_striing m_year_set(); //metoda zwraca wartosc i_data_year w postaci N_striing
private:
	virtual N_striing m_is_there_contens(N_striing &Word); //metoda analizuje i edytuje w razie potrzeby dane przychodzace w postaci N_striing
	virtual N_striing m_set_contens(); //metoda do konwersji typow
protected:
	int m_set_value_year(); //metoda zwraca wartosc i_data_year
	void m_get_value_year(int value); //metoda podstawia wartosc value do i_data_year
	int i_data_year = NULL; //zmienna i_data_year przechowuje warosc roku
};
#endif // !year_H




