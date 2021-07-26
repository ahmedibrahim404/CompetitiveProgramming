#include <iostream>

using namespace std;

int n;
int main(){
    scanf("%d", &n);

    for(int i=n;i<=1007;i++){

        int no=i;
        int cur=0;
        while(no!=0){
            int last=no%10;
            cur += last;
            no/=10;
        }

        if(cur%4==0) return printf("%d", i), 0;

    }

    return 0;
}
