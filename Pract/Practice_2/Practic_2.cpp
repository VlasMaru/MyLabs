#include <iostream>
#include <iostream>
#include <string>
#include "fuun.hpp"

int main()
{
    std::string A, B, choose, L;
    std::cout << "Print 'X' if you want to use Multi or 'Y' if you want to use Sum :" << std::endl;
    std::cin >> choose;
    std::cout << "Enter your numbers: " << std::endl;
    std::cout << "A : " << std::endl;
    std::cin >> A;
    std::cout << "B : " << std::endl;
    std::cin >> B;
    vm::Compliter(&A, &B);
   
    if (choose == "X")
    {
        std::cout << "Result: " << std::endl;
        std::cout << vm::Multi(A, B) << std::endl; 
    }
    if (choose == "Y")
    {
        std::cout << "Result: " << std::endl;
        std::cout << vm::Sum(A, B) << std::endl;
    }

 
    
    // my Lord...
    
   
    //std::string masi[1000];
    //std::string H = "123456788";
    //vm::Separator(masi,H);
    //long long g = vm::SizeOfMass(A,B);
    //for (int c = 0; c < 1000; c++) { std::cout << masi[c]<< " "; }
}


