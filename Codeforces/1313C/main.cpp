#include <bits/stdc++.h>

typedef long long ll ;
using namespace std ;
const int N = 500001+3;
int a[N], ans[N], n;
ll L[N], R[N];

int main(){

    memset(R, 0, sizeof R);
    memset(L, 0, sizeof L);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    stack<int> sk;
    L[0] = a[0];
    sk.push(0);
    int mn=0;
    for (int i = 1; i < n; i++){
        if (a[i] <= a[mn])L[i] = 1LL*(i+1)*a[i];
        else{
            while(!sk.empty() && a[i] <= a[sk.top()])sk.pop();
            if (sk.empty()) L[i] = 1LL*(i+1)*a[i];
            else
                L[i] = L[sk.top()] + (1LL*i-sk.top())*a[i];
        }
        sk.push(i);
        if (a[i] <= a[mn])mn=i;
    }


    sk = stack<int>();
    R[n-1] = a[n-1];
    mn=n-1;
    sk.push(n-1);
    for (int i = n-2; i >= 0; i--){
        if (a[i] <= a[mn]){
          R[i] = 1LL*(n-i)*a[i];
        }else{
          while(!sk.empty() && a[i] <= a[sk.top()])sk.pop();
          if (sk.empty()) R[i] = 1LL*(n-i)*a[i];
          else R[i] = R[sk.top()] + (1LL*sk.top() - i)*a[i];
        }
        sk.push(i);
        if (a[i] <= a[mn])mn=i;
    }



    ll mx = 0;
    int idx = 0;
    for (int i = 0 ; i < n; i++){
        if (L[i] + R[i] - a[i] > mx){
          mx = L[i] + R[i] - a[i];
          idx = i;
        }
    }

    int i = idx - 1;
    while(i >= 0){
        a[i] = min(a[i], a[i+1]);
        i--;
    }
    i = idx + 1;

    while(i < n){
        a[i] = min(a[i], a[i-1]);
        i++;
    }

    for (int i = 0; i < n; i++)
    cout << a[i] <<" ";
    cout <<"\n";
}
