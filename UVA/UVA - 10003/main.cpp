#include<bits/stdc++.h>
using namespace std;
const int MAX=50+5;
int l, n, no;
vector<int> vi;
int dp[MAX][MAX];

int solve(int st, int en){

    if(st+1==en) return 0;

    int &ret=dp[st][en];
    if(~ret) return ret;
    ret=1e9;
    for(int i=st+1;i<en;i++){
        ret=min(ret, solve(st,i)+solve(i, en)+(vi[en]-vi[st]));
    }

    return ret;

}

int main(){
    while(cin >> l && l){
        cin >> n;
        vi.clear();
        vi.push_back(0);
        for(int i=0;i<n;i++){
            cin >> no;
            vi.push_back(no);
        }
        vi.push_back(l);
        int sz=vi.size();
        for(int i=0;i<sz;i++) for(int j=0;j<sz;j++) dp[i][j]=-1;
        printf("The minimum cutting is %d.\n", solve(0, vi.size()-1));
    }
    return 0;
}
