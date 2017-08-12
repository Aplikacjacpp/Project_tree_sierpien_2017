#ifndef N_STRIING_H
#define N_STRIING_H
#include <iostream>
#include <fstream>
class N_striing
{
private:
	char *Table = NULL;
	int size = NULL;
	int m_how_long(const char variable[]);
public:
	N_striing();
	N_striing(const char T[]);
	N_striing(const char &Gover);
	N_striing(const N_striing &C);
	N_striing& operator=(const N_striing &C);
	bool operator==(const N_striing &C);
	bool operator!=(const N_striing &C);
	bool operator>(N_striing &C);
	bool operator<(N_striing &C);
	N_striing operator+(const N_striing &c);
	N_striing operator+(const char &c);
	N_striing operator+(const char c[]);
	N_striing operator+(const int &i);
	N_striing& operator+=(const N_striing &c);
	N_striing& operator+=(const char &c);
	N_striing& operator+=(const char c[]);
	N_striing& operator+=(const int &i);
	char operator[](int values);
	const char* m_c_str();
	N_striing& m_itoa(long long i);
	long long m_atoi(int variable_start, int variable_stop);
	N_striing& m_push_back(const char &Gover); //dodaje na koniec znak*
	N_striing& m_push_back(const char Gover[]); //dodaje na koniec ciag znakow
	N_striing& m_push_front(const char &Gover);  //dodaje na poczatek znak*
	N_striing& m_push_front(const char Gover[]); //dodaje na poczatek ciag znakow
	N_striing& m_insert(int value,const char Gover); //wstawia w wybranym miejscu znak na inny*
	N_striing& m_insert(int value, const char Gover[]); //wstawia w wybranym miejscu ciag znakow
	N_striing& m_swap(const char &Gover_old, const char &Gover_new); //podmienia na znak jesli znajdzie szukany (szukany, do wstawienia)*
	N_striing& m_swap(const char Gover_old[], const char Gover_new[]); // podmieni na ciag znakow jezeli znajdie szukany ciag znakow (szukany, do wstawienia)
	N_striing& m_pop_back(); //usuwa ostatni znak
	N_striing& m_pop_front(); //usuwa pierwszy znak
	N_striing m_clear(); //czysci calosc
	N_striing& m_erase(int i); //usuwa krotke w "tablicy"
	N_striing& m_erase_ray(int value_front, int value_back); //usuwa wybrane krotki w "tablicy"
	N_striing& m_erase_ray(int value_front); //usuwa wsystkie krotki poczawszy od podanej w "tablicy"
	N_striing m_cut(int value_front, int value_back); //wycina wybrane krotki (poczatek, koniec)
	bool m_wchat_char(const char &variable);
	bool m_wchat_char(const char variable[]);
	N_striing m_cut(int value_front); //wycina od wybranej krotki do konca
	N_striing& m_shift(int i, const char &value); //podmienia wybrana krotke na podany znak
	int m_size(); //zwraca rozmiar
	friend std::ostream& operator<<(std::ostream &is,const N_striing &C);
	friend N_striing& operator >> (std::fstream &is, N_striing &C);
	N_striing& m_getline(std::ifstream &is);
	virtual ~N_striing();
};
#endif // !N_striing_H

