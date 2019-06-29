#include<bits/stdc++.h>

using namespace std;

int q, n, no;
vector<int> a, ty;
map<int, int> mp;
bool cmpr(int n2, int n1){
    return a[n2] > a[n1];
}

int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        mp.clear();
        ty=vector<int>(n), a=vector<int>(n);
        int idx=0, idx2=0;

        for(int i=0;i<n;i++){
            scanf("%d", &no);
            if(!mp.count(no)) mp[no]=idx2++;
            a[ mp[no] ]++;
            if(a[ mp[no] ]==1) ty[idx++]= mp[no];
        }

        ty.resize(idx);
        a.resize(idx2);
        sort(ty.begin(), ty.end(), cmpr);
        int can=a[ ty[0] ];
        long long total=0;
        for(int i=0;i<idx;i++){
            total += min(a[ ty[i] ], can);
            can=min(a[ ty[i] ]-1, can-1);
            if(can <= 0) break;
        }

        printf("%lld\n", total);

    }
    return 0;
}
