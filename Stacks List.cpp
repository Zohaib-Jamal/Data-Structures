template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Stack
{
private:
    Node<T> *top;

public:
    Stack() : top(nullptr) {}

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        Node<T> *temp = top;
        top = top->next;
        delete temp;
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot peek.\n";
            return T();
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }
        Node<T> *current = top;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
