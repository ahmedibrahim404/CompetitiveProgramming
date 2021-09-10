#include<bits/stdc++.h>
using namespace std;

const int N = 200000 + 3;
int as[N], bs[N];
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&as[i]);
    for(int i=0;i<n;i++) scanf("%d",&bs[i]);
    sort(as, as+n);
    sort(bs, bs+n);
    int towin = n/2+1;bool c1=1;
    for(int i=n-1, j=towin-1;i >= 0 && j >= 0;i--, j--){
        if(as[i] > bs[j]) continue;
        c1=0;
        break;
    }

    towin = n/2+1;bool c2=1;
    for(int i=n-1, j=towin-1;i >= 0 && j >= 0;i--, j--){
        if(bs[i] > as[j]) continue;
        c2=0;
        break;
    }

    if(c1 && c2) printf("Both\n");
    else if(c1) printf("First\n");
    else if(c2) printf("Second\n");
    else printf("None\n");

    return 0;

}
