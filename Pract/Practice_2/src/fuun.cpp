#include <string>
#include "fuun.hpp"
#include <iostream>
namespace vm
{
	void Compliter(std::string* A, std::string* B)
	{
		int Asize = (*A).length();
		int Bsize = (*B).length();
		int Raz = abs(Asize - Bsize);
		if (Asize > Bsize)
		{
			for (int x = 0; x < Raz; x++) { (*B) = "0" + (*B); }
		}
		if (Asize < Bsize)
		{
			for (int x = 0; x < Raz; x++) { (*A) = "0" + (*A); }
		}
	};

	/*void BiggestNumGoFirst(std::string* A, std::string* B)
	{
		std::string C;
		int Asize = (*A).length();
		int Bsize = (*B).length();
		if (Asize < Bsize) {std::swap(*A, *B);}
		if (Asize == Bsize)
		{

		}
	}*/

	std::string Sum(std::string A, std::string B)
	{
		vm::Compliter(&A, &B);
		std::string C;
		A = "0" + A;
		B = "0" + B;
		C = A;
		int raz_dop;
		int overful = 0;
		for (int x = A.length(); x >= 0; x = x - 1)
		{
			int c = 0;
			int a = int(A[x]) - 48;
			int b = int(B[x]) - 48;
			raz_dop = 0;
			if (overful != 0) { c = overful; }
			overful = 0;
			if ((a + b) >= 10) { raz_dop = ((a + b + c) % 10); overful = ((a + b) / 10); }
			if ((a + b) < 10) { raz_dop = (a + b + c); }
			C[x] = char(raz_dop + 48);
		}
		return C;
	};

	void Separator(std::string* Separator_mas, std::string Y)
	{
		std::string G = Y;

		for (int x = 0; x < Y.length(); x++)
		{
			Separator_mas[x] = G[G.length() - x - 1];
		}
	};

	/*long long SizeOfMass(std::string A, std::string B)
	{
		long long ranks = (A.length()) * (B.length());
		return ranks;
	};*/ 



	/*std::string Multi(std::string& A, std::string& B)
	{
		std::string C;
		std::string sep_mas_a[1000];
		std::string sep_mas_b[1000];
		std::string sub_sum_massive[100];
		int ranks = (A.length()) * (A.length());
		for (int x = 0; x < ranks; x++)
		{
			A = "0" + A;
			B = "0" + B;
		}
		C = ""; //Строка конечной суммы приравнивается для уравнивания разрядов (взято с лихвой) 
		vm::Separator(sep_mas_a, A);
		vm::Separator(sep_mas_b, B);
		for (int r = 0; r < 1000; r++)
		{
			for (int t = 0; t < 1000; t++)
			{
				//
				int a, b, c;
				std::string teNNer = "";
				a = int(sep_mas_a[t][0]) - 48; //ride
				b = int(sep_mas_b[r][0]) - 48; //fix
				if ((t + r) > 0)
				{
					for (int u = 0; u < (t + r); u++)
					{
						teNNer = "0" + teNNer;
					}
				}
				c = a * b;
				sub_sum_massive[t + r] = std::to_string(c) + teNNer;
				teNNer = "";
			}
		}
		for (int o = 0; o < 1000; o++)
		{
			C = vm::Sum(sub_sum_massive[o], C);
		}
		return C;
	};
	//////
	int a = int(A[length-r-1]) - 48;
			int b = int(B[length-r-1]) - 48;
			if (a == 0) { a = 1; };
			if (b == 0) { b = 1; };
			C[C.length() - r] = char(((a * b + overful) % 10) + 48);
			overful = ((a * b) / 10);
	
	std::string Multi(std::string A, std::string B)
	{
		std::string C = "";
		int sub_sum_massive[1001];

		int overful = 0;
		int ranks = (A.length()) * (A.length());
		for (int x = 0; x < ranks; x++)
		{
			C = "0" + C;
		} 
		int length = A.length();
		for (int k = 0; k < 1001; k++)
		{
			sub_sum_massive[k] = 0;
		}
		// развёртка числа С
		int position;
		for (int y = 0; y < length; y++)
		{
			position = y;
			int c = 0;
			int prev_a = 0;
			if (y != 0) { prev_a = int(A[length - y - 2]) - 48; }
			int a = int(A[length-y-1]) - 48;
			for (int z = 0; z < position+1; z++)
			{
				int b = int(B[B.length() - z-1]) - 48;
				c += b * a;
			}
			sub_sum_massive[1000 - y] = c;
		}
		// 
		int ooverful = 0;
		for (int j = 0; j < 1000; j++)
		{
			sub_sum_massive[1000 - j] = (sub_sum_massive[1000 - j] + ooverful) % 10;
			ooverful = ((sub_sum_massive[1000 - j] + ooverful) / 10);
		}
		for (int r = 0; r < C.length(); r++)
		{
			C[C.length() - r -1] = char(((sub_sum_massive[1000 - r]) + 48));
		}
		return C;
	};*/

	std::string Multi(std::string A, std::string B)
	{
		std::string C;
		std::string sep_mas_a[1000];
		std::string sep_mas_b[1000];
		std::string sub_sum_massive[1000];
		std::string work_pony[1000];
		for (int t = 0; t < 1000; t++)
		{
			sub_sum_massive[t] = "0";
			work_pony[t] = "0";
			sep_mas_a[t] = "0";
			sep_mas_b[t] = "0";
		}
		int ranks = (A.length()) * 2 + 1;
		C = "";
		for (int x = 0; x < ranks; x++) { C = "0" + C; }
		vm::Separator(sep_mas_a, A);
		vm::Separator(sep_mas_b, B);
		int counter_pony = 0;
		for (int sub = 0; sub < 1000; sub++)
		{
			for (int pony = 0; pony < 1000; pony++)
			{
				work_pony[pony] = std::to_string((std::stoll(sep_mas_b[sub]) * ((std::stoll(sep_mas_a[pony])))));
				for (int v = 0; v < pony; v++)
				{
					if (work_pony[pony] != "0")
					{
						work_pony[pony] = work_pony[pony] + "0";
					}
				}
			}
			for (int v = 0; v < 1000; v++)
			{
				sub_sum_massive[sub] = Sum(sub_sum_massive[sub], work_pony[v]);
				if (work_pony[v] == "0") { break; }
			}
		}
		// ^errrrroooorr^ утечка времени

		int ooverful = 0;
		std::string helper;
		for (int j = 0; j < 1000; j++)
		{
			helper = sub_sum_massive[j];
			sub_sum_massive[ j] = std::to_string((std::stoll(sub_sum_massive[j]) + ooverful) % 10);
			ooverful = ((std::stoll(helper) + ooverful) / 10);
		}
		for (int r = 0; r < C.length()-1; r++)
		{
			C[C.length()-r-1] = sub_sum_massive[r][0];
		}
		return C;
	}
}