#include<bits/stdc++.h>
using namespace std;
int n, ns[100+3];
bool is[100+3];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
            scanf("%d",&ns[i]);
        is[ ns[i] ]=0;
    }
    sort(ns, ns+n);
    int cnt=0;
    for(int i=0;i<n;i++){

        if(!is[ ns[i] ]){
            cnt++;
            is[ ns[i] ]=1;
            for(int j=ns[i];j<=100;j+=ns[i]){
                is[j]=1;
            }
        }

    }

    printf("%d\n", cnt);
    return 0;
}
