#include <iostream>

using namespace std;

int main(){

    int t, n, s;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        s=0;
        for(int i=0;i<n;i++){
            int no;
            scanf("%d",&no);
            s+=no;
        }
        if(s >= n){
            printf("%d\n", (s-n));
            continue;
        }

        printf("1\n");

    }

    return 0;
}
