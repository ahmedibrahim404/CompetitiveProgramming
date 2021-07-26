#include <iostream>

using namespace std;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n%2==1){
            printf("Bob\n");
            continue;
        }


        int cnt=0;
        while(n%2==0){
            n/=2;
            cnt++;
        }


        if(n == 1 && (cnt&1)){
            printf("Bob\n");
        } else printf("Alice\n");



    }
    return 0;
}
