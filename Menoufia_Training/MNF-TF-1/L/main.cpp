#include <iostream>

using namespace std;

string s;
int main(){
    cin >> s;
    int len=s.length(), as=0, bs=0, ac=0, bc=0;
    for(int i=0;i<len;i++) if(s[i] =='A') as++; else bs++;
    for(int i=0;i<len;i++){
        if(s[i]=='A') ac++;
        else bc++;
        if(as-ac==ac && bs-bc==bc) return cout << "YES\n" << i+1 << " " << len << endl, 0;
    }
    cout << "NO" << endl;
    return 0;
}
