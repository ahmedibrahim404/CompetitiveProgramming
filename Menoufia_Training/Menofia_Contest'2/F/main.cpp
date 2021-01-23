#include <iostream>

using namespace std;

int n, m, ns[500+3][500+3];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int result=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ns[i][j];
        }
        if(result==-1) result=ns[i][0];
        else result ^= ns[i][0];
    }
    if(result != 0){
        cout << "TAK" << endl;
        for(int i=0;i<n;i++){
            cout << "1";
            if(i != n-1) cout << " ";
        }
        return 0;
    } else {
        int row=-1, idx;
        bool stop=0;
        for(int i=0;i<n && !stop;i++){
            for(int j=1;j<m;j++){
                if(ns[i][j] != ns[i][0]){
                    row=i, idx=j;
                    stop=1;
                    break;
                }
            }
        }
        if(row == -1){
            cout << "NIE" << endl;
            return 0;
        } else {
            cout << "TAK" << endl;
            for(int i=0;i<n;i++){
                if(i != row)cout << "1";
                else cout << idx+1 << endl;
                if(i != n-1) cout << " ";
            }
        }
    }
    return 0;
}

