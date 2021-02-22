#include<bits/stdc++.h>

using namespace std;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ns[n];
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
        }
        sort(ns, ns+n);
        bool done=0;
        for(int i=1;i<n;i++){
            if(ns[i] != ns[i-1]){
                cout << n-i << "\n";
                done=1;
                break;
            }
        }
        if(!done)
        cout << "0\n";
    }
    return 0;
}
