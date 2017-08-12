/***************************************************************************************************************
*"human.h"
*
*
*
*
*
*CONTENTS:
* "Klasa reprezentujaca czlowieka, najmniejsza komurka bazy danych, zawierajaca: C_first_name, C_last_name, C_id,
C_date"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     30.04.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 02.05.2015	 adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 02.05.2015	 adding parameter constructor								      Lukasz Witek vel Witkowski
*1.3	 03.05.2015	 adding methods												      Lukasz Witek vel Witkowski
*1.3     09.05.2017  Adding a overloaded operator                                     Mateusz Marchelewicz
*1.3	 23.05.2017	 Adding methods interface										  Bartosz Bukowski
****************************************************************************************************************/
#ifndef C_HUMAN_H
#define C_HUMAN_H
#include "../Personaly/last_name.h"
#include "../Personaly/first_name.h"
#include "../Personaly/id.h"
#include "../date/date.h"
#include "../Personaly/gender.h"
#include "../narzedzia/Vektor.h"
#include "../Helpful/definition.h"
#include <windows.h>
class C_human
{
public:
	C_human();
	C_human(C_id &id);
	C_human(const C_human &human);
	C_human& operator=(const C_human &human);
	bool operator==(const C_human &human);
	bool operator!=(const C_human &human);
	//friend std::ostream& operator<<(std::ostream& is, C_human &human);
	void m_get_first_name(C_first_name &f_name);
	void m_get_first_name(N_striing &f_name);
	void m_get_last_name(C_last_name &l_name);
	void m_get_last_name(N_striing &l_name);
	void m_get_gender(C_gender &gender);
	void m_get_gender(N_striing &gender);
	void m_get_gender(bool gender);
	void m_shift_id(N_striing &id);
	void m_shift_id(int id);
	void m_shift_id(C_id &id);
	void m_get_date(C_date date);
	void m_delete_first_name();
	void m_delete_last_name(int value);
	void m_delete_last_name();
	void m_delete_gender();
	void m_delete_date(int value);
	void m_delete_date();
	void m_update_date(int value, C_date& date);
	void m_update_last_name(int value, C_last_name& l_name);
	void m_update_last_name(int value, N_striing& l_name);
	void interf_cut(N_striing &first, N_striing &last, C_human &human, int cut);
	void interf_m(C_human &human, C_date &d, C_date ds = NULL);
	void interf_mb(N_striing firstnamee, N_striing lastnamee, C_date &du, C_date ds = NULL, char poz = '*', char pion = '|');
	void interf_mbd(N_striing firstname, N_striing lastname, C_date &du, C_date ds = NULL, char poz = '*', char pion = '|');
	friend std::ostream& operator<<(std::ostream &is,const C_human &h);
	N_striing m_short_interface_personaly();
	N_striing m_short_interface_date();
	C_human& m_clear();
	C_human& m_clear_date();
	C_human& m_clear_last_name();
	C_first_name m_set_first_name();
	C_last_name m_set_last_name();
	C_last_name m_set_last_name(int value);
	C_gender m_set_gender();
	C_id m_set_id();
	C_date m_set_date(int value);
	C_date m_set_date();
	N_vektor<C_date> m_set_Vdate();
	N_vektor<C_last_name> m_set_V_last_name();
	virtual ~C_human();
private:
	N_vektor<C_date> V_date;
	C_id Id;
	C_first_name First;
	N_vektor<C_last_name> V_last;
	C_gender Gender;
};
#endif // !C_human_H
