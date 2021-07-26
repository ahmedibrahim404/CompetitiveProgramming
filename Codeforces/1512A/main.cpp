#include<bits/stdc++.h>


using namespace std;

int main(){
int t;
scanf("%d",&t);
while(t--){
int n;
    scanf("%d",&n);int ns[n];
    for(int i=0;i<n;i++) scanf("%d",&ns[i]);
    for(int i=0;i<n;i++){
        if(count(ns, ns+n, ns[i]) == 1) {
        printf("%d\n", i+1);
        break;}
    }
}
    return 0;
}
