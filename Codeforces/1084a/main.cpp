#include <iostream>

using namespace std;

int n, as[100+9], ans=0, fi=1e9;

int main(){

    scanf("%d", &n);
    int mx=0;
    for(int i=0;i<n;i++){
        scanf("%d", &as[i]);
    }

    for(int j=0;j<n;j++){
        mx=j, ans=0;
        for(int i=0;i<n;i++){
            ans += ( abs(mx-i) + i + mx ) * 2 * as[i];
        }
        fi=min(fi, ans);
    }



    printf("%d", fi);

    return 0;
}
