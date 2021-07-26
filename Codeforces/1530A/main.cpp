#include <iostream>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
    scanf("%d",&n);
    int mx=1;
    while(n){
        mx=max(mx, n%10);
        n/=10;
    }
    printf("%d\n", mx);
}
    return 0;
}
