#include <iostream>

using namespace std;

int t,n,m;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        int a,b,c,d;
        bool is=0;
        for(int i=0;i<n;i++){
            cin >> a >> b >> c >> d;
            if(b==c) is=1;
        }

        if(m&1){
            cout << "NO\n";
            continue;
        }

        if(is){
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";



    }
    return 0;
}
