#include <iostream>

using namespace std;
typedef long long ll;
int t;
ll l, r, m;

bool check(ll no){
    return no >= l && no <= r;
}

int main(){
    cin >> t;
    while(t--){
        cin >> l >> r >> m;
        for(ll st=l;st<=r;st++){
            // approach 1
            ll no=st-(m%st);
            if(no<=r-l){
            ll a=st;
            ll b=l, c=l+no;
            cout << a << " " << b << " " << c << endl;
            break;;
            }
         // approach 2
            no=m%st;
            if(no>r-l) continue;
            ll a=st;
            ll b=r;
            ll c=r-no;
            cout << a << " " << b << " " << c << endl;
            break;
        }
    }
    //10 12 43
    return 0;
}
