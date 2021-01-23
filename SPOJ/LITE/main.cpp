#include <iostream>

using namespace std;

int tree[262144 + 3];
bool lazy[262144 + 3];

void check(int st, int en, int p){


    if(lazy[p]){
        tree[p] = (en-st+1)-tree[p];
        if(en!=st){
            lazy[2*p] = !lazy[2*p];
            lazy[2*p+1] = !lazy[2*p+1];
        }
        lazy[p]=0;
    }


}

void build(int st, int en, int p){

    if(st==en){
        tree[p]=0;
        return;
    }
    int mid=(st+en)/2;
    build(st, mid, 2*p);build(1+mid, en, 2*p+1);
    tree[p]=tree[2*p]+tree[2*p+1];

}

int from, to, cur;
void update(int st, int en, int p){

    check(st, en, p);
    if(st > to || from > en) return;



    if(from <= st && en <= to){
        tree[p]=(en-st+1)-tree[p];
        if(st != en){
        lazy[2*p] = !lazy[2*p];
        lazy[2*p+1] = !lazy[2*p+1];
        }
        return;
    }

    int mid=(st+en)/2;
    update(st, mid, 2*p);
    update(1+mid, en, 2*p+1);

    tree[p]=tree[2*p]+tree[2*p+1];

}

int query(int st, int en, int p){


    check(st, en, p);
    if(st > to || from > en) return 0;

    if(from <= st && en <= to){
        return tree[p];
    }

    int mid=(st+en)/2;
    return query(st, mid, 2*p) + query(1+mid, en, 2*p+1);


}


int n, m;
int main(){
    scanf("%d%d",&n,&m);
    build(0, n-1, 1);
    while(m--){

        int a;
        scanf("%d%d%d",&a,&from,&to);
        from--, to--;
        if(!a){
            cur=query(0, n-1, 1);
            update(0, n-1, 1);
        } else {
            printf("%d\n", query(0, n-1, 1));
        }

    }
    return 0;
}
