/***************************************************************************************************************
*"sl_date.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_save_load"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef C_SL_RELATIONS
#define C_SL_RELATIONS
#include "save_load.h"
#include "../Databases/goverment_relation.h"
#include "../Relation/partner.h"
#include "../narzedzia/Vektor.h"
class C_sl_relations :public C_save_load
{
public:
	C_sl_relations(); //konstruktor bezparametrowy
	C_sl_relations(const C_sl_relations & sl_relations); //konstruktor kopiujacy
	C_sl_relations& operator=(const C_sl_relations& sl_relations); //operator przypisania
	bool operator==(const C_sl_relations& sl_relations); //operator porownania ==
	bool operator!=(const C_sl_relations& sl_relations); //operator porownania !=
	virtual ~C_sl_relations(); //wirtualny destruktor
protected:
	void m_load_file_relation(bool what, N_striing Data); //czytanie z pliku
	virtual N_striing m_cypher_on(N_striing data); //odszyfrowywanie
	virtual N_striing m_cypher_off(N_striing data); //zaszyfrowywanie
	void m_add_new_relations(C_id id,N_vektor<C_children> V_children, 
	N_vektor<C_parent> V_parent, N_vektor<C_sibling> V_sibling, 
	N_vektor<C_grandchildren> V_grandchildren, N_vektor <C_grandparents> V_grandparents,
	N_vektor<C_partner> V_partner, N_vektor<C_order> V_order);
	N_vektor<C_goverment_relation> V_goverment_relation;
	C_goverment_relation m_set_gover_relation(int i);
private:
	bool m_what(int i);
};
#endif // !C_SL_RELATIONS



