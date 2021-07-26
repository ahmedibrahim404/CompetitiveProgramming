#include <iostream>

using namespace std;

int n, m, a;
int as[10], bs[10];

int main(){


    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &a);as[a]++;
    }

    for(int i=0;i<m;i++){
        scanf("%d", &a);bs[a]++;
    }

    int mi1=500, mi2=500;
    for(int i=1;i<=9;i++){
        if(as[i] >= 1 && bs[i] >= 1) return printf("%d\n", i), 0;
        if(as[i] > 0 && i < mi1) mi1=i;
        if(bs[i] > 0 && i < mi2) mi2=i;
    }

    if(mi1 > mi2) swap(mi1, mi2);

    printf("%d", mi1*10 + mi2);

    return 0;
}
