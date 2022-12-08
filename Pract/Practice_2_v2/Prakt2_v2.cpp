#include <iostream>
#include <iostream>
#include <string>
#include "fuun.hpp"

int main()
{
    // Menu //
    std::string A, B, choose;
    std::cout << "Print 'X' if you want to use Multi or 'Y' if you want to use Sum :" << std::endl;
    std::cin >> choose;
    if ((choose != "x") && (choose != "X") && (choose != "Y") && (choose != "y"))
    {
        std::cout << "! Input Error !" << std::endl;
        return 36;
    }
    std::cout << "Enter your numbers: " << std::endl;
    std::cout << "A : " << std::endl;
    std::cin >> A;
    std::cout << "B : " << std::endl;
    std::cin >> B;
    vm::Compliter(&A, &B);

    if ((choose == "X") || (choose == "x"))
    {
        std::cout << "Result: " << std::endl;
        std::cout << vm::BigMulti(A, B) << std::endl;
    }
    if ((choose == "Y") || (choose == "y"))
    {
        std::cout << "Result: " << std::endl;
        std::cout << vm::Sum(A, B) << std::endl;
    }
}


// Version without menu
/*std::string A, B;
    std::cin >> A;
    std::cin >> B;
    vm::Compliter(&A, &B);
    //std::cout << vm::Sum(A, B) << std::endl;
    //std::cout << vm::SmallMulti(A, B) << std::endl;
    std::cout << vm::BigMulti(A, B) << std::endl;

*/