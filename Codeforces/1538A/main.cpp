#include <iostream>

using namespace std;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ns[n+2];
        int mx=n+1, mn =n+1;
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
            if(mx == n+1 || ns[i] > ns[mx]) mx = i;
            if(mn == n+1 || ns[i] < ns[mn]) mn = i;
        }


        int mxx = max(mn, mx);
        int mnn = min(mn, mx);

        printf("%d\n", min( n-mnn, min( mxx+1, n-mxx + mnn+1 ) ));


    }
    return 0;
}
