#include <iostream>
using namespace std;


struct Node {
    int data;       
    Node* left;      
    Node* right;     

    Node(int val) 
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


Node* insert(Node* root, int val) {

    if (root == nullptr)  // Base case (to insert node here)
    {  
        return new Node(val); // retrun address of new node 
    }

    if (val < root->data) // recursive case
    { 
        root->left = insert(root->left, val); 
    } 

    else                 // recursive case
    {  
        root->right = insert(root->right, val); 
    }

    return root;  
}


bool search(Node* root, int val) {

    if (root == nullptr)  // لو وصلنا لأخر التري وملقناش القيمه 
    { 
        return false;
    }

    if (root->data == val) // Base case (لقينا القيمة)
    {  
        return true;
    }

    if (val < root->data) // recursive case
    {  
        return search(root->left, val);  
    }

    else                 // recursive case
    {                  
        return search(root->right, val); 
    }
}

// Delete Helper Functions
Node* findMin(Node* root) 
{
    while (root->left != nullptr) // ندور على أصغر قيمة
    {  
        root = root->left;
    }
    return root;
}



Node* deleteNode(Node* root, int val) 
{
    if (root == nullptr) { // Base case (لو وصلنا لأخر التري وملقناش القيمه) 
        return root;  
    }

    if (val < root->data) {  // recursive case (لو القيمه اصغر ندور في الفرع الشمال )
        root->left = deleteNode(root->left, val);
    }

    else if (val > root->data) {  // recursive case ( لو القيمه اكبر ندور في الفرع اليمين  )
        root->right = deleteNode(root->right, val);
    }

    else  // لقينا القيمة اللي عايزين نحذفها
    { 
        if (root->left == nullptr && root->right == nullptr) // لو العقدة ليها فرعين leaf node
        {  
            delete root;
            return nullptr;
        } 
        else if (root->left == nullptr) // لها فرع يمين  بس 
        {  
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)  // لو مفيش فرع يمين
        { 
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // لو العقدة ليها فرعين
        Node* temp = findMin(root->right);  // نجيب أصغر قيمة في اليمين
        // or Node* temp = findMax(root->left);  // نجيب أكبر قيمة في الشمال
        root->data = temp->data;         // نبدل القيم بتاعت العقده ال عاوز تحذفها ب القيمه دي 
        root->right = deleteNode(root->right, temp->data);  // نحذف القيمة
    }
    return root;
}

// 4. Functions للمرور على الشجرة (Traversal)

// (a) Inorder Traversal (ترتيب تصاعدي)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);  // الأول ندخل الشمال
    cout << root->data << " ";  // نطبع القيمة
    inorder(root->right);  // بعدين ندخل اليمين
}

// (b) Preorder Traversal
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";  // نطبع القيمة الأول
    preorder(root->left);  // بعدين ندخل الشمال
    preorder(root->right);  // وبعدين اليمين
}

// (c) Postorder Traversal
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);  // ندخل الشمال الأول
    postorder(root->right);  // بعدين اليمين
    cout << root->data << " ";  // نطبع القيمة في الآخر
}

int main() {
    Node* root = nullptr;  // الشجرة فاضية في البداية

    // إدخال القيم
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    cout << "Inorder Traversal: ";
    inorder(root);  // طباعة القيم بترتيب تصاعدي
    cout << endl;

    cout << "Search for 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;

    root = deleteNode(root, 50);  // حذف القيمة 50
    cout << "After Deletion of 50 (Inorder Traversal): ";
    inorder(root);  // طباعة القيم بعد الحذف
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
