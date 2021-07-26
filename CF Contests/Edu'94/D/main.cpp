#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX=3000+2;
int l[MAX], r[MAX], as[MAX];
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(l, 0, sizeof l);
        memset(as, 0, sizeof as);
        for(int i=0;i<n;i++){
            scanf("%d",&as[i]);
        }

        long long ans=0;
        for(int i=0;i<n;i++){

            memset(r, 0, sizeof r);

            for(int j=n-1;j>i;j--){

                ans += (long long) r[ as[i] ] * l[ as[j] ];

                r[ as[j] ]++;

            }

            l[ as[i] ]++;

        }

        printf("%lld\n", ans);


    }
    return 0;
}
