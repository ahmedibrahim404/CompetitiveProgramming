#include <iostream>

using namespace std;
int A,B,C;
int main(){
    scanf("%d%d%d",&A,&B,&C);
    printf("%d\n", min((A/2)+B, C));
    return 0;
}
