#include<bits/stdc++.h>

using namespace std;

int t, x;

int main(){
    cin >> t;
    while(t--){
        cin >> x;
        int ans=0;
        for(int i=9;i>0;i--){
            if(x >= i) x-=i, ans*=10, ans += i;
        }
        if(x){
            cout << "-1\n";
            continue;
        }

        vector<int> lst;
        while(ans) {
            lst.push_back(ans%10);
            ans /= 10;
        }

        sort(lst.begin(), lst.end());
        for(int i=0;i<lst.size();i++) cout << lst[i];
        cout << "\n";

    }
    return 0;
}
