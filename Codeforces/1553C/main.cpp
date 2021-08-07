#include <iostream>

using namespace std;

int t;
string str;

int solve(int cur=0, int f=0, int s=0){

    if(cur == 10) return cur;

    if(f + (10-cur)/2 < s) return cur;
    if(s + (10-cur+1)/2 < f) return cur;

    if(str[cur] == '1') return solve(cur+1, f+(cur%2==0), s+(cur%2==1));
    else if(str[cur] == '0') return solve(cur+1, f, s);
    else return min( solve(cur+1, f+(cur%2==0), s+(cur%2==1)), solve(cur+1, f, s) );
}

int main(){
    cin >> t;
    while(t--){
        cin >> str;
        cout << solve() << "\n";
    }
    return 0;
}
