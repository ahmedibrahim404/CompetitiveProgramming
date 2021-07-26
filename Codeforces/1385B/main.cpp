#include <iostream>

using namespace std;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        bool is[n];
        for(int i=0;i<n;i++) is[i]=0;
        for(int i=0;i<2*n;i++){
            int no;
            scanf("%d",&no);
            if(!is[no-1]){
                is[no-1]=1;
                printf("%d ", no);
            }
        }
        printf("\n");
    }
    return 0;
}
