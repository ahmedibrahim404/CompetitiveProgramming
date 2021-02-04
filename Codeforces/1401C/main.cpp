#include<bits/stdc++.h>
using namespace std;
const int MAX=100000+3;
int t, n, as[MAX];
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        map<int, vector<int>> mp, mp2;
        set<int> st;
        int mi=2e9;
        for(int i=0;i<n;i++){
            cin >> as[i];
            mp2[ as[i] ].push_back(i);
            mi=min(mi, as[i]);
        }
        sort(as, as+n);
        for(int i=0;i<n;i++){
            mp[ as[i] ].push_back(i);
        }
        bool can=1;
        for(int i=0;i<n;i++){
            if(st.find(as[i]) != st.end()) continue;
            sort(mp[ as[i] ].begin(), mp[ as[i] ].end());
            sort(mp2[ as[i] ].begin(), mp2[ as[i] ].end());
            st.insert(as[i]);
            int sz=mp[ as[i] ].size();
            for(int j=0;j<sz;j++){
                if(mp[as[i]][j] != mp2[as[i]][j]){
                    if(as[i] % mi){
                        can=0;
                        break;
                    }
                }
            }
            if(!can) break;
        }

        if(can){
            cout << "YES\n";
        } else cout << "NO\n";

    }
    return 0;
}
