#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=50000+3;
int C, P, S;
ll sc[MAX];
ll score[MAX];
string strss[MAX];
map<string, int> cids, pids;
int main(){
    cin >> C >> P >> S;
    string str;
    for(int i=1;i<=C;i++){
        cin >> strss[i];
        cids[strss[i]]=i;
    }
    for(int i=1;i<=P;i++){
        cin >> str >> sc[i];
        pids[str]=i;
    }

    string a, b, c;
    while(S--){
        cin >> a >> b >> c;
        if(c!="AC") continue;
        int solver=cids[a];
        int problem=pids[b];
        score[solver]+=sc[problem];
    }

    for(int i=1;i<=C;i++){
        string name=strss[i];
        cout << name << " " << score[i] << endl;
    }


    return 0;
}
