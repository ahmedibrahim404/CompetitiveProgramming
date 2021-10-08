#include<bits/stdc++.h>
using namespace std;

int main(){

    /*

        5 3
        5 1 2 3 4

        0 => 3, 4
        1 => 4
        2 =>
        3 => 0
        4 => 0, 1

    */

    int t;
    scanf("%d",&t);
    while(t--){

        int n, x;
        scanf("%d%d",&n,&x);
        int ns[n];
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
        }

        if(x * 2 - 1 < n){
            cout << "YES\n";
            continue;
        }

        if(2*x-1 >= n && is_sorted(ns+(n-x), ns+x-1)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }

    return 0;
}
