#include <iostream>

using namespace std;

int n, m;

int main(){

    scanf("%d %d", &n, &m);
    printf("%d\n", min(n, m)+1);
    for(int i=0;i<min(n, m)+1;i++) printf("%d %d\n", i, m-i);

    return 0;
}
