#pragma once

template <class T>
class DynamicArray
{
public:
    DynamicArray();
    ~DynamicArray();

    int size;
    int usedElements;
    T * arr[size];

};

