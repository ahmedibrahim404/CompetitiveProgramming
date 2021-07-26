#include <iostream>

using namespace std;

int T, K, N;
int main(){
    freopen("chief.in", "r", stdin);
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N >> K;
        cout << (N/K) << " " << (N%K) << "\n";
    }
    return 0;
}
