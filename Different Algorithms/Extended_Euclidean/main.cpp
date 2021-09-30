#include <iostream>

using namespace std;

typedef long long ll;
ll x, y;
ll gcd(ll a, ll b){
    if(!b) return a;
    return gcd(b, a%b);
}

ll extended_euclid(ll a, ll b){
    if(a<0){
        ll ans=extended_euclid(-a, b);
        x *= -1;
        return ans;
    }
    if(b<0){
        ll ans=extended_euclid(a, -b);
        y *= -1;
        return ans;
    }
    if(!b){
        x=1, y=0;
        return a;
    }
    ll ans=extended_euclid(b, a%b);
    ll prevx=x, prevy=y;
    x=prevy; y=prevx-(a/b)*x;
    return ans;
}

ll lin_diophantine(ll a, ll b, ll c){
    // solve ax+by=c
    ll g=extended_euclid(a, b);
    if(c%g==0){
        // there is an answer
        x*=c/g, y*=c/g;
        // to get first pos ( ax-by=c ) answers
        if(c==0){
            x=x+3*b/gcd(a, b);
            y=y-3*a/gcd(a, b);
        }
    }
    return g;
}

ll a, b, c;
int main(){

    cin >> a >> b;
    extended_euclid(a, b);

    cout << x << " " << y << endl;

    // solve ax+by=c
    cin >> a >> b >> c;
    lin_diophantine(a, b, c);
    cout << "X is " <<x << ", and Y is " << y << endl;

    // get more values as k = 3
    x=x+3*b/gcd(a, b);
    y=y-3*a/gcd(a, b);
    cout << x << " " << y << endl;
    /** to find more values ( maybe positive or negative
        a*x+b*y=g  (( (a%b)  ))
        a(x+b)+b(y-a)=g ( true ) +ab -ab
        a(x+b/g)+b(y-a/g)=g ( true )
        a(x+k*b/g)+b(y-k*a/g) = g

        formula
        x=x+(k*b)/gcd(a, b)
        y=y-(k*a)/gcd(a, b)
    */




    // for 3 integers
    // gcd(a, b) = x*a + y*b;
    // gcd(a, b, c) = gcd(a, gcd(b, c)) = x*a+y*gcd(b, c)=x*a+y*( n*b + m*c ) = ....
    cin >> a >> b >> c;
    // gcd(a, b, c) = gcd(a, gcd(b, c)) = xa + y*(gcd(b,c)) = xa + y( nb+mc ) = xa + ynb + ymc;
    ll x1, y1, n, m;
    extended_euclid(a, gcd(b, c));
    x1=x, y1=y;

    extended_euclid(b, c);
    n=x, m=y;
    cout << x1 << " " << y1*n << " " << y1*m << endl;
    return 0;
}
