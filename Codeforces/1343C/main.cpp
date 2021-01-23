#include <iostream>

using namespace std;
typedef long long ll;
int t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        ll ns[n];
        ll sum=0;
        ll prev=-1, no;
        ll need;
        for(int i=0;i<n;i++){
            cin >> no;
            if(prev==-1){
                need=no;
                if(no > 0) prev=1;
                else prev=0;
            } else if(prev==1){
                if(no>0) need=max(need, no);
                else {
                    sum += need;
                    prev=0, need=no;
                }
            } else {
                if(no<0) need=max(need, no);
                else {
                    sum += need;
                    prev=1, need=no;
                }
            }

        }

        sum += need;

        cout << sum << "\n";

    }
    return 0;
}
