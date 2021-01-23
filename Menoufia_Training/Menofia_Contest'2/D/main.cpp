#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int n, ch[4], pre, a;
int as[100+9];
string str;

bool cmp(int x2, int x1){
    return ch[x2] < ch[x1];
}

int main(){
    cin >> n;
    int idx1=0, idx2=0;
    for(int k=0;k<4;k++){
        int cnt=0, first;
        for(int i=0;i<n;i++){
            cin >> str;
            for(int j=0;j<n;j++){
                a=str[j]-'0';
                if(i == 0 && j ==0)first=a;
                if(a == pre && !(i==0&&j==0)) a = (1-pre), cnt++;
                pre=a;
            }
        }
        if(first == 0) ch[k]=cnt;
        else ch[k]=(n*n)-cnt;
        as[idx1++]=k;
    }


    sort(as, as+idx1, cmp);
    int ans=ch[as[0]]+ch[as[1]]+((n*n)-ch[as[2]])+((n*n)-ch[as[3]]);

    cout << ans << endl;

    return 0;
}
