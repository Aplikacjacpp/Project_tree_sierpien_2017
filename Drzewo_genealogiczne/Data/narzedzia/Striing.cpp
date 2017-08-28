#include "striing.h"
N_striing::N_striing() {
	Table = new char[1];
	size = 0;
	Table[0] = '\0';
}
N_striing::N_striing(const char T[])
{
	int i;
	size = m_how_long(T);
	Table = new char[1+size];
	for (i=0;i<m_how_long(T);i++)
	{
		Table[i] = T[i];
	}
	Table[size] = '\0';
}
N_striing::N_striing(const char &gover)
{
	size = 1;
	char Gover = const_cast<char&> (gover);
	Table = new char[1+size];
	Table[0] = Gover;
	Table[size] = '\0';
}
N_striing::N_striing(const N_striing &C) { if (this != &C) *this = C; }
N_striing& N_striing::operator=(const N_striing &C)
{
	if (this == &C) return *this;
	if (*this == C) return *this;
	if (C.Table == NULL)
	{
		this->~N_striing();
		int i;
		size = C.size;
		this->Table = new char[1+size];
		for (i = 0; i < size; i++)
		{
			this->Table[i] = C.Table[i];
		}
		Table[size] = '\0';
		return *this;
	}
	else
	{
		int i;
		this->~N_striing();
		size = C.size;
		this->Table = new char[1 + size];
		for (i = 0; i < size; i++)
		{
			this->Table[i] = C.Table[i];
		}
		Table[size] = '\0';
		return *this;
	}
}
bool N_striing::operator==(const N_striing &C)
{
	if (this->size == C.size)
	{
		int i;
		for (i = 0; i < size; i++)
		{
			if (Table[i] != C.Table[i]) return false;
		}
		return true;
	}
	return false;
}
bool N_striing::operator!=(const N_striing &C)
{
	if (this->size == C.size)
	{
		int i;
		for (i = 0; i < size; i++)
		{
			if (Table[i] != C.Table[i]) return true;
		}
		return false;
	}
	return true;
}
char N_striing::operator[](int values)
{
	return Table[values];
}
N_striing& N_striing::m_push_back(const char &gover)
{
	int i;
	char Gover = const_cast<char&> (gover);
	if (this->size == 0 || this->Table == NULL)
	{
		this->~N_striing();
		this->size = 1;
		this->Table = new char[1+size];
		for (i = 0; i < size; i++)
		{
			Table[i] = Gover;
		}
		Table[size] = '\0';
		return *this;
	}
	N_striing C(*this);
	this->~N_striing();
	this->size = 1 + C.size;
	this->Table = new char[1+size];
	for (i = 0; i < size - 1; i++)
	{
		Table[i] = C.Table[i];
	}
	Table[size - 1] = Gover;
	Table[size] = '\0';
	return *this;
}
N_striing& N_striing::m_push_front(const char &gover)
{
	int i;
	char Gover = const_cast<char&> (gover);
	if (this->size == 0 || this->Table == NULL)
	{
		this->~N_striing();
		this->size = 1;
		this->Table = new char[1+size];
		for (i = 0; i < size; i++)
		{
			Table[i] = Gover;
		}
		Table[size] = '\0';
		return *this;
	}
	N_striing C(*this);
	this->~N_striing();
	this->size += 1;
	this->Table = new char[1+size];
	this->Table[0] = Gover;
	for (i = 0; i<C.size; ++i)
	{
		this->Table[(i + 1)] = C.Table[i];
	}
	Table[size] = '\0';
	return *this;
}
N_striing N_striing::m_clear()
{
	N_striing G;
	*this = G;
	return *this;
}
N_striing& N_striing::m_shift(int i, const char &value)
{
	if (i >= 0 && i < size)
	{
		Table[i] = value;
	}
	return *this;
}
N_striing& N_striing::m_erase(int value)
{
	if (value >= 0 && value < size)
	{
		int j, i = 0;;
		N_striing C(*this);
		this->~N_striing();
		size = C.size;
		Table = new char[1+(--size)];
		for (j = 0; j < size+1; j++)
		{
			if (j == value) continue;
			Table[i] = C.Table[j];
			i++;
		}
		Table[size] = '\0';
		return *this;
	}
	return *this;
}
N_striing& N_striing::operator+=(const N_striing &c)
{
	N_striing C = const_cast<N_striing&> (c);
	for(int i=0; i<C.m_size();i++)
	m_push_back(C[i]);
	return *this;
}
N_striing::~N_striing()
{
	delete[] Table;
}
int N_striing::m_size()
{
	return this->size;
}
std::ostream& operator<<(std::ostream &is,const N_striing &C)
{
	N_striing str = C;
	for (int i = 0; i<str.m_size(); i++)
		is << str.Table[i];
	return is;
}
N_striing N_striing::operator+(const char &c)
{
	N_striing A(*this);
	A.m_push_back(c);
	return A;
}
N_striing N_striing::operator+(const char c[])
{
	N_striing A(*this);
	int i;
	this->~N_striing();
	size = m_how_long(c) + A.size;
	Table = new char[1+size];
	for (i = 0; i < A.size; i++)
		Table[i] = A.Table[i];
	for (i = 0; i < m_how_long(c); i++)
		Table[A.size + i] = c[i];
	Table[size] = '\0';
	return *this;
}
N_striing N_striing::operator+(const N_striing &c){ 
	N_striing A(*this);
	A += c;
	return A;
}
N_striing& N_striing::operator+=(const char &c) {
	N_striing A(*this);
	int i;
	this->~N_striing();
	size = 1 + A.size;
	Table = new char[1+size];
	for (i = 0; i < A.size; i++)
		Table[i] = A.Table[i];
	Table[size - 1] = c;
	Table[size] = '\0';
	return *this;
}
N_striing& N_striing::operator+=(const char c[]) {
	N_striing A(*this);
	int i;
	this->~N_striing();
	size = m_how_long(c) + A.size;
	Table = new char[1+size];
	for (i = 0; i < A.size; i++)
		Table[i] = A.Table[i];
	for (i = 0; i < m_how_long(c); i++)
		Table[A.size + i] = c[i];
	Table[size] = '\0';
	return *this;
}
N_striing& N_striing::operator+=(const int &i){
	m_push_back((char)i);
	return *this;
}
N_striing N_striing::operator+(const int &i) {
	N_striing S(*this);
	S.m_push_back((char)i);
	return S;
}
N_striing& N_striing::m_itoa(long long value) {
	if (value == 0)
	{
		m_push_back("0");
		return *this;
	}
	int i, Value;
	bool what=false;
	for (i = 64; i >= 0; i--) {
		Value = value*pow(10, -i);
		if (Value != 0||what)
		{
			what = true;
			m_push_back((char)(Value + 48));
			value = value-Value*pow(10, i);
		}
	}
	return *this;
}
N_striing& N_striing::m_push_back(const char Gover[]) {
	int i, size_values = m_how_long(Gover);
	N_striing A(*this);
	this->~N_striing();
	size = size_values + A.size;
	Table = new char[1+size];
	for (i = 0; i < A.size; i++)
		Table[i] = A.Table[i];
	for (i=0;i<size_values;i++)
	{
		Table[A.size + i] = Gover[i];
	}
	Table[size] = '\0';
	return *this;
}
N_striing& N_striing::m_push_front(const char Gover[]){
	int i, size_values = m_how_long(Gover);
	N_striing A(*this);
	this->~N_striing();
	size = size_values + A.size;
	Table = new char[1+size];
	for (i = 0; i<size_values; i++)
		Table[i] = Gover[i];
	for (i = 0; i < A.size; i++)
		Table[size_values+i] = A.Table[i];
	Table[size] = '\0';
	return *this;
}
N_striing& N_striing::m_pop_back() {
	m_erase(m_size() - 1);
	return *this;
}
N_striing& N_striing::m_pop_front() {
	m_erase(0);
	return *this;
}
N_striing& N_striing::m_insert(int value, const char Gover) {
	if (value >= 0 && value < size)
	{
		int i, j = 0;;
		N_striing STR(*this);
		this->~N_striing();
		this->size = STR.size;
		this->Table = new char[1+(++size)];
		for (i = 0; i < size; i++)
		{
			if (i == value)
			{
				this->Table[i] = Gover;
				continue;
			}
			this->Table[i] = STR.Table[j];
			j++;
		}
		Table[size] = '\0';
	}
	return *this;
}
N_striing& N_striing::m_insert(int value, const char Gover[]) {
	int i = 0;
	while(1)
	{
		if (Gover[i] == '\0') break;
		m_insert(value++,Gover[i]);
		i++;
	}
	return *this;
}
N_striing& N_striing::m_swap(const char &Gover_old, const char &Gover_new) {
	int i;
	for (i = 0; i < size; i++)
	{
		if (Table[i] == Gover_old) {
			Table[i] = Gover_new;
			return *this;
		}
	}
	throw "blad! wyjscie poza zakres!";
}
N_striing& N_striing::m_swap(const char Gover_old[], const char Gover_new[]) {
	int i;
	int z = m_how_long(Gover_old);
	for (i = 0; i < size; i++)
	{
		if (Table[i] == Gover_old[0]) {
			int j=0;
			while(1)
			{
				if (Gover_old[j] != '\0')
				{
					if (Table[i + j] == Gover_old[j])
						j++;
				}
				else
				{
					if (z == j)
					{
						j = 0;
						while(1)
						{
							if (Gover_new[j] == '\0') return *this;
							m_shift(i+j, Gover_new[j]);
							j++;
						}
					}
					break;
				}
			}
		}
	}
	return *this;
}
N_striing& N_striing::m_erase_ray(int value_front, int value_back) {
	if ((value_front >= 0 && value_front < size)&&(value_back>=0&& value_back<size))
	{
		if (value_front < value_back)
		{
			int j, i = 0;
			int sub = value_back - value_front;
			N_striing C(*this);
			this->~N_striing();
			size = C.size;
			size = size - sub;
			Table = new char[1+size];
			for (j = 0; j < size + sub; j++)
			{
				if (j >= value_front&&j<=value_back) continue;
				Table[i] = C.Table[j];
				i++;
			}
			Table[size] = '\0';
			return *this;
		}
		else if (value_front >= value_back)
		{
			int j, i = 0;
			int sub = value_front - value_back;
			N_striing C(*this);
			this->~N_striing();
			size = C.size;
			size = size - sub;
			Table = new char[1+size];
			for (j = 0; j < size + sub; j++)
			{
				if (j >= value_back&&j <= value_front) continue;
				Table[i] = C.Table[j];
				i++;
			}
			Table[size] = '\0';
			return *this;
		}
	}
	return *this;
}
N_striing& N_striing::m_erase_ray(int value_front) {
	if (value_front >= 0 && value_front < size)
	{
		int j, i = 0;
		N_striing C(*this);
		this->~N_striing();
		size = C.size;
		size = size - (size-value_front);
		Table = new char[1+size];
		for (j = 0; j < size + (size - value_front); j++)
		{
			if (j >= value_front) continue;
			Table[i] = C.Table[j];
			i++;
		}
		Table[size] = '\0';
		return *this;
	}
	return *this;
}
N_striing N_striing::m_cut(int value_front, int value_back) {
	N_striing STR;
	if ((value_front >= 0 && value_front < size) && (value_back >= 0 && value_back < size))
	{
	
		if (value_front < value_back)
		{			
			for (int i = 0; i < m_size(); i++)
			{
				if (i >= value_front && i < value_back)
					STR.m_push_back(this->Table[i]);
			}
			return STR;
		}
		else if (value_back >= value_front)
		{
			for (int i = 0; i < m_size(); i++)
			{
				if (i >= value_back && i < value_front)
					STR.m_push_back(this->Table[i]);
			}
			return STR;
		}
	}
	return STR;
}
N_striing N_striing::m_cut(int value_front) {
	if (value_front >= 0 && value_front < size)
	{
		N_striing STR(*this);
		for (int i = 0; i < m_size(); i++)
		{
			if (i<value_front) STR.m_erase(i);
		}
		return STR;
	}
	throw "blad! wyjscie poza zakres!";
}
N_striing& operator>>(std::fstream &is, N_striing &C) {
	char variable;
	is >> variable;
	C.m_push_back(variable);
	return C; //nie wiem czy dobrze!!
}
long long N_striing::m_atoi(int variable_start, int variable_stop) {
	int i, j = 0, values = 0;
	if ((variable_start >= 0 && variable_start < size) && (variable_stop >= 0 && variable_stop < size))
	{
		if (variable_start < variable_stop)
		{

			for (i = variable_stop;i >= variable_start;i--)
			{
				values += ((int)Table[i] - 48)*pow(10, j);
				j++;
			}
		}
		else
		{
			for (i = variable_start;i >= variable_stop;i--)
			{
				values += ((int)Table[i] - 48)*pow(10, j);
				j++;
			}
		}
	}
	return values;
}
int N_striing::m_how_long(const char variable[]) {
	int z = 0;
	while(1)
	{
		if (variable[z] == '\0') break;
		z++;
	}
	return z;
}
bool N_striing::m_wchat_char(const char &variable) {
	int i;
	for (i = 0; i < size;i++)
		if (variable == Table[i]) return true;
	return false;
}
bool N_striing::m_wchat_char(const char variable[]) {
	int i, j;
	for (i = 0; i < size;i++) {
		if (variable[0] == Table[i]) {
			for (j = 0; j < m_how_long(variable);j++){
				if (variable[j] == Table[i])j++;
				i++;
			}
			if (j == m_how_long(variable))return true;
		}
	}
	return false;
}
const char* N_striing::m_c_str(){ //nie dziala!!!
	char* D = new char[1+size];
	int i;
	for ( i= 0; i < size;i++)
	{
		D[i] = Table[i];
	}
	D[size] = '\0'; //eureka dziala!!:)
	return D;
}
N_striing& N_striing::m_getline(std::ifstream &is) {
	char values[256]; 
	bool what = false;
		is.getline(values, 256);
		m_push_back(values);
	return *this;
}
bool N_striing::operator>(N_striing &C) {
	int i = 0;
	if (C.size == 0 && size > 0) return true;
	else if (size == 0 && C.size > 0) return false;
	else if (Table[i] > C.Table[i]) return true;
	else if (Table[i] < C.Table[i]) return false;
	else
	{
		if (size <= C.size) {
			for (i = 0; i < size; i++)
			{
				if (Table[i] > C.Table[i]) { return true;  break; }
				else if (Table[i] < C.Table[i]) { return false; break; }
			}
		}
		else if (size > C.size) {
			for (i = 0; i < C.size; i++)
			{
				if (Table[i] > C.Table[i]) { return true;  break; }
				else if (Table[i] < C.Table[i]) { return false; break; }
			}
		}
		return false;
	}
}
bool N_striing::operator<(N_striing &C) {
	int i = 0;
	if (C.size == 0 && size > 0) return false;
	else if (size == 0 && C.size > 0) return true;
	else if (Table[i] < C.Table[i]) return true;
	else if (Table[i] > C.Table[i]) return false;
	else
	{
		if (size <= C.size) {
			for (i = 0; i < size; i++)
			{
				if (Table[i] < C.Table[i]) { return true;  break; }
				else if (Table[i] > C.Table[i]) { return false; break; }
			}
		}
		else if (size > C.size) {
			for (i = 0; i < C.size; i++)
			{
				if (Table[i] < C.Table[i]) { return true;  break; }
				else if (Table[i] > C.Table[i]) { return false; break; }
			}
		}
		return false;
	}
}