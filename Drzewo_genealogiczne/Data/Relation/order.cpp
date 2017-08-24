#include "order.h"
C_order::C_order() :C_relation(n_order) { ID_value = 0; ID_index = 0; }
C_order::C_order(C_id &id) : C_relation(n_order) { ID_index = id; ID_value = 0; }
C_order::C_order(const C_id &id) : C_relation(n_order) { ID_index = id; ID_value = 0; }
C_order::C_order(const C_order &sib) : C_relation(sib) {
	if (this != &sib) *this = sib;
}
C_order& C_order::operator=(const C_order &sib) {
	if (this == &sib) return *this;
	if (*this == sib) return *this;
	ID_index = sib.ID_index;
	ID_value = sib.ID_value;
	bSib = sib.bSib;
	satribut = sib.satribut;
	return *this;
}
bool C_order::operator==(const C_order &sib) {
	if (ID_index == sib.ID_index && ID_value == sib.ID_value &&
		bSib == sib.bSib&& satribut == sib.satribut) return true;
	return false;
}
bool C_order::operator!=(const C_order &sib) {
	if (ID_index != sib.ID_index || ID_value != sib.ID_value||
		bSib != sib.bSib||satribut != sib.satribut) return true;
	return false;
}
C_order::~C_order() {}
void C_order::m_get_id(C_id &id) { ID_value = id; }
C_id C_order::m_set_index_id() { return ID_index; }
C_id C_order::m_set_id() { return ID_value; }
int C_order::m_set_variable() { return t_order; }
void C_order::m_get_complete_content(N_striing Data) {
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
void C_order::m_get_complete_content(C_id index, C_id value) {
	ID_index = index;
	ID_value = value;
}

void C_order::m_set_bSib(bool bSibm)
{
	bSib = bSibm;
}
N_striing C_order::m_get_content()
{
	return ID_value.m_set_contens();
}
void C_order::m_get_atribut(N_striing atribut) {
	satribut = atribut;
	satribut += k_atribut_order;
}
N_striing C_order::m_get_atribut() {
	return satribut;
}
std::ostream& operator<<(std::ostream &is, const C_order &data) {
		is << data.satribut;
		return is;
}