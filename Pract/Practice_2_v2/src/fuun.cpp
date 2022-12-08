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

	std::string Sum(std::string A, std::string B)
	{
		vm::Compliter(&A, &B);
		std::string C;
		A = "0" + A;
		B = "0" + B;
		C = A;
		int raz_dop;
		int overful = 0;
		for (int x = A.length() - 1; x >= 0; x = x - 1)
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
	std::string SmallMulti(std::string A, std::string B)
	{
		std::string C,SmallTempString;
		C = "";
		SmallTempString = "";
		int b = stoi(B);
		int k = A.length() - 1;  // Number of Digits in "big" number
		for (int y = A.length() - 1; y > -1; y--)
		{
			SmallTempString += ((std::to_string((int(A[y]) - 48) * b)));
			for (int f = y; f < k; f++)
			{
				SmallTempString += "0";
			};
			C = Sum(C, SmallTempString);
			SmallTempString = "";
		}
		return C;
	};
	std::string BigMulti(std::string A, std::string B)
	{
		std::string C,K, TempString;
		TempString = "";
		Compliter(&A, &B);
		int z = A.length() - 1;
		for (int b = z; b > - 1; b--)
		{
			TempString += B[b];
			K = SmallMulti(A, TempString);
			for (int f = b; f < z; f++)
			{
				K += "0";
			};
			C = Sum(C, K);
			TempString = "";
		}
		return C;
	}
}