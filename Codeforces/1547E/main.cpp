#include <iostream>

using namespace std;
typedef pair<int, int> pi;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, k;
        scanf("%d%d",&n,&k);
        int ns[n], deg[n], deg2[n];

        for(int i=0;i<n;i++) deg[i]=2e9, deg2[i]=2e9;

        for(int i=0;i<k;i++){
            int idx;
            scanf("%d",&idx);
            idx--;
            ns[i] = idx;
        }

        for(int i=0;i<k;i++){
            int t;
            scanf("%d",&t);
            deg[ ns[i] ] = t;
            deg2[ ns[i] ] = t;
        }


        for(int i=1;i<n;i++){
            deg[i] = min(deg[i], deg[i-1]+1);
        }

        for(int i=n-2;i>=0;i--){
            deg2[i] = min(deg2[i], deg2[i+1]+1);
        }

        for(int i=0;i<n;i++) printf("%d ", min(deg[i], deg2[i]));
        printf("\n");


    }
    return 0;
}
