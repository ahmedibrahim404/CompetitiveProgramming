#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int N = 1000000 + 3;

int n, m;
int tim=0;
vvi ns;
vi arr;
char in[N];
int prevS[N], dep[N], sT[N], eT[N];
int sum[N][26];
vvi idxs;
void dfs(int x){
    sT[x]=tim++;
    idxs[ dep[x] ].push_back(sT[x]);
    arr.push_back(x);
    for(int to: ns[x]){
        dep[to] = dep[x]+1;
        dfs(to);
    }
    eT[x]=tim-1;
}

int main(){
    scanf("%d%d",&n,&m);
    ns=vvi(n);
    memset(prevS, -1, sizeof prevS);
    idxs=vvi(n);
    memset(sum, 0, sizeof sum);
    for(int i=1;i<n;i++){
        int p;
        scanf("%d",&p);p--;
        ns[p].push_back(i);
    }

    dep[0]=0;
    scanf("%s", in);
    dfs(0);

    for(int i=0;i<arr.size();i++){
        int node=arr[i];
        if(prevS[ dep[node] ] != -1){
            for(int j=0;j<26;j++){
                sum[i][j] += sum[ prevS[ dep[node] ] ][j];
            }
        }
        sum[i][ in[ node ]-'a' ]++;
        prevS[ dep[ node ] ] = i;
    }



    while(m--){
        int a, b;
        scanf("%d%d",&a,&b);
        a--;b--;

        if(!idxs[b].size()){
            printf("Yes\n");
            continue;
        }

        int l = lower_bound(idxs[b].begin(), idxs[b].end(), sT[a])-idxs[b].begin();
        l--;
        int r = upper_bound(idxs[b].begin(), idxs[b].end(), eT[a])-idxs[b].begin();
        r--;


        if(l > r){
            printf("Yes\n");
            continue;
        }

        int c=0;
        int can=2;
        for(int j=0;j<26;j++){
            c = ((r < idxs[b].size() ?  sum[ idxs[b][r] ][j] : 0) - ((l >= 0 && l < idxs[b].size()) ? sum[ idxs[b][l] ][j] : 0));
            if(c % 2 == 1) can--;
        }

        if(can > 0){
            printf("Yes\n");
        } else printf("No\n");

    }

    return 0;
}
