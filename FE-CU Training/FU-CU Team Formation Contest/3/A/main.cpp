#include <iostream>

using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MAX=100000+3;
int N, bs[MAX];
string a;
pi l[MAX], m[MAX], r[MAX];
int ans=0, num=-1;

bool vis[MAX];
void dfs(int idx=0, int par=-1, int last=0, int lastnum=-1){

    int sz=ns[idx].size();
    for(int i=0;i<sz;i++){
        int to=ns[idx][i];
        if(l[to].second==lastnum){
            last+l[to].first
        }
        dfs(to, idx);



    }

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    ns=vvi(N);
    for(int i=0;i<N;i++){
        cin >> a >> bs[i];
        int len=a.length();
        bool is=0;
        int cnt=1, no=a[0]-'0';
        for(int i=1;i<len;i++){
            if(a[i]==a[i-1]) cnt++;
            else {
                if(!is){
                    l[i].first=cnt;
                    l[i].second=no;
                    is=1;
                } else {
                    if(cnt > m[i]){
                        m[i].first=cnt;
                        m[i].second=no;
                    } else if(cnt==m[i]){
                        if(m[i].second>no){
                            m[i].second=no;
                        }
                    }
                }
                cnt=1;
                no=a[i]-'0';
            }
        }
        if(!is){
            l[i].first=cnt;
            l[i].second=no;
        }
        if(cnt > m[i]){
            m[i].first=cnt;
            m[i].second=no;
        } else if(cnt==m[i]){
            if(m[i].second>no){
                m[i].second=no;
            }
        }
        r[i].first=cnt;
        r[i].second=no;

    }

    int x, y;
    for(int i=0;i<N-1;i++){
        cin >> x >> y;
        x--, y--;
        ns[x].push_back(y);
        ns[y].push_back(x);
    }

    dfs(0);

    return 0;
}
