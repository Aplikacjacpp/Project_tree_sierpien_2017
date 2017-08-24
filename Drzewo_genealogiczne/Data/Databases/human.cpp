#include "human.h"
C_human::C_human() { 
	C_date date; 
	date.m_get_type(d_date_bristday); V_date.m_push_back(date);
	date.m_get_type(d_date_dead); V_date.m_push_back(date);
	date.m_get_type(d_date_slubu); V_date.m_push_back(date);
}
C_human::C_human(C_id &id) { Id = id; 
C_date date;
date.m_get_type(d_date_bristday); V_date.m_push_back(date);
date.m_get_type(d_date_dead); V_date.m_push_back(date);
date.m_get_type(d_date_slubu); V_date.m_push_back(date);
}
C_human::C_human(const C_human &human) { if (this != &human) *this = human; }
C_human& C_human::operator=(const C_human &human) {
	if (this == &human) return *this;
	if (*this == human) return *this;
	V_date = human.V_date;
	Id = human.Id;
	First = human.First;
	V_last = human.V_last;
	Gender = human.Gender;
	return *this;
}
bool C_human::operator==(const C_human &human) {
	if (V_date == human.V_date && Id == human.Id && First == human.First && V_last == human.V_last&&Gender==human.Gender) return true;
	return false;
}
bool C_human::operator!=(const C_human &human) {
	if (V_date != human.V_date ||
		Id != human.Id ||
		First != human.First ||
		V_last != human.V_last||
		Gender!=human.Gender) return true;
	return false;
}
C_human::~C_human() {}
void C_human::m_get_first_name(C_first_name &f_name) { First = f_name; }
void C_human::m_get_first_name(N_striing &f_name) { C_first_name F(f_name); First = F; }
void C_human::m_get_last_name(C_last_name &l_name) { V_last.m_push_back(l_name); }
void C_human::m_get_last_name(N_striing &l_name) { C_last_name L(l_name); V_last.m_push_back(L); }
void C_human::m_get_gender(C_gender &gender) { Gender = gender; }
void C_human::m_get_gender(N_striing &gender) { C_gender G(gender); Gender = G; }
void C_human::m_get_gender(bool gender) 
{
	N_striing G;
	G.m_itoa((int)gender);
	Gender.m_get_contens(G);
}
void C_human::m_shift_id(N_striing &id) { C_id I(id,1); Id = I; }
void C_human::m_shift_id(int id) { C_id I(id); Id = I; }
void C_human::m_shift_id(C_id &id) { Id = id; }
void C_human::m_get_date(C_date date) {
//	std::cout << "dodanie\n"<<date.m_set_DD_MM_YYYY()<<"\n";
	
	switch(V_date.m_size())
	{
	case 0:
	{
		N_striing s_data = d_date_bristday;
		date.m_get_type(s_data);
		V_date.m_push_back(date);
		break;
	}
	case 1:
	{
		N_striing s_data = d_date_slubu;
		date.m_get_type(s_data);
		V_date.m_push_back(date);
		break;
	}
	case 2:
	{
		N_striing s_data = d_date_dead;
		date.m_get_type(s_data);
		V_date.m_push_back(date);
		break;
	}
	default:
		return;
	}
	//V_date.m_push_back(date); 
	//std::cout << V_date[0].m_set_DD_MM_YYYY() << "\n";
}
void C_human::m_delete_first_name() { N_striing data = ""; First.m_get_contens(data); }
void C_human::m_delete_last_name(int value) { V_last.m_erase(value); }
void C_human::m_delete_last_name() { V_last.m_pop_front(); }
void C_human::m_delete_gender() { N_striing data = ""; Gender.m_get_contens(data);}
void C_human::m_delete_date(int value) { V_date.m_erase(value); }
void C_human::m_delete_date() { V_date.m_pop_front(); }
void C_human::m_update_date(int value, C_date& date) {
	switch (value)
	{
	case 0:
	case 1:
	case 2:
	{
		V_date.m_erase(value);
		if (value >= V_date.m_size())
		{
			V_date.m_push_back(date);
			return;
		}
		V_date.m_insert(value, date);
		break;
	}
	default:
		std::cout << "Error wykroczenie poza vektor dat!!\n";
		break;
	}
}
void C_human::m_update_last_name(int value, C_last_name& l_name) { 
	V_last.m_erase(value);
	if (V_last.m_size() == 0)
	{
		V_last.m_push_back(l_name);
	}
	else
	V_last.m_insert(value, l_name);
}
void C_human::m_update_last_name(int value, N_striing& l_name) {
	C_last_name L(l_name); 
	V_last.m_erase(value);
	if (V_last.m_size() == 0)
	{
		V_last.m_push_back(L);
	}
	else
		V_last.m_insert(value, L);
}
C_human& C_human::m_clear() { C_human H(m_set_id()); return H; }
C_human& C_human::m_clear_date() { V_date.m_close(); return *this; }
C_human& C_human::m_clear_last_name() { V_last.m_close(); return *this; }
C_first_name C_human::m_set_first_name() { return First; }
C_last_name C_human::m_set_last_name() { return V_last[0]; }
C_last_name C_human::m_set_last_name(int value) { return V_last[value]; }
C_gender C_human::m_set_gender() { return Gender; }
C_id C_human::m_set_id() { return Id; }
C_date C_human::m_set_date(int value) { return V_date[value]; }
C_date C_human::m_set_date() { return V_date[0]; }
N_vektor<C_date> C_human::m_set_Vdate() {
	return V_date;
}
N_vektor<C_last_name> C_human::m_set_V_last_name() {
	return V_last;
}

void C_human::interf_cut(N_striing &first, N_striing &last, C_human &human, int cut)
{
	int f = first.m_size();
	int l = last.m_size();
	N_striing firstname;
	N_striing lastname;

	int sum, ss;
	sum = f + l;
	ss = sum;
	if (sum < cut)
	{
		firstname = first;
		lastname = last;

	}
	else if (sum == cut)
	{
		firstname = first.m_cut(0, 1);
		lastname = last.m_erase_ray(l);
	}
	else if (sum > cut)
	{
		if (l < cut-4)
		{
			firstname = first.m_cut(0, 1);
			lastname = last.m_erase_ray(l);
		}
		else
		{
			firstname = first.m_cut(0, 1);
			lastname = last.m_erase_ray(cut -4);
		}
	}
	human.m_get_first_name(firstname);
	human.m_get_last_name(lastname);
}

void C_human::interf_m(C_human &human, C_date &d, C_date ds)
{
	std::cout << human;
	std::cout << "ur." << d.m_set_DD_MM_YYYY() << "\n";
	if (ds.m_day_set() != '0')
		std::cout << "zm." << ds.m_set_DD_MM_YYYY() << "\n";
}

void C_human::interf_mb(N_striing firstnamee, N_striing lastnamee, C_date &du, C_date ds, char poz, char pion)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	bool zm;
	if (ds.m_day_set() == '0') zm = false;
	else zm = true;

	int f = firstnamee.m_size();
	int l = lastnamee.m_size();
	N_striing firstname = firstnamee;
	N_striing lastname = lastnamee;

	int sum, ss;
	sum = f + l;
	ss = sum;
	if (sum == 13)
	{	
		firstname = firstnamee.m_cut(0, 1) + '.';
		lastname = lastnamee.m_erase_ray(l);
		ss = firstname.m_size() + lastname.m_size();
	}
	else if (sum > 13)
	{
		if (l < 11)
		{
			firstname = firstnamee.m_cut(0, 1) + '.';
			lastname = lastnamee.m_erase_ray(l);
		ss = firstname.m_size() + lastname.m_size();
		}
		else
		{
		firstname = firstnamee.m_cut(0, 1) + '.';
		lastname = lastnamee.m_erase_ray(10);
		ss = firstname.m_size() + lastname.m_size();
		}
	}
	
	for (int i = 0; i<17; i++)
	{
		std::cout << poz;
	}

	std::cout << std::endl << pion;
	for (int i = 0; i<15; i++)
	{
		std::cout << " ";
	}
	std::cout << pion << std::endl;

	std::cout << pion << " " << firstname << " " << lastname;
	for (int i = 0; i<(11 -(ss)+2); i++)
	{
		std::cout << " ";
	}
	std::cout << pion << std::endl;

	std::cout << pion;
	for (int i = 0; i<15; i++)
	{
		std::cout << " ";
	}
	std::cout << pion << std::endl;

	std::cout << pion << " " << "ur." << du.m_day_set() << "." << du.m_month_set() << "." << du.m_year_set();
	if ((ds.m_day_set().m_c_str() >= "1") && (ds.m_day_set().m_c_str() <= "9") &&
		(ds.m_month_set().m_c_str() >= "1") && (ds.m_month_set().m_c_str() <= "9"))
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << " ";
		}
		std::cout << pion << std::endl;
	}
	else if ((ds.m_day_set().m_c_str() >= "1") && (ds.m_day_set().m_c_str() <= "9"))
	{
		for (int i = 0; i < 2; i++)
		{
			std::cout << " ";
		}
		std::cout << pion << std::endl;
	}
	else if ((ds.m_month_set().m_c_str() >= "1") && (ds.m_month_set().m_c_str() <= "9"))
	{
		for (int i = 0; i < 2; i++)
		{
			std::cout << " ";
		}
		std::cout << pion << std::endl;
	}
	else
	{
		for (int i = 0; i < 1; i++)
		{
			std::cout << " ";
		}
		std::cout << pion << std::endl;
	}

	if (zm)
	{
		std::cout << pion;
		for (int i = 0; i<15; i++)
		{
			std::cout << " ";
		}
		std::cout << pion;

		std::cout << std::endl << pion << " " << "zm." << ds.m_day_set() << "." << ds.m_month_set() << "." << ds.m_year_set();
		if ((ds.m_day_set().m_c_str() >= "1") && (ds.m_day_set().m_c_str() <= "9") &&
			(ds.m_month_set().m_c_str() >= "1") && (ds.m_month_set().m_c_str() <= "9"))
		{
			for (int i = 0; i < 3; i++)
			{
				std::cout << " ";
			}
			std::cout << pion << std::endl;
		}
		else if ((ds.m_day_set().m_c_str() >= "1") && (ds.m_day_set().m_c_str() <= "9"))
		{
			for (int i = 0; i < 2; i++)
			{
				std::cout << " ";
			}
			std::cout << pion << std::endl;
		}
		else if ((ds.m_month_set().m_c_str() >= "1") && (ds.m_month_set().m_c_str() <= "9"))
		{
			for (int i = 0; i < 2; i++)
			{
				std::cout << " ";
			}
			std::cout << pion << std::endl;
		}
		else
		{
			for (int i = 0; i < 1; i++)
			{
				std::cout << " ";
			}
			std::cout << pion << std::endl;
		}
	}

	std::cout << pion;
	for (int i = 0; i<15; i++)
	{
		std::cout << " ";
	}
	std::cout << pion << std::endl;

	for (int i = 0; i<17; i++)
	{
		std::cout << poz;
	}
}

void C_human::interf_mbd(N_striing firstname, N_striing lastname, C_date &du, C_date ds, char poz, char pion)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	bool zm;
	if (ds.m_day_set() == '0') zm = false;
	else zm = true;

	int sum = firstname.m_size() + lastname.m_size();
	if ((firstname.m_size() + lastname.m_size() >= 13))
	{
		for (int i = 0; i<(sum)+5; i++)
		{
			std::cout << poz;
		}

		std::cout << std::endl << pion;
		for (int i = 0; i<(sum)+3; i++)
		{
			std::cout << " ";
		}
		std::cout << pion << std::endl;

		std::cout << pion << " " << firstname << " " << lastname << " " << pion << std::endl;

		std::cout << pion;
		for (int i = 0; i<(sum)+3; i++)
		{
			std::cout << " ";
		}
		std::cout << pion << std::endl;

		std::cout << pion << " " << "ur." << du.m_day_set() << "." << du.m_month_set() << "." << du.m_year_set();
		if ((ds.m_day_set().m_c_str() >= "1") && (ds.m_day_set().m_c_str() <= "9") ||
			(ds.m_month_set().m_c_str() >= "1") && (ds.m_month_set().m_c_str() <= "9"))
		{
			for (int i = 0; i < ((sum)+5) - 15; i++)
			{
				std::cout << " ";
			}
			std::cout << pion << std::endl;
		}
		else
		{
			for (int i = 0; i < ((sum)+4) - 15; i++)
			{
				std::cout << " ";
			}
			std::cout << pion << std::endl;
		}

		if (zm)
		{
			std::cout << pion;
			for (int i = 0; i<(sum)+3; i++)
			{
				std::cout << " ";
			}
			std::cout << pion << std::endl;

			std::cout << pion << " " << "zm." << ds.m_day_set() << "." << ds.m_month_set() << "." << ds.m_year_set();
			if ((du.m_day_set() == '9') || (ds.m_month_set().m_c_str() >= "1") && (ds.m_month_set().m_c_str() <= "8"))
			{
				for (int i = 0; i < ((sum)+5) - 15; i++)
				{
					std::cout << " ";
				}
				std::cout << pion << std::endl;
			}
			else
			{
				for (int i = 0; i < ((sum)+4) - 15; i++)
				{
					std::cout << " ";
				}
				std::cout << pion << std::endl;
			}
		}

		std::cout << pion;
		for (int i = 0; i<(sum)+3; i++)
		{
			std::cout << " ";
		}
		std::cout << pion << std::endl;

		for (int i = 0; i<(sum)+5; i++)
		{
			std::cout << poz;
		}
	}
	else
	{
		for (int i = 0; i<17; i++)
		{
			std::cout << poz;
		}

		std::cout << std::endl << pion;
		for (int i = 0; i<15; i++)
		{
			std::cout << " ";
		}
		std::cout << pion << std::endl;

		std::cout << pion << " " << firstname << " " << lastname;
		for (int i = 0; i<(12 - (sum)+1); i++)
		{
			std::cout << " ";
		}
		std::cout << pion << std::endl;

		std::cout << pion;
		for (int i = 0; i<15; i++)
		{
			std::cout << " ";
		}
		std::cout << pion << std::endl;

		std::cout << pion << " " << "ur." << du.m_day_set() << "." << du.m_month_set() << "." << du.m_year_set();
		if ((ds.m_day_set().m_c_str() >= "1") && (ds.m_day_set().m_c_str() <= "9") &&
			(ds.m_month_set().m_c_str() >= "1") && (ds.m_month_set().m_c_str() <= "9"))
		{
			for (int i = 0; i < ((sum)+8) - 15; i++)
			{
				std::cout << " ";
			}
			std::cout << pion << std::endl;
		}
		else if ((ds.m_day_set().m_c_str() >= "1") && (ds.m_day_set().m_c_str() <= "9"))
		{
			for (int i = 0; i < ((sum)+7) - 15; i++)
			{
				std::cout << " ";
			}
			std::cout << pion << std::endl;
		}
		else if ((ds.m_month_set().m_c_str() >= "1") && (ds.m_month_set().m_c_str() <= "9"))
		{
			for (int i = 0; i < ((sum)+7) - 15; i++)
			{
				std::cout << " ";
			}
			std::cout << pion << std::endl;
		}
		else
		{
			for (int i = 0; i < ((sum)+6) - 15; i++)
			{
				std::cout << " ";
			}
			std::cout << pion << std::endl;
		}

		if (zm)
		{
			std::cout << pion;
			for (int i = 0; i<15; i++)
			{
				std::cout << " ";
			}
			std::cout << pion << std::endl;

			std::cout << pion << " " << "zm." << ds.m_day_set() << "." << ds.m_month_set() << "." << ds.m_year_set();
			if ((ds.m_day_set().m_c_str() >= "1") && (ds.m_day_set().m_c_str() <= "9") &&
				(ds.m_month_set().m_c_str() >= "1") && (ds.m_month_set().m_c_str() <= "9"))
			{
				for (int i = 0; i < ((sum)+8) - 15; i++)
				{
					std::cout << " ";
				}
				std::cout << pion << std::endl;
			}
			else if ((ds.m_day_set().m_c_str() >= "1") && (ds.m_day_set().m_c_str() <= "9"))
			{
				for (int i = 0; i < ((sum)+7) - 15; i++)
				{
					std::cout << " ";
				}
				std::cout << pion << std::endl;
			}
			else if ((ds.m_month_set().m_c_str() >= "1") && (ds.m_month_set().m_c_str() <= "9"))
			{
				for (int i = 0; i < ((sum)+7) - 15; i++)
				{
					std::cout << " ";
				}
				std::cout << pion << std::endl;
			}
			else
			{
				for (int i = 0; i < ((sum)+6) - 15; i++)
				{
					std::cout << " ";
				}
				std::cout << pion << std::endl;
			}
		}

		std::cout << pion;
		for (int i = 0; i<15; i++)
		{
			std::cout << " ";
		}
		std::cout << pion << std::endl;

		for (int i = 0; i<17; i++)
		{
			std::cout << poz;
		}
	}
}
std::ostream& operator<<(std::ostream &is,const C_human &h) {
	int i;
	//na razie bez ramki...
	is <<"\t"<< h.First<<"\n\t";
	N_vektor<C_last_name> Last = h.V_last;
	N_vektor<C_date> date = h.V_date;
	for (i = 0; i < Last.m_size(); i++) {
		is<<"Surname:"<< Last[i];
	}
	is << "\n\t"<<h.Gender << "\n\t";
	for (i = 0; i < date.m_size(); i++) {
		switch (i)
		{
		case 0:
		{
			is <<"Date of birth: "<< date[i];
			break;
		}
		case 1:
		{
			is << "Date of death: " << date[i]; //polskie litery
			break;
		}
		case 2:
		{
			is << "Date of wedding: " << date[i]; //polskie litery
			break;
		}
		default:
			break;
		}
		is << "\n";
	}
	return is;
}
N_striing C_human::m_short_interface_personaly() {
	N_striing data;
	data = First.m_set_contens()[0];
	data += ". ";
	int i;
	for (i = 0; i < 5; i++)
		data += this->V_last[0].m_set_contens()[i];
	return data;
}
N_striing C_human::m_short_interface_date() {
	return V_date[0].m_set_DD_MM_YYYY();
}