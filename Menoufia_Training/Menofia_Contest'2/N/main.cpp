#include <iostream>

using namespace std;

int n, y;;
int main(){
    cin >> n >> y;
    for(int i=n;i>=0;i--){
        for(int j=n-i;j>=0;j--){
            int k=n-(i+j);
            if((i*10000)+(j*5000)+(1000*k) == y){
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}
