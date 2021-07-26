#include <iostream>
using namespace std;
const int N = 1 << 17 + 4;

int seg[4*N], ns[N], idx, x, n, q;

bool Build(int id = 1,int l =0,int r = n-1){
    if(l==r) {seg[id] = ns[l]; return 1;}
    int mid = (l+r)/2;

    bool ret = Build(id*2,l,mid) | Build(id*2+1,mid+1,r);

    if(ret) seg[id] = seg[id*2] | seg[id*2+1];
    else seg[id] = seg[id*2] ^ seg[id*2+1];

    return !ret;
}

bool Update(int id = 1,int l =1,int r = n){
    if(l==r) { seg[id] = ns[l] = x; return 1; }
    int mid = (l+r)/2,ret;
    if(idx<=mid) ret = Update(id*2,l,mid);
    else ret = Update(id*2+1,mid+1,r);

    if(ret) seg[id] = seg[id*2] | seg[id*2+1];
    else seg[id] = seg[id*2] ^ seg[id*2+1];

    return !ret;
}

int main(){
    scanf("%d%d",&n,&q);
    n = (1<<n);
    for(int i =0;i<n;++i)scanf("%d",&ns[i]);
    Build();
    while(q--){
        scanf("%d%d",&idx,&x);
        Update();
        printf("%d\n",seg[1]);
    }

    return 0;
}
