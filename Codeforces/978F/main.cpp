#include<bits/stdc++.h>
using namespace std;

int n, k, a, b;
int rs[200000+9], ans[200000+9];
map<int, int> mp;
int main(){
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d", &rs[i]);
        mp[i]=rs[i];
    }

    sort(rs, rs+n);

    for(int i=0;i<k;i++){
        scanf("%d %d", &a, &b);
        a--, b--;
        if(mp[b] < mp[a]) ans[a]++;
        if(mp[a] < mp[b]) ans[b]++;
    }

    for(int i=0;i<n;i++){
        ans[i]=lower_bound(rs, rs+n, mp[i])-rs-ans[i];
        printf("%d ", ans[i]);
    }

    return 0;
}
