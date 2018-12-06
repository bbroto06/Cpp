/*
Video explanation at : https://youtu.be/qsMahidcehY
Q. Given a class A, we want to know at any time, how many objects of A live in the heap memory ?
Note : It requires knowledge on 6 C++ Principles :-
1. Static data member in Classes.
2. How to define static data members ?
3. Constructors / Destructors.
4. Memory Allocation - Stack v/s Heap
5. Dynamic Memory
6. Difference between new/delete and malloc/free.
*/

#include <iostream>
using namespace std;

class A{
public:
    static int x;
    A(){
         // x++; // Un-comment to increment the count of stack instances of A
    }
    ~A(){
        // x--; // Un-comment to decrement the count of stack instances of A
    }
    
    void* operator new (size_t size){
        x++;
    }
    
	/* Even after overloading delete method, it is not decrementing the counter */
    void operator delete (void* size){
        x--;
    }
};

int A::x = 0;


int main()
{
    /* local --> stack */
    A a, b;
    A c, d, e;
    
    
    /* dynamic --> heap */
    // A* ptr = (A*) malloc(sizeof(A)); // [C style memory allocation] malloc only allocates memory; it does not call constructor
    //free(ptr); // [C style memory de-allocation] only de-allocate memory; doesn't call the destructor
    
    A* ptr_A = new A; // [C++ style memory allocation] allocates memory and calls the constructor as well
    A* ptr_A1 = new A;
   
    delete ptr_A; // [C++ style memory de-allocation] decrement x in destructor

    
    cout << A::x << endl; // To count instances of A

}
