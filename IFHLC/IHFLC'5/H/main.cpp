#include<bits/stdc++.h>
using namespace std;

int T;
long long a, b;
int main(){
    cin >> T;
    while(T--){
        cin >> a >> b;
        if(__gcd(a, b) != 1) cout << "Sim\n";
        else cout << "Nao\n";
    }
    return 0;
}
