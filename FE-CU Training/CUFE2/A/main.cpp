#include<bits/stdc++.h>

using namespace std;

double x1, yy1, x2, y2;
double x3, y3, x4, y4;
const double EPS=1e-8;
double ans=1e10;

double f(double t){
    double slope1=(y2-yy1)/(x2-x1);
    double slope2=(y4-y3)/(x4-x3);

    double theta1=atan(slope1), theta2=atan(slope2);

    double xx1=x1, xx3=x3, yyy=yy1, yy3=y3;


    xx1 = x1+cos(theta1)*t;
    yyy = yy1+sin(theta1)*t;

    xx3 = x3+cos(theta2)*t;
    yy3 = y3+sin(theta2)*t;

    double answer=sqrt((xx1-xx3)*(xx1-xx3)+(yyy-yy3)*((yyy-yy3)));
    ans=min(ans, answer);

    return answer;
}

int main(){
    cin >> x1 >> yy1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;


    // 1, 3
        ans=min( ans, sqrt( (x1-x3)*(x1-x3)+(yy1-y3)*(yy1-y3) ) );
    // 2, 4
        ans=min( ans, sqrt( (x2-x4)*(x2-x4)+(y2-y4)*(y2-y4) ) );



    double len1=sqrt( (x2-x1)*(x2-x1)+(y2-yy1)*(y2-yy1) );
    double len2=sqrt( (x4-x3)*(x4-x3)+(y4-y3)*(y4-y3) );

    double fin=min(len1, len2);

    double st=0, en=fin;

    while(en-st>EPS){

        cout << st << " " << en << "\n";

        double t1=(st+en)/3, t2=2*(st+en)/3;

        if(f(t1)-f(t2)>EPS){
            st=t1;
        } else {
            en=t2;
        }

    }


    return 0;
}
