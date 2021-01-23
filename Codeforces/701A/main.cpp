#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> ns[100+9];
int main(){

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &ns[i].first);
        ns[i].second=i;
    }

    sort(ns, ns+n);
    for(int i=0;i<n/2;i++){
        printf("%d %d\n", ns[i].second+1, ns[n-i-1].second+1);
    }

    return 0;
}
