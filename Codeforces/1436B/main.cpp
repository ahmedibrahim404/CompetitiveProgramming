#include<bits/stdc++.h>
using namespace std;

int t, n;
int ans[100+1][100+1];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(ans, 0, sizeof ans);
        int cur=0;
        for(int i=0;i<n-1;i++){
            ans[i][cur]=ans[i][cur+1]=1;
            cur++;
        }
        ans[n-1][n-1]=1;
        ans[n-1][0]=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                printf("%d ", ans[i][j]);
            printf("\n");
        }


    }
    return 0;
}
