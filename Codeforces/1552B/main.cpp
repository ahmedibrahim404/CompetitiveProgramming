#include <iostream>

using namespace std;



int main(){
    int t, n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);int ns[n][5];
        for(int i=0;i<n;i++) for(int j=0;j<5;j++) scanf("%d",&ns[i][j]);
        int cur=0;
        for(int i=1;i<n;i++){
            int cnt=0;
            for(int j=0;j<5;j++){
                if(ns[i][j] < ns[cur][j]) cnt++;
            }
            if(cnt >= 3) cur=i;
        }


        for(int i=0;i<n;i++){
            if(i == cur) continue;
            int cnt=0;
            for(int j=0;j<5;j++){
                if(ns[i][j] > ns[cur][j]) cnt++;
            }
            if(cnt < 3){
                cur=-2;
                break;
            }
        }

        printf("%d\n", cur+1);
    }

    return 0;
}
