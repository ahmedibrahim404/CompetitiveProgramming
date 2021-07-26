#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int T;
string str;
bool is[26], vis[26];
bool ns[26][26];

int bfs(int node){

    int cnt=1;
    queue<pi> q;
    q.push(pi(node, -1));
    vis[node]=1;
    while(!q.empty()){
        pi no=q.front();q.pop();
        int nono=no.first, par=no.second;
        for(int i=0;i<26;i++){
            if(ns[i][nono] && i!=par && !vis[i]) vis[i]=1, cnt ++, q.push( pi(i, nono) );
        }
    }

    return cnt;

}

int main(){
    cin >> T;
    while(T--){

        for(int i=0;i<26;i++)is[i]=0, vis[i]=0;
        memset(ns, 0, sizeof ns);
        while(cin >> str){
            if(str[0]!='(') break;
            ns[ str[1]-'A' ][ str[3]-'A' ]=1;
            ns[ str[3]-'A' ][ str[1]-'A' ]=1;
        }
        cin >> str;
        for(int i=0;i<str.length();i+=2){
            is[str[i]-'A']=1;
        }
        int ac=0, tr=0;
        for(int i=0;i<26;i++){
            if(is[i]){
                if(!vis[i]){
                    int cnt=bfs(i);
                    if(cnt==1)ac++;
                    else tr++;
                }
            }
        }

        cout << "There are "<<tr<<" tree(s) and "<<ac<<" acorn(s)."<< endl;

    }
    return 0;
}
