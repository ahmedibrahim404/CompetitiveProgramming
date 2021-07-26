#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a, b;
        scanf("%d%d",&a,&b);
        int st=0, en=100;
        int ans=1e9;
        while(en >= st){
            bool can=0;
            int mid=(st+en)/2;
            for(int i=0;i<=mid;i++){
                int nb = b+i;
                int rem=(mid-i), na=a;
                while(rem--){
                    na/=nb;
                }
                if(!na) can=1;
            }
            if(can) en=mid-1, ans=min(ans, mid);
            else st=mid+1;
        }
        printf("%d\n", ans);
    }

    return 0;
}
