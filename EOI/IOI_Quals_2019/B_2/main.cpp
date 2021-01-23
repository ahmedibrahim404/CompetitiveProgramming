#include<bits/stdc++.h>

using namespace std;
int T, N;
const int MAX=(3*1e5)+9;
int ns[MAX];

int main(){
    scanf("%d", &T);

    while(T--){

        scanf("%d", &N);
        int num, idx=0;
        for(int i=0;i<N*3;i++){
            scanf("%d", &ns[idx++]);
        }

        sort(ns, ns+idx);
        for(int i=0;i<N;i++) printf("%d ", ns[i]);
        printf("\n");


    }

    return 0;
}
