#include <iostream>

using namespace std;

int s, x1, x2;
int t1, t2;
int f, d;

int main(){

    scanf("%d %d %d", &s, &x1, &x2);
    scanf("%d %d", &t1, &t2);
    scanf("%d %d", &f, &d);

    int dis;
    if(d==1){
        if(x2 >= x1){
            if(f <= x1) dis=x2-f;
            else dis=(s-f)+s+x2;
        } else dis = (s-f)+(s-x2);
    } else {
        if(x2 > x1) dis=f+x2;
        else {
            if(f >= x1) dis=(f-x2);
            else dis=(f+s)+(s-x2);
        }
    }

    printf("%d", min( t2*abs(x1-x2), dis*t1 ));

    return 0;
}
