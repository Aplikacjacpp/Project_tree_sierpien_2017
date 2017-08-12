/***************************************************************************************************************
*"order.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_relation"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     30.04.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 03.05.2015	 Adding a virtual methods									      Lukasz Witek vel Witkowski
*1.3	 13.05.2015	 Adding a method "m_set_variable()"							      Lukasz Witek vel Witkowski
*1.4	 17.05.2017  Adding priority methods										  Lukasz Witek vel Witkowski
*1.5	 25.05.2017  Adding private bool variable and method "m_set_bSib()"			  Lukasz Janus
****************************************************************************************************************/
#ifndef ORDER_H
#define ORDER_H
#include "relation.h"
class C_order :public C_relation
{
public:
	C_order(); //konstruktor bezparametrowy
	C_order(C_id &id); //konstruktor parametrowy
	C_order(const C_id &id);  //konstruktor parametrowy ??
	C_order(const C_order &sib); //konstruktor kopiujacy
	C_order& operator=(const C_order &sib); //operator przypisania
	bool operator==(const C_order &sib); //operator porownania ==
	bool operator!=(const C_order &sib); //operator porownania !=
	virtual void m_get_id(C_id &id); //wstawia id do ID_value
	virtual C_id m_set_id(); //zwraca ID_value
	C_id m_set_index_id();
	virtual int m_set_variable(); //zwraca wartosc w t_order
	virtual ~C_order(); //wirtualny destruktor
	virtual void m_get_complete_content(N_striing data); //analizuje i podstawia wyluskane dane pod dane prywatne
	virtual void m_get_complete_content(C_id index, C_id value); //wstawia argumenty do danych prywatnych
	void m_set_bSib(bool bSibm); //metoda dostêpu do zmiennej prywatnej bSib
	N_striing m_get_content(); // wsylanie zawartosci id
	friend std::ostream& operator<<(std::ostream &is, const C_order &data); //przesuniecie operatora przesuniecia bitowego na wyjscie
	void m_get_atribut(N_striing atribut); //wstawianie atrybutu
	N_striing m_get_atribut(); //zwraca wartosc atrybutu
private:
	C_id ID_index; //Id humana wskaznikowego
	C_id ID_value; //Id humana na drugim koncu relacji
	bool bSib;	//zmienna bool
	N_striing satribut; //zmienna z wlasna nazwa relacji
};
#endif // !order_H



