/***************************************************************************************************************
*"goverment_relation.h"
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
*1.2	 14.05.2017  Adding new mothods												  Lukasz Witek vel Witkowski
*1.3	 17.05.2017  Adding a method to return values ​​from relation classes			  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef GOVERMENT_RELATION_H
#define GOVERMENT_RELATION_H
#include "goverment.h"
#include "../Relation/children.h"
#include "../Relation/grandchildren.h"
#include "../Relation/grandparents.h"
#include "../Relation/parent.h"
#include "../Relation/sibling.h"
#include "../Relation/partner.h"
#include "../Relation/order.h"
class C_goverment_relation :
	public C_goverment
{
public:
	C_goverment_relation(); //konstruktor bezparametrowy
	C_goverment_relation(const C_goverment_relation & goverment_relation); //konstruktor kopiujacy
	C_goverment_relation& operator=(const C_goverment_relation& goverment_relation); //operator przypisania
	bool operator==(const C_goverment_relation& goverment_relation); //operator porownania ==
	bool operator!=(const C_goverment_relation& goverment_relation);//operator porownania ==
	virtual ~C_goverment_relation(); //wirtualny destruktor
	virtual bool m_wchat_is(); //sprawdza czy istnieje zawartosc striinga
	virtual void m_get_contens(N_striing &contens); //wprowadza striing
	virtual N_striing m_set_contens(); //zwraca wartosc striinga
	int m_set_value_id(); //zwraca wyszukana wczesniej wartosc striinga 
	N_vektor<C_children> m_set_value_children(); //wyszukuje i zwraca wartosc dla children
	N_vektor<C_parent> m_set_value_parent(); //wyszukuje i zwraca wartosc dla parent
	N_vektor<C_grandchildren> m_set_value_grandchildren(); //wyszukuje i zwraca wartosc dla grandchildren
	N_vektor<C_grandparents> m_set_value_grandparents(); //wyszukuje i zwraca wartosc dla grandparent
	N_vektor<C_sibling> m_set_value_sibling(); //wyszukuje i zwraca wartosc dla sibling
	N_vektor<C_partner> m_set_value_patner(); //wyszukuje i zwraca wartosc dla sibling
	N_vektor<C_order> m_set_value_order();
private:
	virtual N_striing m_is_there_contens(N_striing &Word); //analizuje wprowadzany striing
	N_striing s_goverment_relation; //zmienna przechowujaca striing
	int m_id_value(); //wyszukuje id
	int i_value_id; //przechowuje wartosc id
};
#endif // !GOVERMENT_RELATION_H


//doxygen 
