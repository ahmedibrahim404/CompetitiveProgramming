#include<bits/stdc++.h>

using namespace std;

int t, n, a, b;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&a,&b);
        char str[n];
        scanf("%s", str);
        int ans= n * a;
        if(b > 0){
            ans += b * n;
            printf("%d\n", ans);
            continue;
        }
        char pre = str[0];int cnt=0;
        for(int i=1;i<n;i++){
            if(str[i] != pre) cnt++;
            pre = str[i];
        }

        ans += ((cnt+1)/2+1) * b;
        printf("%d\n", ans);

    }
    return 0;
}
