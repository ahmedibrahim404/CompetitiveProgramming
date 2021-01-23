#include <iostream>

using namespace std;
typedef long long ll;
string a;
ll b;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> a >> b;

    int len=a.length();
    ll sum=0;
    for(int i=0;i<len;i++) sum += a[i]-'0';

    ll cur=0;
    for(int i=0;i<len;i++){
        cur=(cur*10+(a[i]-'0'))%b;
    }
    if(cur < 0) cur += b;
    cur %= b;
    if(cur == 0) printf("%.12lf", 1.0*sum/b);
    else printf("-1.000000000000\n");
    return 0;
}
