#include<bits/stdc++.h>
using namespace std ;

const int N = 2e3+5 ;

int t ,n ,a[N][N] ,cnt[N] ;
int q ,idx ,k ;
int main(){
    cin >> t ;
    while(t--){
        cin >> n ;
        for(int i=0;i<n;++i) cin >> a[0][i] ;
        for(int i=1;i<=n;++i){
            memset(cnt, 0, sizeof cnt);
            for(int j=0;j<n;++j) ++cnt[a[i-1][j]] ;
            for(int j=0;j<n;++j) a[i][j] = cnt[a[i-1][j]] ;
        }
        cin >> q ;
        while(q--){
            cin >> idx >> k ;
            cout << a[min(k,n)][--idx] << endl ;
        }
    }
    return 0;
}
