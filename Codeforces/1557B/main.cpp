#include<bits/stdc++.h>
using namespace std;

int t, k, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        int z=0;
        int ns[n], ms[n];for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
            ms[i]=ns[i];
        }
        map<int, int> mp;
        sort(ms, ms+n);
        for(int i=0;i<n;i++){
            mp[ ms[i] ]=i;
        }

        for(int i=1;i<n;i++){
            if(mp[ns[i]] -  mp[ns[i-1]] == 1 || mp[ns[i]] -  mp[ns[i-1]]  == 0) continue;
            z++;
        }
        z++;
        if(z > k) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
