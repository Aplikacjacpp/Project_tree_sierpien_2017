#include "data.h"
C_data::C_data(N_striing string) {
	s_data_text = string;
}
C_data::C_data(const C_data &data) {
	if (this != &data) *this = data;
}
C_data& C_data::operator=(const C_data &data) {
	if (*this == data) return *this;
	s_data_text = data.s_data_text;
	return *this;
}
bool C_data::operator==(const C_data &data) {
	if (s_data_text == data.s_data_text) return true;
	return false;
}
bool C_data::operator!=(const C_data &data) {
	if (s_data_text != data.s_data_text) return true; 
	return false;
}
C_data::~C_data() {};
N_striing C_data::m_what_type() {return s_data_text;}