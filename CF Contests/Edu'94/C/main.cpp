#include <iostream>

using namespace std;
const int MAX=100000+4;
int t;
string str;
int main(){
    cin >> t;
    int x;
    while(t--){
        cin >> str;
        cin >> x;
        int n=str.length();

        string ans="";
        for(int i=0;i<n;i++) ans += '1';
        bool stop=0;
        for(int i=0;i<n;i++){

            if(str[i]=='1') continue;

            if(i-x>=0){
                ans[i-x]='0';
            }
            if(i+x<n){
                ans[i+x]='0';
            }

        }

        for(int i=0;i<n;i++){

            if(str[i]=='0') continue;

            if( (i+x<n&&ans[i+x]=='1') || (i-x>=0&&ans[i-x]=='1')  )continue;
            stop=1;
            break;

        }

        if(stop) cout << "-1\n";
        else cout << ans << "\n";


    }
    return 0;
}
