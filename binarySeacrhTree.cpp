#include <iostream>
using namespace std;

class BST {
    private:
        struct Node
        {
            int data;
            Node* left;
            Node* right;

            Node(int value)
            {
                data = value ; 
                left = right = nullptr;
            }
        };

      
        Node *root = nullptr;

    public:
        // with iterative method
        void insert(int value)
        {
            Node* newNode = new Node; // create a new node in the heap memory
            newNode->data = value;
            newNode->left = nullptr; // because it added a leaf node
            newNode->right = nullptr; // ```````````````````````````
        
            if (root == nullptr) // the tree is Empty
            {
                root = newNode; // frist node in the tree
                return;
            }

            Node* temp = root; 
            Node *parent = nullptr;

            while (temp != nullptr) // 
            {
                parent = temp; // keep track of the parent node
                if (value <= temp->data)
                {
                    // delete root from the tree and add left root node in temp
                    temp = temp->left ; 
                }
                else {
                    // delete root from the tree and add right root node in temp
                    temp = temp->right ; 
                }
            }

            if (value <= parent->data)
            {
                parent->left = newNode;
            }
            else 
            {
                parent->right = newNode;
            }
        }
        
        void recursiveInsert(Node *temp , int value)
        {
            if(value <= temp->data)
            {
                if (temp->left == nullptr)
                {  
                    temp->left = new Node(value);
                }
                else 
                {
                    recursiveInsert(temp->left , value);
                }
            }
            else 
            {
                if (temp->right == nullptr)
                {
                    temp->right = new Node(value);
                }
                else 
                {
                    recursiveInsert(temp->right , value);
                }
            }
        }
        
        // with recursive method
        void add(int value)
        {
            if (root==nullptr)
            {
                root = new Node(value);
            }
            else 
            {
                recursiveInsert(root , value);
            }
        }
         
};



int main() {
   
    return 0;
}

