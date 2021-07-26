#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX=2e5+5;
int cnt=0;
vector<int> vi;
void solve(){
    vector<bool> is_prime(MAX, true);
    is_prime[0]=is_prime[1]=0;
    for (int i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            vi.push_back(i);
            cnt++;
            for (int j = 2*i; j < MAX; j += i)
                is_prime[j] = false;
        }
    }
}

int dp[MAX+5];
int is[MAX+5];
int solveDP(int no){
    if(no > MAX) return 0;
    int &ret=dp[no];
    if(ret != -1) return ret;
    int sz=vi.size();
    ret=0;
    for(int i=0;i<sz;i++){
        if(no*vi[i] > MAX) break;
        ret=max(ret, solveDP(no*vi[i]));
    }
    ret += is[no];
    return ret;
}

int t, n, ns[MAX];
int main(){

    cin >> t;
    solve();

    while(t--){
        cin >> n;
        memset(dp, -1, sizeof dp);
        memset(is, 0, sizeof is);
        int idx=0, no;
        for(int i=0;i<n;i++){
            cin >> no;
            is[no]++;
            ns[i]=no;
        }

        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx, solveDP(ns[i]));
        }

        cout << n-mx << "\n";



    }
    return 0;
}
