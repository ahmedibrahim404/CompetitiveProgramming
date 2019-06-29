#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n1, n2, n3;
string a, b, c, sec;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> a >> b;
    c = to_string(atoi( a.c_str() ) + atoi( b.c_str() ));

    a.erase(remove(a.begin(), a.end(), '0'), a.end());
    b.erase(remove(b.begin(), b.end(), '0'), b.end());
    c.erase(remove(c.begin(), c.end(), '0'), c.end());

    sec = to_string(atoi( a.c_str() ) + atoi( b.c_str() ));

    if(c == sec) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
