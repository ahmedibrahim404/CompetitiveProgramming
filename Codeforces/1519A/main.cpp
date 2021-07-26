#include <iostream>

using namespace std;
int t, r, b, d;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&r,&b,&d);
        if(r > b) swap(r, b);
        b-=r;
        int need=(b+r-1)/r;
        if(need <= d){
            cout << "YES\n";
        } else cout << "NO\n";

    }
    return 0;
}
