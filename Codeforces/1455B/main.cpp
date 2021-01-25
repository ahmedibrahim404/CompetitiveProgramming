#include <iostream>

using namespace std;
typedef long long ll;
ll t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        // summation is 1 + 2 + 3 + 4 + ... + k
        // we can remove any digit and replace it with -1


        ll st=1, en=n, ans=n;
        while(en>=st){
            ll mid=(st+en)/2;
            if(mid*(mid+1) >= 2*n) en=mid-1, ans=mid;
            else st=mid+1;
        }

        cout << ans + ((ans*(ans+1))/2 - n == 1 ? 1 : 0) << "\n";


    }
    return 0;
}
