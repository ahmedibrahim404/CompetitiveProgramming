
#include <iostream>

using namespace std;

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int ns[26];
        int odd=0;
        int cnt=0, mn=2e9;
        for(int i=0;i<26;i++){
            scanf("%d",&ns[i]);
            if(ns[i] > 1) cnt++, mn=min(mn, ns[i]);
            if(ns[i] == 1) odd++;
        }



        if(!cnt) if(odd)printf("%d %d\n",1, odd); else printf("0 0\n");
        else {
            printf("%d", cnt*2 + (odd?1:0));
            printf(" %d\n", odd ? (odd >= mn/2 ? mn/2 : odd) : (mn/2));
        }
    }

    return 0;
}
