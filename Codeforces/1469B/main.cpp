#include <iostream>

using namespace std;
int t, n, m;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int no, mx1=0, cur=0;;
        for(int i=0;i<n;i++){
            scanf("%d",&no);
            cur += no;
            mx1=max(mx1, cur);
        }
        scanf("%d",&m);
        int mx2=0;cur=0;
        for(int i=0;i<m;i++){
            scanf("%d",&no);
            cur += no;
            mx2=max(mx2, cur);
        }

        printf("%d\n", mx1+mx2);

    }


    return 0;
}
