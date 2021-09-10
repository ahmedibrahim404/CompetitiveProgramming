#include <iostream>

using namespace std;

int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);int ns[n];
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        bool can=ns[n-1] == 0;
        int st=n-1;
        for(int i=0;i<n-1;i++){
            if(ns[i] == 0 && ns[i+1] == 1) can=1, st=i;
        }

        if(ns[0] == 1){
            printf("%d ", n+1);
            for(int i=0;i<n;i++) printf("%d ", i+1);
            printf("\n");
            continue;
        }

        if(can){

            for(int i=0;i<n;i++){
                printf("%d ", i+1);
                if(i == st) printf("%d ", n+1);
            }
            printf("\n");

        } else printf("-1\n");


    }
    return 0;
}
