#include <iostream>

using namespace std;

int n;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        string num=to_string(i);
        int len=num.length();
        bool p=1, p1=0, p3=0;
        for(int j=0;j<len;j++){
//            if(num[j]=='4'){
//                p=0;
//                break;
//            }
            if(num[j]=='1') p1=1;
            if(num[j]=='3') p3=1;
            if(p1&&p3){
                p=0;
                break;
            }
        }
        if(!p) cout << i << " ";
    }
//    cout << del << endl;
    return 0;
}
