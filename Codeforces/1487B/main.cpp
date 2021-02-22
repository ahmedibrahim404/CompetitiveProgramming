#include <iostream>

using namespace std;

int t, n, k;

int main(){


    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        k--;
        if(k==0){
            printf("1\n");
            continue;
        }
        if(n%2==0){
            printf("%d\n", (k%n + 1));
        } else {
            k += (3 * k/(n - 1)) - 1;
            printf("%d\n", k % n + 1);
        }
    }
    return 0;
}
