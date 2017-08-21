#include "sl_personalys.h"
C_sl_personalys::C_sl_personalys():C_save_load() {}
C_sl_personalys::C_sl_personalys(const C_sl_personalys & sl_personalys):C_save_load(sl_personalys) {
	if (this != &sl_personalys) *this = sl_personalys;
}
C_sl_personalys& C_sl_personalys::operator=(const C_sl_personalys& sl_personalys) {
	if (this == &sl_personalys) return *this;
	if (*this == sl_personalys) return *this;
	V_goverment_personaly = sl_personalys.V_goverment_personaly;
	return *this;
}
bool C_sl_personalys::operator==(const C_sl_personalys& sl_personalys) {
	if (V_goverment_personaly == sl_personalys.V_goverment_personaly) return true;
	return false;
}
bool C_sl_personalys::operator!=(const C_sl_personalys& sl_personalys) {
	if (V_goverment_personaly != sl_personalys.V_goverment_personaly) return true;
	return false;
}
C_sl_personalys::~C_sl_personalys() {}
void C_sl_personalys::m_load_file_personaly(bool what, N_striing Data) {
	N_striing s_data,s_inline;
	int i_multiple, i, i_start, i_stop;
	if (what)
	{
		Data += "\\";
		Data += f_save_data;
		C_goverment_personaly Gover;
		std::ifstream File;
		File.open(Data.m_c_str());
		if (File.good())
		{
			do {
				s_inline.m_getline(File); //nie wiem czy bedzie dzialac
				if (s_inline == f_end_file) break;
				s_data += s_inline;
				s_inline.m_clear();
			} while (1);
			File.close();
		}
		s_data = m_cypher_on(s_data);
		i_start = 0;
		for (i = 0; i < s_data.m_size(); i++)
		{
			if (s_data[i] == '>')
			{
				i_stop = i;
				N_striing s_help_data = s_data.m_cut(i_start, i_stop);
				s_help_data += '>';
				Gover.m_get_contens(s_help_data);
				V_goverment_personaly.m_push_back(Gover);
				i_start = i_stop+1;
			}
		}
		return;
	}
	else
	{
		Data += "\\";
		Data += f_save_data;
		s_data.m_clear();
		std::ofstream File;
		File.open(Data.m_c_str());
		if (File.good())
		{
			if (V_goverment_personaly.m_size() == 0)
			{

			}
	//		std::cout <<"\nrozmiar zapisywanego:"<< V_goverment_personaly.m_size() << "\n";
			for (i = 0; i < V_goverment_personaly.m_size(); i++)
			{
				s_data += V_goverment_personaly[i].m_set_contens();
				s_data += '\n';
			}
			//s_data = m_cypher_off(s_data);
			File << s_data;
			File << f_end_file;
			File.close();
		}
	}
}
N_striing C_sl_personalys::m_cypher_on(N_striing data) { return data; }; //odszyfrowywanie
N_striing C_sl_personalys::m_cypher_off(N_striing data) { return data; }; //zaszyfrowywanie
void C_sl_personalys::m_add_new_personaly(C_id id, C_first_name first, N_vektor<C_last_name> Last, C_gender gender) {
	C_last_name last;
	int i;
	N_striing data;
	data = "<";
	data += id.m_what_type();
	data += id.m_set_contens();
	data += first.m_what_type();
	data += first.m_set_contens();
	for (i = 0; i < Last.m_size(); i++)
	{
		last = Last[i];
		data += last.m_what_type();
		data += last.m_set_contens();
	}
	data += gender.m_what_type();
	data += gender.m_set_contens();
	data += ">"; 
	C_goverment_personaly Gover;
	Gover.m_get_contens(data);
/*	for(i=0;V_goverment_personaly.m_size();i++)
	{
		if (V_goverment_personaly[i].m_set_value_id()==id.m_set_variable())
		{
			V_goverment_personaly.m_erase(i);
			V_goverment_personaly.m_insert(i, Gover);
			break;
		}
	}*/
	V_goverment_personaly.m_push_back(Gover); //tego bakowalo!!!
	if (m_what(Gover.m_set_value_id()))
	{
		
		if (V_goverment_personaly.m_size() == 0) {
			V_goverment_personaly.m_push_back(Gover);
			return;
		}
		for (i = 0; i < V_goverment_personaly.m_size(); i++)
		{
			if (Gover.m_set_value_id() < V_goverment_personaly[i].m_set_value_id()) {
				V_goverment_personaly.m_insert(i, Gover);
				return;
			}
		}
		V_goverment_personaly.m_push_back(Gover);
	}
////	std::cout << "test:\n" << data << "\n";
//	
//	V_goverment_personaly.m_push_back(Goverment);
////	std::cout <<"\n rozmiar vektora:"<< V_goverment_personaly.m_size() << "\n"<<V_goverment_personaly[0].m_set_contens()<<"\n";
}
C_goverment_personaly& C_sl_personalys::operator[](int i) {
	return V_goverment_personaly[i];
}
bool C_sl_personalys::m_what(int value) {
	int i;
	for (i = 0; i < V_goverment_personaly.m_size(); i++) {
		if (value == V_goverment_personaly[i].m_set_value_id())
		{
			return false;
		}
	}
	return true;
}
void C_sl_personalys::m_update_personaly(C_id id, C_first_name first, N_vektor<C_last_name> V_last, C_gender gender) {
	int i;
	C_last_name last;
	N_striing data;
	data = "<";
	data += id.m_what_type();
	data += id.m_set_contens();
	data += first.m_what_type();
	data += first.m_set_contens();
	for (i = 0; i < V_last.m_size(); i++)
	{
		last = V_last[i];
		data += last.m_what_type();
		data += last.m_set_contens();
	}
	data += gender.m_what_type();
	data += gender.m_set_contens();
	data += ">";
	C_goverment_personaly Gover_person;
	Gover_person.m_get_contens(data);
	int p = id.m_set_contens().m_atoi(0, id.m_set_contens().m_size()-1)-1;
	for (i = 0; i < V_goverment_personaly.m_size(); i++)
	{
		if (i == p)
		{
			V_goverment_personaly.m_erase(i);
			if (i >= V_goverment_personaly.m_size())
			{
				V_goverment_personaly.m_push_back(Gover_person);
				break;
			}
			V_goverment_personaly.m_insert(i, Gover_person);
			//czy sie tutaj zle dodaje??
			break;
		}
	}
	for (i = 0; i < V_goverment_personaly.m_size(); i++)
	{
		std::cout << V_goverment_personaly[i].m_set_contens();
	}
	std::cin >> i;
}