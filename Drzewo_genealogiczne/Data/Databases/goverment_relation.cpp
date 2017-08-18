#include "goverment_relation.h"
C_goverment_relation::C_goverment_relation() {
	s_goverment_relation = "";
	i_value_id = NULL;
}
C_goverment_relation::C_goverment_relation(const C_goverment_relation & goverment_relation) {
	if (this != &goverment_relation) *this = goverment_relation;
}
C_goverment_relation& C_goverment_relation::operator=(const C_goverment_relation& goverment_relation) {
	if (this == &goverment_relation) return *this;
	if (*this == goverment_relation) return *this;
	s_goverment_relation = goverment_relation.s_goverment_relation;
	i_value_id = goverment_relation.i_value_id;
	return *this;
}
bool C_goverment_relation::operator==(const C_goverment_relation& goverment_relation) {
	if (s_goverment_relation == goverment_relation.s_goverment_relation&&
		i_value_id==goverment_relation.i_value_id) return true;
	return false;
}
bool C_goverment_relation::operator!=(const C_goverment_relation& goverment_relation) {
	if (s_goverment_relation == goverment_relation.s_goverment_relation&&
		i_value_id == goverment_relation.i_value_id) return false;
	return true;
}
C_goverment_relation::~C_goverment_relation() {}
bool C_goverment_relation::m_wchat_is() { if (this->s_goverment_relation.m_size() >= 1 || this->s_goverment_relation != '\0') return true; return false; }
void C_goverment_relation::m_get_contens(N_striing &contens) { 
	this->s_goverment_relation = m_is_there_contens(contens); 
	i_value_id=m_id_value(); 
}
N_striing C_goverment_relation::m_set_contens() { return this->s_goverment_relation; }
N_striing C_goverment_relation::m_is_there_contens(N_striing &Word) { //naprawione !
	int i, value = 0, X;// , Y;
	for (i = 0; i < Word.m_size(); i++)
	{
		X = ((int)Word[i] - 48)+(int)Word[i - 1];
	//	std::cout << Word[i - 1] << " = " << Y << "\t" << Word[i] << " = " << X << "\n";
		//X = X + Y;
		switch (X)
		{
		case t_children:
			//std::cout << Word[i - 1] << " = " << Y << "\t" << Word[i] << " = " << X << "\n";
			value++; break;
		case t_grandchildren:
			//std::cout << Word[i - 1] << " = " << Y << "\t" << Word[i] << " = " << X << "\n";
			value++; break;
		case t_grandparent:
			//std::cout << Word[i - 1] << " = " << Y << "\t" << Word[i] << " = " << X << "\n";
			value++; break;
		case t_parent:
			//std::cout << Word[i - 1] << " = " << Y << "\t" << Word[i] << " = " << X << "\n";
			value++; break;
		case t_sibling:
			//std::cout << Word[i - 1] << " = " << Y << "\t" << Word[i] << " = " << X << "\n";
			value++; break;
		default:
			break;
		}
	}
	if (value >= 1) return Word;
	std::cout << "Problem with file relation.save!\n";
	return "";
}
int C_goverment_relation::m_id_value() {
	int i, j;
	N_striing str, relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation.m_clear();
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_id_relation)
		{
			for (j = i + 1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					continue;
				}
					return str.m_atoi(0, str.m_size() - 1);
				}
			}
		}
	return 0;
} //trzeba przetestowac!!
int C_goverment_relation::m_set_value_id() {
	return i_value_id;
}
N_vektor<C_children> C_goverment_relation::m_set_value_children() {
	N_vektor<C_children> Vektor;
	C_children children;
	int i, j;
	N_striing str, relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation.m_clear();
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_children)
		{
			for (j = i + 1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					continue;
				}
					C_id Id, Id_value;
					Id.m_get_contens(i_value_id);
					Id_value.m_get_contens(str);
					children.m_get_complete_content(Id, Id_value);
					Vektor.m_push_back(children);
					i = j;
					break;
				}
			}
		}
	return Vektor;
} //do przetestowania
N_vektor<C_parent> C_goverment_relation::m_set_value_parent() {
	N_vektor<C_parent> Vektor;
	C_parent parent;
	int i, j;
	N_striing str, relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation.m_clear();
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_parent)
		{
			for (j = i + 1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					continue;
				}
					C_id Id, Id_value;
					Id.m_get_contens(i_value_id);
					Id_value.m_get_contens(str);
					parent.m_get_complete_content(Id, Id_value);
					Vektor.m_push_back(parent);
					i = j;
					break;
				}
			}
		}
	return Vektor;
}; //do przetestowania
N_vektor<C_grandchildren> C_goverment_relation::m_set_value_grandchildren() {
	N_vektor<C_grandchildren> Vektor;
	C_grandchildren grandchildren;
	int i, j;
	N_striing str, relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation.m_clear();
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_grandchildren)
		{
			for (j = i + 1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					continue;
				}
						C_id Id, Id_value;
						Id.m_get_contens(i_value_id);
						Id_value.m_get_contens(str);
					grandchildren.m_get_complete_content(Id, Id_value);
					Vektor.m_push_back(grandchildren);
					i = j;
					break;
				}
			}
		}
	return Vektor;
}; //do przetestowania
N_vektor<C_grandparents> C_goverment_relation::m_set_value_grandparents() {
	N_vektor<C_grandparents> Vektor;
	C_grandparents grandparent;
	int i, j;
	N_striing str, relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation.m_clear();
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_grandparent)
		{
			for (j = i + 1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					continue;
				}
				C_id Id, Id_value;
				Id.m_get_contens(i_value_id);
				Id_value.m_get_contens(str);
				grandparent.m_get_complete_content(Id, Id_value);
				Vektor.m_push_back(grandparent);
				i = j;
				break;
			}
		}
	}
	return Vektor;
	//dobrze dziala :)
} //do przetestowania
N_vektor<C_sibling> C_goverment_relation::m_set_value_sibling() {
	N_vektor<C_sibling> Vektor;
	C_sibling sibling;
	int i, j;
	N_striing str, relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation.m_clear();
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_sibling)
		{
			for (j = i + 1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					continue;
				}
						C_id Id, Id_value;
						Id.m_get_contens(i_value_id);
						Id_value.m_get_contens(str);
					sibling.m_get_complete_content(Id, Id_value);
					Vektor.m_push_back(sibling);
					i = j;
					break;
				}
			}
		}
	return Vektor;
}//do przetestowania
N_vektor<C_partner> C_goverment_relation::m_set_value_patner() {
	N_vektor<C_partner> Vektor;
	C_partner sibling;
	int i, j;
	N_striing str,relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		str.m_clear(); //czy na pewno??
		relation.m_clear();
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_partner)
		{
			for (j = i+1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					//std::cout << str << "  - string\n";
					continue;
				}
					C_id Id, Id_value;
					Id.m_get_contens(i_value_id);
					Id_value.m_get_contens(str);
					sibling.m_get_complete_content(Id, Id_value);
					Vektor.m_push_back(sibling);
					i = j;
					break;
			}
		}
	}
	return Vektor;
}
//wyszukuje i zwraca wartosc dla sibling
N_vektor<C_order> C_goverment_relation::m_set_value_order() {
	N_vektor<C_order> Vektor;
	C_order sibling;
	int i, j,p;
	N_striing str, relation;
	for (i = 1; i < s_goverment_relation.m_size(); i++) {
		relation.m_clear();
		relation.m_push_back(s_goverment_relation[i - 1]);
		relation.m_push_back(s_goverment_relation[i]);
		if (relation == n_order)
		{
			for (j = i + 1; j < s_goverment_relation.m_size(); j++)
			{
				if (s_goverment_relation[j] >= '0' && s_goverment_relation[j] <= '9') {
					str.m_push_back(s_goverment_relation[j]);
					continue;
				}
				C_id Id, Id_value;
				Id.m_get_contens(i_value_id);
				Id_value.m_get_contens(str);
				sibling.m_get_complete_content(Id, Id_value);
				i = j;
				if (s_goverment_relation[i] == k_atribut_order)
				{
					str.m_clear();
					for (p = 0; p < s_goverment_relation.m_size(); p++)
					{
						if (s_goverment_relation[p] != k_atribut_order)
						{
							str.m_push_back(s_goverment_relation[p]);
							continue;
						}
						break;
					}
				}
				Vektor.m_push_back(sibling);
				break;
			}
		}
	}
	return Vektor;
}