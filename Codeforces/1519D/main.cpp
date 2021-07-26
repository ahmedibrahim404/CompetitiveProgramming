#include <iostream>

using namespace std;
typedef long long ll;
const int MAX=5000+3;
int t,n;ll as[MAX], bs[MAX];
int main(){


    int t=1;
    while(t--){
        cin >> n;
        ll tot=0;
        for(int i=0;i<n;i++) cin >> as[i];
        for(int i=0;i<n;i++){
            cin >> bs[i];
            tot += as[i] * bs[i];
        }

        ll ans=tot;
        for(int i=0;i<n;i++){
            int l=i, r=i+1;
            ll cur=tot;
            while(l >= 0 && r < n){

                cur -= as[l] * bs[l];
                cur -= as[r] * bs[r];

                cur += as[l] * bs[r];
                cur += as[r] * bs[l];

                ans=max(ans, cur);

                l--;
                r++;
            }

        }

        for(int i=0;i<n;i++){
            int l=i-1, r=i+1;
            ll cur=tot;
            while(l >= 0 && r < n){

                cur -= as[l] * bs[l];
                cur -= as[r] * bs[r];

                cur += as[l] * bs[r];
                cur += as[r] * bs[l];

                ans=max(ans, cur);

                l--;
                r++;
            }

        }

        cout << ans << "\n";


    }

    return 0;
}
