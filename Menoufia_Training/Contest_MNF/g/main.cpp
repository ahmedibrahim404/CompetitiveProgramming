#include <iostream>

using namespace std;
typedef long long ll;
int n;
ll cnt=0, total=0;
int main(){
    scanf("%d",&n);
    for(int i=n;i>=2;i--){
        total += (i-1)*i;
        cnt += (i-1);
    }

    printf("%.7lf", (double) total/cnt);

    return 0;
}
