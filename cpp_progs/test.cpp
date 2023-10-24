// test.cpp
#include <bits/stdc++.h>

using namespace std;
int main(){
    char *ch, *A[2];
    A[0] = "C++ is the best";
    A[1] = "and a powerful language";
    ch = A[0];
    cout << "Hello world" << endl; // Hello world
    cout << "\n\tA: " << A << endl; // C++ is the best
    cout << "\n\t&A: " << &A << endl; // base address of A (address of A[0] pointer)
    cout << "\n\t&A[0]: " << &A[0] << endl; // C++ is the best
    cout << "\n\t*A[0]: " << *A[0] << endl; // C
    cout << "\n\t*A: " << *A << endl; // C++ is the best

    cout << "\n\tch: " << ch << endl; // C++ is the best
    cout << "\n\t*ch: " << *ch << endl; // C

    /*
    for(int x=0;x<=1000;x++){
        cout << "number: " << pow(2, x) << endl;
    }
    */
    return 0;
}
