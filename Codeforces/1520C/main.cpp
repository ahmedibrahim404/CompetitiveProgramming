#include <iostream>

using namespace std;

int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        if(n==2){
            cout << "-1\n";
            continue;
        }
        int cur=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << cur << " ";
                cur += 2;
                if(cur > n*n){
                    cur=2;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
