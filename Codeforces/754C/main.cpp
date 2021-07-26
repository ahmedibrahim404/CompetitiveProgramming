#include<bits/stdc++.h>

using namespace std;
typedef pair<string ,int> pi;
const int MAX=100+9;
int t, n, m;
map<string, int> mp;
pi msg[MAX];

bool dp[MAX][MAX];
int vis[MAX][MAX];
int vis2[MAX][MAX];
bool is[MAX][MAX];

string names[MAX];

int lvl=1, lvl2=1;
bool solve(int idx=0, int presender=n+1){

    if(idx==m) return 1;


    bool &ret=dp[idx][presender];
    if(vis[idx][presender]==lvl) return ret;
    vis[idx][presender]=lvl;

    ret=0;
    if(msg[idx].second==0){
        for(int i=1;i<=n;i++){
            if(is[idx][i] && presender != i){
                ret|=solve(idx+1, i);
            }
        }
    } else {
        if(is[idx][ msg[idx].second ] && msg[idx].second != presender){
            ret|=solve(idx+1, msg[idx].second);
        }
    }

    return ret;

}

void build(int idx=0, int presender=n+1){

    if(idx==m) return;

    bool &ret=dp[idx][presender];
    if(vis2[idx][presender]==lvl2) return;
    vis2[idx][presender]=lvl2;

    if(msg[idx].second==0){
        for(int i=1;i<=n;i++){
            if(is[idx][i] && presender != i){
                if(solve(idx+1, i) == ret){

                    cout << names[i] << ":" << msg[idx].first << endl;
                    build(idx+1, i);
                    return;
                }
            }
        }
    } else {
        if(is[idx][ msg[idx].second ] && msg[idx].second != presender){
            if(solve(idx+1, msg[idx].second)==ret){
                cout << names[ msg[idx].second ] << ":" << msg[idx].first << endl;
                build(idx+1, msg[idx].second);
                return;
            }
        }
    }

}



int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        mp.clear();
        memset(is, 1, sizeof is);
        string name;
        mp["?"]=0;
        for(int i=1;i<=n;i++){
            cin >> name;
            mp[name]=i;
            names[i]=name;
        }
        cin >> m;
        cin.ignore();
        string str;
        for(int i=0;i<m;i++){
            getline(cin, str);
            int j=0;
            while(str[j] != ':'){
                j++;
            }
            msg[i].first=str.substr(j+1);
            string sender=str.substr(0, j);
            msg[i].second=mp[sender];
        }
        lvl++, lvl2++;


        auto splitIntoTokensOfLatinLetters = [](const string& s) {
            vector<string> result;
            string token;
            for (char c : s) {
                if (isalpha(c) || isdigit(c)) {
                    token += c;
                }
                else {
                    if (!token.empty()) {
                        result.push_back(token);
                    }
                    token.clear();
                }
            }
            if (!token.empty()) {
                result.push_back(token);
            }
            return result;
        };



        for(int i=0;i<m;i++){
            string m=msg[i].first;
            vector<string> tokens = splitIntoTokensOfLatinLetters(m);
            for (const string& z : tokens) {
                if(mp.find(z)==mp.end()) continue;
                int idx = mp[z];
                is[i][idx] = false;
            }
        }



        bool res=solve();
        if(!res){
            cout << "Impossible" << endl;
            continue;
        }
        build();

//        for(int i=0;i<m;i++){
//            cout << "SENDER " << msg[i].second << endl;
//            cout << "MSG " << msg[i].first << endl;
//        }

    }

    return 0;
}
