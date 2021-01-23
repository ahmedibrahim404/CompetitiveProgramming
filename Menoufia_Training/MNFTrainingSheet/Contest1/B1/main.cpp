#include <iostream>

using namespace std;

int t, n;
int main(){

    scanf("%d",&t);
    while(t--){
        int o=0;
        bool is=
        scanf("%d",&n);
        while(n%6==0){
            n/=6;
            o++;
        }

        if(n==1){
            printf("%d\n", o);
            continue;
        }

        int re=n,cnt=0;
        while(re%3==0){
            re/=3;
            cnt++;
        }

        if(re==1){printf("%d\n", cnt*2+o);continue;}
        printf("-1\n");








    }

    return 0;
}
