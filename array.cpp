#include <iostream>
using namespace std;
class Array
{
private :
    int size;
    int length;
    int* items;
public :
    // constructor
    Array(int arrsize){
        size = arrsize;
        length = 0;
        items = new int[arrsize];
    }
    // done 
    void Fill()
    {
        int num_of_items;
        cout << "How many items you want to fill ? \n";
        cin >> num_of_items;
        if (num_of_items > size)
        {
            cout << "You cannot exceed the array size \n";
            return;
        }
        else
        {
            for (int i = 0; i < num_of_items; i++)
            {
                cout << "Enter item num " << i << endl;
                cin >> items[i];
                length++;

            }
        }
      }
    // done 
    void Display()
    {
        cout << "Display Array content \n";
        // genral for loop 
        for (int i = 0; i < length; i++)
        {
            cout << items[i] << "\t";
        }
        cout << endl;
    }
    // done 
    int getSize()
    {
        return size;
    }
    // done 
    int getLength()
    {
        return length;
    }
    // done 
    int Search(int key)
    {
        int index = -1;
        for (int i = 0; i < length; i++)
        {
            if (items[i] == key)
            {
                index = i;
                break;
         }
          
        }
  return index;
    }
    void Append(int newitem)
    {
        if (length < size)
        {
            items[length] = newitem;
            length++;
        }
        else
            cout << "Array is full \n";
    }
    void Insert(int index, int newitem)
    {
        if (index >= 0 && index < size)
        {
            for (int i = length; i > index; i--)
            {
                items[i] = items[i - 1];
            }
            items[index] = newitem;
            length++;
        }
        else
        {
            cout << " Error - Index out of Range \n";
        }
    }
    void Delete(int index)
    {
        if (index >= 0 && index < size)
        {
            for (int i = index; i < length - 1; i++)
                items[i] = items[i + 1];
            length--;
        }
        else
            cout << "Index out of Array Range \n";
    }
    void Enlarge(int newsize)
    {
        if (newsize <= size)
        {
            cout << "New size must be larger than current size \n";
            return;
        }
        else
        {
            size = newsize;
            int* old = items;
            items = new int[newsize];
            for (int i = 0; i < length; i++)
            {
                items[i] = old[i];
            }
            delete[ ]old;

        }
    }
    void Merge(Array other)
    {
        int newsize = size + other.getSize();
        size = newsize;
        int* old = items;
        items = new int[newsize];
        int i;
        for ( i = 0; i < length; i++)
        {
            items[i] = old[i];
        }
        delete[]old;
        int j = i;
        for (int i = 0; i < other.getLength(); i++)
        {
            items[j++] = other.items[i];
            length++;
        }

    }
};
int main()
{
    Array arr(6) ; 
    

    
    return 0;    
}