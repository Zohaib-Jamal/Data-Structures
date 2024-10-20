#include <iostream>
using namespace std;

template <typename T>
class SLList
{
    class Node;
    Node *head;
    int size;

public:
    SLList()
    {
        head = nullptr;
        size = 0;
    }

    void insertAtEnd(T element)
    {
        Node *node = new Node(element);
        if (!head)
        {
            head = node;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
        size++;
    }

    void insertAtStart(T n)
    {
        Node *temp = new Node(n, head);
        head = temp;
        size++;
    }

    void print()
    {
        cout << endl;
        Node *temp = head;
        if (!head)
        {
            cout << "Nothing found!\n";
            return;
        }
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void deleteAtStart()
    {
        if (!head)
        {
            return;
        }
        Node *del = head;
        head = head->next;
        delete del;
        size--;
    }

    void deleteAtEnd()
    {
        if (!head)
        {
            return;
        }
        if (!head->next)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next && temp->next->next)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        size--;
    }

    ~SLList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

template <typename T>
class SLList<T>::Node
{
public:
    Node *next;
    T data;
    Node(T d = 0, Node *n = nullptr)
    {
        data = d;
        next = n;
    }
};
