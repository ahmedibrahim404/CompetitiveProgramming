#include <bits/stdc++.h>


using namespace std;



int main() {

    string s;
    int k, kk;
    cin >> s >> k;
    kk = k;
    int n = s.length();
    vector<pair<char, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i].first = s[i];
        vec[i].second = i;
    }
    sort(vec.begin(), vec.end());
    string ans;
    int cur = -1, cnt=k;
    for (int i = 0; i < n; ++i) {
        cout << n-vec[i].second-1 << " " << cnt << "\n";
        if (n - vec[i].second - 1 >= cnt && vec[i].second > cur) {
            ans += vec[i].first;
            cur = vec[i].second;
            cnt--;
        }
        if(!cnt) break;
    }
    cout << ans << endl;
    return 0;
}
