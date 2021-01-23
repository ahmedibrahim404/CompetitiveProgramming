#include<bits/stdc++.h>
using namespace std;

int ns[4];

int main(){
    for(int i=0;i<4;i++)
    cin >> ns[i];
    sort(ns, ns+4);

    if(ns[3]-ns[1]==ns[2]-ns[0]) printf("YES\n");
    else printf("NO\n");

    return 0;
}
