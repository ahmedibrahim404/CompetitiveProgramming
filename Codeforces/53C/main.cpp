#include <iostream>

using namespace std;

int st, en, n;

int main(){
    scanf("%d", &n);
    int st=1, en=n;
    while(en >= st){

        if(st != en)
            cout << st++ << " " << en-- << " ";
        else cout << st++ << " ";
    }

    return 0;
}
