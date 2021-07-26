#include <iostream>

using namespace std;
int t, a, b;

int main(){
    freopen("students.in","r", stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        printf("%d\n", a-b);
    }
    return 0;
}
