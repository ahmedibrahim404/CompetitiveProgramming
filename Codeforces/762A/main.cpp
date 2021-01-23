#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
vector<int> div;
int main(){
    scanf("%lld %lld", &n, &k);
    int cnt=0;

    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if(n/i != i) cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}
