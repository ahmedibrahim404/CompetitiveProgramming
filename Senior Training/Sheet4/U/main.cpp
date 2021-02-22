#include<bits/stdc++.h>
using namespace std;

int n;
string str;
int main(){
    cin >> n;
    double no, ans=0;
    vector<double> vi=vector<double>(n);
    for(int i=0;i<n;i++){
        cin >> str >> vi[i];
    }

    sort(vi.begin(), vi.end(), greater<double>());
    for(int i=0;i<n;i++){
        ans += (i+1) * 1.0 * vi[i];
    }
    cout << fixed;
    cout << setprecision(10);
    cout << ans << "\n";
    return 0;
}
