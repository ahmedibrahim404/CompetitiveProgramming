#include <iostream>

using namespace std;
const int N=100000+3;
typedef pair<int, int> pi;
int tree[262144 + 3];
int ns[N];
int build(int st, int en, int p=1){

    if(st==en){
        return tree[p]=0;
    }

    int mid=(st+en)/2;
    int p1 = build(st, mid, 2*p);
    int p2 = build(mid+1, en, 2*p+1);

    return tree[p] = max(p1, p2);

}

int l, r;
int query(int st, int en, int p){

    if(st >= l && en <= r) return tree[p];

    int mid=(st+en)/2;
    if(r <= mid) return query(st, mid, 2*p);
    if(l > mid) return query(mid+1, en, 2*p+1);

    int p1=query(st,mid,2*p);
    int p2=query(mid+1,en,2*p+1);

    return max(p1, p2);


}

int idx, val;
void update(int st, int en, int p){

    if(st==en) {tree[p]=val;return;}
    if(idx < st || idx > en) return;

    int mid=(st+en)/2;
    if(idx <= mid) update(st, mid, 2*p);
    else update(mid+1, en, 2*p+1);

    tree[p]=max(tree[2*p], tree[2*p+1]);

}

int n;
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> ns[i];
    build(0, n-1);
    int ans=1;

    idx=ns[0];val=1;
    update(0, n-1, 1);

    for(int i=1;i<n;i++){

        int best=1;
        if(ns[i] != 0){
            l=0, r=ns[i]-1;
            best=query(0, n-1, 1) + 1;
        }

        idx=ns[i];val=best;
        update(0, n-1, 1);

        ans=max(ans, best);
    }

    cout << ans << "\n";

    return 0;
}
