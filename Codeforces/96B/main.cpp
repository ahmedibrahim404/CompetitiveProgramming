#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[10000000+9];
int idx=0;
ll n;

void build(ll num, int fours, int sevens){
    if(num > 1e10) return;

    if(num != 0 && fours==sevens)
        arr[idx++]=num;

    build(num*10+4, fours+1, sevens);
    build(num*10+7, fours, sevens+1);
}

int main(){

    build(0, 0, 0);

    sort(arr, arr+idx);

    scanf("%lld", &n);

    int id=lower_bound(arr, arr+idx, n)-arr;
    printf("%lld", arr[id]);
    return 0;
}
