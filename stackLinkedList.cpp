#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};

class Stack {
   
    Node* top;

public:
    
    Stack() { this->top = nullptr; }

    
    bool isEmpty() 
    {   
        return top == nullptr;
    }

    // Function to push an element onto the stack
    void push(int data) 
    {
      
        // Create a new node with given data
        Node* new_node = new Node(data);

        // Check if memory allocation for the new node
        if (!new_node) {
            cout << "\nStack Overflow";
        }

        // Link the new node to the current top node
        new_node->next = top;

        // Update the top to the new node
        top = new_node;
    }

    // Function to remove the top element from the stack
    void pop() 
    {

       
        if (this->isEmpty()) {
            cout << "\nStack Underflow" << endl;
        }
        else {
            
            // Assign the current top to a temporary
            Node* del = top;

            // Update the top to the next node
            top = top->next;

            // Deallocate the memory of the old top node
            delete del;
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