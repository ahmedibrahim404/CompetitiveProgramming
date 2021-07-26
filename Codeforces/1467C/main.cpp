#include <iostream>

using namespace std;
typedef long long ll;
const int MAX=300000+3;
int n1, n2, n3;
ll p1[MAX], p2[MAX], p3[MAX];
int main(){
    cin >> n1 >> n2 >> n3;
    ll t1,t2,t3, m1=2e18, m2=2e18, m3=2e18;
    t1=t2=t3=0;

    for(int i=0;i<n1;i++){
        cin >> p1[i];
        t1 += p1[i];
        m1=min(m1, p1[i]);
    }

    for(int i=0;i<n2;i++){
        cin >> p2[i];
        t2 += p2[i];
        m2=min(m2, p2[i]);

    }

    for(int i=0;i<n3;i++){
        cin >> p3[i];
        t3 += p3[i];
        m3=min(m3, p3[i]);
    }

    ll mx=-2e18;
    mx = max(t2 - t3 + t1, mx);
    mx = max(- t2 + t3 + t1, mx);

    mx = max(t3 - t1 + t2, mx);
    mx = max(- t3 + t1 + t2, mx);

    mx = max(t1 - t2 + t3, mx);
    mx = max(- t1 + t2 + t3, mx);

    mx=max(mx, t1+t2+t3-2*(m1+m2));
    mx=max(mx, t1+t2+t3-2*(m2+m3));
    mx=max(mx, t1+t2+t3-2*(m1+m3));

    cout << mx << "\n";

    return 0;
}
