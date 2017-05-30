#pragma once

/*
* Class: List
* -----------
*
* this is my List class, it is double linked in both dirctions
* it is also a template class so it should work with anything
*
* Author: Callum Dunstone
*/
template <class T>
class List
{
private:

    /*
    * Class: ListNode
    * ---------------
    *
    * List Nodes make up the contents of the list and are used to store the information held in a list
    * it is also used to link all the elemeants of the list together through pointers
    *
    * Author: Callum Dunstone
    */
#pragma region ListNodes

    class ListNode
    {
    public:
        /*
        * Function: Constructor
        * ---------------------
        *
        * this is the Default constructor that sets
        * the pointers used to point to other list nodes to nullptr
        *
        */
        ListNode() { previous = next = nullptr; }

        /*
        * Function: DeConstructor
        * ---------------------
        *
        * this is the Default deconstructor sets the pointers to nullptr again
        *
        */
        ~ListNode()
        {
            previous = next = nullptr;
        };

        ListNode * next; /*points the the next list node in the list or null if it is at the end of the list*/
        ListNode * previous; /*points the the previous list node in the list or null if it is at the start of the list*/

        T obj; /*this stores the value of the list currently being stored*/
    };

#pragma endregion
    
    ListNode * m_first; /*a pointer to the first elemteant in the list*/
    ListNode * m_last; /*a pointer to the last elemeant in the list*/

    int m_listCount; /*stores the size of the list*/


public:
    /*
    * Function: Constructor
    * ---------------------
    *
    * sets length of list to zero, creates the m_first, m_last and sets them to be pointing to nullptr
    *
    */
    List();

    /*
    * Function: DeConstructor
    * ---------------------
    *
    * this is the Default deconstructor and it runs the DeleteAll()
    *
    */
    ~List();

    /*
    * Function: PushFront
    * -------------------
    *
    * this adds an elemeant to the front of the list
    *
    * Parameters: this takes in a const T & value that will be used to add to the list
    *
    * returns: returns nothing as it is a null function
    */
    void PushFront(const T & value);

    /*
    * Function: PushBack
    * ------------------
    *
    * this adds an elemeant to the PushBack of the list
    *
    * Parameters: this takes in a const T & value that will be used to add to the list
    *
    * returns: returns nothing as it is a null function
    */
    void PushBack(const T & value);

    /*
    * Function: PushBack
    * ------------------
    *
    * this deletes the elemeant at the end of the list
    *
    * Parameters: this takes in no pareameters
    *
    * returns: returns nothing as it is a null function
    */
    void PopBack();

    /*
    * Function: PopFront
    * ------------------
    *
    * this deletes the elemeant at the front of the list
    *
    * Parameters: this takes in no pareameters
    *
    * returns: returns nothing as it is a null function
    */
    void PopFront();

    /*
    * Function: Remove
    * ------------------
    *
    * this takes in a refrence to a value to try and find in the list, 
    * once it finds the first instance of the value it will delete it
    *
    * Parameters: this takes in const T & value that it will use to search to find the first instance of in the list
    *
    * returns: returns nothing as it is a null function
    */
    void Remove(const T & value);

    /*
    * Function: RemoveAll
    * -------------------
    *
    * this takes in a refrence to a value to try and find in the list,
    * every instance of that value it finds it will delete
    *
    * Parameters: this takes in const T & value that it will use to search for in the list
    *
    * returns: returns nothing as it is a null function
    */
    void RemoveAll(const T & value);

    /*
    * Function: DeleteAll
    * -------------------
    *
    * this deletes all elemeants in the list
    *
    * Parameters: this takes no parameters
    *
    * returns: returns nothing as it is a null function
    */
    void DeleteAll();

    /*
    * Function: First
    * ---------------
    *
    * this returns the value of the first elemeant of the list
    *
    * Parameters: this takes no parameters
    *
    * returns: a refrence to the value held in the first node of the list
    */
    T & First();

    /*
    * Function: Last
    * ---------------
    *
    * this returns the value of the Last elemeant of the list
    *
    * Parameters: this takes no parameters
    *
    * returns: a refrence to the value held in the Last node of the list
    */
    T & Last();

    /*
    * Function: GetElemeantAt
    * -----------------------
    *
    * this works as a mock interator with the intention of being used in a for loop
    * it finds the elemeant held in the positions passed into the function
    *
    * Parameters: this takes const int & P used to look through the elemeant to find the position of an elemeant held in the list
    *
    * returns: a refrence to the value held in the Last node of the list
    */
    T & GetElemeantAt(const int & P);

    /*
    * Function: GetLength
    * -------------------
    *
    * this returns the amount of nodes in the list
    *
    * Parameters: this has no parameters
    *
    * returns: a int holding the leangth of the list
    */
    int GetLength();

    /*
    * Function: InsertAtPosition
    * --------------------------
    *
    * allows you to insert a new node with in a position between first and start
    *
    * Parameters: int P is the position with in the array that you want to but the new node, T value is the value for the new node
    *
    * returns: a int holding the leangth of the list
    */
    void InsertAtPosition(int P, T value);

    class ListIterator
    {
    public:
        ListIterator() {};

        ListIterator(const ListIterator & other) { iterator = other.iterator; };

        ~ListIterator() {};

        ListNode * iterator;

        T & operator * () {return iterator->obj;};
        
        void operator++() { iterator = iterator->next; };
        
        void operator++(int) { iterator = iterator->next; };

        void operator--() { iterator = iterator->previous; };

        void operator--(int) { iterator = iterator->previous; };

        void operator += (const int & P)
        {
            for (int i = 0; i < P; i++)
            {
                iterator = iterator->next;
            }
        };

        ListIterator & operator = (const ListIterator & other) { iterator = other.iterator; return *this; };

        bool operator == (const ListIterator & other)
        {
            if (iterator == other.iterator)
            {
                return true
            }
            else
            {
                return false;
            }
        };

        bool operator != (const ListIterator & other) 
        {
            if (iterator != other.iterator)
            { 
                return true; 
            }
            else
            {
                return false;
            }
        };

    private:

    };

    ListIterator begin() { ListIterator it; it.iterator = m_first; return it; };

    ListIterator end() { ListIterator it; it.iterator = nullptr; return it; };
};

#pragma region ListFunctions

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
        delete m_first;
    }

    template<class T>
    void List<T>::DeleteAll()
    {

    //loops through every thing so we can delete it going throught the start node
    while (true && m_listCount > 0)
    {
        ListNode * holder;

        holder = m_first->next;

        delete m_first;

        m_first = holder;

        //if m_first is == to a nullptr we have looped through the list
        if (m_first == nullptr)
        {
            m_first = nullptr;
            m_last = nullptr;


            //make sure they are dead!!!
            delete m_first;
            delete m_last;

            //set them back up pointing to new nodes
            m_first = new ListNode();
            m_last = new ListNode();

            //make sure they are pointing to nothing as the list is empty
            m_first->previous = nullptr;
            m_first->next = nullptr;

            m_last = m_first;

            //set size to zero
            m_listCount = 0;

            return;
        }
    }
    }

    template<class T>
    void List<T>::PushFront(const T & value)
    {
    //if size of list is zero we dont need to do anything fancy
    if (m_listCount == 0)
    {
        m_first->obj = value;
    }
    else
    {
        //creat a new node that we will be shoving into the list
        ListNode * NN = new ListNode();

        //set it up as the first node
        NN->previous = nullptr;
        NN->next = m_first;

        //relink the original first node to be pointing at the new node
        m_first->previous = NN;

        //have the pointer for the first node now point to the new node
        m_first = NN;

        //set the new nodes value
        m_first->obj = value;
    }

    //increase list size by one
    m_listCount++;
    }

    template<class T>
    void List<T>::PushBack(const T & value)
    {
    //if size of list is zero we dont need to do anything fancy
    if (m_listCount == 0)
    {
        m_last->obj = value;
    }
    else
    {
        //creat a new node that we will be shoving into the list
        ListNode * NN = new ListNode();

        //set it up as the last node
        NN->previous = m_last;
        NN->next = nullptr;

        //relink the original last node to be pointing at the new node
        m_last->next = NN;

        //have the pointer for the last node now point to the new node
        m_last = NN;

        //set the new nodes value
        m_last->obj = value;
    }

    //increase list size by one
    m_listCount++;
    }

    template<class T>
    void List<T>::PopBack()
    {
    //since list is only one elemeant we cheat and delete everything
    if (m_listCount == 1)
    {
        DeleteAll();
        return;
    }

    //removes the node and sets up the previous node node as the new last node
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
    //again list size is one we are lazy and ceat and just call delet all
    if (m_listCount == 1)
    {
        DeleteAll();
        return;
    }

    //removes the fron node and sets its next to be the new front node
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
    void List<T>::InsertAtPosition(int P, T value)
    {
        //checks that the value passed in is with in bounds
        if (P > m_listCount || P < 0)
        {
            throw;
        }

        //if the position is zero we can cheat and use push front
        if (P == 0)
        {
            PushFront(value);
            return;
        }

        //the position is equal to the list size we can cheat and use pushback
        if (P == m_listCount)
        {
            PushBack(value);
            return;
        }


        //uses the iterator
        List<T>::ListIterator it = begin();

        it += P;

        ListNode * holder = it.iterator;

        ListNode * NN = new ListNode();
        NN->next = holder->next;
        NN->previous = holder;
        NN->obj = value;

        ListNode * HolderTwo = holder->next;
        HolderTwo->previous = NN;

        holder->next = NN;

        m_listCount++;
    }

    template<class T>
    void List<T>::Remove(const T & value)
    {
    ListNode * node = m_first;
    
    //if the list is a size of one and its value is the one we are looking for delete everything and return else return
    if (m_listCount == 1 && node->obj == value)
    {
        DeleteAll();
        return;
    }
    else if(m_listCount == 1 && node->obj != value)
    {
        return;
    }

    //this loops through the list looking for the afirst that holds the value we are looking for
    //once we find the value we need to check wich side has a nullptr if a side has a nullptr if one dose have a nullptr we use the other side
    //then we remove the node and update where the nodes are pointing 
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
    //if the list is a size of one and its value is the one we are looking for delete everything and return else return
    if (m_listCount == 1 && node->obj == value)
    {
        DeleteAll();
        return;
    }
    else if (m_listCount == 1 && node->obj != value)
    {
        return;
    }
    
    //this loops through the list looking for the all nodes that holds the value we are looking for
    //once we find the value we need to check wich side if a side has a nullptr if one dose even have a nullptr and use the other side
    //then we remove the node and update where the nodes are pointing and continue looping looking for the next one
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

        if (P > m_listCount || P < 0)
        {
            throw;
        }




        List<T>::ListIterator it = begin();

        it += P;

        return *it;
            
    }

    template<class T>
    int List<T>::GetLength()
    {
    return m_listCount;
    }

#pragma endregion