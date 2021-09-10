#include<bits/stdc++.h>


using namespace std;
const double EPS = 1e-12;
double ans=-1.0;
double area(double a, double b, double c){
    if (max({a, b, c}) * 2 > a + b + c)
            return 0;

    double cr = (a+b+c)/2.0;
    double det = cr*(cr-a)*(cr-b)*(cr-c);
    return sqrt(det);
}
int t, a, b, c, k;
int main(){
    freopen("sticks.in", "r", stdin);

    cin >> t;
    while(t--){
        int v[3];
        cin >> v[0] >> v[1] >> v[2] >> k;
        sort(v, v+3);

        ans=-1.0;
        double st=0, en=min(k, v[1]+v[2]-v[0]);
        for(int j=0;j<300;j++){
            double step=(en-st)/3.0;
            double m1=st+step, m2=st+2.0*step;
            if(area(v[0]+m1, v[1], v[2]) > area(v[0]+m2, v[1], v[2])){
                en=m2;
            } else {
                st=m1;
            }
        }

        cout << setprecision(12) <<  area(v[0]+st, v[1], v[2])<< "\n";


    }

    return 0;
}
