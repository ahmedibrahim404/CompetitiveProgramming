#include <iostream>

using namespace std;

int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int lst[n+1], ans[n+1];
        for(int i=0;i<=n;i++) lst[i]=-1, ans[i]=0;
        int no;
        for(int i=0;i<n;i++){
            scanf("%d",&no);
            if(i-lst[no]>1){
                ans[no] ++;
            }
            lst[no]=i;
        }

        int mi=1e9;
        for(int i=1;i<=n;i++){
            int no=i;
            if(lst[no] != -1 && n-lst[no] > 1) ans[no]++;
            if(lst[no] != -1) mi=min(mi, ans[no]);
        }

        printf("%d\n", mi);

    }
    return 0;
}
