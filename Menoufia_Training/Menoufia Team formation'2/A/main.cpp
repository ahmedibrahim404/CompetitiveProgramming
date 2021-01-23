#include<bits/stdc++.h>

using namespace std;
int n, ns[100+3], no, cnt[100+3];
int main(){
    scanf("%d",&n);
    int idx=0;
    for(int i=0;i<=100;i++) cnt[i]=ns[i]=0;
    for(int i=0;i<n;i++){
        scanf("%d",&no);
        if(cnt[no]) continue;
        cnt[no]++;
        ns[idx++]=no;
    }

    if(idx>3){
        printf("-1\n");
        return 0;
    }

    if(idx==1){
        printf("0\n");
    } else if(idx==2){
        sort(ns, ns+2);
        if((ns[1]-ns[0])%2)
        printf("%d\n", (ns[1]-ns[0]));
        else printf("%d\n", (ns[1]-ns[0])/2);
    } else {
        sort(ns, ns+3);
        if(ns[1]-ns[0]==ns[2]-ns[1]) printf("%d\n", (ns[1]-ns[0]));
        else printf("-1\n");
    }


    return 0;
}
