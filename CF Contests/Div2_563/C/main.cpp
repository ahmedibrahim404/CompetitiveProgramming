#include<bits/stdc++.h>
using namespace std;

int n;
int ns[1000000+9];
bool primes[1000000+9];
int main(){

    scanf("%d", &n);
    memset(primes, 1, sizeof(primes));

    int a=1;
    for(int i=2;i<=n;i++){
        if(!primes[i]) continue;
        ns[i]=a;
        for(int j=i+i;j<=n;j+=i){
            ns[j]=a;
            primes[j]=false;
        }
        a++;
    }

    for(int i=2;i<=n;i++) printf("%d ", ns[i]);

    return 0;
}
