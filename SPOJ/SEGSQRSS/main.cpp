#include <iostream>

using namespace std;
typedef long long ll;
const int N = 1 << 17;
struct node {
    ll sum, sumsqr, p1, p2;
} tree[N << 2];
ll ns[N];
void check(int st, int en, int idx){

    if(tree[idx].p2){
        tree[idx].sum = tree[idx].p2 * (en-st+1);
        tree[idx].sumsqr = tree[idx].p2 * tree[idx].p2  * (en-st+1);

        if(st != en) tree[idx*2+1].p2 = tree[idx].p2,tree[idx*2+2].p2 = tree[idx].p2;
    }

    if(tree[idx].p1){
        tree[idx].sumsqr += tree[idx].p1 * tree[idx].p1 * (en-st+1) + tree[idx].sum * 2 * tree[idx].p1;
        tree[idx].sum += tree[idx].p1 * (en-st+1);
        if(st != en)
        tree[idx*2+1].p1 += tree[idx].p1, tree[idx*2+2].p1 += tree[idx].p1;
    }

}

void merge(int idx){
    tree[idx].sum = tree[idx*2+1].sum + tree[idx*2+2].sum;
    tree[idx].sumsqr = tree[idx*2+1].sumsqr + tree[idx*2+2].sumsqr;

}

void build(int st, int en, int idx){

    if(st == en) {
        tree[idx] = { ns[st], ns[st]*ns[st], 0, 0 };
        return;
    }

    int mid=(st+en)>>1;
    build(st, mid, 2*idx+1);
    build(1 + mid, en, 2*idx+2);


    if(st != en)merge(idx);
}
int l, r; ll v1, v2;
void update(int st, int en, int idx){

    check(st, en, idx);

    if(st > r || l > en) return;

    if(l <= st && en <= r) {
        tree[idx].sumsqr += v1 * v1 * (en-st+1) + tree[idx].sum * 2 * v1;
        tree[idx].sum += (en-st+1) * v1;
        if(st != en) tree[idx*2+1].p1 += v1, tree[idx*2+2].p1 += v1;
        return;
    }

    int mid=(st+en)>>1;
    update(st, mid, 2*idx+1);
    update(1+mid, en, 2*idx+2);

    merge(idx);

}

void update2(int st, int en, int idx){

    check(st, en, idx);

    if(st > r || l > en) return;

    if(l <= st && en <= r) {
        tree[idx].sum = (en-st+1) * v2;
        tree[idx].sumsqr = v2 * v2 * (en-st+1);
        if(st != en) tree[idx*2+1].p2 = v2, tree[idx*2+2].p2 = v2;
        return;
    }

    int mid=(st+en)>>1;
    update2(st, mid, 2*idx+1);
    update2(1+mid, en, 2*idx+2);

    merge(idx);

}

ll query(int st, int en, int idx){

    check(st, en, idx);

    if(st > r || l > en) return 0;

    if(l <= st && en <= r) {
        return tree[idx].sumsqr;
    }

    int mid=(st+en)>>1;
    return query(st, mid, 2*idx+1) + query(1+mid, en, 2*idx+2);

}

int main(){
    int t, n, m;
    scanf("%d",&t);int idx=1;
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        build(0, n-1, 0);
        printf("Case %d:\n", idx++);
        while(m--){
            int x;
            scanf("%d%d%d",&x,&l,&r);
            l--, r--;
            if(x==2){
                printf("%d\n", query(0, n-1, 0));
            } else if(x==1){
                scanf("%d",&v1);
                update(0, n-1, 0);
            } else {
                scanf("%d",&v2);
                update2(0, n-1, 0);
            }
        }
    }
    return 0;
}
