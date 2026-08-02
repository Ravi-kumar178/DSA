#include <iostream>
using namespace std;

void heapify(int *arr, int i, int capacity)
{
    int leftChild = 2*i;
    int rightChild = 2*i+1;
    int largestIndex = i;

    if ((leftChild <= capacity) && (arr[leftChild] > arr[largestIndex]))
    {
        largestIndex = leftChild;
    }
    if ((rightChild <= capacity) && (arr[rightChild] > arr[largestIndex]))
    {
        largestIndex = rightChild;
    }

    if (largestIndex == i)
        return;

    swap(arr[largestIndex], arr[i]);
    heapify(arr, largestIndex, capacity);

    return;
}

class Heap
{
public:
    int *arr;
    int size;
    int index;

    Heap(int _size)
    {
        this->arr = new int[_size];
        this->size = _size;
        this->index = 0;
    }

    void push(int val)
    {
        // check overflow condition
        if (index == size - 1)
        {
            cout << "Memory overflow" << endl;
            return;
        }
        // increase value and push val
        index++;
        arr[index] = val;

        // shift the pushed element to its correct position by heapify up
        int childIndex = index;
        while (childIndex > 1)
        {
            int parentIndex = childIndex / 2;
            if (arr[childIndex] >= arr[parentIndex])
            {
                swap(arr[childIndex], arr[parentIndex]);
                childIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
        return;
    }

    void pop()
    {
        if(index == 0){
            cout<<"underflow"<<endl;
            return;
        }
        swap(arr[1], arr[index]);
        index--;
        int capacity = index;
        heapify(arr, 1, capacity);
    }

    bool empty()
    {
        return index == 0 ? true : false;
    }

    int heapSize()
    {
        return index;
    }

    int top()
    {
        // empty heap
        return index == 0 ? -1 : arr[1];
    }
};

int main()
{
    Heap hp(6);
    hp.push(1);
    hp.push(2);
    hp.push(3);
    hp.push(4);
    hp.push(5);
    // hp.push(6);
    cout << hp.empty() << endl;
    cout << hp.heapSize() << endl;
    cout << hp.top() << endl;
    hp.pop();
    cout << hp.top() << endl;
    hp.pop();
    cout << hp.top() << endl;
    hp.pop();
    cout << hp.top() << endl;
    hp.pop();
    cout << hp.top() << endl;
    hp.pop();
    cout << hp.top() << endl;
    hp.pop();
    cout<<hp.top()<<endl;
    return 0;
}