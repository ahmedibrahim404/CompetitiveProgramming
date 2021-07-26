#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, k;
        scanf("%d%d",&n,&k);
        int arr[n+5], ns[n+5], cnt[n+5];for(int i=0;i<n+2;i++) arr[i]=0;
        for(int i=0;i<n;i++){
            int no;scanf("%d",&no);
            ns[i]=no;
            arr[no]++;
        }
        int ex=0;
        for(int i=0;i<=n;i++) if(arr[i] > k) ex += arr[i]-k;
        int ans=n-ex;
        ans-= ans%k;

        for(int i=0;i<n+2;i++) arr[i]=1, cnt[i]=0;
        int can=1;
        for(int i=0;i<n;i++){
            while( cnt[ can ] >= ans/k ) can++;

            if(arr[ ns[i] ] > can){
                while(cnt[ arr[ns[i]] ] >= ans/k) arr[ ns[i] ]++;
                if( arr[ ns[i] ] <= k && cnt[ arr[ ns[i] ] ] <ans/k ){printf("%d ", arr[ ns[i] ]);
                cnt[ arr[ ns[i] ] ]++;
                arr[ ns[i] ]++;} else printf("0 ");
            } else {
                if(can <= k && cnt[can] < ans/k){
                printf("%d ", can);
                cnt[can]++;
                arr[ ns[i] ] = can;
                } else printf("0 ");
            }

        }

        printf("\n");

    }
    return 0;
}
