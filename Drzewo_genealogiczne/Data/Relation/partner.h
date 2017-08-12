/***************************************************************************************************************
*"grandchildren.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_relation"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     02.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.2	 25.05.2017  Adding private bool variable and method "m_set_bPart()"		  Lukasz Janus
****************************************************************************************************************/
#ifndef C_partner_H
#define C_partner_H
#include "relation.h"
class C_partner :public C_relation
{
public:
	C_partner();
	C_partner(C_id &id);
	C_partner(const C_id &id);
	C_partner(const C_partner & partner);
	C_partner& operator=(const C_partner& partner);
	bool operator==(const C_partner& partner);
	bool operator!=(const C_partner& partner);
	virtual ~C_partner();
	void m_set_bPart(bool bPartm);
	virtual void m_get_id(C_id &id);
	virtual C_id m_set_id();
	C_id m_set_index_id();
	virtual int m_set_variable();
	virtual void m_get_complete_content(N_striing data);
	virtual void m_get_complete_content(C_id index, C_id value);
	friend std::ostream& operator<<(std::ostream &is, const C_partner &data);
	N_striing m_get_content();
private:
	C_id ID_index;
	C_id ID_value;
	bool bPart;
};
#endif // !C_partner_H



