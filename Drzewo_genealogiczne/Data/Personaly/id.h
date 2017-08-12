/***************************************************************************************************************
*"id.h"
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
*1.3	 02.05.2015	 Adding parameter constructors								      Lukasz Witek vel Witkowski
*1.3     09.05.2017  Adding a overloaded operators									  Mateusz Marchelewicz
*1.4	 13.05.2015	 Adding a method "m_set_variable()"							      Lukasz Witek vel Witkowski
*1.5	 14.05.2015	 Update constructor class										  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef ID_H
#define ID_H
#include "data.h"
class C_id:public C_data  
{
public:
	C_id();
	C_id(char* id);
	C_id(N_striing &id, bool t);
	C_id(int id);
	C_id(const C_id &C);
	C_id& operator=(const C_id &C);
	bool operator==(const C_id &C);
	bool operator!=(const C_id &C);
	bool operator>(C_id &id);
	bool operator<(C_id &id);
	virtual ~C_id();
	virtual bool m_wchat_is();
	virtual void m_get_contens(N_striing &contens);
	virtual N_striing m_set_contens();
	virtual int m_set_variable();
	void m_get_contens(int value);
private:
	virtual N_striing m_is_there_contens(N_striing &Word);
	N_striing s_data_id;
};
#endif // !ID_H
