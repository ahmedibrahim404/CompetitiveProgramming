#include<bits/stdc++.h>
using namespace std;
const int MAX=35+1;
int n, m;
int ns[MAX];

vector<int> st;
int mx=0;

void solve1(int idx=0, int mod=0){

    if(idx==n/2){
        mx=max(mx, mod);
        st.push_back(mod);
        return;
    }

    solve1(idx+1, mod);
    mod += ns[idx];
    mod %= m;
    solve1(idx+1, mod);

}

void solve2(int idx=0, int mod=0){

    if(idx==n){
        // mod
        mx=max(mx, mod);
        int idx=lower_bound(st.begin(), st.end(), m-1-mod)-st.begin();
        if(idx==st.size()) idx--;
        if(st[idx]+mod>=m) idx--;
        if(idx) mx=max(mx, (mod+st[idx])%m);
        return;
    }

    solve2(idx+1, mod);
    mod += ns[idx];
    mod %= m;
    solve2(idx+1, mod);

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> ns[i];
    }

    solve1(0, 0);
    sort(st.begin(), st.end());
    solve2(n/2, 0);

    cout << mx << endl;

    return 0;
}
