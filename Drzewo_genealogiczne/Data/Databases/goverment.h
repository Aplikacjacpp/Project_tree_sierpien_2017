/***************************************************************************************************************
*"goverment.h"
*
*
*
*
*
*CONTENTS:
* "Klasa bazowa dla innych klas do przechowywania 'wierszy' pliku"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.01    09.05.2017  Pure Virtual Methods Added										  Mateusz Marchelewicz
****************************************************************************************************************/
#ifndef GOVERMENT_H
#define GOVERMENT_H
#include "../narzedzia/striing.h"
#include "../narzedzia/Vektor.h"
#include "../Helpful/definition.h"
class C_goverment
{
public:
	C_goverment();
	C_goverment(const C_goverment & goverment);
	C_goverment& operator=(const C_goverment& goverment);
	bool operator==(const C_goverment& goverment);
	bool operator!=(const C_goverment& goverment);
	virtual ~C_goverment();
	virtual bool m_wchat_is() = 0;
	virtual void m_get_contens(N_striing &contens) = 0;
	virtual N_striing m_set_contens() = 0;

private:
	virtual N_striing m_is_there_contens(N_striing &Word) = 0;
	N_striing s_goverment_text;
};
#endif // !GOVERMENT_H



