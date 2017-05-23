#include <iostream>
#include <Stack.h>
#include <List.h>

void main()
{

    List<int> test = List<int>();

    
    while (true)
    {
        for (int i = 0; i < 1000000; i++)
        {
            test.PushBack(rand());
        }

        test.DeleteAll();
    }


}