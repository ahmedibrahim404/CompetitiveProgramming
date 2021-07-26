#include <iostream>

using namespace std;

int main(){
    freopen("alimagde.in", "r", stdin);
    int t, n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int cur=0, add=1;
        while(cur + add < n){
            cur += add;
            add++;
        }
        printf("%d\n", n-add+1);
    }
    return 0;
}
