#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;int ns[n];
    for(int i=0;i<n;i++){
        cin >> ns[i];
    }


    int ans = ns[n-1];
    for(int i=n-2;~i;i--){
        ans = abs(ans - ns[i]);
    }

    cout << ans << endl;

    return 0;
}
