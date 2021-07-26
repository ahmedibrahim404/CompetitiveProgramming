#include <iostream>

using namespace std;

int T, n, m;
int main(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        long long ans=0;
        for(int i=2;i<=min(n, m)+1;i++){
            ans += max(0LL, 1LL*(n-(i-1))*(m-(i-1)));
            ans += max(0LL, 1LL*(m-i)*(n-i));
        }

        cout << ans << "\n";
    }
    return 0;
}
