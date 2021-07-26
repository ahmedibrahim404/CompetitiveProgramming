#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi mult(const vvi &a, const vvi &b) {
    vvi ret;
    ret=a;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b[0].size(); ++j) {
            for (int k = 0; k < a[0].size(); ++k) {
                ret[i][j] = max(ret[i][j], a[i][k] + b[k][j]);
            }

        }
    }
    return ret;
}

vvi power(vvi a,int b){
    if (b==1)
        return a;
    if (b%2)
        return mult(a, power(a,b-1));
    return power(mult(a,a),b/2);
}


int n, m;
vvi ns;
int main(){
    scanf("%d%d",&n,&m);
    ns = vvi(n, vi(n, -1e9));
    while(m--){
        int i, j, c1, c2;
        scanf("%d%d%d%d",&i,&j,&c1,&c2);
        i--, j--;
        ns[i][j]=max(c1, ns[i][j]);
        ns[j][i]=max(c2, ns[j][i]);
    }

    for(int i=0;i<n;i++) ns[i][i]=0;

    int st=2, en=n;
    int ans=0;
    while(en >= st){
        int mid=(st+en)>>1;
        vvi a=power(ns, mid);
        bool cc=0;
        for(int i=0;i<n;i++) if(a[i][i] > 0) cc=1;
        if(cc)ans=mid, en=mid-1;
        else st=mid+1;
    }


    printf("%d\n", ans);

    return 0;
}
