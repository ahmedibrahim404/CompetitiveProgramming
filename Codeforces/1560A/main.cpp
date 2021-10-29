#include <iostream>

using namespace std;

int ns[1000 + 3];
int main(){
    int t;
    cin >> t;
    int idx=0;
    for(int i=1;idx < 1000+2;i++){
        if(i%3 == 0 || i%10 == 3) continue;
        ns[idx++] = i;
    }

    while(t--){
        int c;cin >> c;
        cout << ns[c-1] << endl;
    }
    return 0;
}
