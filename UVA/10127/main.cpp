#include <iostream>

using namespace std;

int n;
int main(){
    while(scanf("%d", &n) == 1){

        int c=0, x=0;
        while(true){
            c = ((c*10)+1)%n;
            x++;
            if(c == 0) break;
        }

        printf("%d\n", x);

    }
    return 0;
}
