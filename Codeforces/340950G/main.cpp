#include <bits/stdc++.h>

using namespace std;

const int MAX = 501;

int n;
string arr;

int solve (int l, int r) {
    if (l > r) return 0;
    if(l +1 == r && (arr[l] == '*' || arr[r] == '*')){
        if (arr[l] >= 'a' && arr[l] <= 'z'){
            return 1;
        } else if (arr[r] >= 'a' && arr[r] <= 'z'){
            return 1;
        }
        return 0;
    }
    if (l == r) return 1;

    int ans;

    ans = 1e9;
    if (arr[l] == '?' || arr[r] == '?') ans = min(ans, 2 + solve(l+1, r-1));
    if (arr[l] == '*') {
        ans = min(ans, 2 + solve(l, r-1));
        ans = min(ans, solve(l+1, r));
    }
    if (arr[r] == '*') {
        ans = min(ans, 2 + solve(l+1, r));
        ans = min(ans, solve(l, r-1));
    }

    if(arr[l] == arr[r] && arr[r] == '*'){
        ans=min(ans, solve(l+1, r-1));
    }

    if (arr[l] == arr[r] && arr[l] >= 'a' && arr[l] <= 'z') ans = min(ans, 2 + solve(l+1, r-1));

    return ans;
}

void build (int l, int r) {

    if (l > r) return;
    if(l +1 == r && (arr[l] == '*' || arr[r] == '*')){
        if (arr[l] >= 'a' && arr[l] <= 'z'){
            cout << arr[l];
        } else if (arr[r] >= 'a' && arr[r] <= 'z'){
            cout << arr[r];
        }
        return;
    }


    if (l == r) {
        if (arr[l] >= 'a' && arr[l] <= 'z'){
            cout << arr[l];
        } else {
            cout << 'a';
        }
        return;
    }

    int cur = solve(l, r);
    if ((arr[l] == '?' || arr[r] == '?') && 2 + solve(l+1, r-1) == cur){
        if(arr[l] == '?' && arr[r] != '?' && arr[r] != '*') {
            cout << arr[r];
            build(l+1, r-1);
            cout << arr[r];
            return;
        }  else if(arr[l] != '?' && arr[r] == '?' && arr[l] != '*'){
            cout << arr[l];
            build(l+1, r-1);
            cout << arr[l];
            return;
        } else {
            cout << 'a';
            build(l+1, r-1);
            cout << 'a';
            return;
        }
    }


    if (arr[l] == '*') {
        if(cur == 2 + solve(l, r-1)){
            if(arr[r] >= 'a' && arr[r] <= 'z'){
                cout << arr[r];
                build(l, r-1);
                cout << arr[r];
                return;
            } else {
                cout << 'a';
                build(l, r-1);
                cout << 'a';
                return;
            }
        } else if(cur == solve(l+1, r)){
            build(l+1, r);
            return;
        }
    }

    if (arr[r] == '*') {
        if(cur == 2 + solve(l+1, r)){
            if(arr[l] >= 'a' && arr[l] <= 'z'){
                cout << arr[l];
                build(l+1, r);
                cout << arr[l];
                return;
            } else {
                cout << 'a';
                build(l+1, r);
                cout << 'a';
                return;
            }
        } else if(cur == solve(l, r-1)){
            build(l, r-1);
            return;
        }
    }
    if(arr[l] == arr[r] && arr[r] == '*' && solve(l+1, r-1) == cur){
        build(l+1, r-1);
        return;
    }

    if (arr[l] == arr[r] && arr[l] >= 'a' && arr[l] <= 'z' && cur == 2 + solve(l+1, r-1)){
        cout << arr[l];
        build(l+1, r-1);
        cout << arr[l];
        return;
    }

}

int main()
{

    cin >> arr;
    n = arr.size();
    int ans = solve(0, n-1);
    if (ans == 1e9) return cout << -1, 0;
    build(0, n-1);
    return 0;
}
