#include<bits/stdc++.h>
using namespace std;


int t;
long long a, b, c;
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        cout << max(1, (int) sqrt((a+b)*(a+b)+(c*c))-1) << "\n";
    }
    return 0;
}
