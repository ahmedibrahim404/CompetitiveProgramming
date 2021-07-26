#include <iostream>
#include <math.h>

using namespace std;

int idxs[100000+9], ns[100000+9];
int n, m, k, a;
long long c=0;
int main(){
    scanf("%d %d %d", &n, &m, &k);

    for(int i=1;i<=n;i++){
        scanf("%d", &a);
        idxs[a]=i;
        ns[i]=a;
    }

    for(int i=0;i<m;i++){
        scanf("%d", &a);
        c+=ceil((double)idxs[a]/k);
        if(idxs[a] == 1) continue;
        swap(ns[idxs[a]-1], ns[idxs[a]]);
        idxs[ns[idxs[a]]]=idxs[ns[idxs[a]-1]];
        idxs[ns[idxs[a]-1]]=idxs[ns[idxs[a]]]-1;
    }

    printf("%lld", c);

    return 0;
}
