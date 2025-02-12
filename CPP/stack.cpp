#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define MAX 10

class Stack {
    int top;

public:
    int arrayStack[MAX]; // Maximum size of Stack

    Stack() { top = -1; } // when you create object top is -1  Top is index not value 
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    int display();
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        arrayStack[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = arrayStack[top--];
        return x;
    }
}

int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = arrayStack[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int Stack::display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << arrayStack[i] << "\n";
    }
}
// Driver program to test above functions
int main()
{
    class Stack myStack; // create object of class Stack

    myStack.push(10);
    myStack.push(20);   
    myStack.push(30);
    myStack.pop();
    myStack.push(40);
    cout << myStack.display();
    

    /*
    40
    20
    10
    */
    return 0;
}


