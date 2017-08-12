#ifndef ALPHABET_H
#define ALPHABEt_H
#include "../narzedzia/Vektor.h"
struct alfabet
{
	char litera;
	int lp;
	int ascii;
	bool operator==(alfabet &a) {
		if (litera == a.litera&&lp == a.lp&&ascii == a.ascii) return true; return false;
	}
	bool operator!=(alfabet &a) {
		if (litera != a.litera&&lp != a.lp&&ascii != a.ascii) return true; return false;
	}
	void ladowanie_sz(N_vektor<alfabet> &v)
	{
		char lit = ' ';
		for (int i = 0; i <222; i++)
		{
			alfabet t;
			t.litera = lit;
			t.lp = i + 1;
			t.ascii = (int)lit;
			v.m_push_back(t);
			lit++;
		}
	}
};
#endif // !ALPHABET_H
