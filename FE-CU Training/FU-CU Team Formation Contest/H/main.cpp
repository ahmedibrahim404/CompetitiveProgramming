#include <iostream>
#include <cstring>
using namespace std;
const int MAX=100+3;
int dp[MAX][MAX][MAX], ns[MAX];
int t, n, k;

int solve(int idx, int pre, int cnt){


    if(idx==n) return 0;
    int &ret=dp[idx][pre][cnt];
    if(~ret) return ret;
    ret=0;
    ret=solve(idx+1, pre, cnt);

    if(ns[idx]>ns[pre]){
        ret=max(ret, solve(idx+1, idx, cnt+1));
        if(cnt+1>=k){
            ret=max(ret, cnt+1+solve(idx+1, n, 0));
        }
    }

    return ret;
}

//bool vis[MAX];
//void build(int idx=0){
//
//    if(idx==n) return;
//
//    int ret=dp[idx];
//    if(vis[idx]) return;
//    vis[idx]=1;
//    int pre=-1e9, took=0;
//    if(ret==solve(idx+1)){
//        build(idx+1);
//        return;
//    }
//    for(int i=idx;i<n;i++){
//
//        if(ns[i]>pre){
//            pre=ns[i];
//            took++;
//            if(took>=k){
//                if(ret==took+solve(i+1)){
//                    cout << "TOOK FROM " << idx << " TO " << i << " NO OF " << took << endl;
//                    build(i+1);
//                    return;
//                }
//            }
//        }
//    }
//}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        ns[n]=-1e9;
        for(int i=0;i<n;i++){
            cin >> ns[i];
        }
        for(int i=1;i<=n;i++){
            k=i;
            memset(dp, -1, sizeof dp);
            cout << solve(0, n, 0) << " ";
        }
        cout << endl;
    }

    return 0;
}
