template <typename T>
class CList
{
    class Node;
    Node *tail;
    int size;

public:
    CList()
    {
        tail = nullptr;
        size = 0;
    }

    void insert(T element)
    {
        if (isEmpty())
        {
            tail = new Node(element);
            tail->next = tail;
        }
        else
        {
            tail->next = new Node(element, tail->next);
            tail = tail->next;
        }
        size++;
    }

    void print()
    {
        cout << endl;
        Node *temp = tail->next;
        if (!tail)
        {
            cout << "Nothing found!\n";
            return;
        }
        while (temp != tail)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << tail->data;
        cout << endl;
    }

    bool isEmpty()
    {
        return tail == nullptr;
    }

    void deleteHead()
    {
        if (isEmpty())
        {
            return;
        }
        if (tail->next == tail)
        {
            delete tail;
            tail = nullptr;
        }
        else
        {
            Node *temp = tail->next;
            tail->next = temp->next;
            delete temp;
        }
        size--;
    }

    ~CList()
    {
        if (isEmpty())
        {
            return;
        }

        Node *temp = tail->next;
        while (temp != tail)
        {
            Node *temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
        delete tail;
        tail = nullptr;
    }
};

template <typename T>
class CList<T>::Node
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

