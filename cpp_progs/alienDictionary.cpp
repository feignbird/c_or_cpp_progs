/**
 * problem statement
 * list of words are given ['work', 'world', 'row']
 * noOfWords = 3
 * order = "btpgvraxjyukesiqznchofwmdl"
 * 
 * check if the words are lexicographically sorted
 * 
*/

// CPP reference
// https://www.geeksforgeeks.org/c-classes-and-objects/

#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

bool alienDictionary(int n, vector<string> &words, string &order){
    cout << "n: " << n << endl;
    //cout << "words: " << words << endl;
    cout << "order: " << order << endl;
    return true;
}

// class customVector: vector{

// }

int main(){
    int n = 3;
    vector<string> words({"work", "word", "row"});
    string order = "btpgvraxjyukesiqznchofwmdl";
    cout << "In main" << endl;
    cout << "\tn: " << n << endl;
    //cout << "\twords: " << words << endl;
    cout << "\torder: " << order << endl;
    //alienDictionary(n, words, )
    return 0;
}


/*

// Time Complexity: O(W)

// Space Complexity: O(1)

// where ‘W’ total number of letters in ‘WORDS’ array.

bool alienDictonary(int n, vector<string> &words, string &order)

{

vector<int> rank(26, 0);

for(int i = 0; i < 26; i++){

rank[order[i] - 'a'] = i;

}

// Transforming the words to form transformedWords

for(string& word : words){

for(char& c : word)

{

c = (char) 'a' + rank[c - 'a'];

}

}

for(int i = 1 ; i < n; i++){

if(words[i-1] > words[i]){

return false;

}

}

return true;

}
*/