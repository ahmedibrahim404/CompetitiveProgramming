#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 3;
int par[N];

int get(int x){
    return par[x] = (x == par[x] ? x : get(par[x]));
}

void add(int a, int b){
    a=get(a);b=get(b);
    par[b]=a;
}

vector<int> combine(vector<int> v1, vector<int> v2){
    vector<int> ans =vector<int>(6);
    for(int i=0;i<3;i++) ans[i] = v1[i];
    for(int i=0;i<3;i++) ans[i+3] = v2[i];
    return ans;
}


int main(){

    freopen("triangles.in", "r", stdin);

    int t, n;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        map<vector<int>, int> mp;

        for(int i=0;i<n;i++){
            vector<int> v1 = vector<int>(3);
            vector<int> v2 = vector<int>(3);
            vector<int> v3 = vector<int>(3);

            scanf("%d%d%d",&v1[0], &v1[1], &v1[2]);
            scanf("%d%d%d",&v2[0], &v2[1], &v2[2]);
            scanf("%d%d%d",&v3[0], &v3[1], &v3[2]);

            vector<int> v=combine(v1, v2);
            if(mp.find(v) == mp.end()) mp[v] = i;
            else add(i, mp[v]);

            v=combine(v2, v1);
            if(mp.find(v) == mp.end()) mp[v] = i;
            else add(i, mp[v]);

            v=combine(v1, v3);
            if(mp.find(v) == mp.end()) mp[v] = i;
            else add(i, mp[v]);

            v=combine(v3, v1);
            if(mp.find(v) == mp.end()) mp[v] = i;
            else add(i, mp[v]);

            v=combine(v3, v2);
            if(mp.find(v) == mp.end()) mp[v] = i;
            else add(i, mp[v]);

            v=combine(v2, v3);
            if(mp.find(v) == mp.end()) mp[v] = i;
            else add(i, mp[v]);


        }

        int f=get(0);bool can=1;
        for(int i=1;i<n;i++){
            if(get(i) != f) can=0;
        }
        if(can) printf("Yes\n");
        else printf("No\n");

    }

    return 0;
}
