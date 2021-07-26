#include<bits/stdc++.h>
using namespace std;

int n, idx=0, num;
int v[100+9];
map<int, int> mp;
int main(){

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &num);
        mp[ num ]++;
        if(mp[num] == 1){
            v[idx++]=num;
        }
    }

    if(idx > 3) return printf("-1"), 0;

    if(idx == 1) return printf("0\n"), 0;

    if(idx == 2) return printf("%d", (abs(v[0]-v[1])%2==0) ? abs(v[0]-v[1])/2 : abs(v[0]-v[1]) ), 0;

    if(idx == 3){
        sort(v, v+idx);
        if(v[1]-v[0] == v[2]-v[1]) return printf("%d", v[2]-v[1]), 0;
        else printf("-1");
    }

    return 0;
}
