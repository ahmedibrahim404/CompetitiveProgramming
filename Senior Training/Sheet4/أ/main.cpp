#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;

bool is(ll no){
    return ((double) sqrt(no) * sqrt(no)) == ((double) no);
}

int main(){
    cin >> N;

    for(ll i=0;i*i<=min(N, (ll) 1e18);i++){
        if(is(N - i*i)){
            cout << i << " " << sqrt(N - i*i) << "\n";
            return 0;
        }
    }

    cout << "No Solutions\n";

    return 0;
}
