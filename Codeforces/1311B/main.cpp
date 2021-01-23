#include<bits/stdc++.h>
using namespace std;
int t, n, m;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        int ns[n];
        int is[m];
        for(int i=0;i<m;i++) is[i]=0;
        for(int i=0;i<n;i++){
            cin >> ns[i];
        }
        for(int i=0;i<m;i++){
            int no;
            cin >> no;
            no --;
            is[i]=no;
        }

        sort(is, is+m);

        for(int j=0;j<m;j++){
            for(int i=0;i<m;i++){
            if(ns[ is[i] ] > ns[ is[i] + 1 ]) swap(ns[ is[i] ], ns[ is[i]+1 ]);
        }

        }


        if(is_sorted(ns, ns+n)) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}
