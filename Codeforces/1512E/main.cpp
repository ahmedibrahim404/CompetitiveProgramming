#include<bits/stdc++.h>

using namespace std;

int sig(int n){
    return n*(n+1)/2;
}

int sum(int a, int b){
    return sig(b) - sig(a-1);
}

int main(){

    int t;
    cin >>t;
    while(t--){
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        if(s > n*(n+1)/2){
            cout << "-1\n";
            continue;
        }
        int k = r - l + 1;
        set<int> st;
        set<int> st2;
        for(int i=n;i >= k && k > 0;i--){
            if(i >= k && sum(i-k+1, i-1) >= s - i && sum(1, k-1) <= s - i){
                st.insert(i);
                k--;
                s -= i;
            }
        }
        if(k > 0){
            cout << "-1\n";
            continue;
        }

        for(int i=1;i<=n;i++){
            if(st.count(i)) continue;
            st2.insert(i);
        }

        int ans[n];
        l--, r--;
        auto it = st.begin();
        for(int j=l;j<=r;j++){
            ans[j] = *it;
            it++;
        }

        it = st2.begin();
        for(int i=0;i<n;i++){
            if(i >= l && i <= r) continue;
            ans[i] = *it;
            it++;
        }

        for(int i=0;i<n;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";

    }

    return 0;
}
