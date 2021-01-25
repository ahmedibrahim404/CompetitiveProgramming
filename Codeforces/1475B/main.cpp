#include <iostream>

using namespace std;
int t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        bool is=0;
        for(int i=0;i<=1000;i++){
            for(int j=0;j<=1000;j++){
                if(2020*i + 2021*j == n){
                    cout << "YES\n";
                    is=1;
                    break;
                } else if(2020*i + 2021*j > n){
                    break;
                }
            }
            if(is) break;
        }
        if(!is) cout << "NO\n";
    }
    return 0;
}
