#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
const int MAX=1e6+3;
char str[MAX+2];
pi tree[MAX<<2];

pi build(int st, int en, int p=1){

    if(st==en){
        pi p3=pi(0, 0);
        if(str[st] == '(') p3.first++;
        else p3.second++;
        return tree[p]=p3;
    }
    int mid=(st+en)/2;
    pi p1=build(st, mid, 2*p);
    pi p2=build(mid+1, en, 2*p+1);
    int re=min(p2.second, p1.first);
    p2.second-=re;p1.first-=re;
    pi p3=pi(p1.first + p2.first, p1.second + p2.second);
    return tree[p]=p3;

}

int from, to;

pi query(int st, int en, int p=1){

    if(from <= st && en <= to) return tree[p];
    if(st > to || en < from) return pi(0, 0);

    int mid=(st+en)/2;

    if(to <= mid) return query(st, mid, 2*p);
    if(from > mid) return query(1+mid, en, 2*p+1);

    pi p1=query(st, mid, 2*p);
    pi p2=query(mid+1, en, 2*p+1);
    int re=min(p2.second, p1.first);
    p2.second-=re;p1.first-=re;
    pi p3=pi(p1.first + p2.first, p1.second + p2.second);

    return p3;



}
int q;
int main(){
    scanf("%s", str);
    scanf("%d",&q);
    build(0, strlen(str)-1, 1);
    int len=strlen(str);
    while(q--){
        scanf("%d%d",&from,&to);
        from--, to--;
        pi ans=query(0, len-1, 1);
        printf("%d\n", to-from+1-ans.first-ans.second);
    }
    return 0;
}
