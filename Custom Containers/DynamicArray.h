#pragma once

template <class T>
class DynamicArray
{
private:
    int size;
    int usedElements;

public:

    T * arr[1];

    DynamicArray();

    DynamicArray(int _size);

    ~DynamicArray();



};

template<class T>
inline DynamicArray<T>::DynamicArray()
{
    size = 10;
    usedElements = 0;

    arr = T * newArr[size];
}

template<class T>
inline DynamicArray<T>::DynamicArray(const int _size)
{
    size = _size;
    usedElements = 0;

    T * newArr[_size];

    arr = newArr;
}

template<class T>
inline DynamicArray<T>::~DynamicArray()
{

    for (int i = 0; i < size; i++)
    {
        delete arr[i];
    }
}