#include "children.h"
C_children::C_children():C_relation(n_children) { ID_index = 0; ID_value = 0; }
C_children::C_children(C_id &id) : C_relation(n_children) { ID_index = id; ID_value = 0; }
C_children::C_children(const C_id &id) : C_relation(n_children) { ID_index = id; ID_value = 0; }
C_children::C_children(const C_children &children):C_relation(children) {
	if (this != &children) *this = children;
}
C_children& C_children::operator=(const C_children &children){
	if (this == &children) return *this;
	if (*this == children) return *this;
	ID_index = children.ID_index;
	ID_value = children.ID_value;
	bChild = children.bChild;
	return *this;
}
bool C_children::operator==(const C_children &children) {
	if (ID_index == children.ID_index && ID_value == children.ID_value&&bChild == children.bChild) return true;
	return false;
}
bool C_children::operator!=(const C_children &children) {
	if (ID_index != children.ID_index || ID_value != children.ID_value||bChild != children.bChild) return true;
	return false;
}
C_children::~C_children() {}
void C_children::m_get_id(C_id &id) { ID_value = id; }
C_id C_children::m_set_index_id() { return ID_index; }
C_id C_children::m_set_id() { return ID_value; }
int C_children::m_set_variable() { return t_children; }
void C_children::m_get_complete_content(C_id index, C_id value) {
	ID_index = index;
	ID_value = value;
}
void C_children::m_get_complete_content(N_striing Data) {
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
} //do przetestowania
void  C_children::m_set_bChild(bool bChildm)
{
	bChild = bChildm; //o taka metode chodzi?
}
N_striing C_children::m_get_content()
{
	return ID_value.m_set_contens();
}
std::ostream& operator<<(std::ostream &is, const C_children &data) {
	if(data.bChild){
		is << w_children_boy;
		return is;
	}
	is << w_children_girl;
	return is;
}
