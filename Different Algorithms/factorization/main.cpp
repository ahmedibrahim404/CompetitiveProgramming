#include <iostream>

using namespace std;
typedef long long ll;
vector<ll> factor(ll n){

    vector<ll> primes;
    for(ll i=2;i*i<=n;i++){
        while(n%i){
            n/=i;
            primes.push_back(i);
        }
    }

    if(n>1){
        // this means n is prime
        // after sqrt(n) there must be either no primes or just one prime
        primes.push_back(n);
    }

    return primes;

}

/*

    p^n always has n+1 divisors
    p^0, p^1, p^2, ..., p^n

    a^n * b^m has ... divisors??
    (n+1)*(m+1)

    how to get them??
    a^0 b^0
    a^1 b^0
    a^0 b^1

    and try all possible cases

*/

int main(){
    return 0;
}
