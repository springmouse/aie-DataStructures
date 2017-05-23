#include <iostream>
#include <Stack.h>
#include <List.h>

void main()
{

    List<int> test = List<int>();

    test.PushBack(11);
    test.PushBack(9);
    test.PushBack(5);
    test.PushBack(4);
    test.PushBack(6);

    test.PopBack();
    test.PopFront();

    test.Remove(4);
    test.Remove(9);

    test.PushFront(100);
    test.PushFront(111);
    test.PushFront(112);
    test.PushFront(123);

    test.Remove(112);

    test.PushBack(10);
    test.PushBack(10);

    test.PushFront(10);
    test.PushFront(10);

    test.RemoveAll(10);

    int & testlingz = test.First();

    testlingz = 777;

    int & blargh = test.GetElemeantAt(2);

    blargh = 66;

    for (int i = 0; i < test.GetLength(); i++)
    {
        test.GetElemeantAt(i) = i;
    }
}