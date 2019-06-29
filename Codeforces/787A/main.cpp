#include <iostream>

using namespace std;

int a, b, c, d;

int main(){

    scanf("%d %d %d %d", &a, &b, &c, &d);

    int ans=1e9;
    for(int i=b;i<=1e6;i+=a){
        if(i-d >= 0 && (i-d)%c == 0){
            ans=min(ans, i);
            break;
        }
    }


    for(int i=d;i<=1e6;i+=c){
        if(i-b >= 0 && (i-b)%a == 0){
            ans=min(ans, i);
            break;
        }
    }

    printf("%d", (ans==1e9?-1:ans));

    return 0;
}
