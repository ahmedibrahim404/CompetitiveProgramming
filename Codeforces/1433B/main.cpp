#include <iostream>

using namespace std;
int t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int ns[n+1];
        int sz=0, no, prev=0, cnt=0, ans=0;
        for(int i=0;i<n;i++){
            cin >> no;
            if(no==0) cnt++;
            if(no==1){
                 if(prev) ans += cnt;
                 prev=1;
                 cnt=0;
            }
        }

        cout << ans << "\n";


    }
    return 0;
}
