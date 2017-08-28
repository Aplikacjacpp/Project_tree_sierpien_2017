/*N_vektor();
N_vektor(int i);
N_vektor(const N_vektor &V);
N_vektor& operator=(const N_vektor &V);
bool operator==(const N_vektor &V);
T operator[](int values);
N_vektor& m_push_back(T inside);
N_vektor& m_push_front(T inside);
N_vektor& m_pop_back();
N_vektor& m_pop_front();
N_vektor& m_insert(int value, T inside);
N_vektor& m_erase(int value);
N_vektor& m_close();
int m_size();
~N_vektor(); */

#ifndef N_VEKTOR_H
#define N_VEKTOR_H
#include <iostream>
#include <cstdlib> //mozliwe ze nie potrzebne:p
template <typename T> class N_vektor
{
public:
N_vektor() {
		Size = 0;
		Tab = new T[1];
	}
N_vektor(int i) {
		if (i >= 1)
		{
			Size = i;
			Tab = new T[Size];
		}
		else
		{
			Size = 0; //mozna dodac wyjatek!
			Tab = new T[1];
		}
	}
N_vektor(const N_vektor &V) {
		if (this != &V) *this = V;
	}
N_vektor& operator=(const N_vektor &V) {
		if (this == &V) return *this;
		if (*this == V) return *this;
		if (Size == 0 || Tab == NULL)
		{
			this->~N_vektor();
			int i;
			Size = V.Size;
			this->Tab = new T[Size];
			for (i = 0; i < Size; i++)
			{
				this->Tab[i] = V.Tab[i];
			}
			return *this;
		}
		else
		{
			int i;
			this->m_close();
			Size = V.Size;
			this->Tab = new T[Size];
			for (i = 0; i < Size; i++)
			{
				this->Tab[i] = V.Tab[i];
			}
			return *this;
		}
	}
bool operator==(const N_vektor &V) {
		if (this->Size == V.Size)
		{
			int i;
			for (i = 0; i < Size; i++)
			{
				if (Tab[i] != V.Tab[i]) return false; 
			}
			return true;
		}
		return false;
	}
bool operator!=(const N_vektor &V) { //poprawione mam nadzieje ze na lepsze
	if (this->Size != V.Size)
	{
		int i;
		for (i = 0; i < Size; i++)
		{
			if (Tab[i] != V.Tab[i]) return true; 
		}
		return false;
	}
	return false;
}
	T operator[](int values)
	{
		return Tab[values];
	}
N_vektor& m_push_back(T inside) {
		int i;
		if (this->Size == 0 || this->Tab == NULL)
		{
			this->m_close();
			this->Size = 1;
			this->Tab = new T[Size];
			for (i = 0; i < Size; i++)
			{
				Tab[i] = inside;
			}
			return *this;
		}
		N_vektor C(*this);
		this->m_close();
		this->Size = 1 + C.Size;
		this->Tab = new T[Size];
		for (i = 0; i < Size - 1; i++)
		{
			Tab[i] = C.Tab[i];
		}
		Tab[Size - 1] = inside;
		return *this;
	}
N_vektor& m_push_front(T inside) {
		int i;
		if (this->Size == 0 || this->Tab == NULL)
		{
			this->m_close();
			this->Size = 1;
			this->Tab = new T[Size];
			for (i = 0; i < Size; i++)
			{
				Tab[i] = inside;
			}
			return *this;
		}
		N_vektor C(*this);
		this->m_close();
		this->Size = 1 + C.Size;
		this->Tab = new T[Size];
		this->Tab[0] = inside;
		for (i = 0; i<C.Size; ++i)
		{
			this->Tab[(i + 1)] = C.Tab[i];
		}
		return *this;
	}
N_vektor& m_pop_back() {
		m_erase(m_size() - 1);
		return *this;
	}
N_vektor& m_pop_front() {
		m_erase(0);
		return *this;
	}
N_vektor& m_pop(int i) {
	m_erase(i);
	return *this;
}

N_vektor& m_erase(N_vektor<int>& myNumbers_in, int number_in)
{
	std::N_vektor<int>::iterator iter = myNumbers_in.begin();
	while (iter != myNumbers_in.end())
	{
		if (*iter == number_in)
		{
			iter = myNumbers_in.erase(iter);
		}
		else
		{
			++iter;
		}
	}

}


N_vektor& m_insert(int value, T inside) {
		if (value >= 0 && value < Size)
		{
			int i, j = 0;;
			N_vektor STR(*this);
			this->m_close();
			Size = STR.Size;
			Tab = new T[(++Size)];
			for (i = 0; i < Size; i++)
			{
				if (i == value)
				{
					Tab[i] = inside;
					continue;
				}
				Tab[i] = STR.Tab[j];
				j++;
			}
		}
		return *this;
	}
N_vektor& m_erase(int value) {
		if (value >= 0 && value < Size)
		{
			int j, i = 0;
			N_vektor C(*this);
			this->m_close();
			Size = C.Size;
			Tab = new T[(--Size)];
			for (j = 0; j < (Size + 1); j++)
			{
				if (j == value) continue;
				Tab[i] = C.Tab[j];
				i++;
			}
			return *this;
		}
		return *this;
	}
N_vektor m_close() {
		N_vektor<T> V;
		this->~N_vektor();
		return V;
	}
int m_size() {	return Size;}
virtual ~N_vektor() {
		if (Tab) {
			delete[] Tab;
			Tab = NULL;
			Size = NULL;
		}
	}
private:
	int Size = NULL;
	T* Tab = NULL;
};
#endif // !N_VEKTOR_H