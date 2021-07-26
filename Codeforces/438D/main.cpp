#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5 ;
int n ,m ,a[N] ;
long long seg[1<<20] ,mx[1<<20] ;


void build(int ni=0,int ns=0,int ne=n-1){
    if(ns==ne){
        mx[ni] = seg[ni] = a[ns];
        return;
    }
    int l = ni*2+1 ,r = l+1 ,mid = (ns+ne)/2;
    build(l,ns,mid);
    build(r,mid+1,ne);
    seg[ni] = seg[l] + seg[r] ;
    mx[ni] = max(mx[l] ,mx[r]);
}


void update1(int i,int v,int ni=0,int ns=0,int ne=n-1){
    if(ne<i || ns>i) return ;
    if(ns==ne){
        mx[ni] = seg[ni] = v ;
        return;
    }
    int l = ni*2+1 ,r = l+1 ,mid = (ns+ne)/2 ;
    if(i <= mid) update1(i,v,l,ns,mid);
    else update1(i,v,r,mid+1,ne);
    seg[ni] = seg[l] + seg[r] ;
    mx[ni] = max(mx[l] ,mx[r]);
}


void update2(int qs,int qe,int x,int ni=0,int ns=0,int ne=n-1){
    if(ne<qs || ns>qe) return ;
    if(mx[ni] < x) return ;
    if(ns==ne){
        mx[ni] = seg[ni] %= x ;
        return ;
    }
    int l = ni*2+1 ,r = l+1 ,mid = (ns+ne)/2 ;
    update2(qs,qe,x,l,ns,mid);
    update2(qs,qe,x,r,mid+1,ne);
    seg[ni] = seg[l] + seg[r] ;
    mx[ni] = max(mx[l] ,mx[r]);
}


long long query(int qs,int qe,int ni=0,int ns=0,int ne=n-1){
    if(ne<qs || ns>qe || ns>ne) return 0;
    if(ns>=qs && ne<=qe) return seg[ni] ;
    int l = ni*2+1 ,r = l+1 ,mid = (ns+ne)/2 ;
    return query(qs,qe,l,ns,mid) + query(qs,qe,r,mid+1,ne);
}


int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i) scanf("%d",&a[i]);
    build();
    while(m--){
        int t ;scanf("%d",&t);
        if(t==1){
            int l,r ;scanf("%d%d",&l,&r);
            printf("%lld\n",query(--l,--r));
        } else if(t==2){
            int l,r ,x ;scanf("%d%d%d",&l,&r,&x);
            update2(--l,--r,x);
        } else {
            int i ,v ;scanf("%d%d",&i,&v);
            update1(--i,v);
        }
    }
    return 0;
}
