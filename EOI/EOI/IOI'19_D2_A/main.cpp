#include<bits/stdc++.h>

using namespace std;
int T, N, K, ns[100000+9];

bool can(int no){
    int cur=ns[0], groups=1;
    if(cur < no) return 0;
    for(int i=1;i<N;i++){
        if((cur & ns[i]) >= no){
            cur &= ns[i];
        } else {
            groups++, cur=ns[i];
            if(cur < no) return 0;
        }
    }
    if(groups <= K && cur >= no) return 1;
    return 0;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d", &N, &K);
        int mi=1e9;
        for(int i=0;i<N;i++) scanf("%d", &ns[i]), mi=min(mi, ns[i]);
        int st=0, en=1e9;
        for(int i=31;i && en >= st;i--){
            int mid=(st+en)>>1;
            if(can(mid)) st=mid+1;
            else en=mid-1;
        }
        printf("%d\n", st-1);
    }
    return 0;
}
