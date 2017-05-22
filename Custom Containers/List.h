#pragma once

template <class T>
class List
{
public:

    List() {m_first = m_last = nullptr}

    ~List();

    void PushFront(T value);

    void PushBack(T value);

    void insert(ListNode & node, T value);

    void PopBack();

    void PopFront();

    void Erase(ListNode & node);

    void Remove(T value);

    void DeleteAll();

    T & First();

    T & Last();

    ListNode & Begin();

    ListNode & LEnd();

private:

    class ListNode
    {
    public:
        ListNode() {previous = next = nullptr}

        ~ListNode()
        {
            previous = next = nullptr;
            delete obj;
        }
        
        ListNode * previous;
        ListNode * next;

        T obj;
    };

    ListNode * m_first;
    ListNode * m_last;

};

List::List()
{

}