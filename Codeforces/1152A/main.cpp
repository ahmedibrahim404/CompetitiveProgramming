#include<bits/stdc++.h>

using namespace std;

int n, m;
int num;
int o1=0, e1=0, o2=0, e2=0;
int main(){

    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &num);
        if(num%2) o1++;
        else e1++;
    }

    for(int i=0;i<m;i++){
        scanf("%d", &num);
        if(num%2) o2++;
        else e2++;
    }

    long long ans=min(o1,e2)+min(o2,e1);
    printf("%lld", ans);

    return 0;
}
