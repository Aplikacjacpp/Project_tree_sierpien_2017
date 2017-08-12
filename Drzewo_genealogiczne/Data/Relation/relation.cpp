#include "relation.h"
C_relation::C_relation() {}
C_relation::C_relation(N_striing realt) {
	S_relation_text = realt;
}
C_relation::C_relation(const C_relation &relat) { if (this != &relat) *this = relat; }
C_relation& C_relation::operator=(const C_relation &relat) {
	if (this == &relat) return *this;
	if (*this == relat) return *this;
	S_relation_text = relat.S_relation_text;
	return *this;
}
bool C_relation::operator==(const C_relation &relat) {
	if (S_relation_text == relat.S_relation_text) return true;
	return false;
}
bool C_relation::operator!=(const C_relation &relat) {
	if (S_relation_text != relat.S_relation_text) return true;
	return false;
}
C_relation::~C_relation() {}
N_striing C_relation::m_what_type() {return S_relation_text;}