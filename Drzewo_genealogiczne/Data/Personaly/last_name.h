/***************************************************************************************************************
*"last_name.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po C_data"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     25.04.2017  Orginal design													  Mateusz Marchelewicz
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 02.05.2015	 Adding a virtual methods									      Lukasz Witek vel Witkowski
*1.3     09.05.2017  Adding a overloaded operators									  Mateusz Marchelewicz
*1.4	 13.05.2015	 Adding a method "m_set_variable()"							      Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef C_LAST_NAME_H
#define C_LAST_NAME_H
#include "data.h"
class C_last_name : public C_data
{
public:
	C_last_name();
	C_last_name(N_striing &last);
	C_last_name(const C_last_name &last);
	C_last_name& operator=(const C_last_name &last);
	bool operator==(const C_last_name &last);
	bool operator!=(const C_last_name &last);
	friend std::ostream& operator<<(std::ostream& is, C_last_name &last);
	bool operator<(C_last_name &last);
	bool operator>(C_last_name &last);
	virtual ~C_last_name();
	virtual bool m_wchat_is();
	virtual void m_get_contens(N_striing &contens);
	virtual N_striing m_set_contens();
	virtual int m_set_variable();
protected:

private:
	virtual N_striing m_is_there_contens(N_striing &Word);
	N_striing s_data_last_name;
};
#endif // !C_LAST_NAME_H


