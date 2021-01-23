#include <iostream>
using namespace std;
typedef long long ll;
int n;
ll k, ns[100+9];

bool check(ll l1, ll l2, ll l3){
    return (l1+l2+l3)==k;
}

int main(){
    scanf("%d %lld",&n,&k);
    for(int i=0;i<n;i++) scanf("%lld",&ns[i]);
    for(int i=0;i<n;i++){
        int i1=ns[i], i2=-ns[i];
        for(int j=i+1;j<n;j++){
            int j1=ns[j], j2=-ns[j];
            for(int k=j+1;k<n;k++){
                int k1=ns[k], k2=-ns[k];
                if(check(i1, j1, k1) || check(i1, j1, k2) || check(i1, j2, k1) || check(i1, j2, k2) || check(i2, j1, k1) || check(i2, j1, k2)
                   || check(i2, j2, k1) || check(i2, j2, k2)){
                    printf("%d %d %d\n", i+1, j+1, k+1);
                    return 0;
                }
            }
        }
    }
    printf("-1 -1 -1\n");
    return 0;
}
