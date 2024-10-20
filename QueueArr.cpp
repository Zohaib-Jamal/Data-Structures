template <class T>
class QueueArr
{
    int maxSize;
    int size;
    T *arr;
    int front;
    int rear;

public:
    QueueArr(int max = 10)
    {
        maxSize = max;
        size = 0;
        front = 0;
        rear = 0;

        arr = new T[maxSize];
    }

    bool IsFull()
    {

        return size == maxSize;
    }
    bool IsEmpty()
    {

        return 0 == size;
    }

    void Enqueue(T value)
    {
        if (IsFull())
            return;

         arr[rear] = value; 
        rear = (rear + 1) % maxSize; 
        size++;
    }

    T Dequeue()
    {
        if (IsEmpty())
            return T();

        T temp = arr[front]; 
        front = (front + 1) % maxSize; 
        size--;

        return temp;
    }

    void Print() 
    {
        if (IsEmpty())
            return;

        for (int i = 0, j = front; i < size; i++, j = (j + 1) % maxSize)
        {
            cout << arr[j] << " "; 
        }
        cout << endl;
    }
    ~QueueArr()
    {
        delete[] arr; 
    }

};

