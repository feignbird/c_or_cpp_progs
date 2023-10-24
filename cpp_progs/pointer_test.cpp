#include <bits/stdc++.h>
using namespace std;

void increment_this(int* z){
    cout << "incrementing_this: " << z << endl;
    ++*z;
}

int main(){
    int i=5, j=5, k=0x53;
    // int* pointr = &i;
    // cout << "i: " << &i << " and j: " << &j << endl;
    // cout << "pointer: " << pointr << endl;
    // cout << "&pointer: " << &pointr << endl;
    // cout << "&pointer: " << *pointr << endl;
    // cout << "j - i: " << &j - &i << endl;
    // cout << "&k: " << k << endl;

    cout << "i: " << i << endl;
    increment_this(&i);
    cout << "i: " << i << endl;
    return 0;
}