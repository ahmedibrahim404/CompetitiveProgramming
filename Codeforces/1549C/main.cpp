#include <iostream>

using namespace std;

int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    int cnt[n] = {0};
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        a--, b--;
        if(a > b) swap(a, b);
        cnt[a] ++;
    }

    int ans=0;
    for(int i=0;i<n;i++) if(!cnt[i]) ans++;

    int q;
    scanf("%d",&q);
    while(q--){
        int ty;
        scanf("%d",&ty);
        if(ty==3) printf("%d\n", ans);
        else {
            int a, b;
            scanf("%d%d",&a,&b);a--, b--;
            if(a>b) swap(a, b);
            if(ty == 1){
                cnt[a]++;
                if(cnt[a] == 1) ans--;
            } else {
                cnt[a]--;
                if(cnt[a] == 0) ans++;
            }
        }
    }

    return 0;
}
