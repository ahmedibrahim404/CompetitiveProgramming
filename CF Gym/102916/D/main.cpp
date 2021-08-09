#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin >> n;int ns[n];
    for(int i=0;i<n;i++) cin >> ns[i];
    sort(ns, ns+n, greater<int>());
    if(n == 1){
        cout << ns[0] << " " << 0 << "\n";
        return 0;
    } else if(n == 2){
        cout << ns[0] << " " << ns[1] << "\n";
        return 0;
    }

    double ans=1.0 * ns[0];int tot=n-1;
    long long tott=ns[0];
    for(int i=1;i<n;i++){
        int cur=ns[i];
        ans += (0.5) * cur;
        tott += 1LL*ns[i];
    }

    cout << setprecision(12) <<  ans << " " << (double) 1.0 * tott - ans << "\n";
    return 0;
}
