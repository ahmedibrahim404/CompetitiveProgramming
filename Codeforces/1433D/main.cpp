#include <iostream>

using namespace std;
int t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int ns[n];
        bool c=0;
        for(int i=0;i<n;i++){
            cin >> ns[i];
            if(i && ns[i] != ns[i-1]) c=1;
        }
        if(!c) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        int fo=-1;
        for(int i=1;i<n;i++){
            if(ns[i] == ns[0]) continue;
            cout << 1 << " " << i+1 << "\n";
            if(fo==-1) fo=i;
        }

        for(int i=1;i<n;i++){
            if(ns[i]==ns[0]){
                cout << fo+1 << " " << i+1 << "\n";
            }
        }


    }
    return 0;
}
