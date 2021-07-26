#include <iostream>

using namespace std;

int n, k;
bool primes[1000000+3];
const int MAX=1000000;
int main(){
    scanf("%d%d",&n,&k);
    primes[1]=1;
    for(int i=2;i<1000000+3;i++) primes[i]=1;

    for(int i=2;i<=MAX;i++){
        for(int j=i*i;j<=MAX;j++){
            primes[j]=0;
        }
    }
    int no;
    for(int i=0;i<n;i++){
        scanf("%d",&no);
        if(i) cnt[i]=cnt[i-1];
        cnt[i] += primes[no];
    }

    // O(nlogn) approach



    return 0;
}
