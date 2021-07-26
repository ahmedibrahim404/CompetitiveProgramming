#include<bits/stdc++.h>

using namespace std;
int T,n,cur,tot,sz;
vector<string> st;

void get(int sum, string str){

    if(str.length()==n) {
        st[sz++]=str;
        return;
    }
    if (n-str.length()-1>=cur-sum) get(sum, str+"0");
    if(sum<cur) get(sum+1, str+"1");


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> n;
        tot=2*n;
        for(int i=0;i<=tot;i+=2){
            sz=0;
            st=vector<string>(1024+9);
            cur=i/2;
            get(0, "");
            for(int j=0;j<sz;j++) for(int k=0;k<sz;k++) cout<<st[j]<<st[k]<<endl;
        }

    }
    return 0;
}
