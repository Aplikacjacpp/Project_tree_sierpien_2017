/***************************************************************************************************************
*"aplication.h"
*
*
*
*
*
*CONTENTS:
* "Klasa czysto abstrakcyjna dla klas poswieconych interfejsowi, klasa dziecko po klasie enginer"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.0     09.07.2017  Comments added	  		     								      Mateusz Marchelewicz
****************************************************************************************************************/
#ifndef APLICATION_H
#define APLICATION_H
#include "../Enginer/enginer.h"
class C_aplication :
	public C_enginer
{
public:
	C_aplication();				// konstruktor domyslny
	C_aplication(const C_aplication & aplication);		// konstruktor kopiujacy
	C_aplication& operator=(const C_aplication& aplication);		// przeciazone operatora przypisania
	bool operator==(const C_aplication& aplication);		//przeciazenie operatora porownania
	//bool operator!=(const C_aplication& aplication);
	//void m_add_human(C_human human);				// nie uzywane
	virtual ~C_aplication();		// destruktor wirtualny
protected:
	int m_return_index();			// zwraca indeks (int-a)
};
#endif // !APLICATION_H



