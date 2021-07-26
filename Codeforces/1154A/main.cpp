#include<bits/stdc++.h>

using namespace std;

int ns[4];
int main(){
    scanf("%d %d %d %d", &ns[0], &ns[1], &ns[2], &ns[3]);
    sort(ns, ns+4);
    int a=ns[0], b=ns[1], c=ns[2], d=ns[3];
    int sa=(a-b+c)/2;
    int sb=a-sa;
    printf("%d %d %d", sa, sb, d-sb-sa);
    return 0;
}
