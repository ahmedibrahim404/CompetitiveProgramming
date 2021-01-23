#include <iostream>

using namespace std;
typedef long long ll;
const int MAX=100000+3;
ll tree[262144 + 3];
ll lazy[262144 + 3];

void check(int st, int en, int p){
    if(lazy[p]!=0) {
        tree[p] += lazy[p] * (en-st+1);
        if(st!=en) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
}

void build(int st, int en, int p){

    if(st==en){
        tree[p]=0;
        lazy[p]=0;
        return;
    }

    int mid=(st+en)/2;

    build(st, mid, 2*p);
    build(1+mid, en, 2*p+1);

    tree[p] = tree[2*p] + tree[2*p+1];
    lazy[p] = 0;
}

int from, to;ll val;
void update(int st, int en, int p){

    check(st, en, p);
    if(from > en || st > to) return;

    if( from <= st && en <= to ){
        tree[p] += val*(en-st+1);

        if(st != en){
            lazy[2*p] += val;
            lazy[2*p+1] += val;
        }

        return;
    }


    int mid=(st+en)/2;
    update(st, mid, 2*p);
    update(1+mid, en, 2*p+1);


    tree[p]=tree[2*p]+tree[2*p+1];

}


ll query(int st, int en, int p){

    check(st, en, p);

    if(from > en || st > to) return 0;

    if( from <= st && en <= to ){
        return tree[p];
    }

    int mid=(st+en)/2;
    return query(st, mid, 2*p) + query(mid+1, en, 2*p+1);

}
int t, n, q;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> q;
        build(0, n-1, 1);

        while(q--){
            int a, b, c;
            cin >> a;
            if(a){
                cin >> b >> c;
                b--, c--;
                from=b;to=c;
                cout << query(0, n-1, 1) << "\n";
            } else {
                ll d;
                cin >> b >> c >> d;
                b--, c--;
                from=b;to=c;val=d;
                update(0, n-1, 1);
            }
        }

    }
    return 0;
}
