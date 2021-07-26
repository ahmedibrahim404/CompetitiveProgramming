#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool ch[26];
char str[209];
int n;
void clr(){
    for(int i=0;i<26;i++) ch[i]=false;
}

int main(){

    scanf("%d %s", &n, str);
    int mxcnt=0;
    for(int i=0;i<n;i++){
        if(!islower(str[i])) continue;
        int cnt=1;
        clr();
        ch[ str[i]-'a' ]=true;
        for(int j=i+1;j<n;j++){
            if(!islower(str[j])) break;
            if(!ch[ str[j]-'a' ])ch[ str[j]-'a' ]=true, cnt++;
        }
        mxcnt=max(mxcnt, cnt);
    }

    printf("%d", mxcnt);

    return 0;
}
