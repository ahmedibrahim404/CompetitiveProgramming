#include <iostream>

using namespace std;

int t;

int main(){
    scanf("%d",&t);
    while(t--){
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        if(a == b || a == c || b == c) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
