#include <bits/stdc++.h>
using namespace std;

int product(int x)
{
    int prod = 1;
    while (x) {
        prod *= (x % 10);
        x /= 10;
    }
    return prod;
}

int findNumber(int l, int r){
    string a = to_string(l);
    string b = to_string(r);

    int ans = r;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '0')
            continue;

        string curr = b;
        curr[i] = ((curr[i] - '0') - 1) + '0';

        for (int j = i + 1; j < curr.size(); j++) curr[j] = '9';

        int num = 0;
        for (auto c : curr)
            num = num * 10 + (c - '0');

        if (num >= l && product(ans) < product(num))
            ans = num;

    }

    return ans;
}

// Driver Code
int main()
{
    int n;
    cin >> n;
    cout << product(findNumber(1, n)) << endl;
    return 0;
}
