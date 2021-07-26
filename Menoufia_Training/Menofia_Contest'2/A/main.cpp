#include <iostream>

using namespace std;

string s1, s2, s3;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s1 >> s2 >> s3;    int l1=s1.length(), l2=s2.length(), l3=s3.length();

    string s4="";
    for(int i=l1-1;i>=0;i--){
        s4 += s1[i];
    }

    bool f1=0, f2=0;
    for(int i=0;i<l1;i++){

        if(s1[i] == s2[0] && !f1){

            if(s1.substr(i, l2) == s2){

                for(int j=i+l2;j<l1;j++){
                    if(s1[j] == s3[0]){
                        if(s1.substr(j, l3) == s3){
                            f2=1;
                            break;
                        }
                    }
                }

            }
        }

    }

    if(f1 && f2){
        cout << "both" << endl;
    } else if(f1){
        cout << "forward" << endl;
    } else if(f2){
        cout << "backward" << endl;
    } else {
        cout << "fantasy" << endl;
    }

    return 0;
}
