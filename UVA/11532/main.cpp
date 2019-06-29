#include <iostream>
#include<math.h>
using namespace std;

int t;
int p, q;

int main(){
    scanf("%d", &t);

    while(t--){

        scanf("%d %d", &p, &q);
        long long num=0;
        if(p == 0) {
            printf("0\n");
            continue;
        }

        int idx=0;
        if(p > 2*q){
            for(int i=0;i<p-2*q;i++){
                num += pow(2, idx);
                idx++;
            }

            p=2*q;
        }

        if(p)
        num += pow(2, idx), p--, idx++;




        while(p > 0 || q > 0){

            if(q){
                q--;
                idx++;
            }

            if(p > 0){

                if(p > 1){
                    num += pow(2, idx) + pow(2, idx+1);
                    p-=2;
                    idx+=2;
                } else {
                    num += pow(2, idx);
                    p-=1;
                    idx++;
                }

            }

        }

        printf("%lld\n", num);



    }

    return 0;
}
