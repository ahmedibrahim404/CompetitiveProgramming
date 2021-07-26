#include<bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

double ans, a, b, c, d;;

void solve(double c, double m, double p, int i, double cross=1){
    if(c-EPS>0)solve(max(0.0, c-d), m+(m-EPS>0?min(c, d)/2.0:0.0), p+min(c, d)/(m-EPS>0?2.0:1.0), i+1, cross*c);
    if(m-EPS >0)solve(c+(c-EPS>0?min(m, d)/2.0:0.0),max(0.0, m-d), p+min(m, d)/(c-EPS>0?2.0:1.0), i+1, cross*m);
    ans = ans + 1.0 * i * p * cross;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        ans=0;
        solve(a, b, c, 1);
        cout << setprecision(10) << ans << endl;;
    }
    return 0;
}
