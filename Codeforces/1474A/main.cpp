#include <iostream>

using namespace std;
int t, n;
int main(){
    cin >> t;
    while(t--){
        string str;
        cin >> n;
        cin >> str;
        cout << 1;
        int prev=(str[0]-'0'+1);
        for(int i=1;i<n;i++){
            int cur=str[i]-'0';
            int tobe=(3-prev);

            if(tobe==3){
                tobe=2;
            }

            if(tobe - cur == 2){
                if(prev==1){
                    // tobe=0;
                    tobe=0;
                    if(tobe-cur >= 0){
                        cout << tobe-cur;
                        prev = tobe;
                    } else {
                        cout << 1;
                        prev=cur+1;
                    }
                } else {
                    // tobe=1;
                    tobe=1;
                    cout << tobe-cur;
                    prev=tobe;
                }

            } else {
                cout << tobe - cur;
                prev=tobe;
            }


        }

            cout << "\n";
    }
    return 0;
}
