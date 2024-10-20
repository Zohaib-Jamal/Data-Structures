#include <iostream>
using namespace std;

template <class T>
class DLList
{
    class Node;
    Node *Head, *Tail;
    class ListIterator;

public:
    typedef ListIterator Iterator_t;

    DLList()
    {
        Head = new Node(T());
        Tail = new Node(T(), nullptr, Head);
        Head->next = Tail;
    }

    Iterator_t begin()
    {
        return Iterator_t(Head->next);
    }

    Iterator_t end()
    {
        return Iterator_t(Tail);
    }

    void insert(T value)
    {
        Iterator_t iter = end();
        --iter;
        iter.insert(value);
    }

    void print()
    {
        Iterator_t iter = begin();
        while (iter != end())
        {
            cout << *iter << " ";
            ++iter;
        }
        cout << endl;
    }

    ~DLList()
    {
        Node *current = Head->next;
        while (current != Tail)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete Head;
        delete Tail;
    }
};

template <class T>
class DLList<T>::ListIterator
{
    Node *iptr;

public:
    ListIterator(Node *i = nullptr) : iptr(i)
    {
    }

    ListIterator &operator++()
    {
        if (iptr)
        {
            iptr = iptr->next;
        }
        return *this;
    }

    ListIterator &operator--()
    {
        if (iptr)
        {
            iptr = iptr->prev;
        }
        return *this;
    }

    ListIterator operator++(int)
    {
        ListIterator old = *this;
        ++(*this);
        return old;
    }

    ListIterator operator--(int)
    {
        ListIterator old = *this;
        --(*this);
        return old;
    }

    T &operator*()
    {
        return iptr->data;
    }

    bool operator==(const ListIterator &RHS)
    {
        return iptr == RHS.iptr;
    }

    bool operator!=(const ListIterator &RHS)
    {
        return iptr != RHS.iptr;
    }

    ListIterator &insert(const T &value) //inserts and gives next value
    {
        if (iptr)
        {
            Node *temp = new Node(value, iptr->next, iptr);
            iptr->next->prev = temp;
            iptr->next = temp;
            return ListIterator(temp);
        }
        return *this;
    }

    ListIterator &insert(ListIterator &iter) //inserts and gives next value
    {
        if (iptr)
        {
            Node *temp = new Node(iter.iptr->data, iptr->next, iptr);
            iptr->next->prev = temp;
            iptr->next = temp;
            return ListIterator(temp);
        }
        return *this;
    }

    ListIterator &remove(const T &value) // removes current and gives previous value
    {
        if (iptr)
        {
            Node *temp = iptr;
            iptr = iptr->prev;
            iptr->next = iptr->next->next;
            iptr->next->prev = iptr;

            delete temp;
        }

        return iptr;
    }
};

template <class T>
class DLList<T>::Node
{
public:
    Node *next;
    Node *prev;
    T data;

    Node(T d = T(), Node *n = nullptr, Node *p = nullptr) : data(d), next(n), prev(p) {}
};
