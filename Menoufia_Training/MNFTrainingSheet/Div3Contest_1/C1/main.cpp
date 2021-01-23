#include <iostream>

using namespace std;
int T,n, ns[101], no;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<101;i++) ns[i]=0;
        for(int i=0;i<n;i++){
            scanf("%d",&no);
            ns[no]++;
        }
        int tot=0;
        for(int i=1;i<=100;i++){
            int mx=0, add=0;
            for(int j=1;j<=50;j++){
                if(i>j){
                    if(i==2*j) add+=ns[j]/2;
                    else mx+=min(ns[j], ns[i-j]);
                }
            }
            if(mx/2+add>tot){
                tot=mx/2+add;
            }
        }
        printf("%d\n", tot);

    }



    return 0;
}
