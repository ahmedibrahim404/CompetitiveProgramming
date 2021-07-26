#include <iostream>

using namespace std;

int n, m, a, b, c, d1[100], d2[100];
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &a, &b, &c);
        a--, b--;
        d1[a] += c;
        d2[b] += c;
    }

    long long total=0;
    for(int i=0;i<n;i++) total += max(0, d2[i]-d1[i]);
    printf("%lld", total);

    return 0;
}
