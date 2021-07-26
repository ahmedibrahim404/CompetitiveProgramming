#include <iostream>

using namespace std;
typedef long long ll;
const int N = 200000 + 3;
int t, n; ll ns[N];

bool cant(int x, int y){
    bool can=0;
    for(int i=x;i<=y;i++){
        for(int j=i+1;j<=y;j++){
            for(int k=j+1;k<=y;k++){
                if(ns[k] >= ns[j] && ns[j] >= ns[i]) can=1;
                if(ns[k] <= ns[j] && ns[j] <= ns[i]) can=1;
            }
        }
    }

    return can;

}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ll ans=0;
        for(int i=0;i<n;i++) scanf("%lld",&ns[i]);
        for(int i=0;i<n;i++){
            for(int j=i-3;j<=i;j++){
                if(j >= 0 && !cant(j, i)) {
                    ans += (i-j+1);
                    break;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
