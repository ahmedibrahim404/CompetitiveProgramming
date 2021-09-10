#include <iostream>

using namespace std;
typedef long long ll;
int n;
string s;
int main(){
freopen("abc.in", "r", stdin);

    cin >> n >> s;int idx=-1;int a=0, c=0;
    for(int i=0;i<n;i++){
        if(s[i] == 'a'){
            a++;
        } else if(s[i] == 'c') {
            c++;
        } else {
            idx = i;
        }
    }

    if(idx == -1){
        if(a && c)cout << "-1\n";
        else cout << "0\n";
        return 0;
    }

    if((a==0) ^ (c==0)){
        cout << "0\n";
        return 0;
    }

    int cnt=0;
    for(int i=0;i<a;i++){
        if(s[i] == 'a') cnt++;
    }

    int ans= (a-cnt) + (((s[a] == 'a' && idx < a) || (idx == a)) ? 0 : 1);

    swap(a, c);
    cnt=0;
    for(int i=0;i<a;i++){
        if(s[i] == 'c') cnt++;
    }
    ans= min(ans, (a-cnt) + (((s[a] == 'c' && idx < a) || (idx == a)) ? 0 : 1));

    cout<< ans << "\n";

    return 0;
}
