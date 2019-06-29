#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ns[100000+9];

int main(){

    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%d", &ns[i]);

    int ans=0;
    for(int i=0;i<n;i++){
        ans += ns[i]/m+(bool(ns[i]%m));
    }

    printf("%d", ans/2 + (ans&1));

    return 0;
}
