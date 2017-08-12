/***************************************************************************************************************
*"month.h"
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

#ifndef MONTH_H
#define MONTH_H
#include "../Personaly/data.h"
class C_month: public C_data
{
public:
	C_month(); //konstruktor bezparametrowy
	C_month(N_striing &month); //kostruktor parametrowy konwertujacy wartosc month i przypisujacy do zmiennej i_data_month
	C_month(int month); //konstruktor parametrowy przypisujacy wartosc month do zmiennei i_data_month
	C_month(const C_month &C); //konstruktor kopujacy
	C_month& operator=(const C_month &C); //operator przypisania
	bool operator==(const C_month &C); //operator porownania typu ==
	bool operator!=(const C_month &C); //operator porownania typu !=
	virtual ~C_month(); //destruktor
	virtual bool m_wchat_is(); //metoda sprawdzajaca czy istnieje juz wartosc w zmienej i_data_month
	virtual void m_get_contens(N_striing &contens); //metoda przyjmuje za parametr n_striing ktory analizuje i
													//konwertuje ktory nastepnie przypisuje do i_data_month
	virtual int m_set_variable(); //metoda zwraca wartosc charakterystyczna dla typu dany month zapisana pod t_month
	N_striing m_month_set(); //metoda zwraca wartosc i_data_month w postaci N_striinga
	void m_get_month(N_striing &contens); //metoda podstawia po analizie wartosc skonwertowana do i_data_month 
										//(metoda powstala na skutek uwirtualnienia poprzedniej metody "void m_get_contens(N_striing &contens)")
private:
	virtual N_striing m_is_there_contens(N_striing &Word); //metoda analizuje i edytuje w razie potrzeby dane przychodzace w postaci N_striing
	virtual N_striing m_set_contens(); //metoda do konwersji typow
protected:
	int m_set_value_month(); //metoda zwracajaca wartosc zmiennej i_data_month
	void m_get_value_month(int value); //metoda przypisujaca wartosc value do zmiennej i_data_month
	int i_data_month = NULL; //zmienna i_data_month przychowujaca wartosc miesiaca
};
#endif // !month_H



