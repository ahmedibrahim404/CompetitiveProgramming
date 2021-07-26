#include <iostream>
#include<algorithm>
using namespace std;

int n, k;
int ns[100000+9];

int main(){

    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++) scanf("%d", &ns[i]);
    sort(ns, ns+n);

    int sup=0, cur=0;
    while(k--){

        while(cur < n && ns[cur]-sup <= 0) cur++;
        if(cur == n) printf("0\n");
        else printf("%d\n", ns[cur]-sup);
        sup+=( ns[cur]-sup );

    }

    return 0;
}
