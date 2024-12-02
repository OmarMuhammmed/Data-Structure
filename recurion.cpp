#include <iostream> 
using namespace std; 
int factorial(int n) {
   if (n==1) // Base case (not contain func call) 
   {

    return  1 ; 
    
   }
   else // recursive procedure 
   {
    return  n * factorial(n-1) ; 
   }
}
int main() {
    cout << "Enter num to count the factorial : "<<endl;
    int n ;
    cin >> n ;  
    cout <<factorial(n) << endl ; 
    return 0;
}