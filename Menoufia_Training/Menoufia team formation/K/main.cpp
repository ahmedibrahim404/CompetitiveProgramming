#include <iostream>

using namespace std;
int n;
string a, b, c, d, e;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    while(n--){
        cin >> a >> b >> c >> d;
        cin >> a >> b >> c >> e;
        cout << "Uh! "<< e <<"-"<< d <<"!" << endl;
    }
    return 0;
}
