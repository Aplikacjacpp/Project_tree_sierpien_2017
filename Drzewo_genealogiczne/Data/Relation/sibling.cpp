#include "sibling.h"
C_sibling::C_sibling() :C_relation(n_sibling) { ID_value = 0; ID_index = 0; }
C_sibling::C_sibling(C_id &id) : C_relation(n_sibling) { ID_index = id; ID_value = 0;}
C_sibling::C_sibling(const C_id &id) : C_relation(n_sibling) { ID_index = id; ID_value = 0;}
C_sibling::C_sibling(const C_sibling &sib):C_relation(sib) {
	if (this != &sib) *this = sib;
}
C_sibling& C_sibling::operator=(const C_sibling &sib) {
	if (this == &sib) return *this;
	if (*this == sib) return *this;
	ID_index = sib.ID_index;
	ID_value = sib.ID_value;
	bSib = sib.bSib;
	return *this;
}
bool C_sibling::operator==(const C_sibling &sib) {
	if (ID_index == sib.ID_index && ID_value == sib.ID_value&&bSib == sib.bSib) return true;
	return false;
}
bool C_sibling::operator!=(const C_sibling &sib) {
	if (ID_index != sib.ID_index || ID_value != sib.ID_value||bSib != sib.bSib) return true;
	return false;
}
C_sibling::~C_sibling() {}
void C_sibling::m_get_id(C_id &id) { ID_value = id; }
C_id C_sibling::m_set_index_id() { return ID_index; }
C_id C_sibling::m_set_id() { return ID_value; }
int C_sibling::m_set_variable() { return t_sibling; }
void C_sibling::m_get_complete_content(N_striing Data) {
	int i, j;
	bool what = false;
	C_id Id(n_id_personaly);
	N_striing str, data;
	for (i = 1; i < Data.m_size(); i++) {
		data.m_clear();
		data.m_push_back(Data[i - 1]);
		data.m_push_back(Data[i - 1]);
		if (data == n_id_personaly)
		{
			for (j = i; j < Data.m_size(); j++)
			{
				if (Data[j] >= 0 && Data[j] <= 9)
				{
					str.m_push_back(Data[j]);
				}
				else {
					Id.m_get_contens(str);
					if (what)
					{
						ID_value = Id;
						return;
					}
					else
					{
						ID_index = Id;
						what = true;
						break;
					}
				}
			}
		}
	}
	return;
}//do przetestowania
void C_sibling::m_get_complete_content(C_id index, C_id value) {
	ID_index = index;
	ID_value = value;
}

void C_sibling::m_set_bSib(bool bSibm)
{
	bSib = bSibm;
}
N_striing C_sibling::m_get_content()
{
	return ID_value.m_set_contens();
}
std::ostream& operator<<(std::ostream &is, const C_sibling &data) {
	if (data.bSib) {
		is << w_sibling_boy;
		return is;
	}
	is << w_sibling_girl;
	return is;
}