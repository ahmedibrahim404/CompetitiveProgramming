#include <iostream>

using namespace std;
typedef long long ll;
int t, n, k, z;


int main(){
    cin >> t;
    while(t--){
        cin >> n >> k >> z;
        ll ns[n+5], mx[n+5], val1[n+5], val2[n+5];
        for(int i=0;i<n;i++){
             cin >> ns[i];
        }
        mx[0]=0;
        for(int i=0;i<n-1;i++){
            mx[i] = ns[i]+ns[i+1];
            if(i) mx[i]=max(mx[i], mx[i-1]);
        }

        for(int i=1;i<n;i++) ns[i] += ns[i-1];

        ll ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<=z;j++){
                int rem=k-2*j;
                if(rem >= 0) ans=max(ans,  ns[rem]+(j*mx[rem]));
            }
        }

        cout << ans << "\n";

    }
    return 0;
}
