#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, N, K;
int ns[100000+9][33];
int nodes[100000+9];


int solve(int idx, int zeros){

    if(idx == N) return 0;

    int &ret = ns[idx][zeros];

    if(ret != -1) return ret;

    if(zeros == 0){
        ret=max( solve(idx+1, zeros), solve(idx+1, nodes[idx])+1 );
        return ret;
    }

    ret = solve(idx+1, zeros);

    if(nodes[idx] >= zeros && nodes[idx] - zeros <= K)
        ret=max(ret, solve(idx+1, nodes[idx])+1);

    return ret;
}

int main(){

    scanf("%d", &T);

    while(T--){
        scanf("%d %d", &N, &K);
        memset(ns , -1 , sizeof(ns)) ;
        for(int i=0;i<N;i++){
            scanf("%d", &nodes[i]);
            nodes[i]=__builtin_popcount(nodes[i]);
        }

        printf("%d\n", solve(0, 0));
    }

    return 0;
}
