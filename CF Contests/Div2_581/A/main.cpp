#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    cin >> s;
    int len=s.length();
    bool is=1;
    for(int i=1;i<len;i++){
        if(s[i]=='1') is=0;
    }

    if(len%2==0&&is)is=0;

    printf("%d", (len+1)/2-is);
    return 0;
}
