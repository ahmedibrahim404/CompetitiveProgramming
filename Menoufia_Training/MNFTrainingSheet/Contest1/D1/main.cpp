#include<bits/stdc++.h>
using namespace std;


const int MAX=1e5+1;
vector<pair<int,int>> np[MAX];

int T, N, mx=0, M, L, R, no;
int dp[MAX+1];
int main(){

    scanf("%d",&T);
    while(T--){
        mx=0;
        no=1;
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d%d", &M,&L);
            R=L;
            for(int k=0;k<M-1;k++) scanf("%d",&R);
            np[L].push_back(make_pair(R, M));
            no=max(no, R);
        }

        dp[no+1]=0;
        for(int i=no;i>0;i--){
            dp[i]=dp[i+1];

            for(auto j:np[i]){
                if(j.first+1<MAX)
                dp[i]=max(dp[i], j.second+dp[j.first+1]);
                else
                dp[i]=max(dp[i], j.second);
            }
            mx=max(mx, dp[i]);
            np[i].clear();
        }


        printf("%d\n", mx);
    }

    return 0;
}
