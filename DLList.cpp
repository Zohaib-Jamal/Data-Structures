#include <iostream>
using namespace std;

template <class T>
class DLList
{
    class Node
    {
    public:
        T data;
        Node *next;
        Node *prev;

        Node(T d = T(), Node *n = nullptr, Node *p = nullptr)
            : data(d), next(n), prev(p) {}
    };

    Node *Head;
    Node *Tail;
    int size;

public:
    DLList()
    {
        Head = new Node();
        Tail = new Node(T(), nullptr, Head);
        Head->next = Tail;
        size = 0;
    }

    bool isEmpty() const
    {
        return Head->next == Tail;
    }

    void insertAtStart(const T &element)
    {
        Node *temp = new Node(element, Head->next, Head);
        Head->next->prev = temp;
        Head->next = temp;
        size++;
    }

    void insertAtEnd(const T &element)
    {
        Node *temp = new Node(element, Tail, Tail->prev);
        Tail->prev->next = temp;
        Tail->prev = temp;
        size++;
    }

    void print() const
    {
        Node *temp = Head->next;
        if (isEmpty())
        {
            cout << "List is empty!" << endl;
            return;
        }
        while (temp != Tail)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteFromStart()
    {
        if (isEmpty())
        {
            return;
        }
        Node *temp = Head->next;
        Head->next = temp->next;
        temp->next->prev = Head;
        delete temp;
        size--;
    }

    void deleteFromEnd()
    {
        if (isEmpty())
        {
            return;
        }
        Node *temp = Tail->prev;
        Tail->prev = temp->prev;
        temp->prev->next = Tail;
        delete temp;
        size--;
    }

    ~DLList()
    {
        Node *temp = Head->next;
        while (temp != Tail)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete Head;
        delete Tail;
    }
};
