#include <iostream>

using namespace std;

int n;
char s[65000+9];

int main(){

    scanf("%d %s", &n, s);
    long long cnt=0;
    for(int i=0;i<n;i++){
        if( (s[i]-'0')%2==0 ) cnt++, cnt+=i;
    }

    printf("%lld", cnt);

    return 0;
}
