#include <iostream>

using namespace std;
typedef long long ll;
const int MAX=1000+5;
int t, a, b, n;
int as[MAX], bs[MAX], cs[MAX];
int dp[MAX][21 + 3][79 + 3];

int solve(int idx, int ca, int cb){
//    cout << idx << " " << ca << " " << cb << "\n";
    if(ca == 0 && cb == 0) return 0;
    if(idx==n) return 2e9;
    int &ret=dp[idx][ca][cb];
    if(~ret) return ret;
    ret=solve(idx+1, ca, cb);
    ret=min(ret, cs[idx]+solve(idx+1, max(0, ca-as[idx]), max(0, cb-bs[idx])));
    return ret;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        scanf("%d",&n);
        for(int i=0;i<n;i++) for(int j=0;j<=a;j++) for(int k=0;k<=b;k++) dp[i][j][k]=-1;
        for(int i=0;i<n;i++) scanf("%d%d%d",&as[i],&bs[i],&cs[i]);
        printf("%d\n", solve(0, a, b));

    }
    return 0;
}
