#include "goverment_date.h"
C_goverment_date::C_goverment_date() {}
C_goverment_date::C_goverment_date(const C_goverment_date & goverment_date) {
	if (this != &goverment_date) *this = goverment_date;
}
C_goverment_date& C_goverment_date::operator=(const C_goverment_date& goverment_date) {
	if (this == &goverment_date) return *this;
	if (*this == goverment_date) return *this;
	s_goverment_data = goverment_date.s_goverment_data;
	i_value_id = goverment_date.i_value_id;
	return *this;
}
bool C_goverment_date::operator==(const C_goverment_date& goverment_date) {
	if (s_goverment_data == goverment_date.s_goverment_data&&
		i_value_id == goverment_date.i_value_id) return true;
	return false;
}
bool C_goverment_date::operator!=(const C_goverment_date& goverment_date) {
	if (s_goverment_data != goverment_date.s_goverment_data||
		i_value_id != goverment_date.i_value_id) return true;
	return false;
}
C_goverment_date::~C_goverment_date() {}
bool C_goverment_date::m_wchat_is() {
	if (this->s_goverment_data.m_size() >= 1 ||this->s_goverment_data!='\0')
		return true;
	return false;
}
void C_goverment_date::m_get_contens(N_striing &contens) { 
	if (contens.m_size() == 0)
		return;
	this->s_goverment_data = m_is_there_contens(contens);
	//std::cout << s_goverment_data << "\n";
	i_value_id = m_id_value();
}
N_striing C_goverment_date::m_set_contens() { return this->s_goverment_data; }
N_striing C_goverment_date::m_is_there_contens(N_striing &Word) {//naprawione!
	int i,value=0;
	int X;
	for (i = 1; i < Word.m_size(); i++)
	{
		X = ((int)Word[i]-48)+ (int)Word[i - 1];
		switch (X)
		{
		case t_day:
		//	std::cout << Word[i - 1] << " = " << Y << "\t" << Word[i] << " = " << X << "\n";
			value++; break;
		case t_month:
		//	std::cout << Word[i - 1] << " = " << Y << "\t" << Word[i] << " = " << X << "\n";
			value++; break;
		case t_year:
		//	std::cout << Word[i - 1] << " = " << Y << "\t" << Word[i] << " = " << X << "\n";
			value++; break;
		default:
			break;
		}
	}
	if (value >= 3) return Word;
	std::cout << "Problem with file date.save!\n";
	return "";
}
int C_goverment_date::m_id_value() {
	int i,j;
	N_striing str,data;
	for (i = 1; i < s_goverment_data.m_size(); i++) {
		data.m_clear();
		 data.m_push_back(s_goverment_data[i - 1]);
		 data.m_push_back(s_goverment_data[i]);
		if (data==n_id_data)
		{
			for (j = i+1; j < s_goverment_data.m_size(); j++)
			{
				if (s_goverment_data[j] >= '0' && s_goverment_data[j] <= '9')
				{
					str.m_push_back(s_goverment_data[j]);
					continue;
				}
					return str.m_atoi(0, str.m_size() - 1);
			}
		}
	}
	return 0;
} //trzeba przetestowac!!
int C_goverment_date::m_set_value_id() {
	return i_value_id;
}
C_day C_goverment_date::m_set_value_day(const char* value) {
	C_day day;
	if (value == d_date_bristday || value == d_date_dead || value == d_date_slubu)
	{
		bool yes = false;
		int i, j;
		N_striing str, data;
		for (i = 1; i < s_goverment_data.m_size(); i++) {
			data.m_clear();
			data.m_push_back(s_goverment_data[i - 1]);
			data.m_push_back(s_goverment_data[i]);
			if (data == value)
				yes = true;
				if (data == n_day&&yes)
				{
					for (j = i + 1; j < s_goverment_data.m_size(); j++)
					{
						if (s_goverment_data[j] >= '0' && s_goverment_data[j] <= '9')
						{
							str.m_push_back(s_goverment_data[j]);
							continue;
						}
						day.m_get_contens(str);
						return day;
					}
				}
		}
	}
		return day;

}; //przetestowac czy dziala
C_month C_goverment_date::m_set_value_month(const char* value) {
	C_month month;
	if (value == d_date_bristday || value == d_date_dead || value == d_date_slubu)
	{
		bool yes=false;
		int i, j;
		N_striing str, data;
		for (i = 1; i < s_goverment_data.m_size(); i++) {
			data.m_clear();
			data.m_push_back(s_goverment_data[i - 1]);
			data.m_push_back(s_goverment_data[i]);
			if (data == value)
				yes = true;
				if (data == n_month&&yes)
				{
					for (j = i + 1; j < s_goverment_data.m_size(); j++)
					{
						if (s_goverment_data[j] >= '0' && s_goverment_data[j] <= '9')
						{
							str.m_push_back(s_goverment_data[j]);
							continue;
						}
						month.m_get_contens(str);
						return month;
					}
				}
			}
	}
	return month;
}; //przetestowac czy dziala
C_year C_goverment_date::m_set_value_year(const char* value) {
	C_year year;
	if (value == d_date_bristday || value == d_date_dead || value == d_date_slubu)
	{
		bool yes = false;
		int i, j;
		N_striing str, data;
		for (i = 1; i < s_goverment_data.m_size(); i++) {
			data.m_clear();
			data.m_push_back(s_goverment_data[i - 1]);
			data.m_push_back(s_goverment_data[i]);
			if (data == value)
				yes = true;
			if (data == n_year&&yes)
			{
				for (j = i + 1; j < s_goverment_data.m_size(); j++)
				{
					if (s_goverment_data[j] >= '0' && s_goverment_data[j] <= '9')
					{
						str.m_push_back(s_goverment_data[j]);
						continue;
					}
					year.m_get_contens(str);
					return year;
				}
			}
		}
	}
	return year;
}; //przetestowac czy dziala
N_vektor<C_date> C_goverment_date::m_set_value_V_date() {
	N_vektor<C_date> Vektor;
	N_vektor<C_day> day(m_set_value_V_day());
	N_vektor<C_month> month(m_set_value_V_month());
	N_vektor<C_year> year(m_set_value_V_year());
	int i;
	C_date date;
	for (i = 0; i < day.m_size(); i++)
	{
		date.m_get_day(day[i].m_day_set());
		date.m_get_month(month[i].m_month_set());
		date.m_get_year(year[i].m_year_set());
		int x;
		Vektor.m_push_back(date);
	}
	return Vektor;
}
N_vektor<C_day> C_goverment_date::m_set_value_V_day() { //dziala
	N_vektor<C_day> Vektor;
	C_day day;
	int i, j;
	N_striing str, data;
	for (i = 1; i < s_goverment_data.m_size(); i++) {
		data.m_clear();
		data.m_push_back(s_goverment_data[i - 1]);
		data.m_push_back(s_goverment_data[i]);
		if (data == n_day)
		{
			for (j = i+1; j < s_goverment_data.m_size(); j++)
			{
				if (s_goverment_data[j] >= '0' && s_goverment_data[j] <= '9')
				{
					str.m_push_back(s_goverment_data[j]);
					continue;
				}
					day.m_get_contens(str);
				//	std::cout <<"dzien: "<< day.m_day_set() << "\n";
					Vektor.m_push_back(day);
					i = j;
					break;
			}
		}
	}
	return Vektor;
}
N_vektor<C_month> C_goverment_date::m_set_value_V_month() { //dziala
	N_vektor<C_month> Vektor;
	C_month month;
	int i, j;
	N_striing str, data;
	for (i = 1; i < s_goverment_data.m_size(); i++) {
		data.m_clear();
		data.m_push_back(s_goverment_data[i - 1]);
		data.m_push_back(s_goverment_data[i]);
		if (data == n_month)
		{
			for (j = i+1; j < s_goverment_data.m_size(); j++)
			{
				if (s_goverment_data[j] >= '0' && s_goverment_data[j] <= '9')
				{
					str.m_push_back(s_goverment_data[j]);;
					continue;
				}
					month.m_get_contens(str);
				//	std::cout <<"miesiac: "<< month.m_month_set() << "\n";
					Vektor.m_push_back(month);
					i = j;
					break;
			}
		}
	}
	return Vektor;
}
N_vektor<C_year> C_goverment_date::m_set_value_V_year() { //dziala
	N_vektor<C_year> Vektor;
	C_year year;
	int i, j;
	N_striing str,data;
	for (i = 1; i < s_goverment_data.m_size(); i++) {
		data.m_clear();
		data.m_push_back(s_goverment_data[i - 1]);
		data.m_push_back(s_goverment_data[i]);
		if (data==n_year)
		{
			for (j = i+1; j < s_goverment_data.m_size(); j++)
			{
				if (s_goverment_data[j] >= '0' && s_goverment_data[j] <= '9')
				{
					str.m_push_back(s_goverment_data[j]);
					continue;
				}
						year.m_get_contens(str);
			//			std::cout <<"rok: "<< year.m_year_set()<<"\n";
						Vektor.m_push_back(year);
						i = j;
						break;
			}
		}
	}
	return Vektor;
}