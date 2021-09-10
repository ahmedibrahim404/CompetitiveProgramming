#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
double x1 ,yy1, x2, y2;
double vx1, vy1, vx2, vy2;
double ans;
double dis(double tim){
    double nx1 = x1 + vx1 * tim;
    double ny1 = yy1 + vy1 * tim;
    double nx2 = x2 + vx2 * tim;
    double ny2 = y2 + vy2 * tim;

    double re= sqrt((nx1-nx2)*(nx1-nx2) + (ny1-ny2)*(ny1-ny2));
    if(ans - re > EPS) ans = re;

    return re;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);

    cin >> x1 >> yy1 >> x2 >> y2;
    cin >> vx1 >> vy1 >> vx2 >> vy2;

    ans = sqrt((x2-x1) *(x2-x1) + (y2-yy1) * (y2-yy1));

    double st=0, en=1e6;
    while(en - st > EPS){
        double f=st + (en-st)/3.0;
        double s=f + (en-st)/3.0;
        if(dis(f) - dis(s) > EPS) st=f;
        else en=s;
    }

    cout << setprecision(12) << ans;

    return 0;
}
