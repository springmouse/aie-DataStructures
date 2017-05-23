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

        ListNode * next;
        ListNode * previous;

        T obj;
    };

    ListNode * m_first;
    ListNode * m_last;

    int m_listCount;


public:

    List();

    ~List();

    void PushFront(const T & value);

    void PushBack(const T & value);

    void PopBack();

    void PopFront();

    void Remove(const T & value);

    void RemoveAll(const T & value);

    void DeleteAll();

    T & First();

    T & Last();

    T & GetElemeantAt(const int & P);

    int GetLength();

#pragma region PutOnDelay
   /* 
   ListNode List<T>::GetNodeByValue(T value);

    void insert(ListNode & node, T value);
    
    ListNode & Begin();

    ListNode & End();
    */
#pragma endregion

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
void List<T>::PushFront(const T & value)
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
void List<T>::PushBack(const T & value)
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
void List<T>::PopBack()
{
    if (m_listCount > 0)
    {
        ListNode * holder = m_last->previous;

        delete m_last;

        holder->next = nullptr;

        m_last = holder;

        m_listCount--;
    }
}

template<class T>
void List<T>::PopFront()
{
    if (m_listCount > 0)
    {
        ListNode * holder = m_first->next;

        delete m_first;

        holder->previous = nullptr;

        m_first = holder;

        m_listCount--;
    }
}

template<class T>
void List<T>::Remove(const T & value)
{
    ListNode * node = m_first;
    
    if (m_listCount == 1 && node->obj == value)
    {
        DeleteAll();
        return;
    }

    while (true && m_listCount > 1)
    {
        if (node->obj == value)
        {
            ListNode * holder;

            if (node->next != nullptr)
            {
                holder = node->next;

                holder->previous = node->previous;

                delete node;

                if (holder->previous != nullptr)
                {
                    ListNode * nodeHolder = holder->previous;
                    nodeHolder->next = holder;
                }
                else
                {
                    m_first = holder;
                }

                m_listCount--;
                return;

            }
            else if (node->previous != nullptr)
            {
                holder = node->previous;

                holder->next = node->next;

                delete node;

                if (holder->next != nullptr)
                {
                    ListNode * nodeHolder = holder->next;
                    nodeHolder->previous = holder;
                }
                else
                {
                    m_last = holder;
                }

                m_listCount--;
                return;

            }
        }
        else if (node->next == nullptr)
        {
            return;
        }

        node = node->next;
    }
        
}

template<class T>
void List<T>::RemoveAll(const T & value)
{
    ListNode * node = m_first;

    if (m_listCount == 1 && node->obj == value)
    {
        DeleteAll();
        return;
    }

    while (true && m_listCount > 1)
    {
        if (node->obj == value && node != nullptr)
        {
            ListNode * holder;

            if (node->next != nullptr)
            {
                holder = node->next;

                holder->previous = node->previous;

                delete node;

                if (holder->previous != nullptr)
                {
                    ListNode * nodeHolder = holder->previous;
                    nodeHolder->next = holder;
                }
                else
                {
                    m_first = holder;
                }

                m_listCount--;
                node = holder;

            }
            else if (node->previous != nullptr)
            {
                holder = node->previous;

                holder->next = node->next;

                delete node;

                if (holder->next != nullptr)
                {
                    ListNode * nodeHolder = holder->next;
                    nodeHolder->previous = holder;
                }
                else
                {
                    m_last = holder;
                }

                m_listCount--;
                node = holder;

            }
        }
        else if (node->next == nullptr)
        {
            return;
        }
        else
        {
            node = node->next;
        }

    }

}

template<class T>
T & List<T>::First()
{
    return m_first->obj;
}

template<class T>
T & List<T>::Last()
{
    return m_last->obj;
}

template<class T>
T & List<T>::GetElemeantAt(const int & P)
{
    if (P <= m_listCount)
    {
        ListNode * holder = m_first;
        for (int i = 0; i <= P; i++)
        {
            if (i == P)
            {
                return holder->obj;
            }
            else
            {
                holder = holder->next;
            }
        }
    }
    else
    {
        throw;
    }
}

template<class T>
int List<T>::GetLength()
{
    return m_listCount;
}

#pragma region PutOnDelay
//template<class T>
//ListNode List<T>::GetNodeByValue(T value)
//{
//    ListNode * node = m_first->next;
//
//    if (node == nullptr)
//    {
//        return nullptr;
//    }
//
//    if (node->obj == value)
//    {
//        return node;
//    }
//    else
//    {
//        node = node->next
//    }
//
//
//}
//
//template<class T>
//void List<T>::insert(ListNode & node, T value)
//{
//    ListNode * NN = new ListNode();
//
//    NN->previous = node->previous->previous;
//
//    NN->next = node;
//
//    NN->obj = value;
//
//    node->previous = NN;
//}
#pragma endregion