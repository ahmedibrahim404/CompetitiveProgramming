#include <iostream>

using namespace std;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        int w, h, n;
        scanf("%d%d%d",&w,&h,&n);
        int cnt=1;
        while(w%2==0){
            cnt*=2;
            w/=2;
        }
        while(h%2==0){
            cnt*=2;
            h/=2;
        }
        if(cnt >= n) printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}
