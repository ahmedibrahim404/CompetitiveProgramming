#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector< pair<int, int> > ns;
int main(){


    scanf("%d", &n);
    ns=vector<pair<int, int>>(n);
    int idx=0;
    for(int i=0;i<n;i++){
        scanf("%d", &ns[idx].first);
        ns[idx].second=1;
        idx++;
    }

    scanf("%d", &m);
    ns.resize(n+m);
    for(int i=0;i<m;i++){
        scanf("%d", &ns[idx].first);
        ns[idx].second=2;
        idx++;
    }
    sort(ns.begin(), ns.end());

    int res=n*3-m*3;
    int a=n*3, b=m*3;
    int na=a, nb=b;

    for(int i=0;i<n+m;i++){
        if(ns[i].second == 1){
            na--;
        } else {
            nb--;
        }

        if(na - nb > res){
            res=na-nb;
            a=na, b=nb;
        }
    }

    printf("%d:%d", a, b);

    return 0;
}
