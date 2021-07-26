#include<bits/stdc++.h>

using namespace std;
const int MAX=2000+3;
int n;
int main(){
    scanf("%d",&n);
    if(n&1){
        printf("%d\n", (n/2+1)*(n/2+2)*2);
    } else {
        printf("%d\n", (n/2+1)*(n/2+1));
    }
    return 0;
}
