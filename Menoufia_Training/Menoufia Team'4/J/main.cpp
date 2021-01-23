#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll arr[100000+3];
map<ll, int> mp;

int main()
{

    int n,ans=0; cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
//        if(mp.find(arr[i])==mp.end())
//        mp[ arr[i] ]=1;
//        else
//        mp[ arr[i] ]++;
    }
    sort(arr, arr+n);

//    ll pre=0;
//    for(auto elem: mp){
//        mp[ elem.first ] += pre;
//        pre += elem.second;
//    }


//    int f=0,l=n-1, m=(f+l)/2;
    for(int m=0;m<n;m++){
        int idx=upper_bound(arr, arr+n, arr[m])-arr;
        idx--;
        if(idx>=arr[m]){
            ans=max(ans, idx+1);
        }
    }
    cout << ans << "\n";
}
