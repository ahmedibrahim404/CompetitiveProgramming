#include <iostream>

using namespace std;
typedef long long ll;
ll mxcol[200000+3];
int n;
ll ns[200000+3]; int col[200000+3];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%d",&ns[i],&col[i]);
        mxcol[ col[i] ]=1e18;
    }
    bool can=1;
    for(int i=n-1;i>=0;i--){

        if( mxcol[ col[i] ] < ns[i] ){

            can=0;
            break;
        }

        mxcol[ col[i] ]=min( mxcol[ col[i] ], ns[i] );

    }
    if(can) printf("YES\n");
    else printf("NO\n");
    return 0;
}
