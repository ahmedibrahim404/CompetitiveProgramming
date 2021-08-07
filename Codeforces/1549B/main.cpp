#include <iostream>

using namespace std;

int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        int cnt=0;
        bool aval[n];
        for(int i=0;i<n;i++) aval[i]=1;
        for(int i=0;i<n;i++){
            if(s2[i] != '1') continue;
            if(i-1 >= 0 && s1[i-1] == '1' && aval[i-1]){
                cnt++;
                aval[i-1]=0;
            } else if(s1[i] == '0') {
                cnt++;
            } else if(i+1 < n && s1[i+1] == '1' && aval[i+1]){
                cnt++;
                aval[i+1]=0;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
