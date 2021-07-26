#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ns[100000+9];

int solve(int d, int n){

    if(d >= ns[n-1]) return n;
    if(d < ns[0]) return 0;
    // 3 6 8 10 11
    int start=0, end=n;
    int mid, res=0;
    while(end >= start){

        mid = (start+end)/2;

        if(d >= ns[mid]) res=mid+1, start=mid+1;
        else end=mid-1;

    }

    return res;

}



int main(){
    int n, x, q, m;

    scanf("%d", &n);

    for(int i=0;i<n;i++) scanf("%d", &ns[i]);
    sort(ns, ns+n);

    scanf("%d", &q);

    while(q--){

        scanf("%d", &m);
        printf("%d\n", solve(m, n));

    }

    return 0;
}
