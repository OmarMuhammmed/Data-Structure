#include <iostream>
using namespace std;


struct Node 
{
    int data = 0 ; 
    Node *next ; 
};

Node *head = NULL ; 

void insertNode(int value)
{
   Node *newNode = new Node ;  
   newNode -> data = value ; 

   if(head == NULL)
   {
    head = newNode ; 
    newNode -> next = NULL ; 
   }
   else 
   {
    Node *current = head ; 
    while (current->next != NULL)
    {
        current = current -> next ; 
    }
    current -> next = newNode ; //
    newNode -> next = NULL ; 
   }
}


void display()
{
    Node *currentNode ;
    if (head=NULL) cout << "Linked List Empty\n";
    else 
    {
        currentNode = head ;
        while (currentNode != NULL) // haed != NULL
        {
            cout << currentNode ->data <<endl;
            currentNode = currentNode ->next ; 
        }
    }
}


int main()
{
    insertNode(77);
    insertNode(22);
    insertNode(22);
    insertNode(22);
    insertNode(22);
    insertNode(22);
    display();
    return 0 ; 
}