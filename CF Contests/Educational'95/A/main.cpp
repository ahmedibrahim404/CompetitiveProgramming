#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll x, y, k;
int main(){
    cin >> t;
    while(t--){
        cin >> x >> y >> k;
        ll tot=k+y*k-1;
        cout << (tot+x-2)/(x-1)+y*k << endl;
    }
    return 0;
}
