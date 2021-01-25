#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    if(is_sorted(arr.begin(), arr.end()))
        cout << 0 << '\n';
    else
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > x)
            {
                swap(x, arr[i]);
                cnt++;
            }
            if(is_sorted(arr.begin(), arr.end()))
                break;
        }
        if(is_sorted(arr.begin(), arr.end()))
            cout << cnt << '\n';
        else
            cout << -1 << '\n';
    }

}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) test_case();
    return 0;
}
