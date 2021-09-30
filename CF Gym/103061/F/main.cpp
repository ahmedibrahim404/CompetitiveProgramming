#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-15;
int main(){
    int n, m;
    cin >> n >> m;
    double a[n], b[n];
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }

    double st=0.0, en = 2e9;
    double tot = 0;
    for(int j=0;j<1000;j++){

        double mid = (st+en)/2.0;

        double ans = 0;
        for(int i=0;i<n;i++){
            if(mid - a[i] > EPS){
                if(b[i] - a[i] < EPS){
                    ans += 1.0;
                    continue;
                }
                if(mid - b[i] > EPS) ans += 1.0;
                else ans += (mid - a[i])/(b[i] - a[i]);
            }
        }

        if(ans + EPS >= m){
            en = mid;
            tot = mid;
        } else {
            st= mid;
        }

    }

    cout << setprecision(12) << tot << endl;

    return 0;
}
