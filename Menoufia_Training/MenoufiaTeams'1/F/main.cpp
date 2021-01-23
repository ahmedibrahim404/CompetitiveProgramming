#include <iostream>

using namespace std;

int T,a, b;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    string a, b;
    while(T--){
        cin >> a >> b;
        string arr[4];
        arr[0].push_back(b[0]);
        arr[0].push_back(b[1]);
        arr[0].push_back(b[2]);

        arr[1].push_back(b[0]);
        arr[1].push_back(b[1]);
        arr[1].push_back(b[3]);

        arr[2].push_back(b[0]);
        arr[2].push_back(b[2]);
        arr[2].push_back(b[3]);

        arr[3].push_back(b[1]);
        arr[3].push_back(b[2]);
        arr[3].push_back(b[3]);

        int len=a.length();
        int ans=-1;
        for(int i=0;i<len-2;i++){

//            cout << "HEE\n";

            if(i+3<len){
                // try 4
                if(a.substr(i, 4)==b){
                    ans=max(ans, 2);
                }
            }
//            cout << "HEE\n";

            if(i+2<len){
                for(int j=0;j<4;j++){
                    cout << arr[j] << " " << a.substr(i, 3) << endl;
                    if(arr[j]==a.substr(i, 3)) ans=max(ans, 1);
                }
            }

        }

        if(ans==-1){
            cout << "none\n";
        } else if(ans==1){
            cout << "almost good\n";
        } else {
            cout << "good\n";
        }

    }
    return 0;
}
