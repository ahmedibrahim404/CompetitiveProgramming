#include <iostream>

using namespace std;

int n, a;
pair<int, int> ns[100000+9];
int lasta=1, lastb=1;
long long int tot=0;
int main(){
    scanf("%d", &n);

    for(int i=1;i<=2*n;i++){
        scanf("%d", &a);
        if(ns[a].first)
            ns[a].second=i;
        else
            ns[a].first=i;
    }

    for(int i=1;i<=n;i++){
        tot += abs(lasta-ns[i].first) + abs(lastb-ns[i].second);
        lasta = ns[i].first;
        lastb = ns[i].second;
    }

    printf("%lld", tot);

    return 0;
}
