#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 100

class Stack
{
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size = SIZE);
    ~Stack();

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();
};

Stack::Stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}
Stack::~Stack()
{
    delete arr;
}
bool Stack::isEmpty()
{
    return top = -1; ///or return size() == 0;
}
bool Stack::isFull()
{
    return top = capacity - 1; ///or return size() == capacity;
}
int Stack::size()
{
    return top + 1;
}
void Stack::push(int x)
{
    if(isFull())
    {
        cout << "Overflow\n Program Terminated\n";
        exit(EXIT_FAILURE);
    }
    cout << "Inserting " << x << endl;
    arr[++top] = x;
}
int Stack::peek()
{
    if(!isEmpty())
    {
        return arr[top];
    }
    else
    {
        exit(EXIT_FAILURE);
    }
}
int Stack::pop()
{
    if(isEmpty())
    {
        cout << "UnderFlow\n Program Terminated\n";
        exit(EXIT_FAILURE);
    }
    cout << "Removing " << peek() << endl;
    return arr[top--];
}
