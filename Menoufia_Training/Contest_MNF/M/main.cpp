#include <iostream>

using namespace std;
char nth_letter(int n){
    return "abcdefghijklmnopqrstuvwxyz"[n];
}
string s;
int ns[26];
int main(){
    cin >> s;
    int len=s.length();
    for(int i=0;i<len;i++){
        ns[ s[i]-'a' ]++;
    }

    for(int i=0;i<25;i++){
        if(ns[i]>=2){
            ns[i+1] += ns[i]/2;
            ns[i]%=2;
        }
    }

    for(int i=25;i>=0;i--){
        for(int j=0;j<ns[i];j++) cout << nth_letter(i);
    }

    return 0;
}
