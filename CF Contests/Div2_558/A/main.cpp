#include <iostream>

using namespace std;
int n, m;
int main(){
    scanf("%d %d", &n, &m);

    int res=1, a=1, removed=0;
    for(int i=1;i<=m;i++){
        if(a > n) break;
        res+=(a!=1) && (a!=n);
        removed++;
        a+=2;
    }

    if(removed != m){
        res-=(m-removed);
    }

    printf("%d", res);

    return 0;
}
