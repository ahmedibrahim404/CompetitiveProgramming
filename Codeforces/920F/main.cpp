#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const int N = 1e6 + 5;
int n,m,D[N],a[N],L,R;
bool done[4*N];
ll seg[4*N];


void Build(int id=1,int l=1,int r =n){

    if(l==r){
        seg[id] = a[l];
        done [id] = (D[seg[id]] == seg[id]);
        return;
    }

    int mid = (l+r)/2;
    Build(id*2,l,mid); Build(id*2+1,mid+1,r);
    seg[id] = seg[id*2] + seg[id*2+1];
    done[id] = (done[id*2] && done[id*2+1]);

}

void Update(int id=1,int l=1,int r =n){
    if(l>R||r<L||done[id]) return;
    if(l==r){
        a[l] = D[a[l]];
        seg[id] = a[l];
        done [id] = (D[seg[id]] == seg[id]);
        return;
    }
    int mid = (l+r)/2;
    Update(id*2,l,mid); Update(id*2+1,mid+1,r);
    seg[id] = seg[id*2] + seg[id*2+1];
    done[id] = (done[id*2] && done[id*2+1]);
}

ll Get(int id=1,int l=1,int r =n){
    if(L<=l&&r<=R)
        return seg[id];
    if(l>R||r<L)
        return 0;
    int mid = (l+r)/2;
    return Get(id*2,l,mid)+Get(id*2+1,mid+1,r);
}
int main(){

    for(int i=1;i<=1e6;++i) for(int j=i;j<=1e6;j+=i)D[j]++;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    Build();
    while(m--){
        int t;
        scanf("%d%d%d",&t,&L,&R);
        if(t==1)
            Update();
        else
            printf("%lld\n",Get());
    }
    return 0;
}
