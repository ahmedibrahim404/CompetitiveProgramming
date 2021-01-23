#include <iostream>

using namespace std;

int n, ns[200000+9], pos[200000+9], is[200000+9];
int main(){
    scanf("%d",&n);
    int mx=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&ns[i]);
        pos[ ns[i] ]=i;
        if(ns[i]>ns[mx]) mx=i;
    }

    for(int i=1;i<mx;i++){
        is[ ns[i] ]=1;
    }

    for(int i=mx+1;i<=n;i++) is[ ns[i] ]=2;

    int mxx=ns[mx], rl=0, rr=0;
    for(int i=mxx-1;i;i--){

        if(is[i]==1 && abs(pos[i]-mx)-rl <= 1){
            rl++;
            continue;
        } else if(is[i]==2 && abs(pos[i]-mx-rr) <= 1){
            rr++;
            continue;
        } else return printf("NO\n"), 0;
    }

    printf("YES\n");





    return 0;
}
