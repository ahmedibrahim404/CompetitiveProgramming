#include <iostream>

using namespace std;

typedef long long ll;
const int N = 1 << 18;

ll ns[N];

struct node{
    int bits[20]={0}, lazy[20]={0};
} tree[N << 1];

ll sum(int idx){
    ll ans=0;
    for(int i=0;i<20;i++){
        if(tree[idx].bits[i])ans += (1LL<<i) * 1LL*tree[idx].bits[i];
    }
    return ans;
}

void merge(int idx){
    for(int i=0;i<20;i++){
        tree[idx].bits[i] = tree[2*idx+1].bits[i] + tree[2*idx+2].bits[i];
    }
}

void check(int st, int en, int idx){

    for(int i=0;i<20;i++){
        if(tree[idx].lazy[i]){
            tree[idx].bits[i] = (en-st+1) - tree[idx].bits[i];
            (tree[2*idx+1].lazy[i]+=1)%=2, (tree[2*idx+2].lazy[i]+=1)%=2;
            tree[idx].lazy[i]=0;
        }
    }

}

void build(int st, int en, int idx){

    if(st==en){
        ll no=ns[st];
        for(int i=0;i<20;i++){
            tree[idx].bits[i] += (no&1);
            no/=2;
        }
        return;
    }

    int mid=(st+en)>>1;

    build(st, mid, idx*2+1);
    build(1+mid, en, idx*2+2);

    merge(idx);

}

int l, r; ll x;
void update(int st, int en, int idx){

    check(st, en, idx);

    if(st > r || l > en) return;

    if(l <= st && en <= r){
        ll cx=x;
        for(int i=0;i<20 && cx;i++){
            if(cx&1) (tree[idx].lazy[i]+=1)%=2;
            cx/=2;
        }
        check(st, en, idx);
        return;
    }

    int mid=(st+en)>>1;
    update(st, mid, 2*idx+1);
    update(mid+1, en, 2*idx+2);
    merge(idx);

}


ll query(int st, int en, int idx){
    check(st, en, idx);

    if(st > r || l > en) return 0;
    if(l <= st && en <= r) return sum(idx);

    int mid=(st+en)>>1;
    return query(st, mid, 2*idx+1)+ query(1+mid, en, 2*idx+2);

}




int n;

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> ns[i];
    build(0, n-1, 0);
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t >> l >> r;
        l--, r--;
        if(t==1){
            cout << query(0, n-1, 0) << endl;
        } else {
            cin >> x;
            update(0, n-1, 0);
        }
    }
    return 0;
}
