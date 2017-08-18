#include "goverment.h"
C_goverment::C_goverment() { s_goverment_text = ""; }
C_goverment::C_goverment(const C_goverment & goverment) {
	if (this != &goverment) *this = goverment;
}
C_goverment& C_goverment::operator=(const C_goverment& goverment) {
	if (this == &goverment) return *this;
	if (*this == goverment) return *this;
	s_goverment_text = goverment.s_goverment_text;
	return *this;
}
bool C_goverment::operator==(const C_goverment& goverment) {
	if (s_goverment_text==goverment.s_goverment_text) return true;
	return false;
}
bool C_goverment::operator!=(const C_goverment& goverment) {
	if (s_goverment_text!=goverment.s_goverment_text) return true;
	return false;
}
C_goverment::~C_goverment() {}

