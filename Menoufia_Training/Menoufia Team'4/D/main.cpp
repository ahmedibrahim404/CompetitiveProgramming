#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX=200000+3;
int n;
ll ns[MAX], a[MAX];
map<ll, int> mp;

int main(){



    scanf("%d",&n);
    int st=-1, en=-1;
    mp[0]=-1;
    for(int i=0;i<n;i++){
        scanf("%lld",&ns[i]);
        a[i]=ns[i];
        if(ns[i]==0){
            st=i, en=i;
        }
        if(i) ns[i] += ns[i-1];
    }

    if(st==-1){
    for(int i=0;i<n;i++){
        if(mp.find( ns[i] )!=mp.end())
            if( i-(mp[ns[i]]+1)+1 < en-st+1 || st==-1 ) st=mp[ns[i]]+1, en=i;
        mp[ ns[i] ]=i;
    }
    }



    if(st!=-1){
        printf("%d %d\n", st+1, en-st+1);
    } else {
        printf("-1\n");
    }

    return 0;
}
