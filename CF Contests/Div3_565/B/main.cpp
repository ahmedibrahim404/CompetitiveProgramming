#include<bits/stdc++.h>
using namespace std;


int t, n, no;
int cnt[3];
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for(int i=0;i<n;i++) {
            scanf("%d", &no);
            cnt[ (no%3) ]++;
        }
        int ans=cnt[0];
        ans += min(cnt[1], cnt[2]);
        ans += (cnt[1]-(min(cnt[1], cnt[2])))/3;
        ans += (cnt[2]-(min(cnt[1], cnt[2])))/3;
        printf("%d\n", ans);
    }
    return 0;
}
