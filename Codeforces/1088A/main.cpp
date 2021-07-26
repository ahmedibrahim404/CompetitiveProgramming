#include <iostream>
#include <math.h>
using namespace std;

int x;
bool stop=false;
int nex(int a, int b){
    return a + b - (a%b);
}


int main(){

    scanf("%d", &x);
    int f1=-1 , f2=-1;
    for(int i=1;i<=x && !stop;i++){
        for(int j= nex( ceil( (double) x/i ), i ) ;j<=x;j+=i){
            if(j*i > x  && (double) j/i < x){
                f1=i, f2=j;
                stop=true;
                break;
            }
        }
    }

    if(f1 == -1) printf("-1");
    else printf("%d %d", f2, f1);


    return 0;
}
