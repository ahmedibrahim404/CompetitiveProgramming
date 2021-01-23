#include <iostream>
#include <math.h>
using namespace std;
typedef long double ld;
typedef long long ll;

ld a, b, f;
int main(){
    cin >> a >> b >> f;
    ld c=sqrt((a*a)+(b*b));
    ll d=ceil(c/f);
    ll ans=max(1LL, d*d);
    cout << (ll)ans << endl;
    return 0;
}
