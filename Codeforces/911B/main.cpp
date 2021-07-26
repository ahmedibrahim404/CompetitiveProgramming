#include <iostream>

using namespace std;

int n, a, b;

bool can(int no){

    int cu=0;

    if(b / no > 0 && a / no > 0) cu += (a/no) + (b/no);

    return cu >= n;
}

int main(){

    scanf("%d %d %d", &n, &a, &b);

    int st=1, en=201;

    while(en >= st){
        int mid=(st+en)/2;
        if(can(mid)) st++;
        else en--;
    }

    printf("%d", en );

    return 0;
}
