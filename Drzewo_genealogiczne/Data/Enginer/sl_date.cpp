#include "sl_date.h"
C_sl_date::C_sl_date():C_save_load() {}
C_sl_date::C_sl_date(const C_sl_date & sl_date):C_save_load(sl_date) {
	if (this != &sl_date) *this = sl_date;
}
C_sl_date& C_sl_date::operator=(const C_sl_date& sl_date) {
	if (this == &sl_date) return *this;
	if (*this == sl_date) return *this;
	V_goverment_date = sl_date.V_goverment_date;
	return *this;
}
bool C_sl_date::operator==(const C_sl_date& sl_date) {
	if (V_goverment_date==sl_date.V_goverment_date) return true;
	return false;
}
bool C_sl_date::operator!=(const C_sl_date& sl_date) {
	if (V_goverment_date != sl_date.V_goverment_date) return true;
	return false;
}
C_sl_date::~C_sl_date() {}
void C_sl_date::m_file_date(bool what, N_striing Data)
{
	N_striing s_data;
	int i, i_start, i_stop;
	if (what)
	{
		Data += "\\";
		Data += f_save_date;
		N_striing s_inline;
		C_goverment_date Gover;
		std::ifstream File;
		File.open(Data.m_c_str());
		if (File.good())
		{
			do {
				s_inline.m_getline(File); //nie wiem czy bedzie dzialac
				if (s_inline == f_end_file) break;
				s_data += s_inline;
				//std::cout << s_inline << "\n";
				s_inline.m_clear();
			} while (1);
			File.close();
		}
		//s_data = m_cypher_on(s_data);
		i_start = 0;
		for (i = 0; i < s_data.m_size(); i++)
		{
			if (s_data[i] == '>')
			{
				//std::cout << "wartosc" << s_data << "\n";
				i_stop = i;
				N_striing s_help_data = s_data.m_cut(i_start, i_stop);
				//if(s_help_data.m_size()>=5)
				s_help_data += '>';
				Gover.m_get_contens(s_help_data);
				V_goverment_date.m_push_back(Gover);
				//std::cout <<"rozmiar: "<< V_goverment_date.m_size() << "\n"<< s_data.m_cut(i_start, i_stop);
				i_start = i_stop + 1;
			}
		}
	}
	else
	{
		s_data.m_clear();
		Data += "\\";
		Data += f_save_date;
		std::ofstream File;
		File.open(Data.m_c_str());
		if (File.good())
		{
			if (V_goverment_date.m_size() == 0)
			{
				File.close();
					return;
			}
			for (i = 0; i < V_goverment_date.m_size(); i++)
			{
				s_data += V_goverment_date[i].m_set_contens();
				//	if (s_data.m_size() < 5)
				//	continue;
				/*	if (s_data.m_pop_back() != '>'&&s_data.m_pop_back()!='\n')
				s_data += '>';*/
				//std::cout << s_data << "\n";
				s_data += "\n";
			}
			//s_data = m_cypher_off(s_data);
			File << s_data;
			File << f_end_file;
			File.close();
		}
	}
} //czytanie z pliku
N_striing C_sl_date::m_cypher_on(N_striing data) { return data; }; //odszyfrowywanie
N_striing C_sl_date::m_cypher_off(N_striing data) { return data; }; //zaszyfrowywanie
void C_sl_date::m_get_new_date(C_id id,N_vektor<C_date> V_date) {
	int i;
	
	C_date date;
	C_goverment_date Gover;
	N_striing data;
	data = "<";
	data += id.m_what_type();
	data += id.m_set_contens();
		for (i = 0; i < V_date.m_size(); i++)
		{
			date = V_date[i];
			data += date.m_what_type_date();
			data += date.m_set_day().m_what_type();
			if(date.m_day_set()!="/")
			data += date.m_day_set();
			data += date.m_set_month().m_what_type();
			if (date.m_month_set() != "/")
			data += date.m_month_set();
			data += date.m_set_year().m_what_type();
			if (date.m_year_set() != "/")
			data += date.m_year_set();
			if (i == V_date.m_size() - 1)
				data += ">";
		}
	Gover.m_get_contens(data);
	V_goverment_date.m_push_back(Gover);
	if (m_what(Gover.m_set_value_id()))
	{
		int i;
		if (V_goverment_date.m_size() == 0) {
			V_goverment_date.m_push_back(Gover);
			return;
		}
		for (i = 0; i < V_goverment_date.m_size(); i++)
		{
			if (Gover.m_set_value_id() < V_goverment_date[i].m_set_value_id()) {
				V_goverment_date.m_insert(i, Gover);
				return;
			}
		}
		V_goverment_date.m_push_back(Gover);
	}
}
C_goverment_date& C_sl_date::operator[](int i) {
	return V_goverment_date[i];
}
C_goverment_date C_sl_date::m_set_gover_date(int i) {
	return V_goverment_date[i];
}
bool C_sl_date::m_what(int value) {
	int i;
	for (i = 0; i < V_goverment_date.m_size(); i++) {
		if (value == V_goverment_date[i].m_set_value_id())
		{
			return false;
		}
	}
	return true;
}
void C_sl_date::m_update_date(C_id id, N_vektor<C_date> V_date) {
	int i;
	C_date date;
	C_goverment_date Gover;
	N_striing data;
	data = "<";
	data += id.m_what_type();
	data += id.m_set_contens();
	for (i = 0; i < V_date.m_size(); i++)
	{
		date = V_date[i];
		data += date.m_what_type_date();
		data += date.m_set_day().m_what_type();
		data += date.m_day_set();
		data += date.m_set_month().m_what_type();
		data += date.m_month_set();
		data += date.m_set_year().m_what_type();
		data += date.m_year_set();
		if (i == V_date.m_size() - 1)
			data += ">";
	}
	Gover.m_get_contens(data);
	for (i = 0; i < V_goverment_date.m_size(); i++) {
		if (i == (id.m_set_contens().m_atoi(0, id.m_set_contens().m_size()-1)-1))
		{
			V_goverment_date.m_erase(i);
			if (i >= V_goverment_date.m_size())
			{
				V_goverment_date.m_push_back(Gover);
				break;
			}
			V_goverment_date.m_insert(i, Gover);
			break;
		}
	}
}