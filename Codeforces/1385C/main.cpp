#include <iostream>

using namespace std;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ns[n];
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        int stop=n-1;
        for(int i=n-2;i>=0;i--){
            if(ns[i+1] > ns[i]) break;
            stop=i;
        }
        int st=stop-1;
        for(int i=st-1;i>=0;i--){
            if(ns[i+1] < ns[i]) break;
            st=i;
        }
        if(st==-1) st=0;
        printf("%d\n", st);
    }
    return 0;
}
