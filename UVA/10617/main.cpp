#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;

char a[65];
ll dp[65][65];

ll rec(int i,int j){

    if(i >= j) return 1;
    if(i+1 == j) return 2 + (a[i] == a[j]);

    ll &ret=dp[i][j];
    if(ret!=-1) return ret;

    ret=0;
    if(a[i] == a[j])
        ret += 1+rec(i+1, j-1);

    ret+=rec(i+1,j);
    ret+=rec(i, j-1);
    ret-=rec(i+1, j-1);

    return ret;

}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",a);
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",rec(0,strlen(a)-1));
    }
}
