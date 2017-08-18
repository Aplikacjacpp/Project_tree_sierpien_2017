#include "aplication.h"
C_aplication::C_aplication():C_enginer() {}
C_aplication::C_aplication(const C_aplication & aplication):C_enginer(aplication) {
	if (this != &aplication) *this = aplication;
}
C_aplication& C_aplication::operator=(const C_aplication& aplication) {
	if (this == &aplication) return *this;
	if (*this == aplication) return *this;

	return *this;
}
bool C_aplication::operator==(const C_aplication& aplication) {
	return true;
}
/*bool C_aplication::operator!=(const C_aplication& aplication) {
	if (true) return true;
	return false;
}*/
int C_aplication::m_return_index() {
	return i_index;
}
/*void C_aplication::m_add_human(C_human human) {
	this->m_new_human(human);
}*/
C_aplication::~C_aplication() {}