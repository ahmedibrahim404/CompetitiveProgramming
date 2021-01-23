#include <iostream>

using namespace std;
int T, m, r, mi, mx, ns[5];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&m,&r,&mi,&mx);
        for(int i=0;i<m;i++){
            scanf("%d",&ns[i]);
        }
        bool t=0;
        for(int i=mi;i<=mx;i++){
            bool c=0;
            for(int j=0;j<m;j++){
                if(i%ns[j]==r) continue;
                c=1;
                break;
            }
            if(c==1) continue;
            printf("%d\n", i);
            t=1;
            break;
        }

        if(!t) printf("-1\n");

    }

    return 0;
}
