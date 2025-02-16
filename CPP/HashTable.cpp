#include <bits/stdc++.h>
using namespace std;

struct Hash {
    int BUCKET; 
    vector<vector<int>> table; 

    
    int hashFunction(int key) {
        return key % BUCKET;
    }

   
    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    
    void deleteItem(int key) {
        int index = hashFunction(key);
        auto it = find(table[index].begin(), table[index].end(), key);
        if (it != table[index].end()) {
            table[index].erase(it);
        }
    }

   
    void displayHash() {
        for (int i = 0; i < BUCKET; i++) {
            cout << i;
            for (int x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }

   
    Hash(int b) {
        this->BUCKET = b;
        table.resize(BUCKET);
    }
};

int main() {
    vector<int> keys = {15, 11, 27, 8, 12};

    Hash h(7); 
    for (int key : keys)
        h.insertItem(key);

    h.deleteItem(12); 
    h.displayHash();

    return 0;
}
