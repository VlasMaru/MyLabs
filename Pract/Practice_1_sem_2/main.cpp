#include <iostream>
#include <string>
#include "Header.hpp"


int main()
{
	
	/*std::cout << " Hello and welcome to FIBICypher! If you want to work with one object on this computer (some text for coding it, checking key etc.), then use code editor and new object. " << std::endl;
	std::cout << "" << std::endl;
	std::cout << "If you want to encode your text, then use .Encode on your object. Enter new key. Now it's connected with this object! If you'll use .Decode on your object, than you'll see your decoded text!"<< std::endl;
	std::cout << "" << std::endl;
	std::cout << "If you have only coded text and correct key from other user - don't be upset - you can decode it with .Encode and your correct key as new key!" << std::endl; ;
	std::cout << "" << std::endl; */



	//test 1 (you want to code your text and decode it on this computer, while this run )
	//FIBICyClass::Cypher s1("Hello my friend, you are welcome!");
	//s1.Encode();
	//s1.ShowText();
	//s1.ShowCurrentKey();
	//s1.Decode();
	//s1.ShowText(); 

	//test 2 (you have only coded text and key (it's 13 8 5 3 2 1) )
	// 
	FIBICyClass::Cypher s2("welcome! are you friend, my Hello");
	s2.Encode();
	s2.ShowText();

}

//Fibonacci numbers: (without the first two (for unambiguous decoding!!!!!!) ):  1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711,...


	