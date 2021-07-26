#include <iostream>

using namespace std;

int m, n, k, ns[1000], a, b;
int main(){
    scanf("%d %d %d", &m, &n, &k);
    for(int i=0;i<n;i++) ns[i]=k;
    for(int i=0;i<m;i++){
        scanf("%d %d", &a, &b);
        a--;
        ns[a]=min(ns[a], b);
    }


    int ans=0;
    for(int i=0;i<n;i++){
        int totake=min(ns[i], k);
        ans += totake;
        k-=totake;
    }

    printf("%d", ans);


    return 0;
}
