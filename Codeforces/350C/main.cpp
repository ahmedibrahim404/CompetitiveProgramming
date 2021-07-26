#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<pi> vpi;

bool cmpr(pi pr2, pi pr1){
    return abs(pr2.first) + abs(pr2.second) < abs(pr1.first) + abs(pr1.second);
}

vpi ns;
int n, ops=0;
int main(){
    scanf("%d", &n);
    ns=vpi(n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &ns[i].first, &ns[i].second);
        if(ns[i].first != 0 && ns[i].second != 0) ops+=2;
        ops += 4;
    }

    sort( ns.begin(), ns.end(), cmpr );
    printf("%d\n", ops);
    for(int i=0;i<n;i++){

        int x1=ns[i].first, y1=ns[i].second;
        int dirx=1, diry=1;
        if(x1 < 0) dirx=-1;
        if(y1 < 0) diry=-1;

        if(x1 < 0) x1 = -x1;
        if(y1 < 0) y1 = -y1;
        if(x1) {
            if(dirx == 1) printf("1 %d R\n", x1);
            else printf("1 %d L\n", x1);
        }

        if(y1){
            if(diry == 1) printf("1 %d U\n", y1);
            else printf("1 %d D\n", y1);
        }

        printf("2\n");

        if(x1){
            if(dirx == 1) printf("1 %d L\n", x1);
            else printf("1 %d R\n", x1);
        }

        if(y1){
            if(diry == 1) printf("1 %d D\n", y1);
            else printf("1 %d U\n", y1);
        }

        printf("3\n");
    }

    return 0;
}
