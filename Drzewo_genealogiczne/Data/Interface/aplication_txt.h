/***************************************************************************************************************
*"aplication_txt.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_aplication"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1     09.05.2017  Adding methods for menu										  Mateusz Marchelewicz
*1.2     15.05.2017  Windows size changed										      Mateusz Marchelewicz
*1.3     17.05.2017  Font size changed										          Mateusz Marchelewicz
*1.4     21.05.2017  Menu modified, new methods added								  Mateusz Marchelewicz
*1.5     22.05.2017  Menu modified								                      Mateusz Marchelewicz
*1.6	 10.06.2017	 Add value to dystryct private									  Lukasz Witek vel Witkowski
*1.7     27.06.2017  Methods names changed		     								  Mateusz Marchelewicz
*1.7.1   27.06.2017  Comments added	  		     								      Mateusz Marchelewicz
*1.7.2   1.08.2017   New method added	  		     								  Mateusz Marchelewicz
****************************************************************************************************************/
#ifndef APLICATION_TXT_H
#define APLICATION_TXT_H
#include "aplication.h"
#include <Windows.h>

using std::cout;
using std::endl;

class C_aplication_txt :
	public C_aplication
{
public:
	C_aplication_txt();			// konstruktor domyslny
	C_aplication_txt(const C_aplication_txt & aplication_txt);		// konstruktor
	C_aplication_txt& operator=(const C_aplication_txt& aplication_txt);	// konstruktor kopiujacy
	bool operator==(const C_aplication_txt& aplication_txt);	// przeciazone operatory
	bool operator!=(const C_aplication_txt& aplication_txt);
	virtual ~C_aplication_txt();						// destruktor
	void m_set_window(int Width, int Height);			// ustawia wymiary okna, czcionke
//	friend char& operator>>(std::iostream& is, char &c);
	int m_main_menu();			// menu glowne
	int m_sub_1();				// podmenu
	int m_sub_menu_2();		// podmenu, edycja, wyswietlanie drzewa
	void m_import_tree();		// import drzewa
	int m_edit_tree();			// edycja drzewa
	int m_display_tree();		// wyswietla drzewo
	int m_search_tree();		// metoda do wyszukiwania ludzi po danych
	void m_create_logo();		// tworzy "atrape" drzewa
	char m_get_key();			// obsluga polskich znakow, alfabetu
	bool m_what_return();		// menu z opcjami "Tak", "Nie", "Powrot"
	bool m_what_menu();			// do dokonczenia!
	void m_look_at(C_id id);			//metoda wyswietlajaca drzewo
	void m_menu();				//metoda zawiera w sobie jedno calkowite menu
	//Poszczegolne menu:
	int m_menu_name_tree();			// metoda dodaje nazwe drzewa
	C_human m_menu_add_first_name();	// metoda dodaje imie osoby
	C_element m_menu_wybor_humana_wskaznikowego();		// potrzebna do tworzenia relacji
	int m_menu_add_human(int where);			// menu dodawania osoby
	C_human m_menu_add_last_name();		// metoda dodaje nazwisko osoby
	C_human m_menu_add_gender();		// metoda dodaje plec osoby
	C_human m_menu_add_date();			// metoda dodaje daty ur i smierci
	int m_menu_relation(int where);				// wyswietla menu z relacjami
	C_element m_menu_add_relations(int data, C_element Element);	// metoda dodaje relacje do osoby
	int m_menu_edit_human(N_striing Data, int X, C_human& human);		// edycja humana
	C_element m_menu_edit_relations();		// edycja relacji humana
	int m_menu_tree();					// menu w utworzonym drzewie, wyswietlania go, edycja
	void m_export_tree();					// export drzewa do pliku, by go potem moc zaladowac na innym PC
	void cls();						// metoda "czysci" ekran, lepiej nie uzywac system('cls')


private:
	N_vektor<N_striing> Lista;		// do wykorzystania przy liscie ludzi i dystryktow:)
	N_vektor<C_id> V_ID;
	N_striing name_user_profile;	// nazwa usera (Lukasz, Mateusz itp)
	void m_load_lista();			// wyswietla liste utworzonych ludzi
	int m_lista(int what);	// wyswietla liste utworzonych drzew
	bool m_what_files();			// zwiazana z plikami tworzonymi przez program (ope..)
};
#endif // !APLICATION_TXT_H
