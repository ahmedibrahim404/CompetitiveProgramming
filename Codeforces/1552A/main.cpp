#include<bits/stdc++.h>
using namespace std;

int t, n;

int main(){
    cin >> t;
    while(t--){string s;
        cin >> n >> s;
        string s2=s;int pos[27]; for(int i=0;i<27;i++) pos[i]=-1;
        sort(s2.begin(), s2.end());
        for(int i=0;i<n;i++){
            if(!~pos[ s2[i]-'a' ]) pos[ s2[i]-'a' ] = i;
        }int cnt=0;

        pos[26] =n;
        for(int i=26;i>=1;i--){
            if(!~pos[i-1]) pos[i-1] = pos[i];
        }


        for(int i=0;i<n;i++){

            if(i >= pos[ s[i]-'a' ] && i < pos[ (s[i]-'a') + 1 ]) continue;
            cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
