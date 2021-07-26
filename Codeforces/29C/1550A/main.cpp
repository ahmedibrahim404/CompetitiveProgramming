#include <iostream>

using namespace std;

int main(){

    int t, s;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&s);
        int cur=1, sum=1, sz=1;
        while(sum < s){
            cur += 2;
            sum += cur;
            sz++;
        }
        printf("%d\n", sz);
    }


    return 0;
}
