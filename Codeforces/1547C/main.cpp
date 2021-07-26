#include <iostream>

using namespace std;

int t, k, n, m;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&k,&n,&m);
        int ns[n], ms[m], ans[n+m+1];
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        for(int i=0;i<m;i++) scanf("%d",&ms[i]);
        int i=0, j=0, l=0;
        while(true){
            bool is=0;


            if(i < n && ns[i] <= k){
                ans[l++]=ns[i];
                if(!ns[i])k++;
                i++;is=1;
                continue;
            }

            if(j < m && ms[j] <= k){
                ans[l++]=ms[j];
                if(!ms[j])k++;
                j++;is=1;
                continue;
            }

            if(!is) break;

            }

        if(l == n + m){
            for(int i=0;i<l;i++) printf("%d ", ans[i]);
            printf("\n");
        } else printf("-1\n");


        }


    return 0;
}
