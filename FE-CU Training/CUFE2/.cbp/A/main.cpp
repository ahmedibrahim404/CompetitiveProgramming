#include<bits/stdc++.h>

using namespace std;

const double EPS=1e-12;
const double pi=3.14159265359;
double ans;
double len1, len2, theta1, theta2;
double dis2(double ox, double oy, double ex, double ey){ return (ox - ex) * (ox - ex) + (oy - ey) * (oy - ey); }
typedef long long ll;
ll asx, asy, aex, aey;
ll bsx, bsy, bex, bey;

double f(double t){
    double x1, y1, x2, y2, dx, dy, d;
    dx = 1.0*aex - asx, dy = 1.0*aey - asy;
    d = len1;
    if(t>=d-EPS) x1 = aex, y1 = aey;
    else x1 = asx + t * (dx / d), y1 = asy + t * (dy / d);
    dx = bex - bsx, dy = bey - bsy;
    d = len2;
    if(t>=d-EPS) x2 = bex, y2 = bey;
    else x2 = bsx + t * (dx / d), y2 = bsy + t * (dy / d);

    return dis2(x1,y1,x2,y2);

}


int main(){
    cin >> asx >> asy >> aex >> aey;
    cin >> bsx >> bsy >> bex >> bey;
    ans=1e15;

    len1=dis2(asx, asy, aex, aey);
    len2=dis2(bsx, bsy, bex, bey);

    double fin=max(len1, len2);
    double mu=min(len1, len2);

    double st=0, en=mu;
    for(int i=0;i<100;i++){
//
        double t1=st+(-st+en)/3, t2=st+2*(-st+en)/3;
        double ans1=f(t1), ans2=f(t2);


        if(ans1+EPS <= ans2) en = t2;
        else st = t1;
        ans=min(ans, ans1);
        ans=min(ans, ans2);

    }

    st=mu, en=fin;
        cout << st << ",, " << en <<"\n";

    for(int i=0;i<100;i++){
//

        double t1=st+(-st+en)/3, t2=st+2*(-st+en)/3;
        double ans1=f(t1), ans2=f(t2);
        cout << t1 << " " << ans1 << "\n";
        cout << t2 << " " << ans2 << "\n";


        if(ans1+EPS <= ans2) en = t2;
        else st = t1;

        ans=min(ans, ans1);
        ans=min(ans, ans2);
    }

//    if(ans < EPS) ans=0;

    cout << setprecision(12) << ans << "\n";

    return 0;
}
