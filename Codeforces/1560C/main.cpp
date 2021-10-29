#include <iostream>

using namespace std;
typedef long long ll;
int main(){

    int t;
    cin >> t;
    while(t--){

        ll n;cin>> n;

        ll st=1, en=1e5;
        while(en >= st){
            ll mid = (st+en)/2;
            if(mid * mid >= n) en=mid-1;
            else st=mid+1;
        }

        ll row = en+1;
        ll fir = 2*(row-1) + 1;
        ll lst = row*row;

        n -= (row-1)*(row-1);

        ll a1, a2;
        if(n > row){
            a1 = row;
            a2 = row-(n-row);
        } else {
            a2 = row;
            a1 = n;
        }

        cout << a1 << " " << a2 << endl;

    }

    return 0;
}
