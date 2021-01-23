#include <iostream>

using namespace std;

int a, b, c;

int ns[1509];

int main(){

    scanf("%d %d %d", &a, &b, &c);

    ns[a]++, ns[b]++, ns[c]++;

    if(ns[1] >= 1 || ns[2] >= 2 || ns[3] >= 3 || ( ns[4] == 2 && ns[2]== 1 )) return printf("YES"), 0;

    printf("NO\n");

    return 0;
}
