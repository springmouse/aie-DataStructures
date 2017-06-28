#include "UnitTester.h"
#include <Stack.h>
#include <List.h>
#include <DynamicArray.h>
#include <iostream>


List<int> test = List<int>(); /*the list we will test*/

DynamicArray<int> arrayTest = DynamicArray<int>(100);

/*
* Function: TestListEle
* ---------------------
*
* this test if the elemet in the position of the list is the same as the one
* passed in to the function
*
* Parameters: this takes in const char * mes used if the resault is false
*	int elePos the position in the list that we want to check against
*	int checkAgainst the value we want to check against
*
* returns: returns bool to see if it passed or not
*/
bool TestListEle(const char * mes, int elePos, int checkAgainst)
{
    if (test.GetElemeantAt(elePos) == checkAgainst)
    {
        return true;
    }

	//message to send if failed
    std::cout << mes << ": Elemeant at position " << elePos<< " = " << test.GetElemeantAt(elePos) << " =/= " << checkAgainst << "\n";
    return false;
}

//the define to be used through out the tester to test the list
#define TESTLIST(a, b, c) {if(TestListEle(a,b,c) == false) {return false;}}

/*
* Function: ListTester
* --------------------
*
* this runs all the functions to test against the list
*
* Parameters: this takes in no parameters
*
* returns: returns bool to see if the list passed or not 
*/
bool ListTester(); 

//runs through all the test we need and is called by the main
//returns true if all tests passed
bool RunUnitTester()
{
    if (ListTester() == false)
    {
        std::cout << "List Failed \n\n";
        return false;
    }



    return true;
}

#pragma region ListTesterFunctions

/*
* Function: CheckPopFunctions
* ---------------------------
*
* checks the lists pop functions
*
* Parameters: this takes in no parameters
*
* returns: returns a bool to see if the list passed or not
*/
bool CheckPopFunctions();

/*
* Function: TestRemoveFunction
* ---------------------------
*
* checks the lists remove function
*
* Parameters: this takes in no parameters
*
* returns: returns a bool to see if the list passed or not
*/
bool TestRemoveFunction();

/*
* Function: RemoveAllFunction
* ---------------------------
*
* checks the lists remove all function
*
* Parameters: this takes in no parameters
*
* returns: returns a bool to see if the list passed or not
*/
bool RemoveAllFunction();

/*
* Function: GetElemeantAndChangeFunctions
* ---------------------------------------
*
* checks the lists to see if we can get a specific elemeant and change it
*
* Parameters: this takes in no parameters
*
* returns: returns a bool to see if the list passed or not
*/
bool GetElemeantAndChangeFunctions();

/*
* Function: InsertAtFunction
* --------------------------
*
* checks the lists to see if we can insert something in a specific location of the list
*
* Parameters: this takes in no parameters
*
* returns: returns a bool to see if the list passed or not
*/
bool InsertAtFunction();

//checks all the functions above to see if the list is working as intended
bool ListTester()
{

    if (CheckPopFunctions() == false)
    {
        return false;
    }

    if (TestRemoveFunction() == false)
    {
        return false;
    }

    if (RemoveAllFunction() == false)
    {
        return false;
    }

    if (GetElemeantAndChangeFunctions() == false)
    {
        return false;
    }
    
    if (InsertAtFunction() == false)
    {
        return false;
    }

    return true;
}

//checks pop function
bool CheckPopFunctions()
{
	//add elemeants to the list
    test.PushBack(11);
    test.PushBack(9);
    test.PushBack(5);
    test.PushBack(4);
    test.PushBack(6);

	//pop elemeants off
    test.PopBack();
    test.PopFront();

	//first check that the list is the right size
    if (test.GetLength() != 3)
    {
        std::cout << "List Pop Functions failed \n" << "The List is the wrong Size!!! \n";
        return false;
    }

	//check if elemeants are in the right posistion
    TESTLIST("Pop Functions", 0, 9);
    TESTLIST("Pop Functions", 1, 5);
    TESTLIST("Pop Functions", 2, 4);

	//assuming all the above returned true we passed and return true
    return true;
}

//test remove functions
bool TestRemoveFunction()
{
	//remove elemeants from the array
    test.Remove(4);
    test.Remove(9);

	//add some new ones
    test.PushFront(100);
    test.PushFront(111);
    test.PushFront(112);
    test.PushFront(123);

	//remove another
    test.Remove(112);

	//check that the list is the right size
    if (test.GetLength() != 4)
    {
        std::cout << "List Remove Functions failed \n" << "The List is the wrong Size!!! \n";
        return false;
    }

	//check that we have the right elemeants in the right positions
    TESTLIST("Remove Function", 0, 123);
    TESTLIST("Remove Function", 1, 111);
    TESTLIST("Remove Function", 2, 100);
    TESTLIST("Remove Function", 3, 5);

	//assuming all the above returned true we passed and return true
    return true;
}

bool RemoveAllFunction()
{
	//add some new elemeants
    test.PushBack(10);
    test.PushBack(10);

    test.PushFront(10);
    test.PushFront(10);

	//checks list is the right size and things where added correctly
    if (test.GetLength() != 8)
    {
        std::cout << "List Remove Functions failed \n" << "The List is the wrong Size!!! \n";
        return false;
    }

	//make sure every thing is in the right positioon
    TESTLIST("RemoveAll Function", 0, 10);
    TESTLIST("RemoveAll Function", 1, 10);
    TESTLIST("RemoveAll Function", 2, 123);
    TESTLIST("RemoveAll Function", 3, 111);
    TESTLIST("RemoveAll Function", 4, 100);
    TESTLIST("RemoveAll Function", 5, 5);
    TESTLIST("RemoveAll Function", 6, 10);
    TESTLIST("RemoveAll Function", 7, 10);

	//removes all 10 from the list
    test.RemoveAll(10);

	//make sure list is the right size
    if (test.GetLength() != 4)
    {
        std::cout << "List Remove Functions failed \n" << "The List is the wrong Size!!! \n";
        return false;
    }

	//make sure things are where they should be
    TESTLIST("RemoveAll Function", 0, 123);
    TESTLIST("RemoveAll Function", 1, 111);
    TESTLIST("RemoveAll Function", 2, 100);
    TESTLIST("RemoveAll Function", 3, 5);

	//assuming all the above returned true we passed and return true
    return true;
}

bool GetElemeantAndChangeFunctions()
{
	//gets an elemeants from the list
    int & foo = test.Last();
	int & testlingz = test.First();
	int & blargh = test.GetElemeantAt(2);

	//changes the elemeants
    foo = 10110;
    testlingz = 777;
    blargh = 66;

	//checks the list is still the right size
    if (test.GetLength() != 4)
    {
        std::cout << "List Remove Functions failed \n" << "The List is the wrong Size!!! \n";
        return false;
    }

	//checks the elemeants are in the right position with the right vlaue
    TESTLIST("GetElemeantAndChange Functions", 0, 777);
    TESTLIST("GetElemeantAndChange Functions", 1, 111);
    TESTLIST("GetElemeantAndChange Functions", 2, 66);
    TESTLIST("GetElemeantAndChange Functions", 3, 10110);

	//assuming all the above returned true we passed and return true
    return true;
}

bool InsertAtFunction()
{
	//inserts new values in the list at certin locations
    test.InsertAtPosition(0, 88);

    test.InsertAtPosition(1, 123);

    test.InsertAtPosition(2, 9001);

    test.InsertAtPosition(test.GetLength(), 123);

	//checks the list is the right length
    if (test.GetLength() != 8)
    {
        std::cout << "List Remove Functions failed \n" << "The List is the wrong Size!!! \n";
        return false;
    }

	//checks everything is where it is meant to be
    TESTLIST("InsertAt Function", 0, 88);
    TESTLIST("InsertAt Function", 1, 123);
    TESTLIST("InsertAt Function", 2, 9001);
    TESTLIST("InsertAt Function", 3, 777);
    TESTLIST("InsertAt Function", 4, 111);
    TESTLIST("InsertAt Function", 5, 66);
    TESTLIST("InsertAt Function", 6, 10110);
    TESTLIST("InsertAt Function", 7, 123);

	//assuming all the above returned true we passed and return true
    return true;
}

#pragma endregion

#pragma region DynamicArrayFunctions

bool DynamicArrayTester()
{

    return true;
}

#pragma endregion