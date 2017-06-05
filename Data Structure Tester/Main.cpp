#include <iostream>
#include "UnitTester.h"

int main()
{
    
    if (RunUnitTester() == false)
    {
        std::cout << "Unit test failed!" << std::endl;
        return -1;
    }

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}