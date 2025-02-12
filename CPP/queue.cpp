#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* arr;

public:
    // Constructor
    Queue(int capacity) {
        size = capacity;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    bool IsFull(){
        return (rear == size - 1);
    }

    bool IsEmpty(){
        return (front == -1 || front > rear)
    }

    void enqueue(int value) {
        if (IsFull()) {
            cout << "Queue is full! Cannot add " << value << endl;
            return;
        }
        if (front == -1) {
            front = 0; 
        }

        arr[++rear] = value;
        cout << value << " added to the queue.\n";
    }

    // Dequeue: Removing element from the front
    int dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return -1;
        }

        int removed = arr[front++];
        if (front > rear) { 
            front = rear = -1;
        }
        cout << removed << " removed from the queue.\n";
        return removed;
    }

    // Peek: Check the front element
    int peek() {
        if (IsEmpty()) {
            cout << "Queue is empty! Nothing to peek.\n";
            return -1;
        }

        return arr[front];
    }

};

int main() {
    Queue q(5); 

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.dequeue();
    q.dequeue(); 

    return 0;
}
