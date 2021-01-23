#include <iostream>

using namespace std;
int t, n,ns[150000+3];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        int mi=1e8,c=0;;
        for(int i=n-1;i>=0;i--){
            if(ns[i] > mi) c++;
            if(ns[i] < mi) mi=ns[i];
        }
        printf("%d\n",c);
    }
    return 0;
}
