#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int n;
pi ns[500000+9];

bool cmpr(pi p2, pi p1){
    return p2.second < p1.second;
}

int main(){

    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d %d", &ns[i].first, &ns[i].second);
    sort(ns, ns+n, cmpr);

    int last=-1, cnt=0;

    for(int i=0;i<n;i++){
        if( ns[i].first > last )
            cnt++, last=ns[i].second;
    }

    printf("%d", cnt);

    return 0;
}
