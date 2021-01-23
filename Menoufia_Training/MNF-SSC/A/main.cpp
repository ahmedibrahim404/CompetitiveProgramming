#include <iostream>
#include <cstring>
#include<queue>
using namespace std;
int a, b;
char ns[100][100];
bool vis[100][100];
typedef pair<int, int> pi;
int xs[] = {-1, 1, 0, 0};
int ys[] = {0, 0, -1, 1};
int ans=0, mx, my=-1;
void bfs(int a, int b){

    if(a < 0 || b < 0 || a >= mx || b >= mx || ns[a][b]=='1') return;
    if(vis[a][b]) return;

    ans++;
    vis[a][b]=1;
    bfs(a+1, b);
    bfs(a-1, b);
    bfs(a, b+1);
    bfs(a, b-1);

}

int main(){
    string str;
    int t;
    getline(cin, str);
    t=atoi(str.c_str());
    getline(cin, str);
    while (t--){
        my=-1;
        bool read=0;
        int a, b, i=0;
        while(getline(cin, str)){
            if(!read){
                string sa=str.substr(0, 2), sb=str.substr(3, 2);
                a=atoi(sa.c_str()); b=atoi(sb.c_str());
                read=1;
                continue;
            }
            int len=str.length();
            if(my==-1) my=len;
            for(int j=0;j<len;j++) ns[i][j]=str[j];
            i++;
            if(str=="") break;
        }
        mx=i;
        ans=0;
        memset(vis, 0, sizeof(vis));
        bfs(a, b);
        cout << ans << "\n";
    }
    return 0;
}
