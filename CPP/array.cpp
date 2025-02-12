#include <iostream>
using namespace std;

void insert(int arr[], int& n, int value, int pos, int capacity) {
    if (n >= capacity) {
        cout << "Array is full, can't insert!" << endl;
        return;
    }

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1]; 
    }

    arr[pos] = value; 
    n++; 
}
void remove(int arr[], int& n, int pos) {
    if (pos >= n || pos < 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1]; 
    }

    n--; // تقلل عدد العناصر
}

int main() {
    int capacity = 10; 
    int arr[capacity] = {1, 2, 3, 4, 5};
    int n = 5; 

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    insert(arr, n, 99, 5, capacity); 

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    remove(arr, n, 2);
    cout<<"Array after deletion: ";     
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}