#include <iostream>

using namespace std;

void solve(){


}

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int f1 = n/3, f2=n/3;

        printf("%d %d\n", f1 + (n%3==1), f2+(n%3==2));
    }

    return 0;
}
