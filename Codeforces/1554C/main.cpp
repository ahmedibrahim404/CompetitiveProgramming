#include <iostream>

using namespace std;

int t, n, m;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        m++;
        int res=0;
        for(int k=30;~k;k--){
          if ((n >> k & 1) == (m >> k & 1)) { continue; }
          else if (m >> k & 1) res |= 1 << k;
          else break;
        }

        printf("%d\n", res);


    }
    return 0;
}
