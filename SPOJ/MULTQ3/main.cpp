#include <iostream>

using namespace std;
const int N = 1 << 17 + 1;
int n, q;

struct node {
    int zs, os, ts, lazy;
} tree[N << 1];

void combine(int idx){

    tree[idx].zs = tree[2*idx+1].zs + tree[2*idx+2].zs;
    tree[idx].os = tree[2*idx+1].os + tree[2*idx+2].os;
    tree[idx].ts = tree[2*idx+1].ts + tree[2*idx+2].ts;

}

void add2(int st, int en, int idx){
    int arr[3] = {tree[idx].zs, tree[idx].os, tree[idx].ts};

    tree[idx].zs = arr[2];
    tree[idx].os = arr[0];
    tree[idx].ts = arr[1];

}
void check(int st, int en, int idx){

    if(!tree[idx].lazy) return;
    tree[idx].lazy %= 3;

    if(st != en) (tree[2*idx+1].lazy+=tree[idx].lazy)%=3, (tree[2*idx+2].lazy+=tree[idx].lazy)%=3;
    while(tree[idx].lazy--){
        add2(st, en, idx);
    }
    tree[idx].lazy=0;

}
void add(int st, int en, int idx){

    check(st, en, idx);
    add2(st, en, idx);
    if(st != en) tree[2*idx+1].lazy++, tree[2*idx+2].lazy++;


}




void build(int st=0, int en=n-1, int idx=0){

    if(st == en){
        tree[idx]={1, 0, 0, 0};
        return;
    }

    int mid=(st+en)>>1;

    build(st, mid, 2*idx+1);
    build(mid+1, en, 2*idx+2);


    tree[idx].lazy=0;
    combine(idx);

}

int l, r;

void update(int st=0, int en=n-1, int idx=0){
    check(st, en, idx);

    if(l > en || st > r) return;

    if(st >= l && en <= r){
        add(st, en, idx);
        return;
    }


    int mid=(st+en)>>1;
    update(st, mid, 2*idx+1);
    update(mid+1, en, 2*idx+2);

    combine(idx);

}

int query(int st=0, int en=n-1, int idx=0){
    check(st, en, idx);

    if(l > en || st > r) return 0;

    if(st >= l && en <= r){
        return tree[idx].zs;
    }


    int mid=(st+en)>>1;
    return query(st, mid, 2*idx+1) + query(mid+1, en, 2*idx+2);


}

int main(){
    scanf("%d%d",&n,&q);
    build();
    while(q--){
        int t;
        scanf("%d%d%d",&t,&l,&r);
        if(!t) update();
        else printf("%d\n", query());
    }


    return 0;
}
