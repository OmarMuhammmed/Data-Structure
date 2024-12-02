#include <iostream>
using namespace std;


struct Node // Strcut with type node
{
    int data = 0 ; 
    Node *next ; // ptr with type node with next value
};

Node *head = NULL ; // ptr with type node with head value

void insertNode(int data)
{
    Node *newNode ; 
    Node *last ; 
    newNode = new Node ; 
    newNode -> data = data ; 

    if (head == NULL) {  
        head = newNode ; 
        newNode -> next = NULL ; 
    }
    else {
        last = head ; // last ptr points to head 
        while(last -> next != NULL){ 
            last = last -> next ; 
        }
        last -> next = newNode ; 
        newNode -> next = NULL ; 
    }
}

void display()
{
    Node *currentNode ; 
    if (head == NULL) cout << "Linked List is Empty \n" ; 
    else 
    {
        currentNode = head ; 
        while (currentNode != NULL)
        {
            cout << currentNode -> data << "\n" ;
            currentNode = currentNode -> next ;
        }
        
    }
}

int main()
{
    // insertNode(10);
    // insertNode(20);
    display();
    return 0 ; 
}