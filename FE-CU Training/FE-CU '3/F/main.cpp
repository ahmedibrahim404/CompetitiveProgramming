#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
const int MAX=200000+3;
int n, m;
int parent[MAX];
vector<ppi> ans;
map<int, int> mp, mp2;
vvi ns;
int get(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = get(parent[v]);
}

void union_sets(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b)
        parent[b] = a;
}

int main(){
    scanf("%d",&n);
    ns=vvi(MAX);
    for(int i=0;i<n;i++) parent[i]=i;
    int m, cur=0;
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        int no;
        for(int j=0;j<m;j++){
            scanf("%d",&no);
            if(mp.find(no)==mp.end()) mp[no]=cur, mp2[cur++]=no;
            int idx=mp[no];
            ns[idx].push_back(i);
        }
    }


    for(int i=0;i<cur;i++){
        vi v=ns[i];
        int sz=v.size();
        int no=v[0];
        for(int j=1;j<sz;j++){
            int to=v[j];
            if(get(no) != get(to)){
                union_sets(no, to);
                ans.push_back({ {no, to}, mp2[i] });
            }
        }
    }
    int xx=get(0);
    bool is=1;
    for(int i=0;i<n;i++){
        if(get(i) != xx) is=0;
    }

    if(is==0) printf("impossible\n");
    else {
        int sz=ans.size();
        for(int i=0;i<sz;i++){
            printf("%d %d %d\n", ans[i].first.first+1, ans[i].first.second+1, ans[i].second);
        }
    }

    return 0;
}
