#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;ll arr[n+2];
        ll sum=0;
        map<ll, int> st;
        for(int i=0;i<n+2;i++){
            cin >> arr[i];
            sum += arr[i];
            st[arr[i]]++;
        }

        int idx = -1;
        for(int i=0;i<n+2;i++){
            ll fir = sum - 2*arr[i];
            if(st[fir] > (fir == arr[i])) {
                idx = i;
                break;
            }
        }

        if(idx == -1) {
            cout << "-1\n";
            continue;
        }

        int idx2 = -1;
        for(int i=0;i<n+2;i++){
            if(arr[i] == sum - 2 * arr[idx] && i != idx){
                idx2 = i;
                break;
            }
        }

        if(idx == -1 || idx2 == -1) {
            cout << "-1\n";
            continue;
        }

        for(int i=0;i<n+2;i++){
            if(i == idx || i == idx2) continue;
            cout << arr[i] << " ";
        }
        cout << "\n";

    }
    return 0;
}
