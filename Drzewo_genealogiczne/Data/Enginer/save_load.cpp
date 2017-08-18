#include "save_load.h"
C_save_load::C_save_load() {}
C_save_load::C_save_load(const C_save_load & save_load) {
	if (this != &save_load) *this = save_load;
}
C_save_load& C_save_load::operator=(const C_save_load& save_load) {
	if (this == &save_load) return *this;
	//if (*this == save_load) return *this;
	return *this;
}
/*bool C_save_load::operator==(const C_save_load& save_load) {
	if (true) return true;
	return false;
}
bool C_save_load::operator!=(const C_save_load& save_load) {
	if (true) return true;
	return false;
}*/
C_save_load::~C_save_load() {}
/*N_string C_save_load::m_decryption(N_striing a, N_striing tablica, int X)
{
	N_vektor <alfabet> v;
	N_striing slowo = "", haslo = "";
	haslo.m_itoa(X);
	wczytaj(a, slowo);
	ladowanie_sz(v);
	haslo = m_encryption(slowo, v, haslo);
	zapis(a, haslo);
	main_rozkowowywanie(a);
	return 0;
}
void C_save_load::wczytaj_rozkodowacz(N_striing a, N_vektor <N_striing> &date, bool& istnieje)
{
	std::ifstream file;
	file.open(a.m_c_str());
	if (file.good())
	{
		istnieje = true;
		N_striing linie;
		while (true)
		{
			linie.m_clear();
			linie.m_getline(file);
			if (linie == "\0") break;
			date.m_push_back(linie);
		}
		file.close();
	}
	else
	{
		istnieje = false;
	}
}

	void C_save_load::m_analyzing(N_vektor <N_striing> &date, N_striing files)
	{
		std::ofstream file;
		file.open(files.m_c_str());
		if (file.good())
		{
			long long i;
			for (i = 0; i < date.m_size(); i++)
			{
				N_striing retu;
				retu = date[i];
				int x = retu.m_size();
				for (int j = 0; j < x - 2; j++)
				{
					if (retu[j] == '#'&&retu[j + 1] == '@'&&retu[j + 2] == '#')
					{
						file << "\n";
						j = j + 2;
					}
					else
					{
						file << retu[j];
					}
				}
			}
			file.close();
		}
	}
	N_striing C_save_load::m_encryption(N_striing& slowo, N_vektor<alfabet>& v, N_striing& haslo)
	{
		N_striing szyfr = "";
		int x = 0;

		for (int j = 0; j < slowo.m_size(); j++)
		{

			alfabet t, d;
			for (int o = 0; o < 222; o++)
			{
				t = v[o];

				if (t.litera == slowo[j])
				{
					break;
				}
			}
			for (int o = 0; o < 222; o++)
			{
				d = v[o];

				if (d.litera == haslo[x])
				{
					break;
				}
				else
				{
					if (x == haslo.m_size() - 1)
						x = 0;
					else
						x++;
				}
			}
			if ((t.lp - d.lp) >0)
			{
				szyfr += t.litera - d.lp;
			}
			else if ((t.lp - d.lp) == 0)
			{
				szyfr += v[(t.lp - 1 - d.lp - 1) + 220].litera;
			}
			else
			{
				szyfr += v[(t.lp - d.lp) + 220].litera;
			}
		}
		return szyfr;
	}
};
void C_save_load::wczytaj(N_striing a, N_striing& slowo)
{
	std::ifstream file;
	file.open(a.m_c_str());
	if (file.good())
	{
		N_striing	linie;
		while (true)
		{
			linie.m_clear();
			linie.m_getline(file);
			if (linie == "\0") break;
			slowo += linie;
		}
		file.close();
	}
}
void C_save_load::zapis(N_striing a, N_striing& haslo)
{
	std::ofstream file;
	file.open(a.m_c_str());
	if (file.good())
	{
		file << haslo;
		file.close();
	}
}

void C_save_load::wczytuj(N_striing& haslo, bool& istnieje)
{

	std::ifstream file;
	file.open(haslo.m_c_str());
	if (file.good())
	{
		N_striing linie = "";
		istnieje = true;
		haslo = "";
		while (true)
		{
			linie.m_clear();
			linie.m_getline(file);
			if (linie == "\0") break;
			haslo += linie;
		}
		file.close();
	}
	else
	{
		istnieje = false;
	}
}
int C_save_load::main_rozkowowywanie(N_striing a)
{
	N_vektor <N_striing> data;
	bool istnieje;
	wczytaj_rozkodowacz(a, data, istnieje);
	m_analyzing(data, a);
	return 0;
}

void C_save_load::m_analyzing(N_vektor <N_striing> &date, N_striing files)
{
	std::ofstream file;
	file.open(files.m_c_str());
	if (file.good())
	{
		long long i;
		for (i = 0; i < date.m_size(); i++)
		{
			N_striing retu;
			retu = date[i];
			int x = retu.m_size();
			for (int j = 0; j < x - 2; j++)
			{
				if (retu[j] == '#'&&retu[j + 1] == '@'&&retu[j + 2] == '#')
				{
					file << "\n";
					j = j + 2;
				}
				else
				{
					file << retu[j];
				}
			}
		}
		file.close();
	}
}
int C_save_load::main_m_encryption(N_striing a, N_striing tablica, int X)
{
	int s = 0;
	N_vektor <alfabet> v;
	N_vektor <N_striing> slo;
	N_striing  haslo = "";
	haslo.m_itoa(X);
	ladowanie_sz(v);
	wczytuj_sz(a, slo);
	haslo = m_encryption_sz(v, haslo, slo);
	zapis_sz(a, haslo, &s);
	return 0;
}

N_striing C_save_load::m_encryption_sz(N_vektor<alfabet>& v, N_striing& haslo, N_vektor<N_striing>& s)
{
	N_striing slowo = "", szyfr = "";
	for (int i = 0; i < s.m_size(); i++)
	{
		N_striing g;
		g = s[i];
		slowo = slowo + g;
	}
	int x = 0;
	for (int j = 0; j < slowo.m_size(); j++)
	{
		alfabet t, d;
		for (int o = 0; o < 222; o++)
		{
			t = v[o];

			if (t.litera == slowo[j])
			{
				break;
			}
		}
		for (int o = 0; o < 222; o++)
		{
			d = v[o];

			if (d.litera == haslo[x])
			{
				break;
			}
			else
			{
				if (x == haslo.m_size() - 1)
					x = 0;
				else
					x++;
			}
		}
		if ((t.lp + d.lp) < 222)
		{
			szyfr += t.litera + d.lp;
		}
		else if ((t.lp + d.lp) == 444)
		{
			szyfr += v[(t.lp - 1 + d.lp - 1) - 222].litera;
		}
		else if ((t.lp + d.lp) >= 222 && (t.lp + d.lp)<444)
		{
			szyfr += v[(t.lp + d.lp) - 222].litera;
		}
	}
	return szyfr;
}
void C_save_load::zapis_sz(N_striing a, N_striing& haslo, int* s)
{
	std::ofstream file;
	file.open(a.m_c_str());
	if (file.good())
	{
		int x = haslo.m_size();
		if (x>256)
		{
			int y = x / 256;

			for (int i = 0; i < y; i++)
			{
				if (i == 0)
				{
					for (int j = 0; j < 256; j++) {
						file << haslo[j];
					}
					file << "\n";
				}
				if (i > 0)
				{
					if (i == y - 1)
					{
						for (int ze = i * 256; ze < (i + 1) * 256; ze++)
						{
							file << haslo[ze];
						}
						file << "\n";
						for (int st = ((i + 1) * 256) + 1; st < x; st++)
						{
							file << haslo[st];
						}
						file << "\n";
					}
					else
					{
						for (int z = i * 256; z < (i + 1) * 256; z++)
						{
							file << haslo[z];
						}
						file << "\n";
					}
				}
			}
		}
		else
		{
			file << haslo;

		}
		file.close();
	}
	else
	{
		*s = 1;
	}
}
void C_save_load::wczytuj_sz(N_striing& slowo, N_vektor<N_striing>& s)
{
	N_striing linia = "";
	std::ifstream file;
	file.open(slowo.m_c_str());
	int x;
	if (file.good())
	{

		while (true) {
			linia.m_clear();
			linia.m_getline(file);
			std::cout << linia;
			if (linia == "\0") break;
			std::cin >> x;
			linia += "#@#";
			s.m_push_back(linia);
		}
		file.close();
	}
}*/