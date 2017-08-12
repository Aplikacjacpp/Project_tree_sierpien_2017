#include "id.h"
C_id::C_id() :C_data(n_id_data) { s_data_id = ""; }
C_id::C_id(char* id):C_data(id) {}
C_id::C_id(N_striing &id, bool t) : C_data(n_id_data) { s_data_id = m_is_there_contens(id); }
C_id::C_id(int id) : C_data(n_id_data) { s_data_id.m_itoa(id); }
C_id::C_id(const C_id &id):C_data(id) {
	if (this != &id) *this = id;
}
C_id& C_id::operator=(const C_id &id) {
	if (this == &id) return *this;
	if (*this == id) return *this;
	s_data_id = id.s_data_id;
	return *this;
}
bool C_id::operator==(const C_id &id) {
	if (s_data_id == id.s_data_id) return true;
	return false;
}
bool C_id::operator!=(const C_id &id) {
	if (s_data_id != id.s_data_id) return true; 
	return false;
}
bool C_id::operator>(C_id &id)
{
	if (s_data_id.m_atoi(0, s_data_id.m_size()-1) > id.m_set_contens().m_atoi(0, m_set_contens().m_size()-1)) return true;
	return false;
}
bool C_id::operator<(C_id &id)
{
	if (s_data_id.m_atoi(0, s_data_id.m_size()) < id.m_set_contens().m_atoi(0, m_set_contens().m_size())) return true;
	return false;
}
C_id::~C_id() {}
bool C_id::m_wchat_is() { if (this->s_data_id.m_size() >= 1) return true; return false; }
void C_id::m_get_contens(N_striing &contens) { this->s_data_id = m_is_there_contens(contens); }
N_striing C_id::m_set_contens() { return this->s_data_id; }
N_striing C_id::m_is_there_contens(N_striing &Word) { 
	int y = 0;
	do {
		if (Word[y] >= '0' && Word[y] <= '9') y++;
		else
			return "";
	} while (y != Word.m_size());
	return Word;
}
int C_id::m_set_variable() {
	return t_id_data;
}
void C_id::m_get_contens(int value) {
	s_data_id=s_data_id.m_itoa(value);
}