#include <iostream>

using namespace std;
const int N = 10000 + 3;
int n, m, k;;
bool is[N];
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        for(int i=0;i<n;i++) is[i]=0;
        for(int i=0;i<n;i++){
            char cur;
            cin >> cur;
            if(cur == 'S') is[i]=0;
            else is[i]=1;
        }

        k--;
        int cnt=0;
        while(m--){
            char cur;
            cin >> cur;
            if(cur == 'A'){
                k=n-1;
                continue;
            } else {
                int test;
                cin >> test;
                test--;
                if(!is[test] && test <= k) cnt++;
                k=max(test, k);
            }


        }

        cout << cnt << endl;

    }
    return 0;
}
