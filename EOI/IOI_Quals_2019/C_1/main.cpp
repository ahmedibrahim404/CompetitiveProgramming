#include <iostream>

using namespace std;

int T, N, K, num;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> T;

    while(T--){

        cin >> N >> K;

        int pre=-1, len=0, mxlen=0;
        for(int i=0;i<N;i++){
            cin >> num;
            if(pre == num) {
                len++;
            } else {
                if(len > mxlen) mxlen=len;
                pre=num, len=1;
            }
        }

        cout << min(N, mxlen + K) << endl;

    }

    return 0;
}
