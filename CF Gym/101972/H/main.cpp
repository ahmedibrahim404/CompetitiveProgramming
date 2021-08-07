#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m, k;

int main(){
    cin >> t;
    while(t--){
        string a, b;
        cin >> n >> m >> k;
        cin >> a >> b;
        ll cur[26];for(int i=0;i<26;i++) cur[i]=0;
        ll bf[26][26];memset(bf, 0, sizeof bf);
        for(int i=0;i<m;i++){
            cur[ b[i]-'a' ]++;

            for(int j=0;j<26;j++){
                bf[ b[i]-'a' ][j] += cur[j];
            }
        }

        ll ans=0;
        set<pair<int, int>> st;
        for(int i=k-1;i<n;i++){
            int f=a[i]-'a', s=a[i-k+1]-'a';
            if(st.find({f, s}) != st.end()) continue;
            st.insert({f, s});
            ans += 1LL * bf[ f ][ s ];
        }

        cout << ans << endl;

    }
    return 0;
}
