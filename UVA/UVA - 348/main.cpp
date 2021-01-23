#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAX=10+1;
int N;
int dp[MAX][MAX];
pi ns[MAX];
string bld[MAX][MAX];
bool vis[MAX][MAX];
int solve(int l=0, int r=N-1){

    if(l+1==r) return ns[l].first*ns[l].second*ns[r].second;
    if(l==r) return 0;

    int&ret=dp[l][r];
    if(~ret) return ret;
    ret=1e9;
    for(int i=l;i<r;i++){
        ret=min(ret, solve(l, i)+solve(i+1, r)+ns[r].second*ns[l].first*ns[i].second);
    }

    return ret;

}

string build(int l=0, int r=N-1){

    if(l+1==r) return "(A"+to_string(l+1)+" x A"+to_string(r+1)+")";
    if(l==r) return "A"+to_string(l+1);

    int ret=dp[l][r];
    string &res=bld[l][r];
    if(vis[l][r]) return res;
    vis[l][r]=1;

    for(int i=l;i<r;i++){
        int ret2 =solve(l, i)+solve(i+1, r)+ns[r].second*ns[l].first*ns[i].second;
        if(ret==ret2){
            res = "("+build(l, i)+" x "+build(i+1, r)+")";
            break;
        }
    }

    return res;

}

int main(){
    int cs=1;
    while(cin >> N && N){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) dp[i][j]=-1, vis[i][j]=0;
            scanf("%d%d",&ns[i].first, &ns[i].second);
        }
        int cost=solve(0, N-1);
        cout << "Case " << cs++ << ": " << build() << endl;
    }

    return 0;
}
