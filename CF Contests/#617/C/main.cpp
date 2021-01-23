#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;
int t, n;
string str;

map< pr, int > mp;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> str;
        int v=0, h=0;
        bool is=0;
        int st, en;
        mp[pr(0,0)]=-1;
        for(int i=0;i<n;i++){
            if(str[i]=='U') v++;
            else if(str[i]=='D') v--;
            else if(str[i]=='R') h++;
            else h--;
            pr cur=pr(v,h);
            if(mp.find(cur) != mp.end()){
//                cout << i << endl;
//                cout << mp[cur] << endl;
                if(!is){
                    is=1;
                    st=mp[cur]+2;
                    en=i+1;
                } else {
                    if(i-mp[cur]<en-st) st=mp[cur]+2, en=i+1;
                }
//                cout << st << " " << en << endl;
            }
            mp[cur]=i;
        }

        if(is) cout << st << " " << en << endl;
        else cout << -1 << endl;

        mp.clear();
    }
    return 0;
}
