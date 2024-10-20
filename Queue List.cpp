#include <iostream>
using namespace std;

template <class T>
class List
{
    class Node;
    Node *Head, *Tail;
    class ListIterator;

public:
    typedef ListIterator Iterator_t;

    List()
    {
        Head = new Node();
        Tail = new Node();
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

    void print()
    {
        for (Iterator_t iter = begin(); iter != end(); ++iter)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }

    void insert(T value)
    {
        Node *temp = new Node(value, Tail);
        Node *current = Head;

        while (current->next != Tail)
        {
            current = current->next;
        }

        current->next = temp;
    }

    T removeFromHead()
    {
        if (Head->next == Tail)
            return T(); 
        T data = Head->next->data;
        Node *toDelete = Head->next;
        Head->next = Head->next->next;
        delete toDelete; 
        return data;
    }

    ~List()
    {
        Iterator_t iter = begin();
        while (iter != end())
        {
            iter.remove();
        }
        delete Head;
        delete Tail;
    }

private:
    class Node
    {
    public:
        Node *next;
        T data;

        Node(T d = T(), Node *n = nullptr) : data(d), next(n) {}
    };

    class ListIterator
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

        ListIterator operator++(int)
        {
            ListIterator old = *this;
            ++(*this);
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

        void insert(const T &value)
        {
            if (iptr)
            {
                Node *temp = new Node(value, iptr->next);
                iptr->next = temp;
            }
        }

        void remove()
        {
            Node *temp = iptr;

            iptr = iptr->next;

            if (temp)
                delete temp;
        }
    };
};

template <class T>
class Queue
{
    int size;
    int currSize;
    List<T> queue;

public:
    Queue(int s = 10) : size(s), currSize(0) {}

    void Enqueue(T value)
    {
        if (size == currSize)
            return;
        queue.insert(value);
        currSize++;
    }

    T Dequeue()
    {
        if (currSize == 0)
            return T();
        currSize--;
        return queue.removeFromHead();
    }

    bool IsFull() const
    {
        return size == currSize;
    }

    bool IsEmpty() const
    {
        return currSize == 0;
    }

    void Print() 
    {
        queue.print();
    }
};

