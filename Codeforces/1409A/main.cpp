#include <iostream>

using namespace std;

int t, a, b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        if(a > b) swap(a, b);
        int ans=(b-a)/10 + (a%10 != b%10);
        cout << ans << "\n";
    }

    return 0;
}
