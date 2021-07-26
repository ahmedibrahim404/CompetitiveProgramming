#include <iostream>

using namespace std;

int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int ns[n];
        for(int i=0;i<n;i++) ns[i] = i+1;
        for(int i=0;i<n-1;i+=2){
            swap(ns[i], ns[i+1]);
        }

        if(n&1){
            swap(ns[n-1], ns[n-2]);
        }

        for(int i=0;i<n;i++) printf("%d ", ns[i]);
        printf("\n");

    }
    return 0;
}
