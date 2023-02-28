/*Вам даны два массива длиной N (N – разумно большое число).
Тип данных может быть произвольным. Вам необходимо найти способ скопировать содержимое одного массива в другой наиболее эффективно.
Библиотечные функции использовать нельзя.*/

#include <iostream>

const int N = 10000;

template <typename T>

void FastCopy(T* uk_mas1, T* uk_mas2)
{
	long long* new_ll_mass1 = nullptr;
	long long* new_ll_mass2 = nullptr;
	new_ll_mass1 = reinterpret_cast<long long*> (uk_mas1);
	new_ll_mass2 = reinterpret_cast<long long*> (uk_mas2);

	for (int o = 0; o < (N / 2); o++)
	{
		*new_ll_mass2 = *new_ll_mass1;
		new_ll_mass1++;
		new_ll_mass2++;
	}
	
	char* new_ch_mass1 = nullptr;
	char* new_ch_mass2 = nullptr;
	new_ch_mass1 = reinterpret_cast<char*> (uk_mas1) + (N - (N % 2));
	new_ch_mass2 = reinterpret_cast<char*> (uk_mas2) + (N - (N % 2));

	for (int i = N - (N % 2); i < N; i++)
	{
		*new_ch_mass2 = *new_ch_mass1;
		new_ch_mass1++;
		new_ch_mass2++;
	}

}

int main()
{
	double mas1[N] = { 1.2, 1.8, 2.5 };
	double mas2[N] = {0, 0};
	//std::cout << *mas1 << std::endl;
	FastCopy(mas1, mas2);  // from ... to
	
	for (int x = 0; x < N; x++) { std::cout << mas2[x] <<  ' '; }
}

