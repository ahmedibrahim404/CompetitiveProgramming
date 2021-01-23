#include <iostream>
using namespace std;


int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=1e9, ansidx;
        int cnt[n+1], idx[n+1];
        for(int i=0;i<=n;i++) cnt[i]=0;
        int no;
        for(int i=0;i<n;i++){
            scanf("%d",&no);
            cnt[no]++;
            idx[no]=i;
        }
        for(int i=n;i>=1;i--){
            no=i;
            if(cnt[no]==1 && ans > no) ans=no, ansidx=idx[no];
            else if(ans==no && cnt[no] > 1) ans=1e9;
        }
        if(ans==1e9) ansidx=-2;
        printf("%d\n", ansidx+1);
    }
    return 0;
}
