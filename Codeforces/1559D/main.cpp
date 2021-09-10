#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 3;
struct dsu{

    int par[N];set<int> st;
    void init(int n){
        for(int i=0;i<n;i++) par[i]=i, st.insert(i);
    }

    int get(int x){
        return par[x] = x == par[x] ? x : get(par[x]);
    }

    void add(int x, int y){
        x=get(x), y=get(y);
        if(x>y) swap(x, y);
        par[x] = y;
        st.erase(st.find(x));
    }


} d1, d2;

int main(){

    int n, m1, m2;
    scanf("%d%d%d",&n,&m1,&m2);
    d1.init(n);d2.init(n);
    while(m1--){
        int a, b;
        scanf("%d%d",&a,&b);a--, b--;
        d1.add(a, b);
    }

    while(m2--){
        int a, b;
        scanf("%d%d",&a,&b);a--, b--;
        d2.add(a, b);
    }

    vector<pair<int, int>> ans;

    set<int> &s1 = d1.st, &s2=d2.st;

    for(int i=0;i<n;i++){
        int cur=d2.get(i);
        if(s1.count(i) && s1.count(cur)){
            s1.erase(s1.find(i));
        }

        cur=d1.get(i);
        if(s2.count(i) && s2.count(cur)){
            s2.erase(s2.find(i));
        }

    }




    printf("%d\n", s1.size()-1);
    auto it=s1.begin();
    for(int i=0;i<s1.size()-1;i++){
        printf("%d ", (*it)+1);
        it++;
        printf("%d\n", (*it)+1);
    }

    return 0;
}
