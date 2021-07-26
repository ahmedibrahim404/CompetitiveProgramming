#include <iostream>

using namespace std;

int w, h, u1, d1, u2, d2;

int main(){

    scanf("%d %d %d %d %d %d", &w, &h, &u1, &d1, &u2, &d2);


    while(h>0){

        w += h;
        if(h == d1){
            w -= u1;
        } else if (h == d2){
            w -= u2;
        }

        if(w < 0) w=0;
        h--;

    }

    printf("%d", w);

    return 0;
}
