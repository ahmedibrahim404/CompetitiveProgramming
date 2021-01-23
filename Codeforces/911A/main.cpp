#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll ns[100000+9];
int main(){

    scanf("%d", &n);

    ll mi=1e10;
    int midx=1e8;
    for(int i=0;i<n;i++){
        scanf("%lld", &ns[i]);
        mi = min(mi, ns[i]);
    }

    int pre=-1;
    for(int i=0;i<n;i++){

        if(ns[i] == mi){
            if(pre != -1)midx=min(midx, i-pre);
            pre=i;
        }
    }

    printf("%d", midx);


    return 0;
}
