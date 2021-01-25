#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX=2e5+5;

int dp[MAX+5];
int is[MAX+5];
int solveDP(int no){
    if(no > MAX) return 0;
    int &ret=dp[no];
    if(ret != -1) return ret;
    int sz=vi.size();
    ret=0;
    for (int j = 2 * no; j < MAX; j += no) {
      ret = max(ret, solveDP(j));
    }
    ret += is[no];
    return ret;
}

int t, n, ns[MAX];
int main(){

    cin >> t;

    while(t--){
        cin >> n;
        memset(dp, -1, sizeof dp);
        memset(is, 0, sizeof is);
        int idx=0, no;
        for(int i=0;i<n;i++){
            cin >> no;
            is[no]++;
        }

        int mx=0;
        for(int i=1;i<MAX;i++){
            mx=max(mx, solveDP(i));
        }

        cout << n-mx << "\n";



    }
    return 0;
}
