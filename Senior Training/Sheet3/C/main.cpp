#include<bits/stdc++.h>

using namespace std;

const int MAX=5000+3;
int n;
int ns[MAX], ms[MAX], xs[MAX];
int main(){
    while(true){
        scanf("%d",&n);
        if(!n) break;
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
            ms[i]=ns[i];
        }

        sort(ms, ms+n);

        for(int i=0;i<n;i++){
            scanf("%d",&xs[i]);
        }

        sort(xs, xs+n);

        for(int i=0;i<n;i++){
            int idx=-1;
            for(int j=0;j<n;j++){
                if(ns[i]==ms[j]){
                    idx=j;
                    break;
                }
            }

            printf("%d\n", xs[idx]);
        }

        printf("\n");
    }



    return 0;
}
