#include <iostream>
using namespace std;
const int MAX=20000+3;
int cnt[MAX],T, n, no;
int dp[MAX];
int main(){
    cin >> T;
    while(T--){
        for(int i=0;i<MAX;i++) cnt[i]=dp[i]=0;
        cin >> n;
        int mx=0;
        for(int i=0;i<n;i++){
            cin >> no;
            if(cnt[no-1]>0){
                dp[no]=dp[no-1]+1;
            }
            cnt[no]++;
            dp[no]=max(dp[no], 1);
            mx=max(mx, dp[no]);
        }
        cout << mx << endl;
    }

    return 0;
}
