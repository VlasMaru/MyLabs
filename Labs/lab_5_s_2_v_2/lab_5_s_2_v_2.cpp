#include<iostream>
#include<vector>

/*
Реализуйте спецификацию шаблона для вектора из булевских значений. Помните, что на каждое значение должен быть потрачен только 1 бит памяти.
Предусмотрите следующие операции :
1.	Метод добавления в конец вектора
2.	Метод и оператор получения и изменения значения по индексу
3.	Метод size															+
4.	Метод insert и erase

Продемонстрируйте работу с классом.

*/

template <typename T>
class vector
{

};

template<>
class vector<bool>
{
private:

	size_t m_size = 0;
	char* m_vec = new char[m_bytes];
	size_t m_bytes = 0;

public:

	vector<bool>() = default;

	vector(const vector<bool>& other)
	{
		vector<bool> tmp;
		std::swap(tmp.m_vec, m_vec);
		m_size = tmp.m_size;
	}


	vector<bool>& operator= (const vector<bool>& copy)
	{
		vector<bool> temp;
		std::swap(temp.m_vec, m_vec);
		m_size = temp.m_size;

		return *this;
	}

	bool operator[](size_t ind) const
	{
		return static_cast<bool>(((m_vec[ind / 8]) >> ind) & 0b00000001);
	}

	void Reduct(size_t ind, bool el)
	{
		char digit = 1;

		for (int i = 0; i < ind; i++)
		{
			digit *= 2;
		}
		if (el)
		{
			int byte_ind = ind / 8; // находим индекс байта в массиве
			m_vec[byte_ind] |= digit; // устанавливаем бит, используя оператор побитового ИЛИ с маской digit
		}
		else
		{
			int byteIndex = ind / 8; // находим индекс байта в массиве
			m_vec[byteIndex] &= ~digit; // сбрасываем бит, используя оператор побитового И с инвертированной маской ~digit
		}
	}

	void Push_Back(bool el)
	{
		if (m_size % 8 == 0)
		{
			char* temp = new char[(m_size / 8) + 1];
			for (int i = 0; i < m_size; i++)
			{
				temp[i] = m_vec[i];
			}
			delete[] m_vec;
			m_vec = temp;
			Reduct(m_size, el);
		}
		else
		{
			Reduct(m_size, el);
		}

		m_size++;
	}

	void Insert(size_t index, bool  value)
	{
		Push_Back(operator[](m_size - 1));
		for (size_t i = m_size; i != index; i--)
		{
			Reduct(i, operator[](i - 1));
		}

		Reduct(index, value);
	}

	void Erase(size_t ind1, size_t ind2)
	{
		for (size_t i = ind2; i < m_size; i++)
		{
			Reduct(i - (ind2 - ind1), operator[](i));
		}
		m_size = m_size - (ind2 - ind1);
	}

	void Erase(size_t ind)
	{
		for (size_t i = ind; i < m_size - 1; i++)
		{
			Reduct(i, operator[](i + 1));
		}
		m_size--;
	}

	size_t Size()
	{
		return this->m_size;
	}

	void Print()
	{
		for (int i = 0; i < this->Size(); i++)
		{
			std::cout << this->operator[](i) << " ";
		}
	}

	~vector<bool>()
	{
		delete[]m_vec;
	}
};

int main()
{
	vector<bool> vc;
	vc.Push_Back(1);
	vc.Push_Back(1);
	vc.Push_Back(0);
	vc.Push_Back(1);
	vc.Push_Back(1);

	vc.Insert(4, 0);

	vc.Print();

}