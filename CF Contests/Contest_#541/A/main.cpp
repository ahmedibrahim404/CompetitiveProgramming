#include <iostream>

using namespace std;
int w1, h1, w2, h2;
int main(){
    scanf("%d %d %d %d", &w1, &h1, &w2, &h2);
    printf("%d", 2*(w1+h1+h2+2));
    return 0;
}
