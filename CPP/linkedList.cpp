#include <iostream>
using namespace std;


struct Node 
{
    int data = 0 ; 
    Node *next  ; 

    Node(int value)
    {
        data = value ; 
        next = nullptr ; 
    }
};

Node *head = nullptr ; 

void insertNode(int value)
{
   Node *newNode = new Node(value) ;  

   if (head == nullptr)
   {
        head = newNode ;  
   }

   else 
   {
        Node *current = head ; 
        while (current->next != nullptr)
        {
            current = current -> next ; 
        }
        current -> next = newNode ; //
   }
}


void display()
{
    Node *currentNode ;
    if (head==nullptr) cout << "Linked List Empty\n";
    else 
    {
        currentNode = head ;
        while (currentNode != nullptr) // haed != nullptr
        {
            cout << currentNode ->data <<endl;
            currentNode = currentNode ->next ; 
        }
    }
}

Node *deleteLastNode(Node *head)
{
    if (head == nullptr)
    {
        return nullptr ; 
    }

    if (head->next == nullptr) 
    {
        delete head;
        return nullptr;
    }

    Node *secondNode = head ; 
    while (secondNode->next->next != nullptr) //
    {
        secondNode = secondNode->next ; 

    }
    delete secondNode -> next ;
    secondNode->next = nullptr ; 
    return head ;

}

void Sum()
{
    Node* temp = head;
    if (temp == nullptr) cout <<"LinkedList is Empty";

    int sum = 0;
    while(temp != nullptr)
    {
        sum = sum + temp->data;
        temp = temp->next;
    }
    cout<<"Sum of the elements is : "<<sum<<endl;
}

void Max()
{
    Node* temp = head;

    if (temp == nullptr) cout <<"LinkedList is Empty";

    int max = temp->data;
    while(temp != nullptr)
    {
        if(temp->data > max)
        {
            max = temp->data;
        }

        temp = temp->next;
    }
    cout<<"The maximum value is : "<<max<<endl;
}

void Even()
{
  Node* Temp = head;
  while(Temp != nullptr)
  {
  	 if(Temp->data%2==0)
  	{
  	         cout<<Temp->data<<endl;
	}
  	Temp = Temp->next;
  }
}

void insFront(int value)
{
	Node* newNode= new Node(value);
	newNode->next = head;  
	head = newNode;
}

// defulat insert 
// void insLast(int value)
// {
// 	Node* newNode=new Node(value);   
// 	newNode->next=nullptr;

// 	if(head == nullptr)
// 	{
// 		head = newNode;
// 	}

// 	else
// 	{
// 		Node* Temp = head;  
// 		while(Temp->next != nullptr)
// 			Temp = Temp->next;  
// 		Temp->next = newNode;
// 	}
// }


int main()
{
    insertNode(2);
    insertNode(4);
    insertNode(6);
    insertNode(8);
    insertNode(10);
    insFront(0);
    display();
    deleteLastNode(head);
    cout<<"---------------------\n";
    display();
    Sum();
    Max();
    // Even();
    return 0 ; 
}