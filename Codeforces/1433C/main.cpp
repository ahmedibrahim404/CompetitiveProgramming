#include <iostream>

using namespace std;
int t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int mx=0, ns[n+1];
        for(int i=0;i<n;i++){
            int no;
            cin >> no;
            ns[i]=no;
            if(no > mx) mx=no;
        }

        bool f=0;
        for(int i=0;i<n;i++){
            if(ns[i]==mx){
                if((i-1 >= 0 && ns[i-1] < ns[i]) || (i+1<n && ns[i+1] < ns[i])){
                    cout << i+1 << "\n";
                    f=1;
                    break;
                }
            }
        }

        if(!f) cout << "-1\n";

    }
    return 0;
}
