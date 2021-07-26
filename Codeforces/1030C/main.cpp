#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, mx=0;
char a[100+9];
int ns[100+9];
int calc(int num){

    int last=0, bits=0;
    for(int i=0;i<n;i++){
        last += a[i]-'0';
        if(last == num) last=0, bits++;
    }

    if(last == 0 && bits>1) return 1;
    return 0;

}

int main(){

    scanf("%d %s", &n, a);
    for(int i=0;i<n;i++){
        mx += a[i]-'0';
    }

    int st=0, en=mx;

    for(int i=0;i<=en;i++){
        if(calc(i)){
            return printf("YES\n", i), 0;
        }
    }

    return printf("NO\n"), 0;
}
