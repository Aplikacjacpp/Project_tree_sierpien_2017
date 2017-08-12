#include "day.h"
C_day::C_day() :C_data(n_day) { i_data_day = -10; }
C_day::C_day(N_striing &day):C_data(n_day) { i_data_day = m_is_there_contens(day).m_atoi(0, day.m_size()); }
C_day::C_day(int day):C_data(n_day) { i_data_day = day; }
C_day::C_day(const C_day &day):C_data(day) {
	if (this != &day) *this = day;
}
C_day& C_day::operator=(const C_day &day) {
	if (*this == day) return *this;
	i_data_day = day.i_data_day;
	return *this;
}
bool C_day::operator==(const C_day &day) {
	if (i_data_day == day.i_data_day) return true;
	return false;
}
bool C_day::operator!=(const C_day &day) {
	if (i_data_day != day.i_data_day) return true;
	return false;
}
C_day::~C_day() {};
bool C_day::m_wchat_is() { if (this->i_data_day != NULL) return true; return false; }
void C_day::m_get_contens(N_striing &contens) { this->i_data_day = m_is_there_contens(contens).m_atoi(0, contens.m_size()-1); }
N_striing C_day::m_set_contens() { N_striing data; data.m_itoa(this->i_data_day); return data; }
N_striing C_day::m_is_there_contens(N_striing &Word) { 
		int y = 0;
		do {
			if (Word[y] >= '0' && Word[y] <= '9') y++;
			else
				return "";
		} while (y != Word.m_size() && Word.m_size() <= 2);
		if(Word.m_atoi(0, Word.m_size() - 1) <= 31)
		return Word;
		return "1";
} //do rozwiniecia
N_striing C_day::m_day_set() { return m_set_contens(); }
void C_day::m_get_day(N_striing &contens) {
	 int value = contens.m_atoi(0, contens.m_size() - 1);
	 if (value > 31) {
		 contens.m_clear();
		 contens = "31";
	 }
	 i_data_day = m_is_there_contens(contens).m_atoi(0, contens.m_size() - 1);
}
int C_day::m_set_variable() {
	return t_day;
}
int C_day::m_set_value_day() {
	return i_data_day;
}
void C_day::m_get_value_day(int value)
{
	if (value > 31)
		value = 31;
	i_data_day = value;
}

