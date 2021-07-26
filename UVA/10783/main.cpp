#include <iostream>

using namespace std;

int T, a, b;
int main(){
    scanf("%d", &T);
    for(int i=1;i<=T;i++){
        scanf("%d %d", &a, &b);
        int n=(b-a)/2 + 1;
        if(a%2==0) a++;
        if(b%2==0) b--;
        double ans=((double)n/2)*(a+b);
        printf("Case %d: %d\n", i, (int) ans);
    }
    return 0;
}
