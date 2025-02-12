#include <iostream> 
using namespace std; 

// recursive function
int factorial(int n) 
{
    if (n == 0 || n == 1)    // Base case (not contain func call) Must Created
        return 1 ; 

    else  
        // recursive case  
        return  n * factorial(n-1) ;    
}
int main() {
    cout << "Enter num to count the factorial : "<<endl;
    int n ;
    cin >> n ;  
    cout <<factorial(-1) << endl ; 
    return 0;
}