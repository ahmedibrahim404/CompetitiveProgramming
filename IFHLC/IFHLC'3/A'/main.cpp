#include <iostream>

using namespace std;

int T, n, ns[100000+9];
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=0;i<n;i++) cin >> ns[i];
        bool mod=0, done=0;
        for(int i=0;i<n-1;i++){
            if(ns[i] < ns[i+1]){
                if(mod == 0) continue;
                cout << "No\n";
                done=1;
                break;
            } else if(ns[i] > ns[i+1]){
                if(mod == 0 && i != 0) mod=1;
                else if(mod==0 && i == 0){
                    cout << "No\n";
                    done=1;
                    break;
                }
            } else {
                cout << "No\n";
                done=1;
                break;
            }
        }
        if(!done){
            if(mod==1) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}
