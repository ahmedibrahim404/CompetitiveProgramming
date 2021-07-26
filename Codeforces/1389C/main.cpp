#include<bits/stdc++.h>

using namespace std;
int t;
string s;
vector<int> ns[10];
int check(int i, int j){

    if(!ns[i].size() || !ns[j].size()) return 0;

    int idx=ns[i][0];
    bool prev=1;
    int sz1=0, sz2=1;


    while(true){

        int x;
        if(prev){
            x=j;
        } else {
            x=i;
        }


        int idxx=lower_bound(ns[x].begin(), ns[x].end(), idx+1)-ns[x].begin();

        if(idxx==ns[x].size()) break;
        idx=ns[x][idxx];
        if(prev) sz1++;
        else sz2++;


        prev=!prev;

    }

    if(i==j) return sz1+sz2;

    return min(sz1, sz2)*2;


}



int main(){
    cin >> t;
    while(t--){
        cin >> s;
        for(int i=0;i<=9;i++) ns[i].clear();
        int n=s.length();
        for(int i=0;i<n;i++){
            ns[ s[i]-'0' ].push_back(i);
        }
        int ans=n;
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                ans=min(ans, n-check(i, j));
                ans=min(ans, n-check(j, i));
            }
        }

        cout << ans << "\n";

    }
    return 0;
}
