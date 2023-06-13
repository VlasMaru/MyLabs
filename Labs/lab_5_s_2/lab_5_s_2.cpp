/*Лабораторная работа №5
«Вектор bool»

Реализуйте спецификацию шаблона для вектора из булевских значений. Помните, что на каждое значение должен быть потрачен только 1 бит памяти.
Предусмотрите следующие операции:
1.	Метод добавления в конец вектора
2.	Метод и оператор получения и изменения значения по индексу
3.	Метод size
4.	Метод insert и erase

Продемонстрируйте работу с классом.
*/

#include <iostream>
#include <cmath>
#include <string>

template <typename my_type>
class vector
{
};

template<>
class vector <bool>
{
private:
	size_t m_mas_size_t;
	char* m_masbol = new char[m_mas_size_t];
	int bit_size;
public:

	vector<bool>(bool masbol, size_t size) :bit_size(size), m_mas_size_t((bit_size / 8) + int(bool(bit_size % 8)))
	{
		for (int x = 0; x < m_mas_size_t; x++)
		{
			m_masbol[x] = 0x00;
			for (int y = 0; y < 8; y++)
			{
				m_masbol[x] | masbol;
				m_masbol[x] << 1;
			}
		}

	};

	vector<bool>(std::string boolmas) :bit_size(boolmas.length()), m_mas_size_t((boolmas.length() / 8) + int(bool(boolmas.length() % 8)))
	{
		bool* templ = new bool[bit_size];
		for (int x = 0; x < bit_size; x++)
		{
			if (boolmas[x] == 't') { templ[x] = true; }
			if (boolmas[x] == 'f') { templ[x] = false; }
		}

		int counter = 0;
		for (int x = 0; x < m_mas_size_t; x++)
		{
			m_masbol[x] = 0x00;
			if (counter == bit_size) { break;}
			for (int y = 0; y < 8; y++)
			{
				m_masbol[x] = m_masbol[x] & 254;
				m_masbol[x] = m_masbol[x] | templ[counter];
				counter++;
				if (counter == bit_size) { break; }
				m_masbol[x] = m_masbol[x] << 1;
				
			}
		}

	}

	~vector<bool>() { delete[]  m_masbol; };


	std::string return_v()
	{
		std::string show = "";
		std::string mir_show = "";
		char* temp_masbol = new char[this->m_mas_size_t]; //\\

		std::copy(this->m_masbol, this->m_masbol+ this->m_mas_size_t-1, temp_masbol); //

		char ed = 1;
		int counter = -1;
		char cur;

		for (int y = 0; y < this->m_mas_size_t; y++)
		{
			if (counter == bit_size) { break; }
			for (int x = 0; x < 8; x++)
			{
				if (counter == bit_size) { break; }
				if ((y == 0)) { x++;}
				std::cout << "FD   " << int(temp_masbol[y]) << "  DF   ";
				cur = temp_masbol[y] & ed;
				temp_masbol[y] = temp_masbol[y] >> 1;
				if (cur == 1) { show += 't'; };
				if (cur == 0) { show += 'f'; };
				counter++;

			}
		}
		for (int g = show.length(); g >= 0; g--)
		{
			mir_show += show[g];
		}
		delete[] temp_masbol;
		return mir_show;
		

	}

	void printv()
	{
		std::cout << return_v() << std::endl;
	}

	void push_back(bool x)
	{
		std::string new_string = this->return_v();
		std::cout << "String:" << (this->return_v()) << std::endl;
		char new_obj;
		if (x == true) { new_obj = 't';}
		if (x == false) { new_obj = 'f';}
		new_string += new_obj;
		//std::cout << "String:" << new_string <<std::endl;
		vector <bool> templ(new_string); /////////
		std::swap(this->bit_size,templ.bit_size);
		std::swap(this->m_masbol, templ.m_masbol);
		std::swap(this->m_mas_size_t, templ.m_mas_size_t);
	}



};


//реализуй перегруз [] (умножением побитовым на 1 и последующим сдвигом)






int main()
{

	vector <bool> vecc("tfffttttff"); 
	vecc.printv();
	//vecc.push_back(false);
	//vecc.printv();
}
