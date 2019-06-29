#include <iostream>
#include<algorithm>
using namespace std;

int ns[3], d;
int main(){
    scanf("%d %d %d %d", &ns[0], &ns[1], &ns[2], &d);
    sort(ns, ns+3);
    int a=ns[0], b=ns[1], c=ns[2];

    int add=0;
    if(ns[1]-ns[0] < d) add += abs((ns[1]-d)-ns[0]);
    if(ns[2]-ns[1] < d) add += abs((ns[1]+d)-ns[2]);

//    int add=0;
//    if(ns[1]-ns[0] < d) add += abs((ns[1]-d)-ns[0]);
//    if(ns[2]-ns[1] < d) add += abs((ns[1]+d)-ns[2]);

    printf("%d", add);


    return 0;
}
