#include <iostream>
#include "UnitTester.h"

/*
* Function: main
* --------------
*
* this is the main for the unit tester and runs the unit tester
*
*/
int main()
{
    //runs the unit tester to see if it fails or not
    if (RunUnitTester() == false)
    {
		//displae if failed
        std::cout << "Unit test failed!" << std::endl;
        return -1;
    }

	//displa if passed
    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}