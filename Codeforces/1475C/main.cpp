#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t, a, b, k;
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b >> k;
        int fir[a+3], sec[b+3], no;
        pair<int, int> ns[k+3];
        memset(fir, 0, sizeof fir);
        memset(sec, 0, sizeof sec);
        for(int i=0;i<k;i++){
            cin >> no;
            fir[no]++;
            ns[i].first = no;
        }
        for(int i=0;i<k;i++){
            cin >> no;
            sec[no]++;
            ns[i].second=no;
        }

        ll ans=0;
        for(int i=0;i<k;i++){
            ans += (1LL)*(k-fir[ ns[i].first ]-sec[ ns[i].second ]+1);
        }

        cout << ans/2 << "\n";


    }
    return 0;
}
