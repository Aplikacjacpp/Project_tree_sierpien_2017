/***************************************************************************************************************
*"tree.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_element zawiera tablice dynamiczna ludzi"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     01.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 03.05.2015	 adding methods												      Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef TREE_H
#define TREE_H
#include "element.h"
class C_tree :public C_element
{
public:
	C_tree();
	C_tree(const C_element &element);
	C_tree(const C_human &human);
	C_tree(const C_tree &tree);
	C_tree& operator=(const C_tree &tree);
	bool operator==(const C_tree &tree);
	bool operator!=(const C_tree &tree);
	void m_add_human(C_human &h, int data, bool bwhat, int ivalue);
	void m_update_human(C_human &h, int data, int ivalue);
	void m_delete_human(C_human &h, int data, int ivalue);
	void m_delete_human(C_human &h, int data);
	void m_add_id(const C_id &id);
	C_id m_get_id();
	C_human m_get_human(int data, int ivalue);
	friend std::ostream& operator<<(std::ostream& is, const C_tree &tree);
	C_human m_get_index_human();
	virtual ~C_tree();
private:
		N_vektor<C_human> V_human_grandparent;
		N_vektor<C_human> V_human_grandchildren;
		N_vektor<C_human> V_human_children;
		N_vektor<C_human> V_human_parent;
		N_vektor<C_human> V_human_sibling;
		N_vektor<C_human> V_human_partner;
		N_vektor<C_human> V_human_order;
		C_id ID_tree;
};
#endif // !TREE_H



