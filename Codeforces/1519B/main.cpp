#include <iostream>

using namespace std;
const int MAX=100+3;

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int n, m, k;
        scanf("%d%d%d",&n,&m,&k);


        int mi=min(m-1 + m*(n-1), n-1 + n*(m-1));
        int mx=max(m-1 + m*(n-1), n-1 + n*(m-1));


        if(k >= mi && k <= mx) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
