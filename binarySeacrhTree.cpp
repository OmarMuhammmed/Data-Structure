#include <iostream>
#include <queue>
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
        
        int getMaxRecursive(Node* temp)
        {
            if (temp->right == nullptr)
            {
                return temp->data;
            }
            else 
            {
                return getMaxRecursive(temp->right);
            }
        }

        int getMinRecursive(Node* temp)
        {
            if (temp->left == nullptr)
            {
                return temp->data;
            }
            else 
            {
                return getMinRecursive(temp->left);
            }
        }

        int getHeightHelper(Node* temp)
        {
            if (temp == nullptr)
            {
                return -1;
            }
            // H = 1 + max (left subtree height        , right subtree height)
            return 1 + max(getHeightHelper(temp->left) , getHeightHelper(temp->right));
        }

    public:
        // with iterative method
        void insertIterative(int value)
        {
            Node* newNode = new Node(value); // create a new node in the heap memory
            
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
        
        // with recursive method
        void insertRecursive(int value)
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

        // with Iterative method
        int getMax()
        {
            Node* temp = root; // track the root node
            while (temp->right != nullptr)
            {
                temp = temp->right;
            }
            return temp->data;
        }       
       
        int getMin()
        {
            Node* temp = root; // track the root node
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }
            return temp->data;
        } 

        // with recursive method
        int getmax()
        {
            return getMaxRecursive(root);
        }

        int getmin()
        {
            return getMinRecursive(root);
        }

        int getHeight(Node* temp)
        {
            if (root==nullptr)
            {
                return -1 ;
            }
            else 
            {
                return getHeightHelper(root);
            }
        }


        void displayLevelOrder()
        {
            if (root == nullptr) return ; 
            queue<Node*> q ; 
            q.push(root) ; 

            while(!q.empty())
            {
                Node* current = q.front();
                q.pop() ;

                cout << current->data <<" ";
                if (current->left != nullptr) 
                    q.push(current->left);
                if (current->right != nullptr)
                    q.push(current->right);
            }    
            cout<<endl;
        }
};



int main() {

    BST tree;
    tree.insertIterative(10);
    tree.insertIterative(5);
    tree.insertIterative(15);
    tree.insertIterative(3);
    tree.insertIterative(7);
    tree.insertIterative(12);
    tree.insertIterative(18);
    cout<<"Max : "<<tree.getMax();
    cout<<"\nMin : "<<tree.getMin()<<endl;
    tree.displayLevelOrder();
    return 0;
}

