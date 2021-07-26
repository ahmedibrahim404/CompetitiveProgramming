#include <iostream>

using namespace std;

int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ns[n];
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        int l=0, r=n-1;
        while(l < r){
            printf("%d ", ns[l]);
            printf("%d ", ns[r]);
            l++;
            r--;
        }
        if(r==l) printf("%d", ns[l]);
        printf("\n");
    }
    return 0;
}
