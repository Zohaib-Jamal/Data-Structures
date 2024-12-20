#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class BinaryHeap
{
    int currentSize;
    vector<T> data;
    int capacity;

    void ReheapDown(int cnode, int last)
    {
        int maxChild, rightChild, leftChild;
        leftChild = 2 * cnode + 1;
        rightChild = 2 * cnode + 2;
        if (leftChild <= last)
        {

            if (leftChild == last)
                maxChild = leftChild;
            else
            {
                if (data[leftChild] <= data[rightChild])
                    maxChild = rightChild;

                else

                    maxChild = leftChild;
            }
            if (data[cnode] < data[maxChild])
            {
                Swap(data, cnode, maxChild);
                ReheapDown(maxChild, last);
            }
        }
    }
    void ReheapUp(int root, int last)
    {
        int parent;
        if (last > root)
        {
            parent = (last - 1) / 2;
            if (data[parent] < data[last])
            {
                Swap(data, parent, last);
                ReheapUp(root, parent);
            }
        }
    }

public:
    BinaryHeap(int c = 100)
    {
        currentSize = 0;
        capacity = c;
    }
    bool isEmpty()
    {
        return currentSize;
    }
    const T &findMax()
    {
        return data.front();
    }
    void Insert(T newItem)
    {
        if (currentSize < capacity)
        {
            currentSize++;
            data[currentSize - 1] = newItem;
            ReheapUp(0, currentSize - 1);
        }
    }
    void DeleteMax(T &item)
    {

        item = data[0];
        data[0] = data[currentSize - 1];
        currentSize--;
        ReheapDown(0, currentSize - 1);
    }
};

int main()
{

    return 0;
}
