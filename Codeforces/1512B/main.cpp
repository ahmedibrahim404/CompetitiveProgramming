#include <iostream>

using namespace std;
const int N = 400 + 1;
char ns[N][N];
int main(){
    int t;cin >> t;
    while(t--){
        int n;cin>>n;
        pair<int, int> fr={-1, -1}, sc={-1, -1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> ns[i][j];
                if(ns[i][j] == '*') if(fr == pair<int, int>(-1, -1)) fr = {i, j}; else sc = {i, j};
            }
        }

        if(fr.first == sc.first){
            if(fr.first - 1 >= 0){
                ns[fr.first - 1][fr.second] = '*';
                ns[fr.first - 1][sc.second] = '*';
            } else if(fr.first + 1 < n) {
                ns[fr.first + 1][fr.second] = '*';
                ns[fr.first + 1][sc.second] = '*';
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) cout << ns[i][j];
                cout << "\n";
            }
            continue;
        }

        if(fr.second == sc.second){
            if(fr.second - 1 >= 0){
                ns[fr.first][fr.second - 1] = '*';
                ns[sc.first][sc.second - 1] = '*';
            } else if(fr.second + 1 < n){
                ns[fr.first][fr.second + 1] = '*';
                ns[sc.first][sc.second + 1] = '*';
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) cout << ns[i][j];
                cout << "\n";
            }
            continue;
        }

        ns[sc.first][fr.second] = '*';
        ns[fr.first][sc.second] = '*';
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) cout << ns[i][j];
            cout << "\n";
        }


    }
    return 0;
}
