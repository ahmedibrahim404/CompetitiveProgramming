#include <iostream>

using namespace std;

int t, a, b, c;

int calc(int x, int y, int z){
    return abs(x-a) + abs(y-b) + abs(z-c);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        int mi=2e9;
        int x=1e4, y=1e4, z=1e4;
        for(int i=1;i<20000+1;i++){
            for(int j=i;j<20000+1;j+=i){
                if(i > j) continue;
                if(mi > calc(i, j, (c/j) * j + (j))){
                    x=i, y=j, z=(c/j) * j + (j);
                    mi=calc(x, y, z);
                }
                if(mi > calc(i, j, (c/j)* j)){
                    x=i, y=j, z=(c/j)*j;
                    mi=calc(x, y, z);
                }
            }
        }

        cout << calc(x, y, z) << "\n" << x << " " <<y << " " << z << "\n";

    }
    return 0;
}
