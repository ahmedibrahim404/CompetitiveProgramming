#include <iostream>

using namespace std;

int a, b, f, k;

int main(){

    scanf("%d %d %d %d", &a, &b, &f, &k);

    int full=b, cur=0, ct=b;
    int fu=0;
    for(int i=1;i<=k;i++){

        if(cur==0){
            int dis=i==k?a:2*a-f;
            if(ct >= dis) ct-=a;
            else {
                if(ct >= f){
                    ct = full-(a-f);
                    fu++;
                    if(ct < 0) return printf("-1\n"), 0;
                } else return printf("-1\n"), 0;
            }

            cur=a;


        } else {
            int dis=i==k?a:a+f;
            if(ct >= dis) cur=0, ct-=a;
            else {

                if(ct >= a-f){
                    ct=full-f;
                    fu++;
                    if(ct < 0) return printf("-1\n"), 0;
                } else return printf("-1\n", ct, i), 0;

            }

            cur=0;

        }



    }

    printf("%d", fu);

    return 0;
}
