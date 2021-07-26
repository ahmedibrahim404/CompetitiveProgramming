#include <iostream>

using namespace std;

int T, n, k, no;
int main(){
    cin >> T;
    while(T--){
        cin >> n >> k;
        bool found=0;
        for(int i=0;i<n;i++){
            cin >> no;
            if((no+k)%7==0&&!found) {cout << "Yes\n";found=1;}
        }
        if(!found) cout << "No\n";
    }
    return 0;
}
