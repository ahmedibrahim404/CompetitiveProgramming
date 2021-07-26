#include<bits/stdc++.h>
using namespace std;

int n, m, r;
int s[31], b[31];
int main(){

    scanf("%d %d %d", &n, &m, &r);
    for(int i=0;i<n;i++) scanf("%d", &s[i]);
    for(int i=0;i<m;i++) scanf("%d", &b[i]);
    sort(s, s+n);
    sort(b, b+m);
    int can=r/s[0], rem=r%s[0];

    printf("%d", max(can*b[m-1]+rem, r));

    return 0;
}
