/***************************************************************************************************************
*"gender.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po C_data"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     26.04.2017  Orginal design													  Mateusz Marchelewicz
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
*1.2	 02.05.2015	 Adding a virtual methods									      Lukasz Witek vel Witkowski
*1.3	 02.05.2015	 Adding parameter constructors								      Lukasz Witek vel Witkowski
*1.4	 13.05.2015	 Adding a method "m_set_variable()"							      Lukasz Witek vel Witkowski
****************************************************************************************************************/

#ifndef GENDER_H
#define GENDER_H
#include "data.h"
class C_gender: public C_data
{
public:
	C_gender();			// konstruktor bezparam
	C_gender(bool gender);		// konstruktor
	C_gender(N_striing &gender);		// konstruktor
	C_gender(const C_gender &C);		// konstr kop
	C_gender& operator=(const C_gender &C);	// przeciazone operatory
	bool operator==(const C_gender &C);
	bool operator!=(const C_gender &C);
	friend std::ostream& operator<<(std::ostream& is,const  C_gender &gender);		
	virtual ~C_gender();		// destruktor wirtualny
	virtual bool m_wchat_is();		//metoda zwraca true gdy zostalo wprowadzona jakas plec
	virtual void m_get_contens(N_striing &contens);	//metoda do wprowadzenia wartosci do zmiennej s_data_gender
	virtual N_striing m_set_contens();		// zwraca wartosc znajdujaca sie w w/w zmiennej
	virtual int m_set_variable();		// tu tez
protected:

private:
	virtual N_striing m_is_there_contens(N_striing &Word);		// analiza poprawnego wprowadzenia
	N_striing s_data_gender;		// przechowuje plec
};
#endif // !GENDER_H

