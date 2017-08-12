#include "year.h"
C_year::C_year() :C_data(n_year) { i_data_year = 0; }
C_year::C_year(N_striing &year) : C_data(n_year) { i_data_year = m_is_there_contens(year).m_atoi(0, year.m_size()); }
C_year::C_year(int year) : C_data(n_year) { i_data_year = year; }
C_year::C_year(const C_year &year):C_data(year) {
	if (this != &year) *this = year;
}
C_year& C_year::operator=(const C_year &year) {
	if (*this == year) return *this;
	i_data_year = year.i_data_year;
	return *this;
}
bool C_year::operator==(const C_year &year) {
	if (i_data_year == year.i_data_year) return true;
	return false;
}
bool C_year::operator!=(const C_year &year) {
	if (i_data_year != year.i_data_year) return true;
	return false;
}
C_year::~C_year() {};
bool C_year::m_wchat_is() { if (this->i_data_year != NULL) return true; return false; }
void C_year::m_get_contens(N_striing &contens) { this->i_data_year = m_is_there_contens(contens).m_atoi(0, contens.m_size()-1); }
N_striing C_year::m_set_contens() { N_striing data; data.m_itoa(this->i_data_year); return data; }
N_striing C_year::m_is_there_contens(N_striing &Word) { 
		int y = 0;
		do {
			if (Word[y] >= '0' && Word[y] <= '9') y++;
			else
				return "";
		} while (y != Word.m_size() && Word.m_size() <= 4);
		return Word;
}
N_striing C_year::m_year_set() { return m_set_contens(); }
void C_year::m_get_year(N_striing &contens) {
	i_data_year = contens.m_atoi(0, contens.m_size() - 1);
}
int C_year::m_set_variable() {
	return t_year;
}
int C_year::m_set_value_year() {
	return i_data_year;
}
void C_year::m_get_value_year(int value)
{
	i_data_year = value;
}
