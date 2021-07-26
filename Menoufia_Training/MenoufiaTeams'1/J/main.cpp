#include <bits/stdc++.h>

using namespace std;
const int MAX=100000+3;
int n, m;
int a[MAX];
int cnt[MAX];
int main()
{

    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        memset(cnt, 0, sizeof cnt);
        for(int i=0;i<m;i++){
            cin >> a[i];
        }
        int no;
        for(int i=0;i<m;i++){
            cin >> no;
            cnt[1] += abs(no)/n;
            cnt[n+1] -= abs(no)/n;
            no%=(n);
            // a[i] --> (a[i]+no)%n
            int from=a[i], to=(((a[i]+no)%(n))+(n))%(n);
            if(!to)to=n;
            if(no<0) swap(from, to);
            cnt[from]++;
            cnt[to+1]--;
            if(from>to){
                cnt[1]++;
                cnt[n+1]--;
            }
        }

        int hr=0, mx=0;
        for(int i=1;i<=n;i++){
            cnt[i] += cnt[i-1];
        }

        for(int i=1;i<=n;i++){
            if(cnt[i]>mx) mx=cnt[i], hr=i;
        }

        cout << hr << " " << mx << "\n";


    }

}
