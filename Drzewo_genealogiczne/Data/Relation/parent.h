/***************************************************************************************************************
*"parent.h"
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
*1.4	 25.05.2017  Adding private bool variable and method "m_set_bParent()"		  Lukasz Janus
****************************************************************************************************************/
#ifndef PARENT_H
#define PARENT_H
#include "relation.h"
#include "../Personaly/id.h"
class C_parent :public C_relation
{
public:
	C_parent();
	C_parent(C_id &id);
	C_parent(const C_id &id);
	C_parent(const C_parent &parent);
	C_parent& operator=(const C_parent &parent);
	bool operator==(const C_parent &parent);
	bool operator!=(const C_parent &parent);
	virtual void m_get_id(C_id &id);
	virtual C_id m_set_id();
	C_id m_set_index_id();
	virtual int m_set_variable();
	virtual ~C_parent();
	virtual void m_get_complete_content(N_striing data);
	virtual void m_get_complete_content(C_id index, C_id value);
	friend std::ostream& operator<<(std::ostream &is, const C_parent &data);
	void m_set_bParent(bool bParentm);
	N_striing m_get_content();
private:
	C_id ID_index;
	C_id ID_value;
	bool bParent;
};
#endif // !PARENT_H



