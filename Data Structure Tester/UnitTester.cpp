#include "UnitTester.h"
#include <Stack.h>
#include <List.h>
#include <DynamicArray.h>
#include <iostream>


List<int> test = List<int>();
DynamicArray<int> arrayTest = DynamicArray<int>(100);

bool TestListEle(const char * mes, int elePos, int checkAgainst)
{
    if (test.GetElemeantAt(elePos) == checkAgainst)
    {
        return true;
    }

    std::cout << mes << ": Elemeant at position " << elePos<< " = " << test.GetElemeantAt(elePos) << " =/= " << checkAgainst << "\n";
    return false;
}

#define TESTLIST(a, b, c) {if(TestListEle(a,b,c) == false) {return false;}}

bool ListTester();

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

bool CheckPopFunctions();
bool TestRemoveFunction();
bool RemoveAllFunction();
bool GetElemeantAndChangeFunctions();
bool InsertAtFunction();

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

bool CheckPopFunctions()
{
    test.PushBack(11);
    test.PushBack(9);
    test.PushBack(5);
    test.PushBack(4);
    test.PushBack(6);

    test.PopBack();
    test.PopFront();

    if (test.GetLength() != 3)
    {
        std::cout << "List Pop Functions failed \n" << "The List is the wrong Size!!! \n";
        return false;
    }

    TESTLIST("Pop Functions", 0, 9);
    TESTLIST("Pop Functions", 1, 5);
    TESTLIST("Pop Functions", 2, 4);

    return true;
}

bool TestRemoveFunction()
{
    test.Remove(4);
    test.Remove(9);

    test.PushFront(100);
    test.PushFront(111);
    test.PushFront(112);
    test.PushFront(123);

    test.Remove(112);

    if (test.GetLength() != 4)
    {
        std::cout << "List Remove Functions failed \n" << "The List is the wrong Size!!! \n";
        return false;
    }

    TESTLIST("Remove Function", 0, 123);
    TESTLIST("Remove Function", 1, 111);
    TESTLIST("Remove Function", 2, 100);
    TESTLIST("Remove Function", 3, 5);

    return true;
}

bool RemoveAllFunction()
{
    test.PushBack(10);
    test.PushBack(10);

    test.PushFront(10);
    test.PushFront(10);


    if (test.GetLength() != 8)
    {
        std::cout << "List Remove Functions failed \n" << "The List is the wrong Size!!! \n";
        return false;
    }

    TESTLIST("RemoveAll Function", 0, 10);
    TESTLIST("RemoveAll Function", 1, 10);
    TESTLIST("RemoveAll Function", 2, 123);
    TESTLIST("RemoveAll Function", 3, 111);
    TESTLIST("RemoveAll Function", 4, 100);
    TESTLIST("RemoveAll Function", 5, 5);
    TESTLIST("RemoveAll Function", 6, 10);
    TESTLIST("RemoveAll Function", 7, 10);

    test.RemoveAll(10);

    if (test.GetLength() != 4)
    {
        std::cout << "List Remove Functions failed \n" << "The List is the wrong Size!!! \n";
        return false;
    }

    TESTLIST("RemoveAll Function", 0, 123);
    TESTLIST("RemoveAll Function", 1, 111);
    TESTLIST("RemoveAll Function", 2, 100);
    TESTLIST("RemoveAll Function", 3, 5);

    return true;
}

bool GetElemeantAndChangeFunctions()
{
    int & foo = test.Last();

    foo = 10110;

    int & testlingz = test.First();

    testlingz = 777;

    int & blargh = test.GetElemeantAt(2);

    blargh = 66;

    if (test.GetLength() != 4)
    {
        std::cout << "List Remove Functions failed \n" << "The List is the wrong Size!!! \n";
        return false;
    }

    TESTLIST("GetElemeantAndChange Functions", 0, 777);
    TESTLIST("GetElemeantAndChange Functions", 1, 111);
    TESTLIST("GetElemeantAndChange Functions", 2, 66);
    TESTLIST("GetElemeantAndChange Functions", 3, 10110);

    return true;
}

bool InsertAtFunction()
{
    test.InsertAtPosition(0, 88);

    test.InsertAtPosition(1, 123);

    test.InsertAtPosition(2, 9001);

    test.InsertAtPosition(test.GetLength(), 123);

    if (test.GetLength() != 8)
    {
        std::cout << "List Remove Functions failed \n" << "The List is the wrong Size!!! \n";
        return false;
    }

    TESTLIST("InsertAt Function", 0, 88);
    TESTLIST("InsertAt Function", 1, 123);
    TESTLIST("InsertAt Function", 2, 9001);
    TESTLIST("InsertAt Function", 3, 777);
    TESTLIST("InsertAt Function", 4, 111);
    TESTLIST("InsertAt Function", 5, 66);
    TESTLIST("InsertAt Function", 6, 10110);
    TESTLIST("InsertAt Function", 7, 123);

    return true;
}

#pragma endregion

#pragma region DynamicArrayFunctions

bool DynamicArrayTester()
{

    return true;
}

#pragma endregion