#include <iostream>

using namespace std;

int k;

int main(){
    cin >> k;
    long long no=(1<<17);
    cout << "2 3\n";
    cout << no + k << " " << no << " " << 0 << "\n";
    cout << k << " " << no + k << " " << k << "\n";
    return 0;
}
