#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi ns;

const int N = 501;
int n, m;
char str[N][N];

int dfn[N*N], lowestLink[N*N];
bool isArt[N*N];bool root=0;
bool inStack[N*N];
int tim=0;

void tarjan(int node){

    inStack[node]=1;
    dfn[node] = lowestLink[node] = tim++;

    for(int child: ns[node]){
        if(dfn[child]==-1) {
            tarjan(child);
            lowestLink[node]=min(lowestLink[node], lowestLink[child]);
            if(lowestLink[child] >= dfn[node]) {
                if(dfn[node] == 0 && !root)
                    root=1;
                else
                    isArt[node]=1;
            }

        } else if(inStack[child]){
            lowestLink[node]=min(lowestLink[node], dfn[child]);
        }
    }



}

bool check(int x, int y){
    return x < n && y < m && x >= 0 && y >= 0;
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(str[i][j] != '#') str[i][j] = '.';
            cout << str[i][j];
        }
        cout << "\n";
    }
}

int main(){

    cin >> n >> m;int si=-1, sj=-1;ns=vvi(n*m);
    for(int i=0;i<n*m;i++) isArt[i]=0, dfn[i]=-1, lowestLink[i]=0, inStack[i]=0;
    for(int i=0;i<n;i++){
        cin >> str[i];
        for(int j=0;j<m;j++){
            if(str[i][j] == '#') continue;
            if(str[i][j] == '.')si=i, sj=j;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(str[i][j] == '#') continue;

            if(check(i+1, j)) {
                int node=(i+1)*m+j;
                if(str[i+1][j] != '#'){
                    ns[i*m+j].push_back(node);
                }
            }

            if(check(i-1, j)) {
                int node=(i-1)*m+j;
                if(str[i-1][j] != '#'){
                    ns[i*m+j].push_back(node);
                }

            }

            if(check(i, j+1)) {
                int node=i*m+j+1;
                if(str[i][j+1] != '#'){
                    ns[i*m+j].push_back(node);
                }

            }

            if(check(i, j-1)) {
                int node=i*m+j-1;
                if(str[i][j-1] != '#'){
                    ns[i*m+j].push_back(node);
                }
            }


        }
    }



    tarjan(si*m+sj);bool can=1;
    for(int i=0;i<n && can;i++){
        for(int j=0;j<m;j++){
            if(str[i][j] == '#') continue;
            if(dfn[i*m+j] == -1) {
                if(str[i][j] == '.' ){
                    can=0;
                    break;
                }
                if(str[i][j] == '?'){
                    str[i][j] = '#';
                }
            }
        }
    }


    bool cc=1;
    for(int i=0;i<n && can;i++){
        for(int j=0;j<m;j++){
            if(str[i][j] == '?') {
                if(!isArt[i*m+j]) cc=0;
            }
        }
    }


    if(!can) cout << "Impossible\n";
    else {
        if(cc) print();
        else cout << "Ambiguous\n";
    }

    return 0;
}
