#include <iostream>

using namespace std;
typedef long long ll;
const int MAX=400+1;
int N;
ll ns[MAX];
ll dp[MAX][MAX];
ll solve(int l, int r){


    if(r<=l) return 0;

    ll &ret=dp[l][r];
    if(r-l+1==2){
        return ret=ns[r]-(l?ns[l-1]:0);
    }

    if(~ret) return ret;

    ret=1e18;
    for(int i=l;i<r;i++){
        ret=min(ret, solve(l, i)+solve(i+1, r)+ns[r] - (l>0?ns[l-1]:0) );
    }


    return ret;

}

int main(){
    scanf("%d",&N);
    for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) dp[i][j]=-1;
    for(int i=0;i<N;i++){
        scanf("%lld",&ns[i]);
        if(i) ns[i] += ns[i-1];
    }


    printf("%lld\n", solve(0, N-1));


    return 0;
}
