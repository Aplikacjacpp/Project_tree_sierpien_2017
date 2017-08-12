#include "aplication_txt.h"
// #include "Data\Enginer\enginer.h"     nie widzi tego!
#include <cstdlib>
//#include <fstream>
#include <Windows.h>
void C_aplication_txt::cls()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	if (!GetConsoleScreenBufferInfo(hStdout, &csbi))
		return;

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	if (!FillConsoleOutputCharacter(hStdout, (TCHAR) ' ',
		dwConSize, coordScreen, &cCharsWritten))
		return;

	if (!GetConsoleScreenBufferInfo(hStdout, &csbi))
		return;

	if (!FillConsoleOutputAttribute(hStdout, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten))
		return;

	SetConsoleCursorPosition(hStdout, coordScreen);
}

C_aplication_txt::C_aplication_txt() {
	system("del operation.ope&&cls");	// na poczatku usuwa plik operation.ope + czysci ekran
	Sleep(100);
	system("echo %USERPROFILE%>>operation.ope");
	std::ifstream file;
	file.open("operation.ope");			// tworzenie pliku operation.ope
	if (file.good())					// operacje na nim
	{
		name_user_profile.m_getline(file);		// na poczatku nazwa usera
		//name_user_profile.m_push_back("\\");
		//std::cout << name_user_profile << "\n";
		N_striing s_data = name_user_profile;
		s_data += "\\";
		s_data += op_name_catalog;			// do tego nazwa katalogu
		m_get_index_value_tree(s_data);
		file.close();					// zamykanie pliku
	}
	Lista = m_add_to_operation(true, Lista);
	if (m_what_files())
	{
		system("attrib -a +h +r +s operation.ope");
		system("md %USERPROFILE%\\.tree&&%USERPROFILE%>>echo  >>%USERPROFILE%\\.tree\\init.&&cd %USERPROFILE%\\.tree\\&&ATTRIB -A +H init."); //dziala
	}
	m_set_window(150, 70); // wyswietlenie okna z parametrami (wymiarami)
	m_menu();	// wyswietlenie menu
}
C_aplication_txt::C_aplication_txt(const C_aplication_txt & aplication_txt) { //konstruktor kopujacy
	if (this != &aplication_txt) *this = aplication_txt;
	system("del operation.ope&&cls");
	Sleep(100);
	system("echo %USERPROFILE%>>operation.ope");
	std::ifstream file;
	file.open("operation.ope");				// tworzenie pliku operation.ope
	if (file.good())						// operacje na nim
	{
		name_user_profile.m_getline(file);	// na poczatku nazwa usera
		//name_user_profile.m_push_back("\\");
		//	std::cout << name_user_profile << "\n";
		N_striing s_data = name_user_profile;
		s_data += "\\";
		s_data += op_name_catalog;			// do tego nazwa katalogu
		m_get_index_value_tree(s_data);
		file.close();						// zamykanie pliku
	}
	Lista = m_add_to_operation(true, Lista);
	if (m_what_files())
	{
		system("attrib -a +h +r +s operation.ope");
		system("md %USERPROFILE%\\.tree&&%USERPROFILE%>>echo  >>%USERPROFILE%\\.tree\\init.&&cd %USERPROFILE%\\.tree\\&&ATTRIB -A +H init."); //dziala
	}
	m_set_window(150, 70); // wyswietlenie okna z parametrami (wymiarami)
	m_menu();			// Wyswietlenie menu
}
C_aplication_txt& C_aplication_txt::operator=(const C_aplication_txt& aplication_txt) {
	if (this == &aplication_txt) return *this;
	if (*this == aplication_txt) return *this;
	Lista = aplication_txt.Lista;		// przypisanie wartosci
	V_ID = aplication_txt.V_ID;
	name_user_profile = aplication_txt.name_user_profile;
	return *this;
}
bool C_aplication_txt::operator==(const C_aplication_txt& aplication_txt) { // przeciazone operatory, gdy OK zwraca true
	if (Lista == aplication_txt.Lista&&V_ID == aplication_txt.V_ID&&name_user_profile == aplication_txt.name_user_profile) return true;
	return false;
}
bool C_aplication_txt::operator!=(const C_aplication_txt& aplication_txt) { 
	if (Lista != aplication_txt.Lista&&V_ID != aplication_txt.V_ID&&name_user_profile != aplication_txt.name_user_profile) return true;
	return false;
}
C_aplication_txt::~C_aplication_txt() {}
bool C_aplication_txt::m_what_files() {
	N_striing data;
	int i;
	std::ifstream file;
	data = "cd ";
	data += name_user_profile;
	data += "\\.tree\\&&attrib +A -H init."; // wchodzi do folderu zgodnego z nazwa usera
	system(data.m_c_str());
	data = name_user_profile;
	data += "\\.tree\\init.";
	file.open(data.m_c_str());
	if (file.good())
	{
		file.close();			// zamyka plik
		data = "cd ";
		data += name_user_profile;		// wchodzi do folderu zgodnego z nazwa usera
		data += "\\.tree\\&&attrib -A +H init.";
		system(data.m_c_str());
		return false;
	}
	return true;
}

void C_aplication_txt::m_set_window(int Width, int Height)
{
	_COORD coord;			// wymiary
	coord.X = Width;		// szerokosc
	coord.Y = Height;		// wysokosc

	_SMALL_RECT Rect;		// prostokat
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;			// dol
	Rect.Right = Width - 1;				// prawo

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // pobranie uchwytu 
	SetConsoleScreenBufferSize(Handle, coord);            // ustawienie rozmiaru bufora
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // ustawienie rozmiaru okna 
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // szerokosc kazdej litery w czcionce
	cfi.dwFontSize.Y = 24;                  // wysokosc
	cfi.FontFamily = FF_DONTCARE;		// czcionka
	cfi.FontWeight = FW_BOLD;			//FW_NORMAL
	std::wcscpy(cfi.FaceName, L"Consolas"); // czcionka
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}



void C_aplication_txt::m_create_logo()       // metoda tworzy logo (atrape "drzewka")
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);   // metoda ustawia kolory = 15 to bialy
	cout << "\n\n\t\t\t | \n \t\t\t | \n \t\t     ========= \n  \t\t    |         | \n \t\t    | \t      |";
	cout << "\n \t   =============      ====\n";
	cout << "\t  |      |      |\t  |\n";
	cout << "\t  |      |      |\t  |\n";
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "\n\n" << "\t\t\t" << "DRZEWO GENEALOGICZNE - FAMILY TREE\n\n";
}

int C_aplication_txt::m_main_menu() // menu glowne aplikacji
{
	N_striing Menu[3] = { "1. New Tree", "2. Load Tree", "3. Exit" };
	N_striing SubMenu[3] = { "[Create New Tree]", "[Import Your Created Trees]", "[Exit From Program]" };
	int ptr = 0, p = 0;

	while (true)		// dopoki nie podejmie jakiejs akcji ciagle true, ekran z menu nie zniknie
	{
		Lista.m_close();
		Lista = m_add_to_operation(true, Lista);
		cls(); //system("cls");
		m_create_logo(); // tworzy atrape drzewka
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 3; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				std::cout << "\t\t\t\t" << "--> " << Menu[i] << "  " << SubMenu[i] << std::endl;
			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				std::cout << "\t\t\t\t" << Menu[i] << std::endl;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << "ENTER.";
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 3)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
					case 0:
					{
						Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
										//				m_sub_1();
						return M_new_tree;
					}// break;
					case 1:
					{
						Sleep(1500);
						//m_sub_menu_2();
						return M_lista + 1;
					}
					case 2:
					{
						Sleep(1500);
						return M_exit; //dziala!!
					}
				}
				break;
			}
		}

		Sleep(130);     // szybkosc poruszania sie po menu
	}
}

int C_aplication_txt::m_sub_1()
{
	N_striing MenuSub1[3] = { "1. Create New Tree", "2. Import Tree" ,"3. Exit" };
	N_striing SubSub1[3] = { "[Create Your New Tree]", "[Import Your Created Trees]", "[Exit From Program]" };
	int ptr = 0, p = 0;
	char c;
	N_striing data;
	while (true)			// dopoki nie podejmie jakiejs akcji ciagle true, ekran z menu nie zniknie
	{
		cls();
		m_create_logo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 3; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				std::cout << "\t\t\t\t" << "--> " << MenuSub1[i] << "  " << SubSub1[i] << std::endl;
			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				std::cout << "\t\t\t\t" << MenuSub1[i] << std::endl;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";
		while (true)			// dopoki nie podejmie jakiejs akcji ciagle true, ekran z menu nie zniknie
		{
			if (GetAsyncKeyState(VK_SPACE) != 0) return M_menu_glowne; // gdy SPACJA wroci do main_menu
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr <= -1)      // gdy wykracza wraca na koniec
				{
					ptr = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr >= 3)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
				case 0:
				{
					Sleep(1500);
					//						m_menu_name_tree();
					return M_creating_new_tree;
				}
				case 1:
				{
					Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
					//Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
					//m_sub_menu_2();		// opcje poprawnie wczytanego drzewa
					return M_import_tree;
				}
				case 2:
				{
					//	std::cout << '\n';
					//	exit(0);
					//	break;
					Sleep(1500);
					return M_exit; //Jak chcesz Mateusz moze byc (powrot) czyli "M_menu_glowne;"
				}
				}
			}

			Sleep(150);
		}

		Sleep(150);
	}

	//Sleep(150);     // szybkosc poruszania sie po menu
}


int C_aplication_txt::m_edit_tree()
{
	char C;
	C_human human, HHuman; //id dodaje sie dopiero w silniku
	N_striing data;
	N_striing MenuSub1[5] = { "1. Add a person", "2. Edit a person", "3. Add a relation", "4. Edit a relation", "5. Exit" }; //do rozbudowy
	N_striing SubSub1[5] = { "[You can add a person to your tree]", "[You can edit a person]", "[You can add a relation to a person]",
		"[You can edit a relation to a person]", "[Exit From Program]" };
	int ptr = 0, p = 0;
	int i;
	while (true)
	{
		Sleep(150);
		cls();
		m_create_logo();		// atrapa drzewka
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (i = 0; i < 5; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				std::cout << "\t\t\t\t" << "--> " << MenuSub1[i] << " \n\t\t " << SubSub1[i] << std::endl;
			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				std::cout << "\t\t\t\t" << MenuSub1[i] << std::endl;
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";

		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE)) return M_menu_glowne;	// SPACJA to powrot do main_menu
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 4;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 5)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				Sleep(1500);
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
				case 0: {
					Sleep(150);
					return M_add_human + 1; // menu dodawania nowej osoby
				}
				case 1: {
					Sleep(150);
					return M_lista + 2; //skok103
										// edycja osoby (jesli jakas jest)
										//tu trzeba zrobic 
										//retu
				}
				case 2: {
					Sleep(150);
					return M_menu_relation; // menu relacji
				}
				case 3: {
					Sleep(150);
					return M_edit_relation; 	// edycja relacji
				}
				case 4: {
					Sleep(150);
					return M_menu_glowne; //exit <-tu sie ruzni kod Lukasza od Kodu Mateusza Mateusz wstawil tu Exit
				}
				}
				Sleep(150);	// szybkosc poruszania sie po menu
			}
			Sleep(150);     // szybkosc poruszania sie po menu
		}
	}
}
int C_aplication_txt::m_search_tree()
{
	N_striing MenuSub1[3] = { "1. Search by personal data", "2. Search by date" , "3. Exit" };
	N_striing SubSub1[3] = { "[You can search person by personal data]", "[You can search person by dates]", "[Back To Menu]" };
	int ptr = 0, p = 0;

	while (true)
	{
		cls();
		m_create_logo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (int i = 0; i < 3; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				std::cout << "\t\t\t\t" << "--> " << MenuSub1[i] << " \n\t\t " << SubSub1[i] << std::endl;
			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				std::cout << "\t\t\t\t" << MenuSub1[i] << std::endl;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << "ENTER.";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << " if you want back to main menu.";
		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE)) return M_menu_glowne;
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 3)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
				case 0:
				{
					Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
									//wyszukiwanie ludzi po danych personalnych

				}
				case 1:
				{
					//wyszukiwanie ludzi po datach
				}
				case 2:
				{
					return M_menu_glowne;
				}

				}
			}
		}

		Sleep(150);     // szybkosc poruszania sie po menu
	}
}
int C_aplication_txt::m_display_tree()
{
	N_striing MenuSub1[3] = { "1. Display from the oldest", "2. Search" , "3. Exit" };
	N_striing SubSub1[3] = { "[You can display trees from the oldest]", "[Search your created trees]", "[Back To Menu]" };
	int ptr = 0, p = 0;
	while (true)
	{
		cls();
		m_create_logo(); //<- roznica w kodach!! tu bylo zakomentowane logo!! 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (int i = 0; i < 3; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub1[i] << " \n\t\t " << SubSub1[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub1[i] << endl;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";
		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE)) return M_menu_glowne;
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 3)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
					case 0:
					{
						Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
										//SubMenu3();
					} break;
					case 1:
					{
						Sleep(1500);
						//m_search_tree();
						return M_szukanie;
					}
					case 2:
					{
						Sleep(1500);
						return M_exit;
					}
				}
				break;
			}
		}
		Sleep(150);     // szybkosc poruszania sie po menu
	}
}
int C_aplication_txt::m_sub_menu_2()
{
	//moim zadniem lista z wczytanymi drzewami do wyboru:P
	//m_lista(false); //lista drzew
	//				//std::cout << "Click SpaceBar to return";
	//				//if (GetAsyncKeyState(VK_SPACE) != 0) m_main_menu();
	//return;
	//	m_lista(true);
	N_striing Menu2[4] = { "1. Display Tree", "2. Edit Tree", "3. Export Tree", "4. Exit" };
	N_striing SubMenu2[4] = { "[Display Your Created Trees]", "[Edit Your Created Trees]", "[Export Your Created Trees]", "[Exit From Program]" };
	int pt = 0;
	while (true)
	{
		//system("cls");
		cls();
		//m_create_logo();
		//std::cout << "\t\t\tClick Spacebar to return the menu\n\n";
		//std::cout << "\t\t\tTree successfully loaded\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		for (int i = 0; i < 4; ++i)
		{
			if (i == pt)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << Menu2[i] << " \n\t\t\t " << SubMenu2[i] << endl;
			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << Menu2[i] << endl;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";
		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE)) return M_menu_glowne;
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				pt -= 1;
				if (pt == -1)      // gdy wykracza wraca na koniec
				{
					pt = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				pt += 1;
				if (pt == 4)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					pt = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pt)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
					case 0:
					{
						Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
										// <- nie wiem czy nie powinno byc tu Sleep(150);
										//				m_display_tree();
										//ImportTree();
										//system("dir /s H:\TREE_INOP");
										//system("tree /f H:\TREE_INOP\\Drzewo_genealogiczne\\Drzewo_genealogiczne\\Data");	//w CodeBlocks dziala, tu nie...
										//system("PAUSE");
						return M_lista + 3; //skok101
					}// break;
					case 1:
					{
						Sleep(1500);
						return M_edit_tree; // menu edycji drzewa (dodanie nowej osoby, jej edycja itp)
					}
					case 2:
					{
						return M_export_tree; // export do pliku txt ???? bedzie cos takiego ???
					}
					case 3:
					{
						return M_exit;
					}
				}
				break;
			}
		}
		Sleep(150);     // szybkosc poruszania sie po menu
	}
}
void C_aplication_txt::m_import_tree() // nieuzywane???
{
	N_striing MenuSub1[2] = { "1. Give your tree name", "2. Exit" };
	N_striing SubSub1[2] = { "[You can give your created tree name]", "[Exit From Program]" };
	int ptr = 0, p = 0;
	while (true)
	{
		cls();
		m_create_logo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (int i = 0; i < 2; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub1[i] << "  " << SubSub1[i] << endl;
			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub1[i] << endl;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";

		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE)) m_main_menu();
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 2)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
				case 0:
				{
					Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
									//SubMenu3();
				} break;

				case 1:
				{
					return;
				}
				}
				break;
			}
		}

		Sleep(150);     // szybkosc poruszania sie po menu
	}
}
char C_aplication_txt::m_get_key() {		// metoda pobiera znaki z klawiatury, polskie znaki i Backspace
	char C;
	int Tab_key[26] = { 0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
		0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A };		// kody poszczegolnych 26 znakow
	int Tab_key_number[2][10];		// tablica na cyfry
	char Tab_letter[2][26];			// tablica dwuwymiarowa na 26 malych i duzych
	char Tab_number[10] = { '0','1','2','3','4','5','6','7','8','9' };		// cyfry
	char Tab_polish[9] = { (char)185,(char)230,(char)234,(char)179,(char)241,(char)243,(char)156,(char)159,(char)191 }; //Polskie litery male
	char Tab_Polish[9] = { (char)165,(char)198,(char)202,(char)163,(char)209,(char)211,(char)140,(char)143,(char)175 }; //Polskie litery duze
	int Tab_npolish[9] = { 0x41,0x43,0x45,0x4C,0x4E,0x4F,0x53,0x58,0x5A };
	int i;
	for (i = 0; i < 26; i++)
	{
		Tab_letter[0][i] = 'a' + i;		// wypelnienie tablic tymi znakami , male
		Tab_letter[1][i] = 'A' + i;		// tu tez , duze
	}
	for (i = 0; i < 10; i++)
	{
		Tab_key_number[0][i] = 0x30 + i;		// wypelnienie cyframi
		Tab_key_number[1][i] = 0x60 + i;		// tu tez
	}
	while (true) {
		for (i = 0; i < 10; i++)
		{
			if (GetAsyncKeyState(Tab_key_number[0][i]) != 0 || GetAsyncKeyState(Tab_key_number[1][i]) != 0)
			{
				Sleep(100);
				C = Tab_number[i];
				return C;
			}
		}
		for (i = 0; i < 9; i++)
		{
			if ((GetAsyncKeyState(Tab_npolish[i]) != 0) && (GetAsyncKeyState(VK_SHIFT) == 0) &&
				(GetAsyncKeyState(VK_CAPITAL) == 0) && (GetAsyncKeyState(VK_MENU) != 0)) {
				C = Tab_polish[i];
				Sleep(100);
				return C;
			}
			if ((GetAsyncKeyState(Tab_npolish[i]) != 0) && (GetAsyncKeyState(VK_SHIFT) != 0) && (GetAsyncKeyState(VK_MENU) != 0) ||
				(GetAsyncKeyState(VK_CAPITAL) != 0) && (GetAsyncKeyState(Tab_npolish[i]) != 0) && (GetAsyncKeyState(VK_MENU) != 0)) {
				C = Tab_Polish[i];
				Sleep(100);
				return C;
			}
		}
		for (i = 0; i < 26; i++)
		{
			if ((GetAsyncKeyState(Tab_key[i]) != 0) && (GetAsyncKeyState(VK_SHIFT) == 0) && (GetAsyncKeyState(VK_CAPITAL) == 0) && (GetAsyncKeyState(VK_MENU) == 0))   // strzalka do gory przesuwa wyzej po menu
			{
				C = (Tab_letter[0][i]);
				Sleep(100);
				return C;
			}
			else if (((GetAsyncKeyState(VK_SHIFT) != 0) && (GetAsyncKeyState(Tab_key[i]) != 0)) && (GetAsyncKeyState(VK_MENU) == 0) || ((GetAsyncKeyState(VK_CAPITAL) != 0) && (GetAsyncKeyState(VK_CAPITAL) != 0) && (GetAsyncKeyState(VK_MENU) == 0)))
			{
				C = (Tab_letter[1][i]);
				Sleep(100);
				return C;
			}
			else if ((GetAsyncKeyState(VK_SPACE) != 0))
			{
				Sleep(100);
				return ' ';
			}
			else if ((GetAsyncKeyState(VK_RETURN) != 0) || (GetAsyncKeyState(VK_BACK) != 0) || (GetAsyncKeyState(VK_DOWN) != 0) || (GetAsyncKeyState(VK_UP) != 0) || (GetAsyncKeyState(VK_ESCAPE) != 0)) {
				return '\0';
			}
		}
	}
}
bool C_aplication_txt::m_what_return() {		// metoda ktora pyta co zrobic, wyjsc do menu, pozostac i nic nie zmieniac itp
	N_striing MenuSub1[4] = { "Do you want back to the menu?","1. Yes","2. No", "3. Cancel" };
	N_striing SubSub1[4] = { "","[All data will be deleted]","[Continue]" ,"[Cancel and return to adding data]" };
	int ptr = 1, p = 0;
	while (true)
	{
		cls();
		m_create_logo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (int i = 0; i < 4; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub1[i] << "  " << SubSub1[i] << endl;
			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub1[i] << endl;
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == 0)      // gdy wykracza wraca na koniec
				{
					ptr = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 4)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 1;
				}
				break;
			}
			//else if (ptr ==  && GetAsyncKeyState(VK_RETURN) != 0)
			else if (GetAsyncKeyState(VK_RETURN) != 0) //<- optymalizacja
			{
				switch (ptr)
				{
				case 1:
					return true;
				case 2:
					return false;
				case 3:
					return false;
				}
				return true;
			}
		/*	else if (ptr == 2 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				return false;
			}
			else if (ptr == 3 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				return false;
			}*/
		}

		Sleep(150);     // szybkosc poruszania sie po menu
	}
	//	return false;
}
bool C_aplication_txt::m_what_menu() {
	return true; //do dokonczenia
}
int C_aplication_txt::m_menu_add_human(int where) { // dodawanie nowej osoby
	//	m_load_files(true);
	C_human human;
	int ptr = 0, i;
	bool b_what = false, b_whats = false;
	while (true) {
		if (human.m_set_Vdate().m_size()>0)
		{
			//ptr = 0;
			N_striing MenuSub_add_person[6] = { "1. Add a first name", "2. Add a surname", "3. Add a gender", "4. Add a date","5. Save Person" ,"6. Return" };
			N_striing SubSub_add_person[6] = { "[You can add a first name to your person]", "[You can add a surname to your person]","[You can choose your gender]", "[You can add a date of birth]",
				"[Save your person]", "[Return From Add Person]" };
			Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
							// tutaj powinna byc metoda dolaczenia nowej osoby
			while (true)
			{
				cls();
				m_create_logo();	// atrapa drzewka
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				for (i = 0; i < 6; ++i)
				{
					if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\t\t\t\t" << "--> " << MenuSub_add_person[i] << " \n\t\t " << SubSub_add_person[i] << endl;
					}
					else                // niewybrane opcje sa biale
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << "\t\t\t\t" << MenuSub_add_person[i] << endl;
					}
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\n\n\n\n Use the arrows to navigate the menu ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << char(24) << " " << char(25);        // kody ASCII strzalek
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << ". Confirm your choice with ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "ENTER.";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\n Click ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "SPACEBAR";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << " if you want back to main menu.";
				cout << " \n\n";
				cout << human;
				while (true)
				{
					if (GetAsyncKeyState(VK_SPACE)) {
						//	Sleep(150);
						if (m_what_menu())
							return M_menu_glowne;
						break;
					}
					if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
					{
						//	Sleep(150);
						ptr -= 1;
						if (ptr == -1)      // gdy wykracza wraca na koniec
						{
							ptr = 5;
						}
						break;
					}
					else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
					{
						//	Sleep(150);
						ptr += 1;
						if (ptr == 5)       // gdy wykracza poza menu, znow wraca na poczatek
						{
							ptr = 0;
						}
						break;
					}
					//else if (ptr == 4 && GetAsyncKeyState(VK_RETURN) != 0)
					//{
					//	Sleep(150);
					//	m_new_human(human);
					//	m_save_files(true);
					//
					//	break;
					//	//if
					//}
					else if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						//Sleep(1500);
						switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
						{
							case 0: {
								Sleep(150);
								b_whats = true;
								human.m_get_first_name(m_menu_add_first_name().m_set_first_name()); 	// doda imie
								break;
							}
							case 1: {
								Sleep(150);
								b_whats = true;
								human.m_get_last_name(m_menu_add_last_name().m_set_last_name());		//dodaj nazwisko
								break;
							}
							case 2: {
								Sleep(150);
								b_whats = true;
								human.m_get_gender(m_menu_add_gender().m_set_gender());				//dodaj plec
								break;
							}
							case 3: {
								Sleep(150);
								b_what = true;
								N_vektor<C_date> V_date = m_menu_add_date().m_set_Vdate();
								int iteral;
								for (iteral = 0; iteral < V_date.m_size(); iteral++)
								{
									human.m_get_date(V_date[iteral]);				//dodaj daty
								}
								break;
							}
							case 4: {
								Sleep(150);
								if (!b_what)
								{
									C_date date;
									human.m_get_date(date);
								}
								if (!b_whats)
								{
									C_first_name first;
									C_last_name last;
									C_gender gender;
									human.m_get_first_name(first);		// pobiera imie
									human.m_get_last_name(last);		// pobiera nazwisko
									human.m_get_gender(gender);			// pobiera plec
								}
								m_new_human(human);
								Sleep(150);
								m_save_files(true);				// zapis humana
								//Sleep(150000);
								//		int x;
								//		std::cin >> x;
								//m_what_menu();
								return where;
								//czy chcesz kontynulowac??
								//break;
							}
							case 5: {
								Sleep(150);
								return M_menu_glowne;  //wraca do menu
							}
									//	break;
						}
						break;
					}
					//	Sleep(150);
				}
				break;
				//Sleep(150);
			}
		}
		else {
			N_striing MenuSub_add_person[5] = { "1. Add a first name", "2. Add a surname", "3. Add a gender", "4. Add a date", "5. Return" };
			N_striing SubSub_add_person[5] = { "[You can add a first name to your person]", "[You can add a surname to your person]", "[You can add a gender to your person]",
				"[You can add a date to your person]","[Return From Add Person]" };
			Sleep(120);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
						   // tutaj powinna byc metoda dolaczenia nowej osoby
			while (true)
			{
				cls();
				m_create_logo();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				for (i = 0; i < 5; ++i)
				{
					if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\t\t\t\t" << "--> " << MenuSub_add_person[i] << " \n\t\t " << SubSub_add_person[i] << endl;
					}
					else                // niewybrane opcje sa biale
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << "\t\t\t\t" << MenuSub_add_person[i] << endl;
					}
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\n\n\n\n Use the arrows to navigate the menu ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << char(24) << " " << char(25);        // kody ASCII strzalek
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << ". Confirm your choice with ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "ENTER.";

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\n Click ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "SPACEBAR";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << " if you want back to main menu.";
				while (true)
				{
					if (GetAsyncKeyState(VK_SPACE)) {
						//Sleep(150);
						if (m_what_menu())
							return M_menu_glowne;
						break;
					}
					if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
					{
						//Sleep(150);
						ptr -= 1;
						if (ptr == -1)      // gdy wykracza wraca na koniec
						{
							ptr = 4;
						}
						break;
					}
					else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
					{
						//Sleep(150);
						ptr += 1;
						if (ptr == 5)       // gdy wykracza poza menu, znow wraca na poczatek
						{
							ptr = 0;
						}
						break;
					}
					else if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						//Sleep(1500);
						switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
						{
							case 0: {
								Sleep(150);
								b_whats = true;
								human.m_get_first_name(m_menu_add_first_name().m_set_first_name());  //dodanie imienia
								break;
							}
							case 1: {
								Sleep(150);
								b_whats = true;
								human.m_get_last_name(m_menu_add_last_name().m_set_last_name());	//dadanie nazwiska
								break;
							}
							case 2: {
								Sleep(150);
								b_whats = true;
								human.m_get_gender(m_menu_add_gender().m_set_gender());			//dodaj plec
								break;
							}
							case 3: {
								Sleep(150);
								b_what = true;
								N_vektor<C_date> V_date = m_menu_add_date().m_set_Vdate();
								int iteral;
								for (iteral = 0; iteral < V_date.m_size(); iteral++)
								{
									human.m_get_date(V_date[iteral]);  //dodaj date
								}
								break;
							}
							case 4: {
								Sleep(150);
								return M_menu_glowne;
							}
						}
						break;
					}
				}
				break;
			}
		}
	}
}
C_human C_aplication_txt::m_menu_add_first_name() {
	int ptr = 0;
	int i;
	C_human human;
	N_striing data;
	char C;
	//WH_KEYBOARD_LL;//hak do klawiatury
	//bool b_what;
	Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
					// tutaj powinna byc metoda dolaczenia nowej osoby
	while (true)
	{
		//	b_what = false;
		N_striing MenuSub_add_first_name[2] = { "First name:", "Return" };
		N_striing SubSub_add_first_name[2] = { data ,"[Return From Add Person]" };
		cls();
		m_create_logo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (i = 0; i < 2; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub_add_first_name[i] << " \n\t\t " << SubSub_add_first_name[i] << endl;
			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub_add_first_name[i] << endl;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ESCAPE";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";
		while (true)
		{
			if (GetAsyncKeyState(VK_ESCAPE)) //return M_menu_glowne;
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu					//naprawione:)
			{
				Sleep(150);
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				Sleep(150);
				ptr += 1;
				if (ptr == 2)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (ptr == 0 && GetAsyncKeyState(VK_BACK) != 0)
			{
				Sleep(150);
				data.m_pop_back();
				Sleep(150);
				break;
			}
			else if (ptr == 0 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				Sleep(150);
				if (data.m_size() > 0)  // musi byc cos wpisane
				{
					C_first_name First(data);
					human.m_get_first_name(First);		// zapisuje to
					data.m_clear();
					return human;
				}
			}
			else if (ptr == 0)
			{
				C = m_get_key();
				if (C != '\0') {
					data.m_push_back(C);
				}
				break;
			}
			else if (ptr == 1 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				Sleep(150);
				if (m_what_return()) {
					data.m_clear();
					return human;
				}
				break;
			}

		}
	}
}
C_human C_aplication_txt::m_menu_add_last_name() {
	int ptr = 0, i;
	C_human human;
	N_striing data;
	char C;
	//WH_KEYBOARD_LL;//hak do klawiatury
	bool b_what;

	Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
					//	tutaj powinna byc metoda dolaczenia nowej osoby
	while (true)
	{
		b_what = false;
		N_striing MenuSub_add_last_name[2] = { "Last name:", "Return" };
		N_striing SubSub_add_last_name[2] = { data ,"[Return From Add Person]" };
		cls();
		m_create_logo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


		for (i = 0; i < 2; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub_add_last_name[i] << " \n\t\t " << SubSub_add_last_name[i] << endl;
			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub_add_last_name[i] << endl;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ESCAPE";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";
		while (true)
		{
			if (GetAsyncKeyState(VK_ESCAPE)) {
				Sleep(150);
				if (m_what_menu())
					m_main_menu();//return M_menu_glowne
				break;
			}
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				Sleep(150);
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				Sleep(150);
				ptr += 1;
				if (ptr == 2)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (ptr == 0 && GetAsyncKeyState(VK_BACK) != 0)
			{
				Sleep(150);
				data.m_pop_back();
				break;
			}
			else if (ptr == 0 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				if (data.m_size() > 0) {
					C_last_name Last(data);
					human.m_get_last_name(Last);
					data.m_clear();
					return human;
				}
			}
			else if (ptr == 0)
			{
				C = m_get_key();
				if (C != '\0') {
					data.m_push_back(C);
				}
				break;
			}
			else if (ptr == 1 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				//Sleep(150);
				if (m_what_return()) {
					data.m_clear();
					return human;
				}
			}
		}
		//	Sleep(150);
	}

	//Sleep(150);
}
C_human C_aplication_txt::m_menu_add_gender() {
	int ptr = 1, i;
	char C;
	N_striing data;
	C_human human;
	Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
					// tutaj powinna byc metoda dolaczenia nowej osoby
	while (true)
	{
		//	b_what = false;
		N_striing MenuSub_add_last_name[4] = { "Gender:","- Man","- Woman", "Return" };
		N_striing SubSub_add_last_name[4] = { "","","" ,"[Return From Add Person]" };
		cls();
		m_create_logo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


		for (i = 0; i < 4; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub_add_last_name[i] << "   " << SubSub_add_last_name[i] << endl;
			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub_add_last_name[i] << endl;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ESCAPE";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";
		while (true)
		{
			if (GetAsyncKeyState(VK_ESCAPE)) {
				Sleep(150);
				if (m_what_menu())
					m_main_menu();
				break;
			}
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po me					//naprawione:)
			{
				Sleep(150);
				ptr -= 1;
				if (ptr == 0)      // gdy wykracza wraca na koniec
				{
					ptr = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				Sleep(150);
				ptr += 1;
				if (ptr == 4)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 1;
				}
				break;
			}
			else if (ptr == 1 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				//	Sleep(150);
				human.m_get_gender(true);
				Sleep(150);
				return human;
			}
			else if (ptr == 2 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				//Sleep(150);
				human.m_get_gender(false);
				Sleep(150);
				return human;
			}
			else if (ptr == 3 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				Sleep(150);
				if (m_what_return()) {
					return human;
				}
				break;
			}
			//	Sleep(150);
		}
		//Sleep(150);
	}
}
C_human C_aplication_txt::m_menu_add_date() {
	int ptr = 1, i;
	char C;
	N_striing data;
	C_human human;
	N_striing dd, mm, yy, save, typ;
	bool b_what = false;
	Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
					// tutaj powinna byc metoda dolaczenia nowej osoby
	while (true)
	{
		//	b_what = false;
		data = dd;
		data += '-';
		data += mm;
		data += '-';
		data += yy;
		if (!b_what)
		{
			typ = "Date of birth: ";
			N_striing MenuSub_add_last_name[3] = { typ,"Date:", "Return" };
			N_striing SubSub_add_last_name[3] = { "",data ,"[Return From Add Person]" };
			cls();
			m_create_logo();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


			for (i = 0; i < 3; ++i)
			{
				if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\t\t\t\t" << "--> " << MenuSub_add_last_name[i] << " \n\t\t " << SubSub_add_last_name[i] << endl;
				}
				else                // niewybrane opcje sa biale
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "\t\t\t\t" << MenuSub_add_last_name[i] << endl;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			cout << "\n\n\n\n Use the arrows to navigate the menu ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << char(24) << " " << char(25);        // kody ASCII strzalek
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << ". Confirm your choice with ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "ENTER.";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "\n Click ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "ESCAPE";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << " if you want back to main menu.";
			while (true)
			{
				if (GetAsyncKeyState(VK_ESCAPE)) {
					if (m_what_menu())
						m_main_menu();
					break;
				}
				if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
													//naprawione:)
				{
					ptr -= 1;
					if (ptr <= 0)      // gdy wykracza wraca na koniec
					{
						ptr = 2;
					}
					Sleep(150);
					break;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
				{
					ptr += 1;
					if (ptr >= 3)       // gdy wykracza poza menu, znow wraca na poczatek
					{
						ptr = 1;
					}
					Sleep(150);
					break;
				}
				else if (ptr == 1 && GetAsyncKeyState(VK_BACK) != 0)
				{
					if (yy.m_size() > 0)
					{
						yy.m_pop_back();
						Sleep(150);
						break;
					}
					else
					{
						if (mm.m_size() > 0)
						{
							mm.m_pop_back();
							Sleep(150);
							break;
						}
						else
						{
							if (dd.m_size() > 0)
							{
								dd.m_pop_back();
								Sleep(150);
								break;
							}
							Sleep(150);
							break;
						}
					}
					Sleep(150);
					break;
				}
				else if (ptr == 1)
				{
					if (dd.m_size() < 2) {
						C = m_get_key();
						if (C != '\0') {
							dd.m_push_back(C);
							break;
						}
					}
					else
					{
						if (mm.m_size() < 2) {
							C = m_get_key();
							if (C != '\0') {
								mm.m_push_back(C);
								break;
							}
						}
						else
						{
							if (yy.m_size() < 4) {
								C = m_get_key();
								if (C != '\0') {
									yy.m_push_back(C);
									break;
								}
							}
							C_date date;
							//	human.m_get_date(date);
							date.m_get_day(dd);
							date.m_get_month(mm);
							date.m_get_year(yy);
							human.m_get_date(date);
							b_what = true;
							data.m_clear();
							dd.m_clear();
							mm.m_clear();
							yy.m_clear();
							break;
						}
					}
					break;
				}

				else if (ptr == 2 && GetAsyncKeyState(VK_RETURN) != 0)
				{
					if (m_what_return())
					{
						data.m_clear();
						return human;
					}
					break;
				}
				//	Sleep(150);
			}
			//Sleep(150);
		}
		else
		{
			typ = "Date of death: ";
			N_striing MenuSub_add_last_name[4] = { typ,"Date:","Save", "Return" };
			N_striing SubSub_add_last_name[4] = { "",data ,"","[Return From Add Person]" };
			cls();
			m_create_logo();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


			for (i = 0; i < 4; ++i)
			{
				if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\t\t\t\t" << "--> " << MenuSub_add_last_name[i] << " \n\t\t " << SubSub_add_last_name[i] << endl;
				}
				else                // niewybrane opcje sa biale
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "\t\t\t\t" << MenuSub_add_last_name[i] << endl;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			cout << "\n\n\n\n Use the arrows to navigate the menu ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << char(24) << " " << char(25);        // kody ASCII strzalek
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << ". Confirm your choice with ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "ENTER.";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "\n Click ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "ESCAPE";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << " if you want back to main menu.";
			while (true)
			{
				if (GetAsyncKeyState(VK_ESCAPE)) {
					if (m_what_menu())
						m_main_menu();
					break;
				}
				if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
													//naprawione:)
				{
					ptr -= 1;
					if (ptr <= 0)      // gdy wykracza wraca na koniec
					{
						ptr = 3;
					}
					Sleep(150);
					break;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
				{
					ptr += 1;
					if (ptr >= 4)       // gdy wykracza poza menu, znow wraca na poczatek
					{
						ptr = 1;
					}
					Sleep(150);
					break;
				}
				else if (ptr == 1 && GetAsyncKeyState(VK_BACK) != 0)
				{
					if (yy.m_size() > 0)
					{
						yy.m_pop_back();
						Sleep(150);
						break;
					}
					else
					{
						if (mm.m_size() > 0)
						{
							mm.m_pop_back();
							Sleep(150);
							break;
						}
						else
						{
							if (dd.m_size() > 0)
							{
								dd.m_pop_back();
								Sleep(150);
								break;
							}
							Sleep(150);
							break;
						}
					}
					Sleep(150);
					break;
				}
				else if (ptr == 1)
				{
					if (dd.m_size() < 2) {
						C = m_get_key();
						if (C != '\0') {
							dd.m_push_back(C);
							break;
						}
					}
					else
					{
						if (mm.m_size() < 2) {
							C = m_get_key();
							if (C != '\0') {
								mm.m_push_back(C);
								break;
							}
						}
						else
						{
							if (yy.m_size() < 4) {
								C = m_get_key();
								if (C != '\0') {
									yy.m_push_back(C);
									break;
								}
							}
							C_date date;
							//	human.m_get_date(date);
							date.m_get_day(dd);
							date.m_get_month(mm);
							date.m_get_year(yy);
							if (human.m_set_Vdate().m_size()<2)
								human.m_get_date(date);

							//b_what = true;
							ptr = 2;
							break;
						}
					}
					break;
				}
				else if (GetAsyncKeyState(VK_RETURN) != 0)
				{
					switch (ptr)
					{
					case 2:
					{
						Sleep(150);
						return human;
					}
					case 3:
					{
						if (m_what_return())
						{
							human.m_clear();
							return human;
						}
						break;
					}
					}
				}
			}
		}
	}
}

void C_aplication_txt::m_load_lista() {
	Lista.m_close();
	m_load_files(true);
	N_striing s_Data;
	int i, end = V_goverment_personaly.m_size(); //mam nadzieje ze sluszna poprawa
	for (i = 1; i <= end; i++)
	{
		s_Data.m_clear();
		C_human human;
		human = m_create_human(i);
		s_Data += human.m_set_first_name().m_set_contens();
		s_Data += '  ';
		s_Data += human.m_set_last_name().m_set_contens();
		s_Data += "\n\t\t\t\t";
		if (human.m_set_date(0).m_day_set() == '0' || human.m_set_date(0).m_month_set() == '0') {
			s_Data += " - - ";
		}
		else
		{
			s_Data += human.m_set_date(0).m_day_set();
			//std::cout << s_Data << "\n";
			s_Data += '-';
			s_Data += human.m_set_date(0).m_month_set();
			//std::cout << s_Data << "\n";
			s_Data += '-';
			s_Data += human.m_set_date(0).m_year_set();
			//std::cout << s_Data << "\n";
			//Sleep(2000);
		}
		Lista.m_push_back(s_Data);
		V_ID.m_push_back(human.m_set_id());
	}
}
int C_aplication_txt::m_lista(int what_this) { //do naprawy bedzie switch!!!
	bool b_where = false;
	int ptr = 0, p = 0, i;
	int cykl = 0, pentla = 0;
	while (true)
	{
		switch (what_this)
		{
		case L_tree:
		{
			Lista.m_close();
			Lista = m_add_to_operation(true, Lista);
			b_where = true; //po co to??
			if (Lista.m_size() == 0)
			{
				cls();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				std::cout << "\t\t\t\t" << "No trees!" << "\n";
				Sleep(1500);
				return M_menu_glowne;
				//return;
			}
			cls();
			if (Lista.m_size() < 5)
			{
				cykl = Lista.m_size(); //- cykl;
			}
			else
			{
				cykl = 5;
			}
			while (true)
			{
				cls();
				m_create_logo();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				std::cout << "\t\t\tClick Spacebar to return the menu\n\n";

				if (ptr > 2) {
					if (cykl + 1 <= Lista.m_size())
						cykl += 1;
					else
					{
						cykl = Lista.m_size(); //- cykl;
					}
				}
				for (i = pentla; i < cykl; ++i)
				{

					if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\t\t\t\t" << i + 1 << "\t" << Lista[i] << endl;
					}
					else                // niewybrane opcje sa biale
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << "\t\t\t\t" << i + 1 << "\t" << Lista[i] << endl;
					}
				}
				while (true)
				{
					Sleep(150);
					if (GetAsyncKeyState(VK_SPACE) != 0) return M_menu_glowne;
					if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
					{
						ptr -= 1;
						//cykl -= 2;
						if (ptr < 0)      // gdy wykracza wraca na koniec
						{
							cykl = Lista.m_size();
							if (Lista.m_size() > 5)
								pentla = Lista.m_size() - 5;
							else
								pentla = 0;
							ptr = Lista.m_size();
							continue;
						}
						if (pentla > 0 && ptr < Lista.m_size() - 3)
						{
							pentla--;
						}
						if (cykl > 5 && ptr < Lista.m_size() - 3)
						{
							if (cykl > 6)
								cykl -= 2;
							else
								cykl -= 1;
						}
						break;
					}
					else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
					{
						ptr += 1;
						if (ptr > 2 && ptr < Lista.m_size() - 2)
							pentla++;
						if (ptr > Lista.m_size() - 1)       // gdy wykracza poza menu, znow wraca na poczatek
						{
							pentla = 0;
							if (Lista.m_size() > 5)
								cykl = 5;
							else
								cykl = Lista.m_size();
							ptr = 0;
						}
						break;
					}
					else if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						//przejscie do edycji danych
						Sleep(150);//prawdziwe dla ladowania listy drzew
						N_striing s_data = name_user_profile;
						s_data += "\\"; s_data += op_name_catalog; s_data += "\\"; //poprawa mam nadzieje ze na lepsze
						s_data += Lista[ptr];
						m_get_index_value_tree(s_data);
						return M_load_tree;
					}
				}
			}
		}
		case L_human:
		{
			int r;
			m_load_lista(); //bagi z nadpisywaniem sie listy - chyba naprawione
			if (Lista.m_size() == 0)
			{
				cls();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				std::cout << "\t\t\t\t" << "No people!" << "\n";
				Sleep(1500);
				return M_edit_tree;
			}
			cls();
			if (Lista.m_size() < 5)
			{
				cykl = Lista.m_size(); //- cykl;
			}
			else
			{
				cykl = 5;
			}
			while (true)
			{
				cls();
				m_create_logo();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				std::cout << "\t\t\tClick Spacebar to return the menu\n\n";
				if (ptr > 2) {
					if (cykl + 1 <= Lista.m_size())
						cykl += 1;
					else
					{
						cykl = Lista.m_size(); //- cykl;
					}
				}
				for (i = pentla; i < cykl; ++i)
				{
					if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\t\t\t\t" << i + 1 << "\t" << Lista[i] << endl;
					}
					else                // niewybrane opcje sa biale
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << "\t\t\t\t" << i + 1 << "\t" << Lista[i] << endl;
					}
				}
				while (true)
				{
					Sleep(150);
					if (GetAsyncKeyState(VK_SPACE) != 0) return M_menu_glowne;
					if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
					{
						ptr -= 1;
						//cykl -= 2;
						if (ptr < 0)      // gdy wykracza wraca na koniec
						{
							cykl = Lista.m_size();
							if (Lista.m_size() > 5)
								pentla = Lista.m_size() - 5;
							else
								pentla = 0;
							ptr = Lista.m_size();
							continue;
						}
						if (pentla > 0 && ptr < Lista.m_size() - 3)
						{
							pentla--;
						}
						if (cykl > 5 && ptr < Lista.m_size() - 3)
						{
							if (cykl > 6)
								cykl -= 2;
							else
								cykl -= 1;
						}
						break;
					}
					else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
					{
						ptr += 1;
						if (ptr > 2 && ptr < Lista.m_size() - 2)
							pentla++;
						if (ptr > Lista.m_size() - 1)       // gdy wykracza poza menu, znow wraca na poczatek
						{
							pentla = 0;
							if (Lista.m_size() > 5)
								cykl = 5;
							else
								cykl = Lista.m_size();
							ptr = 0;
						}
						break;
					}
					else if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						C_human human, Human;
						int result;
						result = m_menu_edit_human(V_goverment_personaly[ptr].m_set_contens(), ptr, human);
						if (result == M_edit_tree)
						{
							m_update_human(human);
							m_save_files(true);
							return M_edit_tree;
						}
						else if (result == M_menu_glowne)
						{
							return M_menu_glowne;
						}
					}

				}
				break;
			}
		}
		case L_dysplay:
		{
			int r;
			m_load_lista(); //bagi z nadpisywaniem sie listy - chyba naprawione
			if (Lista.m_size() == 0)
			{
				cls();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				std::cout << "\t\t\t\t" << "No people!" << "\n";
				Sleep(1500);
				return M_edit_tree;
			}
			cls();
			if (Lista.m_size() < 5)
			{
				cykl = Lista.m_size(); //- cykl;
			}
			else
			{
				cykl = 5;
			}
			while (true)
			{
				cls();
				m_create_logo();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				std::cout << "\t\t\tClick Spacebar to return the menu\n\n";
				if (ptr > 2) {
					if (cykl + 1 <= Lista.m_size())
						cykl += 1;
					else
					{
						cykl = Lista.m_size(); //- cykl;
					}
				}
				for (i = pentla; i < cykl; ++i)
				{
					if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\t\t\t\t" << i + 1 << "\t" << Lista[i] << endl;
					}
					else                // niewybrane opcje sa biale
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << "\t\t\t\t" << i + 1 << "\t" << Lista[i] << endl;
					}
				}
				while (true)
				{
					Sleep(150);
					if (GetAsyncKeyState(VK_SPACE) != 0) return M_menu_glowne;
					if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
					{
						ptr -= 1;
						//cykl -= 2;
						if (ptr < 0)      // gdy wykracza wraca na koniec
						{
							cykl = Lista.m_size();
							if (Lista.m_size() > 5)
								pentla = Lista.m_size() - 5;
							else
								pentla = 0;
							ptr = Lista.m_size();
							continue;
						}
						if (pentla > 0 && ptr < Lista.m_size() - 3)
						{
							pentla--;
						}
						if (cykl > 5 && ptr < Lista.m_size() - 3)
						{
							if (cykl > 6)
								cykl -= 2;
							else
								cykl -= 1;
						}
						break;
					}
					else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
					{
						ptr += 1;
						if (ptr > 2 && ptr < Lista.m_size() - 2)
							pentla++;
						if (ptr > Lista.m_size() - 1)       // gdy wykracza poza menu, znow wraca na poczatek
						{
							pentla = 0;
							if (Lista.m_size() > 5)
								cykl = 5;
							else
								cykl = Lista.m_size();
							ptr = 0;
						}
						break;
					}
					else if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						return M_dysplay_tree;
					}

				}
				break;
			}
		}
		}
		Sleep(150);     // szybkosc poruszania sie po menu
	}
	//	return false;
}
int C_aplication_txt::m_menu_name_tree() {
	//Lista.m_close();
	//Lista = m_add_to_operation(true, Lista);

	int ptr = 0, p = 0;
	char c;
	N_striing data;
	bool b_pointer = true;

	while (true)
	{

		if (b_pointer)
		{
			N_striing MenuSub1[1] = { "Give your tree name:" };
			N_striing SubSub1[1] = { data };
			//N_striing MenuSub1[2] = { "Give your tree name:", "Back: " };
			//N_striing SubSub1[2] = { data, "[Back To Main Menu]" };
			cls();
			m_create_logo();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			std::cout << "\t\t\tClick Spacebar to return the menu\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

			for (int i = 0; i < 1; ++i)
			{
				if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\t\t\t\t" << "--> " << MenuSub1[i] << "  " << SubSub1[i] << endl;
				}
				else                // niewybrane opcje sa biale
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "\t\t\t\t" << MenuSub1[i] << endl;
				}
			}
			while (true) {

				if (GetAsyncKeyState(VK_SPACE) != 0) m_main_menu();

				// sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
				if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
				{
					Sleep(1000);
					ptr -= 1;
					if (ptr == 0)      // gdy wykracza wraca na koniec
					{
						ptr = 1;
					}
					break;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
				{
					Sleep(1000);
					ptr += 1;
					if (ptr == 1)       // gdy wykracza poza menu, znow wraca na poczatek
					{
						ptr = 0;
					}
					break;
				}
				else if (ptr == 0 && GetAsyncKeyState(VK_BACK) != 0)
				{
					Sleep(1000);
					data.m_pop_back();
					break;
				}
				else
				{
					c = m_get_key();
					if (c != '\0') {
						data.m_push_back(c);
						break;
					}
					if (GetAsyncKeyState(VK_RETURN) != 0 && data.m_size() > 0)
					{
						Sleep(1500);
						//stworzyc zabezpieczenie przed ponownym stworzeniem tego samego dystryktu
						N_striing s_data = name_user_profile;
						s_data += "\\";
						s_data += op_name_catalog;
						s_data += "\\";
						m_get_index_value_tree(s_data);
						int value;
						for (value = 0; value < Lista.m_size(); value++)
						{
							if (Lista[value] == data) {
								b_pointer = false;
								break;
							}
						}
						if (b_pointer)
						{
							//Lista = m_add_to_operation(false, Lista);
							Lista.m_push_back(data);
							m_create_new_location(data);
							Lista = m_add_to_operation(false, Lista);
							N_striing s_data = name_user_profile;
							s_data += "\\";
							s_data += op_name_catalog;
							s_data += "\\";
							s_data += data;
							//Lista.m_close();
							m_get_index_value_tree(s_data);
							//m_load_files(true);
							//	m_menu_add_human();
							//	m_menu_tree(); //przeskok do dalszego menu!!
							return M_menu_tree;
						}
						break;
						//przeskok do edycji w wczytanu tej lokalizacji
					}

				}

			}
		}
		else
		{
			N_striing MenuSub1[2] = { "Give your tree name:", "Back: " };
			N_striing SubSub1[2] = { data, "[Click Spacebar To Back The Menu]" };
			cls();
			m_create_logo();
			std::cout << "\t\t\t   This name already exists!\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			for (int i = 0; i < 2; ++i)
			{
				if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\t\t\t\t" << "--> " << MenuSub1[i] << "  " << SubSub1[i] << endl;
				}
				else                // niewybrane opcje sa biale
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "\t\t\t\t" << MenuSub1[i] << endl;
				}
			}
			while (true) {
				// sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
				if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
				{
					Sleep(500);
					ptr -= 1;
					if (ptr < 0)      // gdy wykracza wraca na koniec
					{
						ptr = 1;
					}
					break;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
				{
					Sleep(500);
					ptr += 1;
					if (ptr >= 2)       // gdy wykracza poza menu, znow wraca na poczatek
					{
						ptr = 0;
					}
					break;
				}

				else if (ptr == 0 && GetAsyncKeyState(VK_BACK) != 0)
				{
					Sleep(500);
					data.m_pop_back();
					break;
				}


				else if (ptr == 1 && GetAsyncKeyState(VK_SPACE) != 0)
				{
					return M_menu_glowne;
				}


				else
				{
					c = m_get_key();
					if (c != '\0') {
						data.m_push_back(c);
						break;
					}
					if (GetAsyncKeyState(VK_RETURN) != 0 && data.m_size() > 0)
					{
						Sleep(500);
						//stworzyc zabezpieczenie przed ponownym stworzeniem tego samego dystryktu
						m_get_index_value_tree(name_user_profile + "\\.tree\\" + data);
						int value;
						b_pointer = true;
						for (value = 0; value < Lista.m_size(); value++)
						{
							if (Lista[value] == data) {
								b_pointer = false;
								break;
							}
						}
						if (b_pointer)
						{
							Lista.m_push_back(data);
							Lista = m_add_to_operation(false, Lista);
							m_create_new_location(data);
							//Lista.m_close();
							m_get_index_value_tree(data);
							//	m_load_files(true);
							//	m_menu_add_human(); //przeskok do kolejnego menu!!
							return M_add_human + 2;
						}
						break;
						//przeskok do edycji w wczytanu tej lokalizacji
					}

				}

			}
		}
	}
}
//void C_aplication_txt::m_menu_edit_human() {

//}
int C_aplication_txt::m_menu_tree() {

	N_striing Menu[4] = { "1. Display", "2. Edit Tree","3. Export", "4. Exit" };
	N_striing SubMenu[4] = { "[Display Tree]", "[Edit your tree content]","[Export your tree]", "[Back To Menu]" };
	int ptr = 0, p = 0;

	while (true)
	{
		m_load_files(true);
		cls();
		m_create_logo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 4; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << Menu[i] << "   " << SubMenu[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << Menu[i] << "	 " << endl;
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		cout << "ENTER.";

		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr < 0)      // gdy wykracza wraca na koniec
				{
					ptr = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr >= 4)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
				case 0:
				{
					Sleep(1500);
					return M_lista + 3;
				} break;
				case 1:
				{
					Sleep(1500);
					return M_edit_tree;
				}
				case 2:
				{
					Sleep(1500);
					return M_export_tree;
				}
				case 3:
				{
					Sleep(1500);
					return M_menu_glowne;
				}
				}
				break;
			}
		}
		Sleep(150);     // szybkosc poruszania sie po menu
	}
}
int C_aplication_txt::m_menu_relation(int where)
{
	m_load_lista(); //bagi z nadpisywaniem sie listy
	if (Lista.m_size() < 2)		// gdy nie ma choc 2 osob nie zbuduje relacji
	{
		cls();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << "\t\t\t\t" << "Cannot add relationship!" << "\n";
		Sleep(1500);
		return M_edit_tree;
		//Sleep(2000);
		//return;
	}
	C_element Element(m_menu_wybor_humana_wskaznikowego());
	C_element element;
	if (Element == element)
		return where;
	N_striing MenuSub1[10] = { "Add Relationship - MENU","1. Add Grandparent","2. Add Parent","3. Add Sibling","4. Add Partner",
		"5. Add Children", "6. Add Grandchildren", "7. Save relations","8. Exit" };
	N_striing SubSub1[10] = { "", "[Add grandparent to person]", "[Add parent to person]","[Add sibling to person]","[Add partner to person]","[Add child to person]","[Add grandchild to person]", "[Save your created relations]","[Back To Menu]" };
	int ptr = 1, p;
	char c;
	N_striing data;
	N_vektor<C_element> V_element;
	int t;
	C_id ID;
	bool b_pointer;
	//petla po wszystkich relacjach tworzaca elementy i ladujaca je w wektor elementow
	for (p = 0; p < V_goverment_relation.m_size(); p++)
	{
		V_element.m_push_back(m_create_element(V_goverment_relation[p].m_set_value_id()));
	}
	p = 0;
	//ladowanie elementow
	while (true)
	{
		cls();
		m_create_logo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 9; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub1[i] << "  " << SubSub1[i] << endl;
			}

			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub1[i] << endl;
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";
		//	cout << "\n\n" << Element << "\n";
		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE) != 0) return M_menu_glowne;
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr <= 0)      // gdy wykracza wraca na koniec
				{
					ptr = 8;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr >= 9)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
				case 1: //Add grandparent
				{
					b_pointer = true;
					Element = m_menu_add_relations(t_grandparent, Element);
					ID = Element.m_set_v_grandparents()[Element.m_set_v_grandparents().m_size() - 1].m_set_id();
					for (t = 0; t < V_element.m_size(); t++)
					{
						if (V_element[t].m_set_Human().m_set_id() == ID)
						{
							C_grandchildren grandchildren(ID);
							grandchildren.m_get_id(Element.m_set_Human().m_set_id());
							V_element[t].m_get_grandchildren(grandchildren);
							b_pointer = false;
							break;
						}
					}
					if (b_pointer) {
						C_element Element_sprzezony(ID);
						C_grandchildren grandchildren(ID);
						grandchildren.m_get_id(Element.m_set_Human().m_set_id());
						Element_sprzezony.m_get_grandchildren(grandchildren);
						m_new_element(Element_sprzezony, true);
						V_element.m_push_back(Element_sprzezony);
					}
					break;
				}
				case 2: //add parent
				{
					b_pointer = true;
					Element = m_menu_add_relations(t_parent, Element);
					ID = Element.m_set_v_parent()[Element.m_set_v_parent().m_size() - 1].m_set_id();
					for (t = 0; t < V_element.m_size(); t++)
					{
						if (V_element[t].m_set_Human().m_set_id() == ID)
						{
							C_children children(ID);
							children.m_get_id(Element.m_set_Human().m_set_id());
							V_element[t].m_get_children(children);
							b_pointer = false;
							break;
						}
					}
					if (b_pointer) {
						C_element Element_sprzezony(ID);
						C_children children(ID);
						children.m_get_id(Element.m_set_Human().m_set_id());
						Element_sprzezony.m_get_children(children);
						m_new_element(Element_sprzezony, true);
						V_element.m_push_back(Element_sprzezony);
					}
					//	Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
					break;
				}
				case 3: //add sibling
				{
					b_pointer = true;
					Element = m_menu_add_relations(t_sibling, Element);
					ID = Element.m_set_v_sibling()[Element.m_set_v_sibling().m_size() - 1].m_set_id();
					for (t = 0; t < V_element.m_size(); t++)
					{
						if (V_element[t].m_set_Human().m_set_id() == ID)
						{
							C_sibling sibling(ID);
							sibling.m_get_id(Element.m_set_Human().m_set_id());
							V_element[t].m_get_sibling(sibling);
							b_pointer = false;
							break;
						}
					}
					if (b_pointer) {
						C_element Element_sprzezony(ID);
						C_sibling sibling(ID);
						sibling.m_get_id(Element.m_set_Human().m_set_id());
						Element_sprzezony.m_get_sibling(sibling);
						m_new_element(Element_sprzezony, true);
						V_element.m_push_back(Element_sprzezony);
					}
					//return; ??
					break;
				}
				case 4: // partner
				{
					b_pointer = true;
					Element = m_menu_add_relations(t_partner, Element);
					ID = Element.m_set_v_partner()[Element.m_set_v_partner().m_size() - 1].m_set_id();
					for (t = 0; t < V_element.m_size(); t++)
					{
						if (V_element[t].m_set_Human().m_set_id() == ID)
						{
							C_partner partner(ID);
							partner.m_get_id(Element.m_set_Human().m_set_id());
							V_element[t].m_get_partner(partner);
							b_pointer = false;
							break;
						}
					}
					if (b_pointer) {
						C_element Element_sprzezony(ID);
						C_partner partner(ID);
						partner.m_get_id(Element.m_set_Human().m_set_id());
						Element_sprzezony.m_get_partner(partner);
						m_new_element(Element_sprzezony, true);
						V_element.m_push_back(Element_sprzezony);
					}
					break;
				}
				case 5: //children
				{
					b_pointer = true;
					Element = m_menu_add_relations(t_children, Element);
					ID = Element.m_set_v_children()[Element.m_set_v_children().m_size() - 1].m_set_id();
					for (t = 0; t < V_element.m_size(); t++)
					{
						if (V_element[t].m_set_Human().m_set_id() == ID)
						{
							C_parent parent(ID);
							parent.m_get_id(Element.m_set_Human().m_set_id());
							V_element[t].m_get_parent(parent);
							b_pointer = false;
							break;
						}
					}
					if (b_pointer)
					{
						C_element Element_sprzezony(ID);
						C_parent parent(ID);
						parent.m_get_id(Element.m_set_Human().m_set_id());
						Element_sprzezony.m_get_parent(parent);
						m_new_element(Element_sprzezony, true);
						V_element.m_push_back(Element_sprzezony);
					}
					break;
				}
				case 6: //add grandchildren
				{
					b_pointer = true;
					Element = m_menu_add_relations(t_grandchildren, Element);
					ID = Element.m_set_v_grandchildren()[Element.m_set_v_grandchildren().m_size() - 1].m_set_id();
					for (t = 0; t < V_element.m_size(); t++)
					{
						if (V_element[t].m_set_Human().m_set_id() == ID)
						{
							C_grandparents Grandparent(ID);
							Grandparent.m_get_id(Element.m_set_Human().m_set_id());
							V_element[t].m_get_grandparents(Grandparent);
							b_pointer = false;
							break;
						}
					}
					if (b_pointer)
					{
						C_element Element_sprzezony(ID);
						C_grandparents Grandparent(ID);
						Grandparent.m_get_id(Element.m_set_Human().m_set_id());
						Element_sprzezony.m_get_grandparents(Grandparent);
						m_new_element(Element_sprzezony, true);
						V_element.m_push_back(Element_sprzezony);
					}
					break;
				}
				case 7: //save 
				{
					b_pointer = true;
					Element = m_menu_add_relations(t_order, Element);
					ID = Element.m_set_v_order()[Element.m_set_v_order().m_size() - 1].m_set_id();
					for (t = 0; t < V_element.m_size(); t++)
					{
						if (V_element[t].m_set_Human().m_set_id() == ID)
						{
							C_order order(ID);
							order.m_get_id(Element.m_set_Human().m_set_id());
							V_element[t].m_get_order(order);
							b_pointer = false;
							break;
						}
					}
					if (b_pointer) {
						C_element Element_sprzezony(ID);
						C_order order(ID);
						order.m_get_id(Element.m_set_Human().m_set_id());
						Element_sprzezony.m_get_order(order);
						m_new_element(Element_sprzezony, true);
						V_element.m_push_back(Element_sprzezony);
					}
					return where;
				}
				case 8: //exit
				{
					return M_menu_glowne;
				}
				}
			}

			Sleep(150);
		}

		Sleep(150);
	}

}
C_element C_aplication_txt::m_menu_add_relations(int data, C_element Element) {

	switch (data)
	{
	case t_grandparent:
	{
		C_grandparents Grandparent(Element.m_set_Human().m_set_id());
		Grandparent.m_get_id(m_menu_wybor_humana_wskaznikowego().m_set_Human().m_set_id());
		Element.m_get_grandparents(Grandparent);
		break;
	}
	case t_parent:
	{
		C_parent Parent(Element.m_set_Human().m_set_id());
		Parent.m_get_id(m_menu_wybor_humana_wskaznikowego().m_set_Human().m_set_id());
		Element.m_get_parent(Parent);
		break;
	}
	case t_sibling:
	{
		C_sibling Sibling(Element.m_set_Human().m_set_id());
		Sibling.m_get_id(m_menu_wybor_humana_wskaznikowego().m_set_Human().m_set_id());
		Element.m_get_sibling(Sibling);
		break;
	}
	case t_partner:
	{
		C_partner Partner(Element.m_set_Human().m_set_id());
		Partner.m_get_id(m_menu_wybor_humana_wskaznikowego().m_set_Human().m_set_id());
		Element.m_get_partner(Partner);
		break;
	}
	case t_children:
	{
		C_children Children(Element.m_set_Human().m_set_id());
		Children.m_get_id(m_menu_wybor_humana_wskaznikowego().m_set_Human().m_set_id());
		Element.m_get_children(Children);
		break;
	}
	case t_grandchildren:
	{
		C_grandchildren Grandchildren(Element.m_set_Human().m_set_id());
		Grandchildren.m_get_id(m_menu_wybor_humana_wskaznikowego().m_set_Human().m_set_id());
		Element.m_get_grandchildren(Grandchildren);
		break;
	}
	case t_order:
	{
		C_order Order(Element.m_set_Human().m_set_id());
		Order.m_get_id(m_menu_wybor_humana_wskaznikowego().m_set_Human().m_set_id());
		Element.m_get_order(Order);
		break;
	}
	}
	return Element;
}
C_element C_aplication_txt::m_menu_wybor_humana_wskaznikowego() { //do doglebnego zprecyzowania
																  //bool b_where = false;
	if (Lista.m_size() < 1)
	{
		cls();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << "\t\t\t\t" << "No people to create relations!" << "\n";
		Sleep(1500);
		C_element element;
		return element;
	}
	int i, j, w, q;
	N_striing goverment_data;
#pragma region Analiza sprzezenia zwrotnego
	for (j = 0; j < V_ID.m_size(); j++) {
		for (i = 0; i < V_goverment_relation.m_size(); i++) {
			goverment_data.m_clear();
			for (q = 3; q < V_goverment_relation[i].m_set_contens().m_size(); q++)
			{
				if (V_goverment_relation[i].m_set_contens()[q] == 'r')
					break;
				goverment_data += V_goverment_relation[i].m_set_contens()[q];
			}
			if (V_ID[j].m_set_contens() == goverment_data)
			{
				N_striing value, data = V_goverment_relation[i].m_set_contens();
				for (q = 0; q < data.m_size(); q++)
				{
					if (data[q] == 'r')
					{
						q += 2;
						value.m_clear();
						while (data[q] != 'r')
						{
							if (q < data.m_size()) {
								value += data[q];
								q++;
							}
							else
								break;
						}

						for (w = 0; w < V_ID.m_size(); w++)
						{
							if (V_ID[w].m_set_contens() == value)
							{
								Lista.m_erase(w);
								V_ID.m_erase(w);
								break;
							}
						}
					}
				}
				//Lista.m_erase(j);
				//V_ID.m_erase(j);
			}
		}
	}

#pragma endregion
	cls();
	int ptr = 0, p = 0;
	int cykl = 0, pentla = 0;
	//for (i = 0; i < 100; i++)
	//	std::cout << "*";
	//std::cout << '\n';
	if (Lista.m_size() < 5)
	{
		cykl = Lista.m_size(); //- cykl;
	}
	else
	{
		cykl = 5;
	}
	while (true)
	{
		cls();
		m_create_logo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if (ptr > 2) {
			if (cykl + 1 <= Lista.m_size())
				cykl += 1;
			else
			{
				cykl = Lista.m_size(); //- cykl;
			}
		}
		for (i = pentla; i < cykl; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << i + 1 << "\t" << Lista[i] << endl;
			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << i + 1 << "\t" << Lista[i] << endl;
			}
		}
		while (true)
		{
			//if (Lista.m_size() > 1) {
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				//cykl -= 2;
				if (ptr < 0)      // gdy wykracza wraca na koniec
				{
					cykl = Lista.m_size();
					if (Lista.m_size() > 5)
						pentla = Lista.m_size() - 5;
					else
						pentla = 0;
					ptr = Lista.m_size();
					continue;
				}
				if (pentla > 0 && ptr < Lista.m_size() - 3)
				{
					pentla--;
				}
				if (cykl > 5 && ptr < Lista.m_size() - 3)
				{
					if (cykl > 6)
						cykl -= 2;
					else
						cykl -= 1;
				}

				//if (pentla>0&&ptr<Lista.m_size() -3)

				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr > 2 && ptr < Lista.m_size() - 2)
					pentla++;
				if (ptr > Lista.m_size() - 1)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					pentla = 0;
					if (Lista.m_size() > 5)
						cykl = 5;
					else
						cykl = Lista.m_size();
					ptr = 0;
				}
				break;
			}
			//}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				Sleep(150);
				C_element Element(m_create_human(V_ID[ptr]));
				Lista.m_erase(ptr);
				V_ID.m_erase(ptr);
				return Element;
			}
		}
		Sleep(150);     // szybkosc poruszania sie po menu
	}
}
//w momecie tworzenia jednego elementu nie musza byc aktualizowane
int C_aplication_txt::m_menu_edit_human(N_striing Data, int X, C_human &human)  //metoda do przerobienia
{
	X++;
	int i;
	//tworzenie danych
	char C;
	N_striing first_name, sure_name, gender, data, dd, mm, yy;
	for (i = 0; i < Data.m_size(); i++) //problem z analiza
	{
		switch (Data[i])
		{
		case'$':
		{
			i++;
			while (1)
			{
				//i++;
				if (Data[i + 1] == '&')
					break;
				i++;
				first_name += Data[i];
			}
			break;
		}
		case'&':
		{
			i++;
			while (1)
			{
				//i++;
				if (Data[i + 1] == '!')
					break;
				i++;
				sure_name += Data[i];
			}
			break;
		}
		case'!':
		{
			i++;
			while (1)
			{
				//i++;
				if (Data[i + 1] == '>')
					break;
				i++;
				gender += Data[i];
			}
			break;
		}
		}

	}
	//C_human human;
	human = m_create_human(X);
	int pt = 0;//da tego mometu dziala
	if (human.m_set_first_name().m_set_contens() == first_name&&human.m_set_last_name().m_set_contens() == sure_name
		&&human.m_set_gender().m_set_contens() == gender)
	{
		N_vektor<C_date> v_date = human.m_set_Vdate();
		if (v_date.m_size() > 1) {
			dd = v_date[1].m_set_day().m_day_set();
			mm = v_date[1].m_set_month().m_month_set();
			yy = v_date[1].m_set_year().m_year_set();
		}
		//cls();
		while (true)
		{
			data = dd;
			data += " - ";
			data += mm;
			data += " - ";
			data += yy;
			N_striing Menu2[6] = { "1. Name", "2. Surname", "3. Gender", "4. Date of death ","5. Save", "6. Return" };
			N_striing SubMenu2[6] = { first_name, sure_name, gender, data,"[Save Human]", "[Back To Previous Menu]" };
			cls();
			//m_create_logo();
			std::cout << "\tYou can change your personal data. Don't forget to save your changes!\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

			for (int i = 0; i < 6; ++i)
			{
				if (i == pt)       // podswietla dana opcje na niebiesko, dopisuje strzalke
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\t\t\t\t" << "--> " << Menu2[i] << " \n\t\t\t " << SubMenu2[i] << endl;
				}
				else                // niewybrane opcje sa biale
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "\t\t\t\t" << Menu2[i] << endl;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "\n\n\n\n Use the arrows to navigate the menu ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << char(24) << " " << char(25);        // kody ASCII strzalek
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << ". Confirm your choice with ";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

			cout << "ENTER.";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "\n Click ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "SPACEBAR";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << " if you want back to main menu.";


			while (true)
			{
				Sleep(150);
				if (GetAsyncKeyState(VK_SPACE)) return M_menu_glowne;
				if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
				{
					pt -= 1;
					if (pt < 0)      // gdy wykracza wraca na koniec
					{
						pt = 5;
					}
					break;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
				{
					pt += 1;
					if (pt >= 6)       // gdy wykracza poza menu, znow wraca na poczatek
					{
						pt = 0;
					}
					break;
				}
				else
				{
					switch (pt)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
					{
					case 0:
					{
						Sleep(150);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
									   //edycja dotyczaca imienia
						if (GetAsyncKeyState(VK_BACK) != 0)
						{
							//Sleep(150);
							first_name.m_pop_back();
							break;
						}
						C = m_get_key();
						if (C != '\0') {
							first_name.m_push_back(C);
							human.m_set_first_name();
						}
						break;
					}
					case 1:
					{
						Sleep(150);
						if (GetAsyncKeyState(VK_BACK) != 0)
						{
							//Sleep(150);
							sure_name.m_pop_back();
							break;
						}
						C = m_get_key();
						if (C != '\0') {
							sure_name.m_push_back(C);
						}
						break;
					}
					case 2:
					{
						Sleep(150);
						if (GetAsyncKeyState(VK_RETURN) != 0)
						{
							if (gender == "Woman")
							{
								gender = "Man";
								//Sleep(150);
								break;
							}
							else
							{
								gender = "Woman";
								//Sleep(150);
								break;
							}
						}
						break;
					}
					case 3:
					{
						if (GetAsyncKeyState(VK_BACK) != 0 && v_date.m_size()>1)
						{
							if (yy.m_size() > 0)
							{
								yy.m_pop_back();
								//Sleep(150);
								break;
							}
							else
							{
								if (mm.m_size() > 0)
								{
									mm.m_pop_back();
									//Sleep(150);
									break;
								}
								else
								{
									if (dd.m_size() > 0)
									{
										dd.m_pop_back();
										//Sleep(150);
										break;
									}
									//Sleep(150);
									break;
								}
							}
							Sleep(150);
							break;
						}
						else
						{
							if (dd.m_size() < 2) {
								C = m_get_key();
								if (C != '\0') {
									dd.m_push_back(C);
									break;
								}
							}
							else
							{
								if (mm.m_size() < 2) {
									C = m_get_key();
									if (C != '\0') {
										mm.m_push_back(C);
										break;
									}
								}
								else
								{
									if (yy.m_size() < 4) {
										C = m_get_key();
										if (C != '\0') {
											yy.m_push_back(C);
											break;
										}
									}

									break;
								}
							}
							break;
						}
						//edycja dotyczaca daty
					}
					case 4:
					{
						if (GetAsyncKeyState(VK_RETURN) != 0)
						{
							C_first_name First(first_name);
							C_last_name Last(sure_name);
							if (gender == "Men")
								human.m_get_gender(true);
							else
								human.m_get_gender(false);
							C_date date;
							date.m_get_day(dd);
							date.m_get_month(mm);
							date.m_get_year(yy);
							if (v_date.m_size() > 1)
								human.m_update_date(1, date);
							else
								human.m_get_date(date);
							human.m_get_first_name(First);
							human.m_update_last_name(0, Last);
							return M_edit_tree; //skok102
						}
					}
					case 5:
					{
						if (GetAsyncKeyState(VK_RETURN) != 0) {
							return M_edit_tree + 1;
						}

					}
					}//koniec switcha
					break;
				}
			}
			//	Sleep(100);     // szybkosc poruszania sie po menu
		}
		//return M_edit_tree;
	}
	else
	{
		i = 1;
		while (true)
		{
			if (i % 2 == 0)
			{
				if (X + 1 <= Lista.m_size())
					human = m_create_human(X + i);
				else
				{
					human.m_clear();
					return M_edit_tree;
					//po wyjsciu z metody zrobic warunek jesli pusty human to nic nie rob
				}
				if (human.m_set_first_name().m_set_contens() == first_name&&human.m_set_last_name().m_set_contens() == sure_name
					&&human.m_set_gender().m_set_contens() == gender)
				{
					cls();
					std::cout << human;
					N_vektor<C_date> v_date = human.m_set_Vdate();
					if (v_date.m_size() > 1) {
						dd = v_date[1].m_set_day().m_day_set();
						mm = v_date[1].m_set_month().m_month_set();
						yy = v_date[1].m_set_year().m_year_set();
					}
					//cls();
					while (true)
					{
						data = dd;
						data += " - ";
						data += mm;
						data += " - ";
						data += yy;
						N_striing Menu2[6] = { "1. Name", "2. Surname", "3. Gender", "4. Date of death ","5. Save", "6. Return" };
						N_striing SubMenu2[6] = { first_name, sure_name, gender, data,"[Save Human]", "[Back To Previous Menu]" };
						cls();
						//m_create_logo();
						std::cout << "\tYou can change your personal data. Don't forget to save your changes!\n\n";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

						for (int i = 0; i < 6; ++i)
						{
							if (i == pt)       // podswietla dana opcje na niebiesko, dopisuje strzalke
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
								cout << "\t\t\t\t" << "--> " << Menu2[i] << " \n\t\t\t " << SubMenu2[i] << endl;
							}
							else                // niewybrane opcje sa biale
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
								cout << "\t\t\t\t" << Menu2[i] << endl;
							}
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << "\n\n\n\n Use the arrows to navigate the menu ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << char(24) << " " << char(25);        // kody ASCII strzalek
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << ". Confirm your choice with ";

						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

						cout << "ENTER.";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << "\n Click ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "SPACEBAR";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << " if you want back to main menu.";


						while (true)
						{
							Sleep(150);
							if (GetAsyncKeyState(VK_SPACE)) return M_menu_glowne;
							if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
							{
								pt -= 1;
								if (pt < 0)      // gdy wykracza wraca na koniec
								{
									pt = 5;
								}
								break;
							}
							else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
							{
								pt += 1;
								if (pt >= 6)       // gdy wykracza poza menu, znow wraca na poczatek
								{
									pt = 0;
								}
								break;
							}
							else
							{
								switch (pt)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
								{
								case 0:
								{
									Sleep(150);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
												   //edycja dotyczaca imienia
									if (GetAsyncKeyState(VK_BACK) != 0)
									{
										//Sleep(150);
										first_name.m_pop_back();
										break;
									}
									C = m_get_key();
									if (C != '\0') {
										first_name.m_push_back(C);
										human.m_set_first_name();
									}
									break;
								}
								case 1:
								{
									Sleep(150);
									if (GetAsyncKeyState(VK_BACK) != 0)
									{
										//Sleep(150);
										sure_name.m_pop_back();
										break;
									}
									C = m_get_key();
									if (C != '\0') {
										sure_name.m_push_back(C);
									}
									break;
								}
								case 2:
								{
									Sleep(150);
									if (GetAsyncKeyState(VK_RETURN) != 0)
									{
										if (gender == "Woman")
										{
											gender = "Man";
											//Sleep(150);
											break;
										}
										else
										{
											gender = "Woman";
											//Sleep(150);
											break;
										}
									}
									break;
								}
								case 3:
								{
									if (GetAsyncKeyState(VK_BACK) != 0 && v_date.m_size()>1)
									{
										if (yy.m_size() > 0)
										{
											yy.m_pop_back();
											//Sleep(150);
											break;
										}
										else
										{
											if (mm.m_size() > 0)
											{
												mm.m_pop_back();
												//Sleep(150);
												break;
											}
											else
											{
												if (dd.m_size() > 0)
												{
													dd.m_pop_back();
													//Sleep(150);
													break;
												}
												//Sleep(150);
												break;
											}
										}
										Sleep(150);
										break;
									}
									else
									{
										if (dd.m_size() < 2) {
											C = m_get_key();
											if (C != '\0') {
												dd.m_push_back(C);
												break;
											}
										}
										else
										{
											if (mm.m_size() < 2) {
												C = m_get_key();
												if (C != '\0') {
													mm.m_push_back(C);
													break;
												}
											}
											else
											{
												if (yy.m_size() < 4) {
													C = m_get_key();
													if (C != '\0') {
														yy.m_push_back(C);
														break;
													}
												}

												break;
											}
										}
										break;
									}
									//edycja dotyczaca daty
								}
								case 4:
								{
									if (GetAsyncKeyState(VK_RETURN) != 0)
									{
										C_first_name First(first_name);
										C_last_name Last(sure_name);
										if (gender == "Men")
											human.m_get_gender(true);
										else
											human.m_get_gender(false);
										C_date date;
										date.m_get_day(dd);
										date.m_get_month(mm);
										date.m_get_year(yy);
										if (v_date.m_size() > 1)
											human.m_update_date(1, date);
										else
											human.m_get_date(date);
										human.m_get_first_name(First);
										human.m_update_last_name(0, Last);
										return M_edit_tree; //skok102
									}
								}
								case 5:
								{
									if (GetAsyncKeyState(VK_RETURN) != 0) {
										return M_edit_tree + 1;
									}

								}
								}//koniec switcha
								break;
							}
						}
						//	Sleep(100);     // szybkosc poruszania sie po menu
					}
				}
				i++;
			}
			else
			{
				if (X - i>0)
					human = m_create_human(X - i);
				else
				{
					human.m_clear();
					return M_edit_tree;
				}

				if (human.m_set_first_name().m_set_contens() == first_name&&human.m_set_last_name().m_set_contens() == sure_name
					&&human.m_set_gender().m_set_contens() == gender)
				{
					cls();
					std::cout << human;
					N_vektor<C_date> v_date = human.m_set_Vdate();
					if (v_date.m_size() > 1) {
						dd = v_date[1].m_set_day().m_day_set();
						mm = v_date[1].m_set_month().m_month_set();
						yy = v_date[1].m_set_year().m_year_set();
					}
					//cls();
					while (true)
					{
						data = dd;
						data += " - ";
						data += mm;
						data += " - ";
						data += yy;
						N_striing Menu2[6] = { "1. Name", "2. Surname", "3. Gender", "4. Date of death ","5. Save", "6. Return" };
						N_striing SubMenu2[6] = { first_name, sure_name, gender, data,"[Save Human]", "[Back To Previous Menu]" };
						cls();
						//m_create_logo();
						std::cout << "\tYou can change your personal data. Don't forget to save your changes!\n\n";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

						for (int i = 0; i < 6; ++i)
						{
							if (i == pt)       // podswietla dana opcje na niebiesko, dopisuje strzalke
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
								cout << "\t\t\t\t" << "--> " << Menu2[i] << " \n\t\t\t " << SubMenu2[i] << endl;
							}
							else                // niewybrane opcje sa biale
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
								cout << "\t\t\t\t" << Menu2[i] << endl;
							}
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << "\n\n\n\n Use the arrows to navigate the menu ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << char(24) << " " << char(25);        // kody ASCII strzalek
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << ". Confirm your choice with ";

						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

						cout << "ENTER.";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << "\n Click ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "SPACEBAR";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << " if you want back to main menu.";


						while (true)
						{
							Sleep(150);
							if (GetAsyncKeyState(VK_SPACE)) return M_menu_glowne;
							if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
							{
								pt -= 1;
								if (pt < 0)      // gdy wykracza wraca na koniec
								{
									pt = 5;
								}
								break;
							}
							else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
							{
								pt += 1;
								if (pt >= 6)       // gdy wykracza poza menu, znow wraca na poczatek
								{
									pt = 0;
								}
								break;
							}
							else
							{
								switch (pt)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
								{
								case 0:
								{
									Sleep(150);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
												   //edycja dotyczaca imienia
									if (GetAsyncKeyState(VK_BACK) != 0)
									{
										//Sleep(150);
										first_name.m_pop_back();
										break;
									}
									C = m_get_key();
									if (C != '\0') {
										first_name.m_push_back(C);
										human.m_set_first_name();
									}
									break;
								}
								case 1:
								{
									Sleep(150);
									if (GetAsyncKeyState(VK_BACK) != 0)
									{
										//Sleep(150);
										sure_name.m_pop_back();
										break;
									}
									C = m_get_key();
									if (C != '\0') {
										sure_name.m_push_back(C);
									}
									break;
								}
								case 2:
								{
									Sleep(150);
									if (GetAsyncKeyState(VK_RETURN) != 0)
									{
										if (gender == "Woman")
										{
											gender = "Man";
											//Sleep(150);
											break;
										}
										else
										{
											gender = "Woman";
											//Sleep(150);
											break;
										}
									}
									break;
								}
								case 3:
								{
									if (GetAsyncKeyState(VK_BACK) != 0 && v_date.m_size()>1)
									{
										if (yy.m_size() > 0)
										{
											yy.m_pop_back();
											//Sleep(150);
											break;
										}
										else
										{
											if (mm.m_size() > 0)
											{
												mm.m_pop_back();
												//Sleep(150);
												break;
											}
											else
											{
												if (dd.m_size() > 0)
												{
													dd.m_pop_back();
													//Sleep(150);
													break;
												}
												//Sleep(150);
												break;
											}
										}
										Sleep(150);
										break;
									}
									else
									{
										if (dd.m_size() < 2) {
											C = m_get_key();
											if (C != '\0') {
												dd.m_push_back(C);
												break;
											}
										}
										else
										{
											if (mm.m_size() < 2) {
												C = m_get_key();
												if (C != '\0') {
													mm.m_push_back(C);
													break;
												}
											}
											else
											{
												if (yy.m_size() < 4) {
													C = m_get_key();
													if (C != '\0') {
														yy.m_push_back(C);
														break;
													}
												}

												break;
											}
										}
										break;
									}
									//edycja dotyczaca daty
								}
								case 4:
								{
									if (GetAsyncKeyState(VK_RETURN) != 0)
									{
										C_first_name First(first_name);
										C_last_name Last(sure_name);
										if (gender == "Men")
											human.m_get_gender(true);
										else
											human.m_get_gender(false);
										C_date date;
										date.m_get_day(dd);
										date.m_get_month(mm);
										date.m_get_year(yy);
										if (v_date.m_size() > 1)
											human.m_update_date(1, date);
										else
											human.m_get_date(date);
										human.m_get_first_name(First);
										human.m_update_last_name(0, Last);
										return M_edit_tree; //skok102
									}
								}
								case 5:
								{
									if (GetAsyncKeyState(VK_RETURN) != 0) {
										return M_edit_tree + 1;
									}

								}
								}//koniec switcha
								break;
							}
						}
						//	Sleep(100);     // szybkosc poruszania sie po menu
					}
				}
				i++;
			}
		}
	}
}
void C_aplication_txt::m_export_tree() {

}
C_element C_aplication_txt::m_menu_edit_relations() {
	C_element A;
	return A;
}
void C_aplication_txt::m_look_at(C_id id) {
	C_tree Tree(m_create_tree(id));

}
void C_aplication_txt::m_menu() {
	int Value = 0;
	while (true)
	{
		switch (Value)
		{
		case M_exit:
		{
			return;
		}
		case M_menu_glowne:
		{
			Value = m_main_menu();
			break;
		}
		case M_new_tree:
		{
			Value = m_sub_1();
			break;
		}
		case M_load_tree:
		{
			Value = m_sub_menu_2();
			break;
		}
		case M_creating_new_tree:
		{
			Value = m_menu_name_tree();
			break;
		}
		case M_import_tree:
		{
			Value = m_sub_menu_2();
			break;
		}
		case M_dysplay_tree:
		{
			Value = m_display_tree();
			break;
		}
		case M_edit_tree:
		{
			Value = m_edit_tree();
			break;
		}
		case M_szukanie:
		{
			Value = m_search_tree();
			break;
		}
		case M_menu_tree:
		{
			Value = m_menu_tree();
			break;
		}
		case (M_add_human + 1):
		{
			Value = m_menu_add_human(M_edit_tree);
			break;
		}
		case (M_add_human + 2):
		{
			Value = m_menu_add_human(M_creating_new_tree);
			break;
		}
		case M_menu_relation:
		{
			Value = m_menu_relation(M_edit_tree);
			break;
		}
		case M_edit_relation:
		{
			m_menu_edit_relations(); //dokonczyc rozbudowe i rozbudowac funkcje
			Value = M_edit_tree;
			break;
		}
		case (M_lista + 1): //wyswietla liste drzew
		{
			Value = m_lista(L_tree);
			break;
		}
		case (M_lista + 2): //wyswietla liste humana
		{
			Value = m_lista(L_human);
			break;
		}
		case (M_lista + 3): //wyswietla drzewo
		{
			Value = m_lista(L_dysplay);
			break;
		}

		}
	}
	//delete Value;
}