#include <iostream>

using namespace std;
int t, n;
string str;
int main(){
    cin>>t;
    while(t--){
        cin >> n >> str;
        int cur=0, o=0;
        for(int i=0;i<n;i++){
            if(str[i]=='(') cur++;
            else cur--;
            if(cur<0) cur=0, o++;
        }
        printf("%d\n", max(o, cur));
    }
    return 0;
}
