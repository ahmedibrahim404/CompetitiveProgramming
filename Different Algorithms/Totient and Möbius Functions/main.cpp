#include <iostream>

using namespace std;

/*

Totient function

Q(n) counts integers i < n such that gcd(i, n)=1 i.e. i,n are coprimes

Q(5)=4 => [1,2,3,4]
Q(10)=4 => [1,3,7,9]

If a,b,c are pairwise coprime ( (a, b) are coprime, (b, c) are, (a, c) are )  then
    Q(a*b*c) = Q(a)*Q(b)*Q(c)


If p is prime
    Q(p^k) = p^k - p^(k-1) = p^k-1 ( p - 1 )


Implement Q(n)
    1- brute force
    2- factorization {
        get all primes that are divisors
        for example
            180=2*2*3*3*5
                =2^2 * 3^2 * 5^1
            Q(180)= Q(2^2 * 3^2 * 5^1)
                = Q(2^2) * Q(3^2) * Q(5^1)
                = (2^2-2^1) * (3^2-3^1) * (5^1-5^0)
                = .....

    }

    3- sieve ( in ranges ) {
        loop over all primes
            go to all their multiples and multiply
            for example
                when i=2
                    go to j = 4, 4=2^2 then Q(4) = Q=(2^2) = 2^2-2^1
                    go to j = 6 6=3^1 * 2^1  Q(6) = Q(3^1 * 2^1) = ...
                    ( 3^1 will be processed when i=3 and so on)
    }



Q(N!) {

    iterate over i=2 i=N
        ans=1
        if(i is prime) ans *= ( i-1);
        else ans *= i;
    think why? you got it once ( 28/9/2020 )
}

*/



/*

    mobius function ==> {

        = -1 square free number with odd number of primes
        mobius[ 2,3,5 ]=-1


        = 0 not square free number



        = 1 => square free number with even number of primes
        mobius[ 2,3,5,7 ]=1
    }


*/










int main(){
    return 0;
}
