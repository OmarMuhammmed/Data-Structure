#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int new_data)
    {
        data = new_data;
        next = nullptr;
    }
};


class Queue {

    Node *front, *rear;

public:
    
    Queue() { front = rear = nullptr; }

    bool isEmpty()
    {
        return (front == nullptr);
    }

    
    void enqueue(int new_data) {

        Node* new_node = new Node(new_data);

        if (isEmpty()) {
            front = rear = new_node;
            new_node->next = nullptr;
            return;
        }

       
        rear->next = new_node; // link between the last node and the new node
        rear = new_node;
        new_node->next = nullptr;
    }

  
    void dequeue() {

        
        if (this->isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        
        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    
    int getFront() {
      
        if (isEmpty()) {
            cout << "Queue is empty\n";
        }
        return front->data;
    }

    
    int getRear() {

        if (this->isEmpty()) {
            cout << "Queue is empty\n";
          
        }
        return rear->data;
    }
};

// Driver code to test the queue implementation
int main()
{
    Queue q;

    // Enqueue elements into the queue
    q.enqueue(10);
    q.enqueue(20);

    // Display the front and rear elements of the queue
    cout << "Queue Front: " << q.getFront() << endl;
    cout << "Queue Rear: " << q.getRear() << endl;

    // Dequeue elements from the queue
    q.dequeue();
    q.dequeue();

    // Enqueue more elements into the queue
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Dequeue an element from the queue
    q.dequeue();

    // Display the front and rear elements of the queue
    cout << "Queue Front: " << q.getFront() << endl;
    cout << "Queue Rear: " << q.getRear() << endl << endl;

    return 0;
}