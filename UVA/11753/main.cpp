#include <iostream>

using namespace std;

int t, n, k, ns[10000+9];

int solve(int st, int en, int cnt){
    if(cnt > k) return 1e9;
    if(st >= en) return cnt;
    if(ns[st] == ns[en]) return solve(st+1, en-1, cnt);
    else return min(solve(st+1, en, cnt+1), solve(st, en-1, cnt+1));
}

int main(){
    scanf("%d", &t);
    int cs=1;
    while(t--){
        scanf("%d %d", &n, &k);
        for(int i=0;i<n;i++) scanf("%d", &ns[i]);
        int cnt=solve(0, n-1, 0);
        if(cnt == 0) printf("Case %d: Too easy\n", cs++);
        else if(cnt > k) printf("Case %d: Too difficult\n", cs++);
        else printf("Case %d: %d\n", cs++, cnt);
    }

    return 0;
}
