#include <iostream>

int main()

{
	setlocale(LC_ALL, "Russian");

	int massive[4] = { 0,4,9,10 };
	int mas_s = std::size(massive);
	unsigned int bank = 0;

	// запаковка ЗЕРКАЛЬНАЯ
	for (int l = 0; l < std::size(massive); l++)
	{
		bank = bank | massive[l]; // закидываем в "хранилище" двоичную запись числа из массива 0000 0000
		if (l < (std::size(massive) - 1)) // чтобы  не ушло за край массива в следущем условии
		{
			bank = bank << 4; // 4 нуля справа
		}
	}

	// распаковка
	for (int y = std::size(massive)-1; y >= 0; y--)
	{
		int current_num = ((bank << (32 - 4) >> (32 - 4)));
		bank = bank >> 4;
		std::cout << current_num << ' ';
	}

}







/*
Как известно, минимальный размер памяти, который мы можем прочитать, составляет 1 байт. Но иногда встречаются задачи, когда данные не такие большие, и даже 1 байта для них может быть много. Придумайте механизм упаковки нескольких значений в 1 байт.
Такой подход позволяет уменьшить размер используемой памяти и может быть полезен, например, при передаче данных по радиосвязи.

Порядок выполнения:
1.	Определите минимальное количество бит на число. Если получается так, что в 1 байт вы можете записать 2.5 числа, например, то задействуйте 2 байта.
2.	Разработайте операции добавления и извлечения чисел.

Вариант 1.
Целые числа от 0 до 10.

10 -> (2 vid) -> 1010 (4 БИТА) 

int -> 4 байта
1 байт -> 8 бит (в двоичном виде) 

*/

