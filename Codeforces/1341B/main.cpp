#include <iostream>

using namespace std;
int t, n, k;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        int ns[n];
        for(int i=0;i<n;i++) cin >> ns[i];
        int p[n];
        for(int i=0;i<n;i++) p[i]=0;
        for(int i=1;i<n-1;i++){
            if(ns[i] > ns[i-1] && ns[i] > ns[i+1]) p[i]=1;
        }
        for(int i=1;i<n;i++) p[i] += p[i-1];
        // i => i+k-1
        int mx=0, l=0;
        for(int i=0;i<n;i++){
            if(i+k-1 >= n) continue;
            int no=p[i+k-2]-p[i];
            if(no > mx) mx=no, l=i;
        }
        cout << mx+1 << " " << l+1 << "\n";
    }
    return 0;
}
