#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;

pi ns[1000+3];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ns[i].first);
        ns[i].second=i+1;
    }
    sort(ns, ns+n, greater<pi>());
    int total=0;
    for(int i=0;i<n;i++){
        total+=(ns[i].first*i)+1;
    }

    printf("%d\n", total);
    for(int i=0;i<n;i++) printf("%d ", ns[i].second);

    return 0;
}
