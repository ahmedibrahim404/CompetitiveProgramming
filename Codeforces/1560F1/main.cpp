#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int k;
vector<ll> v[12];
void solve(ll cur=0, int dif=0, int j=1){
    if(cur > 2e10) return;
    v[j].push_back(cur);
    bool arr[10]= {0};
    ll ncur=cur;
    while(ncur){
        arr[ncur%10]=1;
        ncur/=10;
    }

    for(ll i=0;i<=9;i++){
        if(arr[i]) solve(cur*10+i, dif, j);
        else if(dif+1 <= j)solve(cur*10+i, dif+1, j);
    }

}

int main(){
    for(int j=1;j<=2;j++){
        solve(0, 0, j);
        sort(v[j].begin(), v[j].end());
    }
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int idx = lower_bound(v[k].begin(), v[k].end(), n) - v[k].begin();
        cout << v[k][idx] << endl;
    }
    return 0;
}
