#include <iostream>

using namespace std;
int q, n;
int ty(char no){
    if(no-'0' <= 2) return 1;
    return 2;
}
int main(){
    cin >> q;
    while(q--){
        cin >> n;
        string a, b;
        cin >> a >> b;
        bool can=1;
        bool cur=0;
        for(int i=0;i<n;i++){
            if( (ty(a[i])==2 && ty(b[i])==2) ){
                cur = ! cur;
                continue;
            }
            if((cur&&ty(b[i])==1)||(!cur && ty(a[i])==1)) continue;
            can=0;
        }

        if(can && cur) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}
