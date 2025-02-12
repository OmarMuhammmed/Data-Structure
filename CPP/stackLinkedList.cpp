#include <bits/stdc++.h>
using namespace std;

class Node {
public:

    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
   
    Node *top; // pointer with type Node 

public:
    
    Stack() 
    { 
        top = nullptr;
    }

    
    bool isEmpty() 
    {   
        return top == nullptr;
    }

    
    void push(int data) 
    {
        Node* new_node = new Node(data);

        if (!new_node)
        { 
            cout << "\nStack Overflow";
        }

        if (top == nullptr) // if stack is empty
        { 
            top = new_node;
            new_node -> next = nullptr;
            return;
        }

        new_node -> next = top;

        top = new_node;
    }

    void pop() 
    {
        if (isEmpty()) {
            cout << "\n Stack is Empty " << endl;
        }

        else {    

            Node* temp = top;

            top = top->next;

            delete temp;
        }
    }

    // Function to return the top element of the stack
    int peek() 
    {

        // If stack is not empty, return the top element
        if (!isEmpty())
            return top->data;
        else {
            cout << "\nStack is empty";
            return INT_MIN;
        }
    }
};

// Driver program to test the stack implementation
int main() {
    // Creating a stack
    Stack st;

    // Push elements onto the stack
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    // removing two elemements from the top
      cout << "Removing two elements..." << endl;
    st.pop();
    st.pop();

    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    return 0;
}