#include<bits/stdc++.h>
using namespace std;

bool isin(double x, double y, double r){
    return x*x+y*y <= r*r;
}
double r1, r2, r3, PI, each;
int w, t, n;
int main(){
    PI=2*acos(0.0);
    cin >> t;
    while(t--){
        cin >> w >> r1 >> r2 >> r3;
        each=2.0*PI/w*180/PI;
        int tot =0;
        cin >> n;
        for(int i=0;i<n;i++){
            double a, b;

            cin >> a >> b;
            if(isin(a, b, r1)){
                tot += 50;
                continue;
            }
            double ca=a>0.0?a:-a, cb=b>0.0?b:-b;
            double t=atan(cb/ca)*180/PI;
            if(a>0.0 && b < 0.0) t=360.0-t;
            else if(a<0 && b>0) t=180.0-t;
            else if(a<0 && b<0) t=180.0+t;
            int part=0;
            while(t > 0){
                t -= each;
                part++;
            }

            if(!isin(a, b, r3)) part=0;

            tot += part*( isin(a, b, r2) ? 2 : 1 );

        }

        cout << tot << endl;

    }
//    cout << atan(4/6) *180/PI << endl;

    return 0;
}
