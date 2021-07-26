#include<bits/stdc++.h>

using namespace std;

int t, h, w;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&h,&w);
        int ans[h+5][w+5];
        memset(ans, 0, sizeof ans);
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if((i == 1 || j == 1 || i == h || j == w))
                if(!ans[i-1][j] && !ans[i-1][j-1] && !ans[i-1][j+1] && !ans[i][j-1]) ans[i][j]=1;
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
