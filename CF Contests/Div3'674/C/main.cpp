#include<bits/stdc++.h>
using namespace std;
int t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int no=ceil((double)sqrt(n));
        cout << ((n+no-1)/no)+no-2 << "\n";
    }
    return 0;
}
