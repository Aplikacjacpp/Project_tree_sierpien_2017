#include "grandparents.h"
C_grandparents::C_grandparents() :C_relation(n_grandparent) { ID_index = 0; ID_value = 0; }
C_grandparents::C_grandparents(C_id &id) : C_relation(n_grandparent) { ID_index = id; ID_value = 0; }
C_grandparents::C_grandparents(const C_id &id) : C_relation(n_grandparent) { ID_index = id; ID_value = 0; }
C_grandparents::C_grandparents(const C_grandparents & grandparents):C_relation() {
	if (this != &grandparents) *this = grandparents;
}
C_grandparents& C_grandparents::operator=(const C_grandparents& grandparents) {
	if (this == &grandparents) return *this;
	if (*this == grandparents) return *this;
	ID_index = grandparents.ID_index;
	ID_value = grandparents.ID_value;
	bGrandP=grandparents.bGrandP;
	return *this;
}
bool C_grandparents::operator==(const C_grandparents& grandparents) {
	if (ID_index == grandparents.ID_index&&ID_value == grandparents.ID_value&&bGrandP == grandparents.bGrandP) return true;
	return false;
}
bool C_grandparents::operator!=(const C_grandparents& grandparents) {
	if (ID_index != grandparents.ID_index||ID_value != grandparents.ID_value||bGrandP != grandparents.bGrandP) return true;
	return false;
}
C_grandparents::~C_grandparents() {}
void C_grandparents::m_get_id(C_id &id) { ID_value = id; }
C_id C_grandparents::m_set_index_id() { return ID_index; }
C_id C_grandparents::m_set_id() { return ID_value; }
int C_grandparents::m_set_variable() { return t_grandparent; }
void C_grandparents::m_get_complete_content(C_id index, C_id value) {
	ID_index = index;
	ID_value = value;
}
void C_grandparents::m_get_complete_content(N_striing Data) {
	int i, j;
	bool what = false;
	C_id Id(n_id_personaly);
	N_striing str,data;
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
void C_grandparents::m_set_bGrandP(bool bGrandPm)
{
	bGrandP = bGrandPm;
}
N_striing C_grandparents::m_get_content()
{
	return ID_value.m_set_contens();
}
std::ostream& operator<<(std::ostream &is, const C_grandparents &data) {
	if (data.bGrandP) {
		is << w_grandparents_boy;
		return is;
	}
	is << w_grandparents_girl;
	return is;
}