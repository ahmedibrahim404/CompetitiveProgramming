#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int n;
vpi ns;

int main(){
    scanf("%d", &n);
    ns=vpi(n);
    for(int i=0;i<n;i++) scanf("%d %d", &ns[i].first, &ns[i].second);


    sort(ns.begin(), ns.end());

    int no=0, c=ns[0].second;
    for(int i=1;i<n;i++){

        if(ns[i].second > c) c=ns[i].second;
        else no++;

    }

    printf("%d", no);

    return 0;
}
