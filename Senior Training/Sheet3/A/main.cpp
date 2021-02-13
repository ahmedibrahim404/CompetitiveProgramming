#include<bits/stdc++.h>
using namespace std;
const int MAX=500000+3;
int n, h;
int cum[MAX];

int main(){
    scanf("%d%d",&n,&h);
    int no;
    memset(cum, 0, sizeof cum);
    for(int i=0;i<n;i++){
        scanf("%d",&no);
        if(i&1){
            cum[h-no+1]++;
            cum[h+1]--;
        } else {
            cum[1]++;
            cum[no+1]--;
        }
    }

    int mi=2e9, lvl=0;
    for(int i=1;i<=h;i++){
        cum[i] += cum[i-1];
        if(mi > cum[i]) mi=cum[i], lvl=1;
        else if(mi == cum[i]) lvl++;

    }

    printf("%d %d\n", mi, lvl);

    return 0;
}
