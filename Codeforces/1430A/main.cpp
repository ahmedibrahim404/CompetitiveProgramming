#include <iostream>

using namespace std;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int c1=-1, c2, c3;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(n >= 7 * i + 5 * j && (n - 7 * i - 5 * j)%3==0){
                    c1=(n - 7 * i - 5 * j)/3;
                    c2=j;
                    c3=i;
                    break;
                }
            }

            if(c1!=-1) break;

        }

        if(c1==-1) printf("-1\n");
        else printf("%d %d %d\n", c1, c2, c3);

    }
    return 0;
}
