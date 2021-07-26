#include <iostream>

using namespace std;

int main(){
    int t, n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);int a=0;int no;
        for(int i=0;i<2*n;i++){
            scanf("%d",&no);
            if(no&1) a++;
        }
        if(a==n) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
