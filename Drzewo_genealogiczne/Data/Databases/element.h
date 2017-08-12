/***************************************************************************************************************
*"element.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_human zawiera tablice dynamiczna relacji"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     01.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 03.05.2015	 adding methods												      Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef ELEMENT_H
#define ELEMENT_H
#include "human.h"
#include "../Relation/children.h"
#include "../Relation/sibling.h"
#include "../Relation/parent.h"
#include "../Relation//grandchildren.h"
#include "../Relation//grandparents.h"
#include "../Relation/partner.h"
#include "../Relation/order.h"
class C_element
{
public:
	C_element(); //konstruktor bezparametrowy
	C_element(const C_human& human); //konstruktor parametrowy  argumentem typu human
	C_element(const C_element &human); //konstruktor kopiujacy
	C_element& operator=(const C_element &human); //operator prypisania
	bool operator==(const C_element &human); //operator pryrownania ==
	bool operator!=(const C_element &human); //operator przyrownania !=
	void m_get_children(C_children &children); //metoda dodajaca relacje dziecko do humana wskaznikowego
	void m_get_parent(C_parent &parent); //metoda dodajaca relacje rodzic do humana wskaznikowego
	void m_get_sibling(C_sibling &sibling); //metoda dodajaca relacje rodzenstwa do humana wskaznikowego
	void m_get_grandchildren(C_grandchildren &grandchildren);  //metoda dodajaca relacje wnuk do humana wskaznikowego
	void m_get_grandparents(C_grandparents &grandparents); //metoda dodajaca relacje dziadek do humana wskaznikowego
	void m_get_partner(C_partner &partner); //metoda dodajaca relacje partner do humana wskaznikowego
	void m_get_order(C_order &order); //metoda dodajaca relacje inne do humana wskaznikowego
	void m_update_children(int value,C_children &children); //metoda uaktualniaca relacje dziecko do humana wskaznikowego
	void m_update_parent(int value,C_parent &parent); //metoda uaktualniaca relacje rodzic do humana wskaznikowego
	void m_update_sibling(int value,C_sibling &sibling); //metoda uaktualniaca relacje rodzenstwo do humana wskaznikowego
	void m_update_human(const C_human &human); //metoda uaktualniaca humana wskaznikowego
	void m_update_grandchildren(int value, C_grandchildren &human); //metoda uaktualniaca relacje wnuk do humana wskaznikowego
	void m_update_grandparents(int value, C_grandparents &human); //metoda uaktualniaca relacje dziadek do humana wskaznikowego
	void m_update_partner(int value, C_partner &partner); //metoda uaktualniaca relacje partner do humana wskaznikowego
	void m_update_order(int value, C_order &order); //metoda uaktualniaca relacje inny do humana wskaznikowego
	C_human m_set_Human(); //metoda zwracajaca humana wskaznikowego
	C_children m_set_children(); //metoda zwracajaca relacja dziecko
	C_parent m_set_parent(); //metoda zwracajaca relacja rodzic
	C_sibling m_set_sibling(); //metoda zwracajaca relacja rodzenstwo
	C_partner m_set_partner(); //metoda zwracajaca relacja partner
	C_grandchildren m_set_grandchildren(); //metoda zwracajaca relacja wnuk
	C_grandparents m_set_grandparents(); //metoda zwracajaca relacja dziadek
	C_order m_set_order(); //metoda zwracajaca relacja inny
	C_children m_set_children(int value); //metoda zwracajaca relacja dziecko z tablicy relacji na pozycji wskazanej przez wartosc value
	C_parent m_set_parent(int value); //metoda zwracajaca relacja rodzic z tablicy relacji na pozycji wskazanej przez wartosc value
	C_sibling m_set_sibling(int value); //metoda zwracajaca relacja rodenstwo z tablicy relacji na pozycji wskazanej przez wartosc value
	C_grandchildren m_set_grandchildren(int value); //metoda zwracajaca relacja wnuk z tablicy relacji na pozycji wskazanej przez wartosc value
	C_grandparents m_set_grandparents(int value); //metoda zwracajaca relacja dziadek z tablicy relacji na pozycji wskazanej przez wartosc value
	C_partner m_set_partner(int value); //metoda zwracajaca relacja partner z tablicy relacji na pozycji wskazanej przez wartosc value
	C_order m_set_order(int value); //metoda zwracajaca relacja inny z tablicy relacji na pozycji wskazanej przez wartosc value
	C_element& m_clean(); //metoda czyszczaca wszystkie dane elementu
	void m_clean_children(); //metoda usuwa wszystkie relacje typu dziecko
	void m_clean_parent(); //metoda usuwa wszystkie relacje typu rodzic
	void m_clean_sibling();  //metoda usuwa wszystkie relacje typu rodzenstwo
	void m_clean_grandparents();  //metoda usuwa wszystkie relacje typu dziadek
	void m_clean_grandchildren();  //metoda usuwa wszystkie relacje typu wnuk
	void m_clean_partner(); //metoda usuwa wszystkie relacje typu paretner
	void m_clean_order(); //metoda usuwa wszystkie relacje typu inny
	void m_delete_children(); //metoda usuwa pierwsza relacje typu dziecko
	void m_delete_parent(); //metoda usuwa wszystkie relacje typu rodzic
	void m_delete_sibling(); //metoda usuwa wszystkie relacje typu rodzenstwo
	void m_delete_partner(); //metoda usuwa wszystkie relacje typu partner
	void m_delete_order(); //metoda usuwa wszystkie relacje typu inny
	void m_delete_children(int value);  //metoda usuwa relacje typu dziecko z krotki w tablicy wskazanej przez wartosc value
	void m_delete_parent(int value); //metoda usuwa relacje typu rodzic z krotki w tablicy wskazanej przez wartosc value
	void m_delete_sibling(int value); //metoda usuwa relacje typu rodzenstwo z krotki w tablicy wskazanej przez wartosc value
	void m_delete_grandchildren(int value); //metoda usuwa relacje typu wnuk z krotki w tablicy wskazanej przez wartosc value
	void m_delete_grandparents(int value); //metoda usuwa relacje typu dziadek z krotki w tablicy wskazanej przez wartosc value
	void m_delete_partner(int value); //metoda usuwa relacje typu partner z krotki w tablicy wskazanej przez wartosc value
	void m_delete_order(int value); //metoda usuwa relacje typu inny z krotki w tablicy wskazanej przez wartosc value
	N_vektor<C_grandparents> m_set_v_grandparents(); //metoda zwracajaca cala tablice relacji typu dziadek
	N_vektor<C_grandchildren> m_set_v_grandchildren(); //metoda zwracajaca cala tablice relacji typu wnuk
	N_vektor<C_parent> m_set_v_parent(); //metoda zwracajaca cala tablice relacji typu rodzic
	N_vektor<C_children> m_set_v_children(); //metoda zwracajaca cala tablice relacji typu dziecko
	N_vektor <C_partner> m_set_v_partner();  //metoda zwracajaca cala tablice relacji typu partner
	N_vektor<C_sibling> m_set_v_sibling();  //metoda zwracajaca cala tablice relacji typu rodzenstwo
	N_vektor <C_order> m_set_v_order();  //metoda zwracajaca cala tablice relacji typu inny
	//~C_element();
	virtual ~C_element(); //destruktor
protected:
	C_human Human; //human wskaznikowy
private:
	N_vektor<C_children> V_children; //wektor relacji typu dziecko
	N_vektor<C_parent> V_parent; //wektor relacji typu rodzic
	N_vektor<C_sibling> V_sibling; //wektor relacji typu rodzenstwo
	N_vektor<C_grandchildren> V_grandchildren; //wektor relacji typu wnuk
	N_vektor <C_grandparents> V_grandparents; //wektor relacji typu dziadek
	N_vektor <C_partner> V_partner; //wektor relacji typu dziecko partner
	N_vektor <C_order> V_order;  //wektor relacji typu inny
};
#endif // !ELEMENT_H




