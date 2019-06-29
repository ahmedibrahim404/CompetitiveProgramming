#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14159265

long double ss(double no){
    return sin( no*PI/180 );
}

long double x, y;
int n, r;
int main(){
    scanf("%d %d", &n, &r);

    x=((double) 2*180)/n;
    y=((double) 180-x)/2;

    double ans=r/( (ss(y)/ss(x))-.5 );
    printf("%.9lf", ans/2);

    return 0;
}
