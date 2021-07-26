#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 4 * (1 << 19) + 10;


int lg[N];
int sp[20][N];
int cnt[N];
int n, mx;
void init(){

    lg[0]=-1;
    for(int i=0;i<mx;i++){
        lg[i+1] = lg[i] + !(i & (i+1));
        sp[0][i] = cnt[i];
    }


}

void buildSP(){

    for(int j=1;(1<<j) < mx;j++){
        for(int i=0;i+(1<<(j-1)) < mx;i++){
            int a = sp[j-1][i];
            int b = sp[j-1][i+(1<<(j-1))];
            sp[j][i] = min(a, b);
        }
    }

}

int query(int st, int en){
    int sz=en-st+1;
    int l = lg[sz];
    int a = sp[l][st];
    int b = sp[l][en - (1<<l) + 1 ];
    return min(a, b);
}

int main(){
    scanf("%d",&n);
    set<int> st;
    pair<int, int> ns[n];
    for(int i=0;i<n;i++){
        int x, y;
        scanf("%d%d",&x, &y);
        st.insert(x);st.insert(y);
        st.insert(x+1);st.insert(y+1);
        ns[i].first=x;ns[i].second=y;
    }

    mx=0;
    map<int, int> mp;
    for(auto it=st.begin();it!=st.end();it++){
        mp[*it]=mx++;
    }

    for(int i=0;i<n;i++){
        int fir=ns[i].first, sec=ns[i].second;
        cnt[ mp[fir] ]++;cnt[ mp[sec]+1 ]--;
    }

    for(int i=0;i<=mx;i++){
        if(i) cnt[i] += cnt[i-1];
    }

    mx++;


    init();
    buildSP();


    for(int i=0;i<n;i++){
        int fir=mp[ns[i].first], sec=mp[ns[i].second];
        if(query(fir, sec) > 1){
            printf("%d\n", i+1);
            return 0;
        }
    }

    printf("-1\n");


    return 0;
}
