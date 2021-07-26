#include<bits/stdc++.h>
using namespace std;

int N;
bool is[10];
int A, n;
string ans="";
vector<int> ns;

char get(int num){
    if(num==0) return '0';
    else if(num==1) return '1';
    else if(num==2) return '2';
    else if(num==3) return '3';
    else if(num==4) return '4';
    else if(num==5) return '5';
    else if(num==6) return '6';
    else if(num==7) return '7';
    else if(num==8) return '8';
    else if(num==9) return '9';

}

void solve(int cur=0, string num="", int res=0){

    if(ans!="") return;

    if(cur && !res){
        ans=num;
        return;
    }

    if(cur==18) return;

    for(int i=ns.size()-1;i>=0;i--){
        solve(cur+1, num+get(ns[i]), (res*10+ns[i])%A);
    }

}


int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&n);
        ns.push_back(n);
    }
    scanf("%d",&A);
    solve();
    if(ans.length()==0) cout << "-1";
    else cout << ans;
    return 0;
}
