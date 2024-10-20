template <class T>
class StackArray {
    T *stack;
    int size;
    int currentSize;

public:
    StackArray(int n = 10) {
        size = n;
        currentSize = 0;
        stack = new T[size];
    }

    bool push(T value) {
        if (currentSize == size)
            return false;
        stack[currentSize++] = value;
        return true;
    }

    bool pop() {
        if (currentSize == 0)
            return false;
        currentSize--;
        return true;
    }

    T top() {
        if (currentSize == 0)
            return T();
        return stack[currentSize - 1];
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == size;
    }

    ~StackArray() {
        delete[] stack;
    }
};
