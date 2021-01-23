#include <iostream>

using namespace std;
const int MAX=1000000+3;
int N, ns[MAX];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&ns[i]);
    int l=0, r=N-1;
    while(true){
        if(r < 0 || l >= N) break;
        if(ns[l]>ns[r]){
            printf("1 ");
            r--;
        } else if(ns[l]<ns[r]){
            printf("2 ");
            l++;
        } else {
            printf("0 ");
            r--, l++;
        }
    }
    if(l==r)printf("0");
    printf("\n");
    return 0;
}
