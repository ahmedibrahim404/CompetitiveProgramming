#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m, k;

struct it {
    int idx;
    ll value;
};

it as1[200000+9];
ll as2[200000+9];
bool took[200000+9];

bool cmpr(it a2, it a1){
    return a2.value > a1.value;
}

int main(){

    scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<n;i++){
        scanf("%lld", &as1[i].value);
        as2[i]=as1[i].value;
        as1[i].idx=i;
    }

    sort(as1, as1+n, cmpr);

    ll sum=0;
    for(int i=0;i<m*k;i++) took[ as1[i].idx ] = true, sum += as1[ i ].value;

    printf("%lld\n", sum);

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(took[i])
            cnt++;
        if(cnt > m){
            cnt = 1;
            printf("%d ", i);
        }
    }

    return 0;
}
