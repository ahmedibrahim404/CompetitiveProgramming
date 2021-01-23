#include <iostream>

using namespace std;
int t, n;
string str;
int ns[200000][26];

int solve(int st, int en, int cur){
    if(st==en) return (str[st]-'a' != cur);
    int mid=(st+en)/2;
    int fir=ns[mid][cur] - (st > 0 ? ns[st-1][cur] : 0);
    int sec=ns[en][cur] - (ns[mid][cur]);
    return min((mid-st+1)-fir + solve(mid+1, en, cur+1), (en-mid)-sec + solve(st, mid, cur+1));;
}

int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n >> str;
        for(int i=0;i<n;i++) for(int j=0;j<26;j++) ns[i][j]=0;
        for(int i=0;i<n;i++){
            ns[i][ str[i]-'a' ]++;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<26;j++){
                ns[i][j] += ns[i-1][j];
            }
        }
        cout << solve(0, n-1, 0) << "\n";

    }
    return 0;
}
