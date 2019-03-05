#include <iostream>
#include <vector>

using namespace std;

int a, b;
vector<vector<int>> ns;
int cm[100007];
bool visited[100007];
bool cycle=false;
int cnt=0, n=0;

void DFS(int n){

    visited[n]=true;
    cnt++;
    for(int i=0;i<ns[n].size();i++){
        if(!visited[ns[n][i]])
            DFS(ns[n][i]);
        else
            cycle=true;
    }

}

int main(){

    int idx=1;
    while(true){
        int x, y;
        cnt=0;
        n=0;
        for(int i=0;i<100007;i++) cm[i]=-1, visited[i]=false;
        ns = vector<vector<int>>(100007);
        while(cin >> x >> y){
            if(x == 0 && y == 0) break;
            if(x < 0) return 0;
            ns[x].push_back(y);
            if(cm[x] == -1)
                cm[x]=0, n++;
            if(cm[y] == -1)
                cm[y]=0, n++;
            cm[y]++;
        }
        int root = -1;
        for(int i=0;i<100007;i++)
            if(cm[i] == 0){
                root=i;
                break;
            }

        if(root == -1){
            cout << "Case " << idx++ << " is not a tree." << endl;
            return 0;
        }

        cycle=false;
        DFS(root);
        if(!cycle && cnt == n)
            cout << "Case " << idx++ << " is a tree." << endl;
        else cout << "Case " << idx++ << " is not a tree." << endl;

    }

    return 0;
}

