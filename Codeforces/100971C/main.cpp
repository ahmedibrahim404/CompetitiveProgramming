#include<bits/stdc++.h>
using namespace std;

int n;
int main(){
    scanf("%d",&n);int ns[n];
    for(int i=0;i<n;i++) scanf("%d",&ns[i]);
    sort(ns, ns+n);
    int tobe = ns[n-1] - ns[0] + 1;
    if(ns[0] + ns[1] > tobe) printf("YES\n%d\n", tobe);
    else printf("NO\n");
    return 0;
}
