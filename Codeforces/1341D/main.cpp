#include<bits/stdc++.h>
using namespace std;
const int MAX=2000 + 5;
int n, k;
string str[MAX];
bool dp[MAX][MAX];
bool vis[MAX][MAX];
int can[MAX][10];
string ans;
bool solve(int idx, int rem){

    if(idx==n) return rem ==0;

    bool &ret=dp[idx][rem];
    if(vis[idx][rem]) return ret;
    vis[idx][rem]=1;
    ret=0;
    for(int i=9;i>=0;i--){
        int cost=can[idx][i];
        if(cost == -1) continue;
        if(rem < cost) continue;
        bool cur=solve(idx+1, rem-cost);
        if(cur){
            ret=1;
            break;
        }
    }

    return ret;

}

void build(int idx, int rem){

    if(idx==n) return;

    bool &ret=dp[idx][rem];
    for(int i=9;i>=0;i--){
        int cost=can[idx][i];
        if(cost == -1) continue;
        if(rem < cost) continue;
        bool cur=solve(idx+1, rem-cost);
        if(cur){
            ans += to_string(i);
            build(idx+1, rem-cost);
            break;
        }
    }


}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> str[i];
    memset(vis, 0, sizeof vis);
    ans="";
    string strs[] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    memset(can, 0, sizeof can);
    for(int i=0;i<n;i++){

        for(int j=0;j<10;j++){

            for(int k=0;k<7;k++){

                if(strs[j][k] == str[i][k]) continue;
                if(str[i][k] == '1'){
                    can[i][j]=-1;
                    break;
                }

                can[i][j]++;

            }

        }

    }

    if(!solve(0, k)){
        cout << "-1\n";
        return 0;
    }

    build(0, k);

    cout << ans << "\n";

    return 0;
}
