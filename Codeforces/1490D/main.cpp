#include <iostream>

using namespace std;
const int N=100+3;
int ns[N];
int getMax(int l, int r){
    if(r == l) return l;
    if(l > r) return -1;
    int mx=l;
    for(int i=l;i<=r;i++){
        if(ns[i] > ns[mx]) mx=i;
    }
    return mx;
}

int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
        }
        int l=0, r=n-1;
        int idx=getMax(l, r);
        for(int i=0;i<n;i++){
            int l=0, r=n-1;
            int cnt=0;;
            while(true){

                int idx=getMax(l, r);
                if(idx > i){
                    r=idx-1;
                    cnt++;
                } else if(idx < i){
                    l=idx+1;
                    cnt++;
                } else {
                    break;
                }

            }

            printf("%d ", cnt);


        }
        printf("\n");

    }
    return 0;
}
