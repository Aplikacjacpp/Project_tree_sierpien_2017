/***************************************************************************************************************
*"first_name.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po C_data"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     22.04.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 02.05.2015	 Adding a virtual methods									      Lukasz Witek vel Witkowski
*1.3     09.05.2017  Adding a overloaded operators									  Mateusz Marchelewicz
*1.4	 13.05.2015	 Adding a method "m_set_variable()"							      Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef C_FIRST_NAME_H
#define C_FIRST_NAME_H
#include "data.h"
class C_first_name :public C_data
{
public:
	C_first_name(); //konstruktor bezparametrowy
	C_first_name(N_striing &first); //konstruktor parametrowy
	C_first_name(const C_first_name &first); //konstruktoe kopiujacy
	C_first_name& operator=(const C_first_name &first); //operator przypisania
	bool operator==(const C_first_name &first); //operator porownania ==
	bool operator!=(const C_first_name &first); //operator porownania !=
	bool operator>(C_first_name &first); //operator wieksze
	bool operator<(C_first_name &first); //operator mniejsze
	friend std::ostream& operator<<(std::ostream& is,const C_first_name &first); //operator przesuniecia bitowego na ostream 
	//(mozna wyswietlac zawartosc za pomoca std::cout)
	//~C_first_name();
	virtual ~C_first_name(); //destruktor
	virtual bool m_wchat_is(); //metoda zwraca true gdy zostalo wprowadzone jakies imie
	virtual void m_get_contens(N_striing &contens); //metoda do wprowadzenia wartosci do zmiennej s_data_first_name
	virtual N_striing m_set_contens(); //metoda do zwrucenia zwartosci znajdujacej sie w zmiennej s_data_first_name
	virtual int m_set_variable(); // metoda zwracajaca wartosc typu C_first_name zdefiniowane pod zmienna t_first_name
protected:
	
private:
	virtual N_striing m_is_there_contens(N_striing &Word); //metoda do analizowania poprawnosci wprowadzonego imienia 
	N_striing s_data_first_name; //zmienna przechoujaca wartosc imienia
};
#endif // !C_FIRST_NAME_H
