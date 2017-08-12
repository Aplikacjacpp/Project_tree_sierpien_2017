#include "gender.h"
C_gender::C_gender() :C_data(n_gender) { s_data_gender = ""; }
C_gender::C_gender(bool gender) : C_data(n_gender) { if (gender) s_data_gender = "Men"; else s_data_gender = "Woman"; }
C_gender::C_gender(N_striing &gender) : C_data(n_gender) { s_data_gender = m_is_there_contens(gender); }
C_gender::C_gender(const C_gender &gender):C_data(gender) {
	if (this != &gender) *this = gender;
}
C_gender& C_gender::operator=(const C_gender &gender) {
	if (this == &gender) return *this;
	if (*this == gender) return *this;
	s_data_gender = gender.s_data_gender;
	return *this;
}
bool C_gender::operator==(const C_gender &gender) {
	if (s_data_gender == gender.s_data_gender) return true;
	return false;
}
bool C_gender::operator!=(const C_gender &gender) {
	if (s_data_gender != gender.s_data_gender) return true;
	return false;
}
C_gender::~C_gender() {};
bool C_gender::m_wchat_is() { if (this->s_data_gender.m_size() >= 1) return true; return false; }
void C_gender::m_get_contens(N_striing &contens) {
	this->s_data_gender = m_is_there_contens(contens); }
N_striing C_gender::m_set_contens() { return this->s_data_gender; }
N_striing C_gender::m_is_there_contens(N_striing &Word) { 
	if ((Word == "Men" || Word == "men") || Word == "1" || (Word == "true" || Word == "True")) { return "Men"; }
	else if ((Word == "Women" || Word == "women") || Word == "0" || (Word == "False" && Word == "false")) { return "Women"; };
		return "";
}
std::ostream& operator<<(std::ostream& is,const C_gender &gender)
{
	is << "Gender: " << gender.s_data_gender<<" ";
	return is;
}
int C_gender::m_set_variable() {
	return t_gender;
}


