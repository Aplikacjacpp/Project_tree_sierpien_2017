/***************************************************************************************************************
*"children.h"
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
*1.5	 26.05.2017  Adding private bool variable and method "m_set_bChild()"		  Lukasz Janus
****************************************************************************************************************/
#ifndef CHILDREN_H
#define CHILDREN_H
#include "relation.h"
class C_children :public C_relation 
{
public:
	C_children();
	C_children(C_id &id);
	C_children(const C_id &id);
	C_children(const C_children &children);
	C_children& operator=(const C_children &children);
	bool operator==(const C_children &children);
	bool operator!=(const C_children &children);
	virtual void m_get_id(C_id &id);
	virtual C_id m_set_id();
	C_id m_set_index_id();
	virtual ~C_children();
	virtual int m_set_variable();
	virtual void m_get_complete_content(N_striing data);
	void m_set_bChild(bool bChildm);
	virtual void m_get_complete_content(C_id index, C_id value);
	friend std::ostream& operator<<(std::ostream &is, const C_children &data);
	N_striing m_get_content();
private:
	C_id ID_index;
	C_id ID_value;
	bool bChild;
};
#endif // !CHILDREN_H



