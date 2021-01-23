#include <iostream>

using namespace std;

int t, n, no;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> no;
            int tot=0;
            for(int j='a';j<='z'&&tot<no;j++,tot++) cout << j;
            cout << endl;
        }
    }
    return 0;
}
