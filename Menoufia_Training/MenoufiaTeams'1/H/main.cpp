#include <iostream>

using namespace std;
const int MAX=100000+3;
int parent[MAX];

int get(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = get(parent[v]);
}

void unions_set(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b)
        parent[b] = a;
}
int n,m,q,a,b, t;
int main(){
    cin >> t;
    while(t--){
    cin >> n >> m >> q;
    for(int i=0;i<n;i++ )parent[i]=i;
    while(m--){
        cin >> a >> b;
        a--, b--;
        unions_set(a, b);
    }
    string ans="";
    while(q--){
        cin >> a >> b;
        a--, b--;
        if(get(a)==get(b)) ans += "1";
        else ans += "0";
    }
    cout << ans << "\n";
    }

    return 0;
}
