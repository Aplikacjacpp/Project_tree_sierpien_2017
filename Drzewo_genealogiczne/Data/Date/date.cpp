#include "date.h"
C_date::C_date():C_day(-1),C_month(-1),C_year(-1) {}
C_date::C_date(char value):C_day(-1),C_month(-1),C_year(-1) { c_value = value; }
C_date::C_date(const C_date &d) : C_day(d.i_data_day), C_month(d.i_data_month), C_year(d.i_data_year) { if (this != &d) *this = d; }
C_date& C_date::operator=(const C_date &d) {
	if (this == &d) return *this;
	if (*this == d) return *this; 
	i_data_day = d.i_data_day;
	i_data_month = d.i_data_month;
	i_data_year = d.i_data_year;
	c_value = d.c_value;
	s_value = d.s_value;
	return *this;
}
bool C_date::operator==(const C_date &d) {
	if (c_value == d.c_value&&s_value == d.s_value&&
		i_data_day == d.i_data_day&& i_data_month == d.i_data_month&&
		i_data_year == d.i_data_year) return true;
	return false;
}
bool C_date::operator!=(const C_date &d) {
	if (c_value != d.c_value||s_value != d.s_value||
		i_data_day != d.i_data_day|| i_data_month != d.i_data_month&&
		i_data_year != d.i_data_year) return true;
	return false;
}
C_date::~C_date() {}
C_day C_date::m_set_day() { C_day day(m_day_set()); return day; }
C_month C_date::m_set_month() { C_month month(m_month_set()); return month; }
C_year C_date::m_set_year() { C_year year(m_year_set()); return year; }
N_striing  C_date::m_set_DD_MM_YYYY() { return m_day_set() +c_value+ m_month_set() +c_value+ m_year_set(); }
N_striing  C_date::m_set_MM_DD_YYYY() { return m_month_set() +c_value+ m_day_set()+c_value+ m_year_set(); }
N_striing  C_date::m_set_YYYY_MM_DD() { return m_year_set() +c_value+ m_month_set() +c_value+ m_day_set(); }
N_striing  C_date::m_set_YYYY_DD_MM() { return m_year_set() +c_value+ m_day_set() +c_value+ m_month_set(); }
void C_date::m_get_DD_MM_YYYY(C_day& day, C_month& month, C_year & year) {
	m_get_day(day.m_day_set()); m_get_month(month.m_month_set()); m_get_year(year.m_year_set());
	if(year.m_year_set()=="0")
		m_analitic_date(false);
	m_analitic_date(true);
}
void C_date::m_shift_day(C_day day)
{
	m_get_day(day.m_day_set());
	m_analitic_date(true);
}
void C_date::m_shift_day(int day) {
	N_striing data;
	data.m_itoa(day);
	m_get_day(data);
	m_analitic_date(true);
}
void C_date::m_shift_day(N_striing day) {
	m_get_day(day);
	m_analitic_date(true);
}
void C_date::m_shift_month(C_month month) {
	m_get_month(month.m_month_set());
	m_analitic_date(true);
}
void C_date::m_shift_month(int month) {
	N_striing data;
	data.m_itoa(month);
	m_get_month(data);
	m_analitic_date(true);
}
void C_date::m_shift_month(N_striing month) {
	m_get_month(month);
	m_analitic_date(true);
}
void C_date::m_shift_year(C_year year) {
	m_get_year(year.m_year_set());
	if (year.m_year_set() == "0")
		m_analitic_date(false);
	m_analitic_date(true);
}
void C_date::m_shift_year(int year) {
	N_striing data;
	data.m_itoa(year);
	m_get_year(data);
	if (data == "0")
		m_analitic_date(false);
	m_analitic_date(true);
}
void C_date::m_shift_year(N_striing year) {
	m_get_year(year);
	if (year == "0")
		m_analitic_date(false);
	m_analitic_date(true);
}
void C_date::m_clear() {
	N_striing data = "";
	m_get_day(data);
	m_get_month(data);
	m_get_year(data);
}
void C_date::m_analitic_date(bool b_what) {
	int i, X;
	int i_day=m_set_value_day(), i_month=m_set_value_month(), i_year=m_set_value_year();
	//std::cout << i_day << "//" << i_month << "//" << i_year << "\n";
	if (b_what)
	{
		if (i_day >= 0 && i_month >= 0)
		{
			if (i_month % 2 == 0 && i_month != 2 && i_month != 8)
			{
				if (i_day > 30)
					i_day = 30;
			}
			if (i_month == 2)
			{
				if (i_year > 0)
				{
					if (abs(i_year - 2016) % 4 == 0)
					{
						//				std::cout <<"wynik:"<< abs(i_year - 2016) % 4 << "\n";
						int i_analiza = NULL;
						i_analiza = i_year / 100;
						//					std::cout << "analiza:" << i_analiza << "rok:" << i_year << "\n";
						//					std::cout << "wynik_2: " << i_year - i_analiza * 100 << "\n";
						if ((i_year - i_analiza * 100) == 0)
						{
							//				std::cout << "day==28" << "\n";
							if (i_day > 28)
								i_day = 28;
							m_get_value_day(i_day);
							m_get_value_month(i_month);
							m_get_value_year(i_year);
							return;
						}
						else
						{
							if (i_day > 29)
							{
								//				std::cout << "dzien = 29:)\n";
								i_day = 29;
							}
							//		std::cout << i_day << "//" << i_month << "//" << i_year << "\n";
							m_get_value_day(i_day);
							m_get_value_month(i_month);
							m_get_value_year(i_year);
							return;
						}
					}
					else
					{
						if (i_day > 28)
							i_day = 28;
					}
					m_get_value_day(i_day);
					m_get_value_month(i_month);
					m_get_value_year(i_year);
					return;
				}
				else
				{
					if (i_day > 28)
						i_day = 28;
				}
			}
		}
	}
	else
	{
		if (i_day >= 0 && i_month >= 0)
		{
			if (i_month % 2 == 0 && i_month != 2 && i_month != 8)
			{
				if (i_day > 30)
					i_day = 30;
			}
			if (i_month == 2)
			{
					if (i_day > 28)
						i_day = 28;
			}
		}
		m_get_value_day(i_day);
		m_get_value_month(i_month);
	}

}
N_striing C_date::m_what_type_date() {
	return s_value;
}
void C_date::m_shift_char(char value) {
	c_value = value;
}
void C_date::m_get_type(N_striing value) {
	s_value = value;
}
std::ostream& operator<<(std::ostream &is, const C_date &d) {
	if(d.i_data_day!=-1&&d.i_data_month!=-1&&d.i_data_year!=-1)
	is <<"data: "<< d.i_data_day << "." << d.i_data_month << "." << d.i_data_year;
	return is;
}
bool C_date::operator<(const C_date &d) //operator mniejsze <
{
	if (this->i_data_year > d.i_data_year)
		return false;
	else
	{
		if (this->i_data_year < d.i_data_year)
			return true;
		else if (this->i_data_year == d.i_data_year)
		{
			if (this->i_data_month > d.i_data_month)
				return false;
			else
			{
				if (this->i_data_month < d.i_data_month)
					return true;
				else if (this->i_data_month == d.i_data_month)
				{
					if (this->i_data_day >= d.i_data_day)
						return false;
					else
						return true;
				}
			}
		}
	}
}
bool C_date::operator>(const C_date &d) //operator wieksze >
{
	if (this->i_data_year < d.i_data_year)
		return false;
	else
	{
		if (this->i_data_year > d.i_data_year)
			return true;
		else if (this->i_data_year == d.i_data_year)
		{
			if (this->i_data_month < d.i_data_month)
				return false;
			else
			{
				if (this->i_data_month > d.i_data_month)
					return true;
				else if (this->i_data_month == d.i_data_month)
				{
					if (this->i_data_day <= d.i_data_day)
						return false;
					else
						return true;
				}
			}
		}
	}
}
bool C_date::operator<=(const C_date &d) //operator mniejsze rowne <=
{
	if (this->i_data_year > d.i_data_year)
		return false;
	else
	{
		if (this->i_data_year < d.i_data_year)
			return true;
		else if (this->i_data_year == d.i_data_year)
		{
			if (this->i_data_month > d.i_data_month)
				return false;
			else
			{
				if (this->i_data_month < d.i_data_month)
					return true;
				else if (this->i_data_month == d.i_data_month)
				{
					if (this->i_data_day > d.i_data_day)
						return false;
					else
						return true;
				}
			}
		}
	}
}
bool C_date::operator>=(const C_date &d) //operator wieksze rowne >=
{
	if (this->i_data_year < d.i_data_year)
		return false;
	else
	{
		if (this->i_data_year > d.i_data_year)
			return true;
		else if (this->i_data_year == d.i_data_year)
		{
			if (this->i_data_month < d.i_data_month)
				return false;
			else
			{
				if (this->i_data_month > d.i_data_month)
					return true;
				else if (this->i_data_month == d.i_data_month)
				{
					if (this->i_data_day < d.i_data_day)
						return false;
					else
						return true;
				}
			}
		}
	}
}