#include <iostream>

using namespace std;
int T, n, k, ns[1000+9];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        if(ns[0]==-1){
            int cur=0;
            while(ns[cur]==-1){
                cur++;
            }
            ns[0]=(ns[cur]-cur+k)%k;
        }
        for(int i=1;i<n;i++){
            if(ns[i]==-1) ns[i] = (ns[i-1]+1)%k;
        }
        for(int i=0;i<n;i++) printf("%d ",ns[i]);
        printf("\n");
    }
    return 0;
}
