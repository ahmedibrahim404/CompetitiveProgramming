#include<bits/stdc++.h>
using namespace std;

int t, n, m;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        bool yes[n][m];
        memset(yes, 0, sizeof yes);
        vector<int> cnt[m];
        for(int i=0;i<m;i++) cnt[i].clear();
        bool is=0;int no;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> no;
                if(no)cnt[j].push_back(i);
            }
        }

        for(int i=0;i<m;i++){
            int sz=cnt[i].size();
            if(sz==2){
                if(yes[ cnt[i][0] ][ cnt[i][1] ]){
                    is=1;
                    break;

                }
                yes[ cnt[i][0] ][ cnt[i][1] ]=1;
                continue;
            }
            is=1;
            break;
        }

        if(is) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}
