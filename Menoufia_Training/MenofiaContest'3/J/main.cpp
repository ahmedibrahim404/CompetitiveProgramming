#include <iostream>

using namespace std;
typedef long long ll;
ll a;
ll mod=1e9+7;
int main(){
    cin >> a;
    a %= mod;
    ll no=1;
    for(int i=1;i<=a;i++){
        no *= 2;
        no %= mod;
    }

    cout << ((no * (no+1))/2)%mod << endl;

    return 0;
}
