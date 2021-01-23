#include <iostream>

using namespace std;
typedef long long ll;
const int MAX=2000+3;
ll dp[MAX][MAX], ns[MAX];
int n;

ll solve(int l=0, int r=n-1){

    if(l>r) return 0;
    ll &ret=dp[l][r];
    if(~ret) return ret;
    int age=l+(n-1)-r+1;
    ret=max( 1LL*age*ns[l]+solve(l+1, r), 1LL*age*ns[r]+solve(l, r-1) );
    return ret;

}

int main(){
    for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) dp[i][j]=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&ns[i]);
    }

    printf("%lld\n", solve(0, n-1));

    return 0;
}
