#include <iostream>

using namespace std;
const int MAX=1e5+3;
int ns[MAX], tree[262144+3];
void build(int st, int en, int p=1){
    if(st==en){
        tree[p]=ns[st];
        return;
    }
    int mid=(st+en)/2;
    build(st, mid, 2*p);
    build(mid+1, en, 2*p+1);

    tree[p] = min(tree[2*p], tree[2*p+1]);
}
int from, to;
int query(int st, int en, int p=1){


    if(from <= st && en <= to) return tree[p];
    if(st > to || en < from) return 2e9;

    int mid=(st+en)/2;

    if(to <= mid) return query(st, mid, 2*p);
    if(from > mid) return query(1+mid, en, 2*p+1);

    return min( query(st, mid, 2*p), query(1+mid, en, 2*p+1) );

}


int n, q;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&ns[i]);
    build(0, n-1, 1);
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&from,&to);
        printf("%d\n", query(0, n-1, 1));
    }
    return 0;
}
