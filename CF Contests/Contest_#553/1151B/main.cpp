#include <iostream>

using namespace std;


int n, m, num;

int main(){

    cin >> n >> m;

    int prev=0;
    string res="";
    for(int i=0;i<n;i++){

        bool took=false;
        for(int j=0;j<m;j++){

            cin >> num;
            if(num != prev && !took){
                prev = prev^num;
                took=true;
                res += to_string(j+1) + " ";
            }

        }

        if(took==false) {
            prev=0;
            res += "1 ";
        }

    }

    if(prev == 0) return cout << "NIE" << endl, 0;

    cout << "TAK" << endl;

    cout << res << endl;

    return 0;
}
