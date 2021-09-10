#include <iostream>

using namespace std;

string s;

int main(){

    cin >> s;
    int n=s.length();int c=0;

    for(int i=0;i<n;i++){
        if(i+1 < n && s.substr(i, 2) == "10") {c++; continue;}
        if(i+2 < n && s.substr(i, 3) == "100") {c++; continue;}
        if(i+2 < n && s.substr(i, 3) == "110") {c++; continue;}
        if(i+3 < n && s.substr(i, 4) == "1010") {c++; continue;}
    }

    if(c&1) printf("Alice");
    else printf("Bob\n");


    return 0;
}
