#include <iostream>

using namespace std;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        int add=0;
        scanf("%d",&n);int ns[n];
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);

            if(i){
                int mx=ns[i] > ns[i-1] ? i : i-1;
                int mi=ns[i] < ns[i-1] ? i : i-1;
                int nmx = ns[mx], nmi=ns[mi];
                while((nmx+nmi-1)/nmi > 2){
                    add++;
                    nmi *= 2;
                }
            }
        }

        printf("%d\n", add);

    }
    return 0;
}
