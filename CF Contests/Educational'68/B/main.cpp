#include<bits/stdc++.h>

using namespace std;

int q, n, m, a[50000+9], b[50000+9];
char str[50000+9];
vector<string> vi;
int main(){
    scanf("%d",&q);
    while(q--){
        for(int i=0;i<n;i++) a[i]=0;
        for(int j=0;j<m;j++) b[j]=0;
        int bm=0, am=0, ai, bi;
        scanf("%d %d",&n,&m);
        vi=vector<string>(n+1);
        for(int i=0;i<n;i++) {
            scanf("%s", str);
            string s(str);
            vi[i]=s;
            for(int j=0;j<m;j++){
                if(str[j]=='*') a[i]++, b[j]++;
            }
        }
        int mi=2e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mi=min(mi, (n-a[i])+(m-b[j])-(vi[i][j]=='.'));
            }
        }
        cout << mi << endl;
    }

    return 0;
}
