#include <iostream>
#include <string>
/*Реализуйте класс String для работы со строками. Понятное дело, что std::string для реализации использовать нельзя, только char.

У вас должны быть реализованы:
1.	Базовый конструктор                                      +++
2.	Конструктор копирования (правило 3-х)                    +++
3.	Оператор присваивания копированием (правило 3-х)         +++
4.	Деструктор (правило 3-х)                                 +++
5.	Операторы + и +=                                         +++
6.	Оператор [] – чтение и изменение элемента                +++
7.	Операторы <, >, ==                                       +++
8.	Операторы ввода и вывода в поток                         +++
9.	Метод find – поиск первого вхождения символа в строку слева +++
10.	 Метод length – длина строки                             +++
11.	 Метод c_str – получить массив char                      +++
12.	 Метод at для получения доступа (чтение и изменение) к элементу строки с проверкой на выход за пределы строки +++
*/


class String
{
private:
	size_t m_size = 0;
	char* m_str = nullptr;
public:
	//my dudes
	friend std::ostream& operator<< (std::ostream& out, const String& x);
	friend std::istream& operator>> (std::istream& in, String& x);



	 /// standart constr + warned constr
	explicit String(const char* words): m_size( strlen(words)), m_str(new char[m_size+1]) // sentence
	{
		std::copy(words, words + m_size, m_str);
		m_str[m_size] = 0;  //for termSym
	};

	String(int y, unsigned int x) = delete; // warned

	explicit String(char letter, unsigned int x)  // one letter->string
	{
		m_size = x;
		m_str = new char[x + 1];
		std::fill(m_str, m_str + x, letter);
		m_str[m_size] = 0; //for termSym

	}
	///
	
	/// rull of 3
	String(const String& other): String(other.m_str) //copy constr (!) + delig constr
	{}

	String& operator= (const String other) // copy assigment operator
	{
		String temp = other;
		std::swap(this->m_size,temp.m_size);
		std::swap(this->m_str, temp.m_str);
		return *this;
	}


	~String() // destructor
	{
		if (m_str != nullptr) { delete[] m_str; }
	}

	///

	void Print() // just printing
	{
		for (int i = 0; i < m_size; i++) { std::cout << m_str[i]; }
		std::cout<<std::endl;
	}

	String& operator += (const String other)
	{
		unsigned int new_lenght = this->m_size + other.m_size;
		String temp('w', new_lenght);
		for (int x = 0; x < this->m_size; x++) { temp.m_str[x] = this->m_str[x];}
		for (int y = 0; y < this->m_size; y++) { temp.m_str[y+ this->m_size] = other.m_str[y];}
		std::swap(temp.m_size, this->m_size);
		std::swap(temp.m_str, this->m_str);
		return *this;
	}
	String operator + ( String other)
	{
		String copy_temp2 = other;
	    String copy_temp1 = *this;
		copy_temp1+=copy_temp2;
		return copy_temp1;
		
	}

	String operator + (char other)
	{
		String copy_temp2 (other,1);
		String copy_temp1 = *this;
		copy_temp1 += copy_temp2;
		return copy_temp1;
	}

	char& operator [] (unsigned int x)
	{
		return (this->m_str[x]);
	}

	bool operator > ( String other) 
	{
		if (this->m_size < other.m_size) { return false; }
		if (this->m_size > other.m_size) {return true; }
		if (this->m_size == other.m_size)
		{ 
			for (int u = 0; u < this->m_size; u++)
			{
				if (int(this->m_str[u]) > int(other.m_str[u])) { return true; }
				if (int(this->m_str[u]) < int(other.m_str[u])) { return false; }
				if (int(this->m_str[u]) == int(other.m_str[u])) { continue;}
			}
			return false;
		}
	}

	bool operator < (String other) 
	{
		if (this->m_size > other.m_size) { return false; }
		if (this->m_size < other.m_size) { return true; }
		if (this->m_size == other.m_size)
		{
			for (int u = 0; u < this->m_size; u++)
			{
				if (int(this->m_str[u]) < int(other.m_str[u])) { return true; }
				if (int(this->m_str[u]) > int(other.m_str[u])) { return false; }
				if (int(this->m_str[u]) == int(other.m_str[u])) { continue; }
			}
			return false;
		}
	}

	bool operator == (String other)
	{
		if (this->m_size == other.m_size)
		{
			for (int u = 0; u < this->m_size; u++)
			{
				if (int(this->m_str[u]) != int(other.m_str[u])) { return false; }
			}
			return true;
		}
	}

	int find(char x)
	{
		for (int c = 0; c < m_size; c++)
		{
			if (m_str[c] == x) { return c; };
		}

		std::cout << "Error! Not found!"<< std::endl;
		return (-1);
		
	}

	int lenght()
	{
		return m_size;
	}

	char* c_str()
	{
		return m_str;
	}

	char& at(unsigned int index)
	{
		if ((this->m_size) > index+1)
		{
			return (this->m_str[index]);
		}
		else
		{
			std::cout << "Error! String is out of range!" << std::endl;
			std::abort();
		}
		
	}

};

std::ostream& operator<< (std::ostream& out, const String& x)
{
	for (int y = 0; y < x.m_size; y++)
	{
		out << x.m_str[y];
	}
	return out;
}

std::istream& operator>> (std::istream& in, String& p)
{
	for (int y = 0; y < p.m_size; y++)
	{
		in >> p.m_str[y];
	}
	return in;
}


int main()
{
    String s1("Hellppppo");
	String s2('C', 15 );
	String s3('c', 15);
	s1.Print();
	s2.Print();
	s3.Print();
    //s2 = s1 = s3;
	s1.Print();
	s2.Print();
	s3.Print();
	String s4("ww.com");
	s1 = s3 + s4 + 'p';
	s3.Print();
	s4.Print();
	s1.Print();
	std::cout << "Read and editing check" << std::endl;
	std::cout << s2[0]  << std::endl;
	s2.Print();
	bool x = (s2 == s3);
	std::cout << x << std::endl ;
	s1.Print();
	std::cout << s1 << std::endl;
	//std::cin >> s1;
	//std::cout << s1.find('r') << std::endl;
	std::cout << s2.lenght() << std::endl;
	s2.at(0) = 'q';
	s2.Print();
}
