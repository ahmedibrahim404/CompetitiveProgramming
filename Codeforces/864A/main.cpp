#include <iostream>

using namespace std;

int main(){

    int numa=0, numb=0, n, a;
    int cnta=0, cntb=0;
    scanf("%d", &n);

    for(int i=0;i<n;i++){

        scanf("%d", &a);

        if(numa == 0 && a != numb){
            numa=a, cnta++;
            continue;
        }

        if(numb == 0 && a != numa){
            numb=a, cntb++;
            continue;
        }

        if(a == numa){
            cnta++;
        } else if(a == numb){
            cntb++;
        } else {
            return printf("NO\n"), 0;
        }

    }

    if(cnta == cntb) printf("YES\n%d %d\n", numa, numb);
    else printf("NO\n");

    return 0;
}
