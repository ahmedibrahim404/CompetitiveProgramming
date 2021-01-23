#include <iostream>

using namespace std;
int t, n, k;
char nth_letter(int n)
{
    return "abcdefghijklmnopqrstuvwxyz"[n-1];
}
int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        int each=n/k;
        for(int j=0;j<k;j++){
        for(int i=0;i<each;i++){
            cout<<nth_letter(j+1);
        }
        }
        int re=n-each*k;
        int idx=0;
        while(re--){
            cout << nth_letter(idx+1);
            idx++;
        }
        cout << endl;

    }
    return 0;
}
