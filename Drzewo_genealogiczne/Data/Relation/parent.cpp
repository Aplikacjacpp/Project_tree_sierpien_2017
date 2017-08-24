#include "parent.h"
C_parent::C_parent():C_relation(n_parent){ ID_index = 0; ID_value = 0; }
C_parent::C_parent(C_id &id) : C_relation(n_parent) { ID_index = id; ID_value = 0;}
C_parent::C_parent(const C_id &id) : C_relation(n_parent) { ID_index = id; ID_value = 0;}
C_parent::C_parent(const C_parent &parent):C_relation(parent) {
	if (this != &parent) *this = parent;
}
C_parent& C_parent::operator=(const C_parent &parent) {
	if (this == &parent) return *this;
	if (*this == parent) return *this;
	ID_index = parent.ID_index;
	ID_value = parent.ID_value;
	bParent= parent.bParent;
	return *this;
}
bool C_parent::operator==(const C_parent &parent) {
	if (ID_index == parent.ID_index && ID_value == parent.ID_value && bParent == parent.bParent) return true;
	return false;
}
bool C_parent::operator!=(const C_parent &parent) {
	if (ID_index != parent.ID_index || ID_value != parent.ID_value || bParent != parent.bParent) return true;
	return false;
}
C_parent::~C_parent(){}
void C_parent::m_get_id(C_id &id) { ID_value = id; }
C_id C_parent::m_set_index_id() { return ID_index; }
C_id C_parent::m_set_id() { return ID_value; }
int C_parent::m_set_variable() { return t_parent; }
void C_parent::m_get_complete_content(C_id index, C_id value) {
	ID_index = index;
	ID_value = value;
}
void C_parent::m_set_bParent(bool bParentm)
{
	bParent = bParentm;
}
void C_parent::m_get_complete_content(N_striing Data) {
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
N_striing C_parent::m_get_content()
{
	return ID_value.m_set_contens();
}
std::ostream& operator<<(std::ostream &is, const C_parent &data) {
	if (data.bParent) {
		is << w_parent_boy;
		return is;
	}
	is << w_parent_girl;
	return is;
}