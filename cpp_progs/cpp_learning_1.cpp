#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    cout << "Hello, world, I'm learning c++ wooohooo!" << endl;
    char str[40];
    int m1, m2, m3, avgMarks;
    cout << "Enter your name : ";
    cin >> str;
    cout << "Enter marks of your subjects : \n";
    cin >> m1 >> m2 >> m3;
    cout << "Hi " << str << ", welcome to average marks calculator program" << endl;
    avgMarks = (m1+m2+m3)/3;
    cout << "Your average marks are : " << avgMarks << endl;
    return 0;
}
