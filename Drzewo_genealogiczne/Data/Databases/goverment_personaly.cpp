#include "goverment_personaly.h"
C_goverment_personaly::C_goverment_personaly() {}
C_goverment_personaly::C_goverment_personaly(const C_goverment_personaly & goverment_personaly) {
	if (this != &goverment_personaly) *this = goverment_personaly;
}
C_goverment_personaly& C_goverment_personaly::operator=(const C_goverment_personaly& goverment_personaly) {
	if (this == &goverment_personaly) return *this;
	if (*this == goverment_personaly) return *this;
	s_goverment_personaly = goverment_personaly.s_goverment_personaly;
	i_value_id = goverment_personaly.i_value_id;
	return *this;
}
bool C_goverment_personaly::operator==(const C_goverment_personaly& goverment_personaly) {
	if (s_goverment_personaly == goverment_personaly.s_goverment_personaly&&
		i_value_id == goverment_personaly.i_value_id) return true;
	return false;
}
bool C_goverment_personaly::operator!=(const C_goverment_personaly& goverment_personaly) {
	if (s_goverment_personaly == goverment_personaly.s_goverment_personaly&&
		i_value_id == goverment_personaly.i_value_id) return false;
	return true;
}
C_goverment_personaly::~C_goverment_personaly() {}
bool C_goverment_personaly::m_wchat_is() { 
	if (this->s_goverment_personaly.m_size() >= 1 || this->s_goverment_personaly != '\0')
		return true;
	return false; 
}
void C_goverment_personaly::m_get_contens(N_striing &contens) { 
	//std::cout << contens;
	this->s_goverment_personaly = m_is_there_contens(contens);
	i_value_id = m_id_value();
//	std::cout <<"\n id:"<< i_value_id<<"\n"<<s_goverment_personaly<<"\n";
}
N_striing C_goverment_personaly::m_set_contens(void) { return s_goverment_personaly; }
N_striing C_goverment_personaly::m_is_there_contens(N_striing &Word) { //naprawione!
	int i, value = 0;
	int X;
	for (i = 1; i < Word.m_size(); i++)
	{
		X = ((int)Word[i]-48)+ (int)Word[i - 1];
	//	std::cout << Word[i - 1] << " = " << Y << "\t" << Word[i] << " = " << X << "\n";
		switch (X)
		{
		case t_first_name:
	//		std::cout << Word[i - 1] << " = " << Y << "\t" << Word[i] << " = " << X << "\n";
			value++; break;
		case t_last_name:
		//		std::cout << Word[i - 1] << " = " << Y << "\t" << Word[i] << " = " << X << "\n";
			value++; break; 
		case t_gender:
	//			std::cout << Word[i - 1] << " = " << Y << "\t" << Word[i] << " = " << X << "\n";
			value++; break;
		default:
			break;
		}
	}
	if (value >= 3) return Word; 
	std::cout << "Problem with file personaly.save!";
	return "";
}
int C_goverment_personaly::m_id_value() {
	int i,j;
	N_striing str;
	char *data = new char[2];
	for (i = 1; i < s_goverment_personaly.m_size(); i++) {
		 data[0] = s_goverment_personaly[i - 1];
		data[1] = s_goverment_personaly[i];
		if (n_id_data == data)
		{
			for (j = i; j < s_goverment_personaly.m_size(); j++)
			{
				if (s_goverment_personaly[j] >= 0 && s_goverment_personaly[j] <= 9)
				{
					str.m_push_back(s_goverment_personaly[j]);
				}
				else {
					delete[] data;
					return str.m_atoi(0, str.m_size() - 1);
				}
			}
		}
	}
	delete[] data;
	return 0;
} //trzeba przetestowac!!
int C_goverment_personaly::m_set_value_id(){
	return i_value_id;
}
C_first_name C_goverment_personaly::m_set_value_first_name() {
	C_first_name First;
	int i, j;
	N_striing str,data;
	for (i = 1; i < s_goverment_personaly.m_size(); i++) { //dziala:)
		data.m_clear();
		data.m_push_back(s_goverment_personaly[i - 1]);
		data.m_push_back(s_goverment_personaly[i]);
		if (data==n_first_name)
		{
			for (j = i+1; j < s_goverment_personaly.m_size(); j++)
			{
				if (!(s_goverment_personaly[j+1] >= '0'&&s_goverment_personaly[j+1] <='9') && s_goverment_personaly[j] != '>')
				{
					str.m_push_back(s_goverment_personaly[j]);
					continue;
				}
					First.m_get_contens(str);
					return First;
			}
		}
	}
	return First;
} //przetestowac czy dziala
N_vektor<C_last_name> C_goverment_personaly::m_set_value_last_name() { //dziala :)
	C_last_name Last;
	N_vektor<C_last_name> Vektor;
	int i, j;
	N_striing str,data;
	for (i = 1; i < s_goverment_personaly.m_size(); i++) {
		data.m_clear();
		data.m_push_back(s_goverment_personaly[i - 1]);
		data.m_push_back(s_goverment_personaly[i]);
		if (data == n_last_name)
		{
			//std::cout << "Result: " << i << "\n";
			str.m_clear();
			for (j = i+1; j < s_goverment_personaly.m_size(); j++)
			{
				if (!(s_goverment_personaly[j + 1] >= '0' && s_goverment_personaly[j + 1] <= '9')&&s_goverment_personaly[j] != '>')
				{
					str.m_push_back(s_goverment_personaly[j]);
					continue;
				}
					Last.m_get_contens(str);
					Vektor.m_push_back(Last);
					i = j;
					break;
			}
		}
	}
	return Vektor;
} //przetestowac czy dziala
C_gender C_goverment_personaly::m_set_value_gender() {
	C_gender Gender;
	int i, j;
	N_striing str,data;
	for (i = 1; i < s_goverment_personaly.m_size(); i++) {
		data.m_clear();
		data.m_push_back(s_goverment_personaly[i - 1]);
		data.m_push_back(s_goverment_personaly[i]);
		if (data == n_gender)
		{
			for (j = i+1; j < s_goverment_personaly.m_size(); j++)
			{
				if (!(s_goverment_personaly[j + 1] >= '0' && s_goverment_personaly[j + 1] <= '9')&& s_goverment_personaly[j] != '>')
				{
					str.m_push_back(s_goverment_personaly[j]);
					continue;
				}
					Gender.m_get_contens(str);
					return Gender;
				}
			}
		}
	return Gender;
} //przetestowac czy dziala