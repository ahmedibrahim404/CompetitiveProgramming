#include<bits/stdc++.h>

using namespace std;

typedef complex<double> point;
#define X real()
#define Y imag()

#define angle(v) (atan2((v).Y, (v).X))
#define length(v) ((double) hypot((v).X, (v).Y))

#define polar(r,t) ((r)*(exp(point(0, (t)))))

#define vec(a,b) ((b)-(a))

// to rotate some vector with theta
// vector is R * e^(theta i) rotate by phi
// then new one is R * e^((theta + phi)*i) = vector * e^(phi * i)
#define rotate(r, t, p) polar((r), (t)+(p))
#define rotate(v, p) ((v) * exp(point(0, p)))

// pass by name in hashing
// pass by value in functions

point a;


int main(){
//    double x, y;
//    cin >> x >> y;
//    a=point(x, y);
//    cout << angle(a)*180.0/22*7 << " " << length(a) << "\n";

    double r, theta;
    cin >> r >> theta;
    point p = polar(r, theta);
    cout << p.X << " " << p.Y << "\n";

    return 0;

}
