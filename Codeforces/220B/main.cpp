#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n,a[N],q,sqr,res[N],freq[N];
int qst[N],qen[N],srt[N];
int cnt,st,en;

void add(int v){
    if(v>n) return;
    if(freq[v] == v) --cnt;
    ++freq[v];
    if(freq[v]==v)++cnt;
}

void rmv(int v){
    if(v>n)return ;
    if(freq[v] == v) --cnt;
    --freq[v];
    if(freq[v]==v)++cnt;
}

void upd(int pos){
    while(en<=qen[pos])add(a[en++]);
    while(en>qen[pos]+1)rmv(a[--en]);
    while(st>qst[pos])add(a[--st]);
    while(st<qst[pos])rmv(a[st++]);
}
int main()
{
    scanf("%d%d",&n,&q);
    sqr=sqrt(n) ;
    for(int i=0;i<n;++i)scanf("%d",a+i);
    for(int i=0;i<q;++i){
        scanf("%d%d",qst+i,qen+i) ;
        --qst[i],--qen[i];
        srt[i]=i;
    }
    sort(srt,srt+q,[](int a,int b){return make_pair(qst[a]/sqr,qen[a])<make_pair(qst[b]/sqr,qen[b]);});
    for(int i=0;i<q;++i){
        int qi=srt[i] ;
        upd(qi);
        res[qi]=cnt;
    }
    for(int i=0;i<q;++i)
        printf("%d\n",res[i]);
    return 0;
}
