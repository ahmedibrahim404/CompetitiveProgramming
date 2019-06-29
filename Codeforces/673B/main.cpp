#include <iostream>

using namespace std;


int n, m, a, b,x ,y;
int main(){
    scanf("%d %d", &n, &m);
        x=1, y=n;
        for(int i=0;i<m;i++){
            scanf("%d %d", &a, &b);
            if(a > b) swap(a, b);
            x=max(x,a);
            y=min(y,b);
        }

        printf("%d", max(y-x, 0));

    return 0;
}
