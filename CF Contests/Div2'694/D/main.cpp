#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 3e5 + 5, INF = 2e9;
int a[N];
void solve()
{
   int n;
   cin >> n;
   map<int,int>cnt;
   for(int i = 0; i < n; i++)
   {
       int x;
       cin >> x;
       a[i] = 1;
       for(int j = 2; j * j <= x; j++)
       {
           int c = 0;
           while(x % j == 0)
           {
               x /= j;
               c++;
           }
           if(c % 2)
               a[i] *= j;
       }
       a[i] *= x;
       cnt[a[i]]++;
   }
   int mx1 = 0, mx2 = 0;
   for(auto P:cnt)
       mx1 = max(mx1, P.second);

   for(auto P:cnt)
   {
       if(P.first == 1) continue;
       if(P.second % 2 == 0)
           cnt[1] += P.second;
   }
   mx2 = max(mx1, cnt[1]);
   int q;
   cin >> q;
   while(q--)
   {
       ll w;
       cin >> w;
       if(w == 0) cout << mx1 << '\n';
       else cout << mx2 << '\n';
   }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
