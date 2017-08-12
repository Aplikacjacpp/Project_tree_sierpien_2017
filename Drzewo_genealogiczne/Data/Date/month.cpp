#include "month.h"
C_month::C_month() :C_data(n_month) { i_data_month = 0; }
C_month::C_month(N_striing &month) : C_data(n_month) { i_data_month = m_is_there_contens(month).m_atoi(0, month.m_size()); }
C_month::C_month(int month) : C_data(n_month) { i_data_month = month; }
C_month::C_month(const C_month &month):C_data(month) {
	if (this != &month) *this = month;
}
C_month& C_month::operator=(const C_month &month) {
	if (*this == month) return *this;
	i_data_month = month.i_data_month;
	return *this;
}
bool C_month::operator==(const C_month &month) {
	if (i_data_month == month.i_data_month) return true;
	return false;
}
bool C_month::operator!=(const C_month &month) {
	if (i_data_month != month.i_data_month) return true;
	return false;
}
C_month::~C_month() {};
bool C_month::m_wchat_is() { if (this->i_data_month != NULL) return true; return false; }
void C_month::m_get_contens(N_striing &contens) { this->i_data_month = m_is_there_contens(contens).m_atoi(0, contens.m_size()-1); }
N_striing C_month::m_set_contens() { N_striing data; data.m_itoa(this->i_data_month); return data; }
N_striing C_month::m_is_there_contens(N_striing &Word) {
		int y = 0;
		do {
			if (Word[y] >= '0' && Word[y] <= '9') y++;
			else
				return "";
		} while (y != Word.m_size() && Word.m_size() <= 2);
		if (Word.m_atoi(0, Word.m_size() - 1) <= 12)
			return Word;
		return "1";
}
N_striing C_month::m_month_set() { return m_set_contens(); }
void C_month::m_get_month(N_striing &contens) {
	int value = contens.m_atoi(0, contens.m_size() - 1);
	if (value > 12)
	{
		contens.m_clear();
		contens = "12";
	}
	i_data_month = m_is_there_contens(contens).m_atoi(0, contens.m_size() - 1);
}
int C_month::m_set_variable() {
	return t_month;
}
int C_month::m_set_value_month() {
	return i_data_month;
}
void C_month::m_get_value_month(int value)
{
	if (value > 12)
		value = 12;
	i_data_month = value;
}