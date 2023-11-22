// Question link
// https://www.hackerrank.com/contests/code-wrangler-challenge/challenges/zs-kingdom-1

#include<iostream>
#include<algorithm>
using namespace std;
/**
 * input:
 * n h
 * a1 a2 a3 ... an
 *
 * output:
 * min value of k
 */

/*
template<typename T, size_t Size>
istream& operator>>(istream& in, T (&arr)[Size]){
    for_each(begin(arr),end(arr),[&in](auto &elem){
        in >> elem;
    });
    return in;
}
    // cin >> t;

*/

int main()
{
    int n, h;
    cout << "Input (n h): ";
    cin >> n >> h;
    int t[n] = { 0 };
    cout << "\nInput (t1 t2 t3 ... tn): ";
    // ERROR on below line
    // for_each(begin(t), end(t), [](auto& elem) { cin >> elem; });
    cout << "\n";
    cout << "n: " << n << "\nh: "<< h;
    for (int i=0;i<n;i++)
        cout << t[i] << " ";
    cout << "\n";
    return 0;
}
