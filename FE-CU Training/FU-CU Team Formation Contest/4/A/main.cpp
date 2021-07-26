#include<bits/stdc++.h>
using namespace std;


int n, m;
string str;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    cin >> str;

    vector<int> odds(n);
    int mxodd=1, mxeven=0;
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(odds[l + r - i], r - i + 1);
        while (k <= i && i + k < n && str[i - k] == str[i + k]) {
            k++;
        }
        odds[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
        mxodd=max(mxodd, r-l+1);
    }

    vector<int> evens(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(evens[l + r - i + 1], r - i + 1);
        while (k <= i - 1 && i + k < n && str[i - k - 1] == str[i + k]) {
            k++;
        }
        evens[i] = k--;

        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }

        mxeven=max(mxeven, r-l+1);
    }


    if(m%2){
        if(mxodd>=m) cout << "Accept\n";
        else cout << "Reject\n";
    } else {
        if(mxeven>=m) cout << "Accept\n";
        else cout << "Reject\n";
    }
    return 0;
}
