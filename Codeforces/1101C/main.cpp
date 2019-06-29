#include<bits/stdc++.h>
using namespace std;

struct seg {
    int idx, from, to;
};

int T, n, l, r;
vector<seg> ns;
int ans[100000+9];

bool cmpr(seg s2, seg s1){
    return s2.from < s1.from;
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        ns=vector<seg>(n);
        for(int i=0;i<n;i++){
            ns[i].idx=i;
            scanf("%d %d", &ns[i].from, &ns[i].to);
        }
        sort(ns.begin(), ns.end(), cmpr);

        int t=ns[0].to, i;
        for(i=1;i<n;i++){
            if(ns[i].from > t) break;
            else t=max(t, ns[i].to);
        }

        if(i == n){
            printf("-1\n");
            continue;
        } else {
            for(int j=0;j<n;j++){
                if(j >= i) ans[ ns[j].idx ]=2;
                else ans[ ns[j].idx ]=1;
            }
        }

        for(int i=0;i<n;i++) printf("%d ", ans[i]);
        printf("\n");
    }

    return 0;
}
