#include <iostream>

using namespace std;

// lamda is lagrange multiplier

/**

    Suppose you have certain Function f(x) = stuff,, and you want to maximize it or minimize it
    under some constrain that g(x) = another stuff

    ex.
    f(x) = sigma ( xi^2 * vi / 2 )
    g(x) = sigma ( xi ) = D ( const )

    to solve it using lagrange multiplier
    F(x) = f(x) - lamda * ( g(x) - D )

    partial deravative w.r.t. x
    and get the value of lamda satisfying the equation ( maybe bs over it )

    in our case

    = xi * vi - lamda = 0
    solve for xi * vi = lamda


**/

int main(){
    return 0;
}
