#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int N = 1000000 + 3;
pi xs[N], ys[N];
int main(){
    int t;cin >> t;
    while(t--){
        int n, m;cin >> n >> m;
        string s;cin >> s;
        int x=0, y=0;

        for(int i=0;i<s.size();i++) xs[i].first=xs[i].second=ys[i].first=ys[i].second=0;

        for(int i=0;i<s.size();i++){
            y += (s[i] == 'R');
            y -= (s[i] == 'L');
            x += (s[i] == 'U');
            x -= (s[i] == 'D');
            if(y > 0)ys[i].first = y;
            else ys[i].second = -y;
            if(x > 0)xs[i].first = x;
            else xs[i].second = -x;

            if(i == 0) continue;
            xs[i].first = max(xs[i-1].first, xs[i].first);
            xs[i].second = max(xs[i-1].second, xs[i].second);

            ys[i].first = max(ys[i-1].first, ys[i].first);
            ys[i].second = max(ys[i-1].second, ys[i].second);

        }

        pi ans;
        for(int i=0;i<s.size();i++){
            int x = xs[i].first;
            int y = m-ys[i].first-1;
            if(x + xs[i].second < n && y - ys[i].second >= 0){
//                cout << x << " " << y << " " << i << " " << 1 << endl;
                if(x < n && y < m)ans = {x, y};
            }
            x = n-xs[i].second-1;
            y = ys[i].second;
            if(x - xs[i].first >= 0 && y + ys[i].first < m){
//                cout << x << " " << y << " " << i << " " << 2 << endl;

                if(x < n && y < m)ans = {x, y};
            }

            x = xs[i].first;
            y = ys[i].second; // 1
            if(x + xs[i].second < n && y + ys[i].first < m){
                if(x < n && y < m)ans = {x, y};
            }

            x = n-xs[i].second-1;
            y = m-ys[i].first-1; // 2
            if(x - xs[i].first >= 0 && y - ys[i].second >= 0){
//                cout << x << " " << y << " " << i << " " << 4 << endl;

                if(x < n && y < m)ans = {x, y};
            }

        }

        cout << ans.first+1 << " " << ans.second+1 << endl;




    }
    return 0;
}
