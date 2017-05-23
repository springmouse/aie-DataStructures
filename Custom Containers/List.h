#pragma once


template <class T>
class List
{
private:

    class ListNode
    {
    public:
        ListNode() { previous = next = nullptr; }

        ~ListNode()
        {
            previous = next = nullptr;
        };

        ListNode * previous;
        ListNode * next;

        T obj;
    };

    ListNode * m_first;
    ListNode * m_last;

    int m_listCount;


public:

    List();

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

};

template<class T>
List<T>::List()
{
    m_first = new ListNode();
    m_last = new ListNode();

    m_first->previous = nullptr;
    m_first->next = nullptr;

    m_last = m_first;

    m_listCount = 0;

    DeleteAll();
}

template<class T>
List<T>::~List()
{
    DeleteAll();
}

template<class T>
void List<T>::DeleteAll()
{
    while (true && m_listCount > 0)
    {
        ListNode * holder;

        holder = m_first->next;

        delete m_first;

        m_first = holder;


        if (m_first == nullptr)
        {
            m_first = new ListNode();
            m_last = new ListNode();

            m_first->previous = nullptr;
            m_first->next = nullptr;

            m_last = m_first;

            m_listCount = 0;

            return;
        }
    }
}

template<class T>
void List<T>::PushFront(T value)
{
    if (m_listCount == 0)
    {
        m_first->obj = value;
    }
    else
    {
        ListNode * NN = new ListNode();

        NN->previous = nullptr;
        NN->next = m_first;

        m_first->previous = NN;

        m_first = NN;

        m_first->obj = value;
    }

    m_listCount++;
}

template<class T>
void List<T>::PushBack(T value)
{
    if (m_listCount == 0)
    {
        m_last->obj = value;
    }
    else
    {
        ListNode * NN = new ListNode();

        NN->previous = m_last;
        NN->next = nullptr;

        m_last->next = NN;

        m_last = NN;

        m_last->obj = value;
    }

    m_listCount++;
}

template<class T>
void List<T>::insert(ListNode & node, T value)
{

}

template<class T>
void List<T>::PopBack()
{

}