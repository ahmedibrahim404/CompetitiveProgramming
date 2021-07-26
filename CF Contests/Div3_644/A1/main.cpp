#include <iostream>

using namespace std;
int t, n, ns[100+3];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++ )scanf("%d",&ns[i]);
        for(int i=n-1;i>=0;i--){
            printf("%d", ns[i]);
            if(i!=0) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
